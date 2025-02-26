#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

int N, K, iMin = INT_MAX, iCount = 0;
int visit[200'002];

int Cal(int iNum, int iCategory)
{
    if (iCategory == 0) 
        return iNum + 1;
    if (iCategory == 1) 
        return iNum - 1;
    if (iCategory == 2) 
        return iNum * 2;
    
    return iNum;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> K;

    fill(visit, visit + 200002, INT_MAX); 
    visit[N] = 0; 

    queue<int> q;
    q.push(N);

    while (!q.empty())
    {
        int iNum = q.front();
        q.pop();

        if (iNum == K)
        {
            if (visit[iNum] < iMin)
            {
                iMin = visit[iNum];
                iCount = 1;  
            }
            else if (visit[iNum] == iMin)
            {
                iCount++;  
            }
            continue;
        }

        for (int i = 0; i < 3; ++i)
        {
            int val = Cal(iNum, i);
            if (val < 0 || val > 200000) 
                continue;

            if (visit[val] == INT_MAX || visit[val] == visit[iNum] + 1)
            {
                visit[val] = visit[iNum] + 1;
                q.push(val);
            }
        }
    }

    cout << iMin << "\n" << iCount;

    return 0;
}
