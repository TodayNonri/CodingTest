#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <climits>
#include <iomanip>

using namespace std;

int N, iResult = 1, iIndex;
int arr[1001], prev_list[1001], iCount[1001];

void Func(int idx)
{
    if (idx == -1)
        return;
    Func(prev_list[idx]);
    cout << arr[idx] << " ";
    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; ++i)
        cin >> arr[i];

    fill(prev_list, prev_list + 1001, -1);
    fill(iCount, iCount + 1001, 1);

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            if (arr[j] < arr[i] && iCount[i] < iCount[j] + 1)
            {
                iCount[i] = iCount[j] + 1;
                prev_list[i] = j;
                if (iResult < iCount[i])
                {
                    iResult = iCount[i];
                    iIndex = i;
                }
            }
        }
    }
    cout << iResult<<"\n";
    Func(iIndex);

    return 0;
}
