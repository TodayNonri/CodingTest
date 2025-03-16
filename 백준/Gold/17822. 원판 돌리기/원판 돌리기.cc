#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int N, M, T, x, d, k, arr[54][54], iResult, visited[54][54], y;
const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };

bool bFlag = 1;
void _rotate(int y, int dir, int k) 
{
    vector<int> v;
    for (int i = 0; i < M; i++)
        v.push_back(arr[y][i]);
    if (dir == 1)
        rotate(v.begin(), v.begin() + k, v.end());
    else
        rotate(v.begin(), v.begin() + M - k, v.end());
    for (int i = 0; i < M; i++)
        arr[y][i] = v[i];
    return;
}
void dfs(int y, int x)
{
    for (int i = 0; i < 4; i++) 
    {
        int ny = y + dy[i];
        int nx = (x + dx[i] + M) % M;
        if (ny < 0 || ny >= N)
            continue;
        if (visited[ny][nx])
            continue;
        if (arr[y][x] == arr[ny][nx]) 
        {
            visited[y][x] = visited[ny][nx] = 1;
            bFlag = 0;
            dfs(ny, nx);
        }
    }
}
bool findAdj()
{
    bFlag = 1;
    memset(visited, 0, sizeof(visited));
    for (int i = 0; i < N; i++) 
    {
        for (int j = 0; j < M; j++)
        {
            if (arr[i][j] == 0)
                continue;
            if (visited[i][j])
                continue;
            dfs(i, j);
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (visited[i][j]) 
                arr[i][j] = 0;
        }
    }
    return bFlag;
}
void setAverage() 
{
    int iSum = 0;
    int iCount = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++) 
        {
            if (arr[i][j] == 0) 
                continue;
            iSum += arr[i][j];
            iCount++;
        }
    }
    double av = (double)iSum / (double)iCount;
    for (int i = 0; i < N; i++) 
    {
        for (int j = 0; j < M; j++)
        {
            if (arr[i][j] == 0)
                continue;
            if ((double)arr[i][j] > av) 
                arr[i][j]--;
            else if ((double)arr[i][j] < av)
                arr[i][j]++;
        }
    }
    return;
}
int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M >> T;
    for (int i = 0; i < N; i++) 
    {
        for (int j = 0; j < M; j++)
        {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < T; i++)
    {
        cin >> x >> d >> k;
        for (int j = x - 1; j < N; j += x) 
        {
            _rotate(j, d, k);
        }
        if (findAdj())setAverage();
    }
    for (int i = 0; i < N; i++) 
    {
        for (int j = 0; j < M; j++) 
        {
            iResult += arr[i][j];
        }
    }
    cout << iResult << "\n";
    return 0;
}
