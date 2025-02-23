#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int H, W;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> H >>W;
	vector<string> vStr;
	vector<int> vNum;
	for (int i = 0; i < H; ++i)
	{
		string strInput;
		cin >> strInput;
		for (int j = 0; j < W; ++j)
		{
			if (strInput[j] == 'c')
			{
				vNum.push_back(0);
			}
			else
			{
				for (int k = j; k >= 0; --k)
				{
					if(k == 0 && strInput[k] != 'c')
						vNum.push_back(-1);
					else if (strInput[k] == 'c')
					{
						vNum.push_back(j-k);
						break;
					}
				}
			}
		}
	}

	for (int i = 0; i < H; ++i)
	{
		for (int j = 0; j < W; ++j)
		{
			cout << vNum[(i*W) +j] << " ";
		}
		cout << "\n";
	}

	return 0;
}
