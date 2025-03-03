#include <iostream>
#include <vector>
#include <climits>
#include <string>
#include <algorithm>

using namespace std; 

int N, M, iResult = 0;
int rect[5][5];
bool axis[5][5] = { false };
bool visited[5][5] = { false };


int FindMax()
{
	int iSum = 0;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (visited[i][j])
				continue;

			vector<int> vNum;
			visited[i][j] = true;
			vNum.push_back(rect[i][j]);
			int iNext = 1;
			if (axis[i][j] == true)
			{
				while (1)
				{
					if (j + iNext  >= M)
						break;
					if (axis[i][j + iNext] == true)
					{
						visited[i][j + iNext] = true;
						vNum.push_back(rect[i][j + iNext]);
						iNext++;
					}
					else
						break;
				}
			}
			else
			{
				while (1)
				{
					if (i + iNext >= N)
						break;
					if (axis[i + iNext][j] == false)
					{
						visited[i + iNext][j] = true;
						vNum.push_back(rect[i + iNext][j]);
						iNext++;
					}
					else
						break;
				}
			}
			string str = "";
			for (auto v : vNum)
				str += to_string(v);
			iSum += stoi(str);
		}
	}
	return iSum;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; ++i)
	{
		string strInput;
		cin >> strInput;
		for (int j = 0; j < M; ++j)
		{
			rect[i][j]= strInput[j] - '0';
		}
	}
		


	for (int bitmask = 0; bitmask < (1 << (N * M)); ++bitmask)
	{
		for (int x = 0; x < N; ++x)
		{
			for (int y = 0; y < M; ++y)
			{
				axis[x][y] = (bitmask & (1 << (x * M + y))); 
			}
		}
		fill(&visited[0][0], &visited[0][0] + 5 * 5, false);
		iResult = max(iResult, FindMax());
	}

	cout << iResult;

	return 0;
}