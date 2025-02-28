#include <iostream>
#include <vector>
#include <climits>
#include <string>

using namespace std;

int N, Coin[44], iResult = INT_MAX;

void CheckSwap(int iHere)
{
	if (iHere == N + 1)
	{
		int iSum = 0;
		for (int i = 1; i <= (1 << (N - 1)); i *= 2)
		{
			int iCount = 0;
			for (int j = 1; j <= N; ++j)
			{
				if (Coin[j] & i)
				{
					iCount++;
				}
			}
			iSum += min(iCount, N - iCount);
		}
		iResult = min(iResult, iSum);
		return;
	}

	CheckSwap(iHere + 1);
	Coin[iHere] = ~Coin[iHere];
	CheckSwap(iHere + 1);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		string strInput;
		cin >> strInput;
		int iValue = 1;
		for (int j = 0; j < N; j++)
		{
			if (strInput[j] == 'T')
				Coin[i] |= iValue;

			iValue *= 2;
		}

	}

	CheckSwap(1);

	cout << iResult;

	return 0;
}