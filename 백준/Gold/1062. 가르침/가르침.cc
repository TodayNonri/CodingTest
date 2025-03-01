#include <iostream>
#include <vector>
#include <climits>
#include <string>
#include <algorithm>

using namespace std;

int N, K, iResult = 0;
int Word[54] = {0, };

int Counting(int iMask)
{
	int iCount = 0;
	for (int i : Word)
	{
		if (i && (i & iMask) == i)
			++iCount;
	}
	return iCount;
}

int FindMax(int iIndex, int iDepth, int iMask)
{
	if (iDepth < 0)
		return 0;
	if (iIndex == 26)
		return Counting(iMask);
	int result = FindMax(iIndex + 1, iDepth - 1, iMask | (1 << iIndex));
	if (iIndex != 'a' - 'a' && iIndex != 'n' - 'a' && iIndex != 't' - 'a' && iIndex != 'i' - 'a' && iIndex != 'c' - 'a')
		result = max(result, FindMax(iIndex + 1, iDepth, iMask));

	return result;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >>K;

	string strInput;
	for (int i = 0; i < N; ++i)
	{
		cin >> strInput;
		for (auto s : strInput)
			Word[i] |= (1 << (s - 'a'));
	}

	cout<<FindMax(0, K, 0);

	return 0;
}