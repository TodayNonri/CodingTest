#include <iostream>
#include <queue>
#include <vector>
#include <string> 

using namespace std;

int N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    vector<string> v(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> v[i];
    }

    for (int i = 0; i < N; ++i)
    {
        bool bCheck = false;
        int iCount = 0;
        int iSum = 0;
        for (int j = 0; j < v[i].size(); ++j)
        {
            if (v[i][j] == 'O')
            {
                ++iCount;
                iSum += iCount;
            }
            else
            {
                iCount = 0;
            }
        }
        cout << iSum << "\n";
    }


    return 0;
}