#include <iostream>
#include <algorithm>
#include <cstring>
#include <deque>
using namespace std;

int N, L;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> L;

    deque<pair<int, int>> dq; 

    for (int i = 0; i < N; ++i)
    {
        int iNum;
        cin >> iNum;

        while (!dq.empty() && dq.back().first > iNum) 
            dq.pop_back();

        dq.emplace_back(iNum, i);

        if (dq.front().second <= i - L) 
            dq.pop_front();
        cout << dq.front().first << " ";
    }


    return 0;
}