#include <iostream>
#include <vector>
#include <climits>
#include <string>
#include <algorithm>

using namespace std;

int X, iResult = 0;

void CutWood(int iLength, int iSum)
{
	if (iSum == X)
	{
		cout << iResult;
		return;
	}
	if (iLength == X)
	{
		cout << 1;
		return;
	}

	int iHalf = (iLength / 2);
	if (iSum + iHalf > X)
		CutWood(iHalf, iSum);
	else if (iHalf + iSum <= X)
	{
		iResult++;
		iSum += iHalf;
		CutWood(iHalf, iSum);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> X;

	CutWood(64, 0);

	return 0;
}