#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;
int N;
int tree[65][65];

string quard(int y, int x, int size)
{
	if (size == 1) return string(1, tree[y][x]);

	char c = tree[y][x];
	
	string strResult = "";

	for (int i = y; i < y + size; ++i)
	{
		for (int j = x; j < x + size; ++j)
		{
			if (c != tree[i][j])
			{
				strResult += '(';
				strResult += quard(y, x, size / 2);
				strResult += quard(y, x + size / 2, size / 2);
				strResult += quard(y + size / 2, x, size / 2);
				strResult += quard(y + size / 2, x + size / 2, size / 2);
				strResult += ')';
				return strResult;
			}
		}
	}
	return string(1, tree[y][x]);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	string strInput;
	for (int i = 0; i < N; ++i)
	{
		cin >> strInput;
		for (int j = 0; j < N; ++j)
			tree[i][j] = strInput[j];
	}

	cout<<quard(0, 0, N)<<"\n";


	return 0;
}
