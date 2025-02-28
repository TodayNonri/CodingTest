#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int N, L, iResult = 0;
int bridge1[101][101];
int bridge2[101][101];

void Check(int arr[101][101])
{
	for (int i = 0; i < N; ++i)
	{
		int iCount = 1;
		int j;
		for (j = 0; j < N - 1; ++j)
		{
			if (arr[i][j] == arr[i][j + 1])
				iCount++;
			else if (arr[i][j] + 1 == arr[i][j + 1] && iCount >= L)
				iCount = 1;
			else if (arr[i][j] - 1 == arr[i][j + 1] && iCount >= 0)
				iCount = -L + 1;
			else 
				break;
		}
		if (j == N - 1 && iCount >= 0)
			iResult++;
	}
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> L;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> bridge1[i][j];
			bridge2[j][i] = bridge1[i][j];
		}
	}

	Check(bridge1);
	Check(bridge2);

	cout << iResult;
	
	return 0;
}