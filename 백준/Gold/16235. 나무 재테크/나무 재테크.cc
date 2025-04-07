#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

int N, M, K;
int Board[11][11];
int Plus[11][11];
vector<int> vTree[11][11];
vector<int> vDeadTree[11][11];

const int dy[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
const int dx[] = { 0, 1, 1, 1, 0, -1, -1, -1 };

void spring()
{
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            if (vTree[i][j].empty())
                continue;

            vector<int> newTrees;
            sort(vTree[i][j].begin(), vTree[i][j].end());

            for (int t = 0; t < vTree[i][j].size(); ++t)
            {
                int age = vTree[i][j][t];
                if (Board[i][j] >= age)
                {
                    Board[i][j] -= age;
                    newTrees.push_back(age + 1);
                }
                else
                {
                    vDeadTree[i][j].push_back(age);
                }
            }
            vTree[i][j] = newTrees;
        }
    }
}

void summer()
{
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            if (vDeadTree[i][j].empty())
                continue;


            for (auto& deadtree : vDeadTree[i][j])
            {
                deadtree /= 2;
                Board[i][j] += deadtree;
            }

            vDeadTree[i][j].clear();
        }
    }
}

void fall()
{
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            if (vTree[i][j].empty())
                continue;


            for (auto& tree : vTree[i][j])
            {
                if (tree % 5 == 0)
                {
                    for (int k = 0; k < 8; ++k)
                    {
                        int ny = i + dy[k];
                        int nx = j + dx[k];
                        if (ny >= N || nx >= N || ny < 0 || nx < 0)
                            continue;
                        vTree[ny][nx].insert(vTree[ny][nx].begin(), 1);
                    }
                }
            }
        }
    }
}

void winter()
{
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            Board[i][j] += Plus[i][j];
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M >> K;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cin >> Plus[i][j];
            Board[i][j] = 5;
        }
    }
    int x, y, iTreeAge;
    for (int i = 0; i < M; ++i)
    {
        cin >> x >> y >> iTreeAge;
        vTree[x-1][y-1].push_back(iTreeAge);
    }

    for (int i = 0; i < K; ++i)
    {
        spring();
        summer();
        fall();
        winter();
    }

    int iCount = 0;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            iCount += vTree[i][j].size(); 
        }
    }
    cout << iCount;

    return 0;
}
