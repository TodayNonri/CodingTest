#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N;

int line[6][3] =
{ {9, 3, 1},
{9, 1, 3},
{3, 9, 1},
{3, 1, 9},
{1, 9, 3},
{1, 3, 9} };
struct tagPosition
{
    int a;
    int b;
    int c;
};
int Visited[61][61][61] = { 0, };

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    vector<int> vSCV(3, 0);

    for (int i = 0; i < N; ++i)
    {
        cin >> vSCV[i];
    }

    tagPosition input = { vSCV[0], vSCV[1], vSCV[2] };
    queue<tagPosition> q;
    q.push(input);

    Visited[q.front().a][q.front().b][q.front().c] = 1;
    while (q.size())
    {
        int a = q.front().a;
        int b = q.front().b;
        int c = q.front().c;
        q.pop();
        for (int i = 0; i < 6; ++i)
        {
            int na = max(0, a - line[i][0]);
            int nb = max(0, b - line[i][1]);
            int nc = max(0, c - line[i][2]);
            if (Visited[na][nb][nc])
                continue;
            Visited[na][nb][nc] = Visited[a][b][c] + 1;

            q.push({ na, nb, nc });
        }
    }

    cout << Visited[0][0][0] - 1;


    return 0;
}
