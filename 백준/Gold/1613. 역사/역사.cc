#include <iostream>
#include <algorithm>

using namespace std;

int N, K, S, E, a, b, c, dist[404][404], t;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);    cout.tie(NULL);

    cin >> N>> K;

    for (int i = 0; i < K; ++i)
    {
        cin >> a >> b;
        dist[a][b] = -1, dist[b][a] = 1;
    }


    for (int k = 1; k <= N; ++k)
        for (int i = 1; i <= N; ++i)
            for (int j = 1; j <= N; ++j)
            {
                if (dist[i][k] == 1 && dist[k][j] == 1) dist[i][j] = 1;
                else if(dist[i][k] == -1 && dist[k][j] == -1) dist[i][j] = -1;
            }

    cin >> t;

    for (int i = 0; i < t; ++i)
    {
        cin >> S >> E;
        cout << dist[S][E] << "\n";
    }

    return 0;
}