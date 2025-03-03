#include <iostream>
#include <vector>
#include <climits>
#include <string>
#include <algorithm>

using namespace std; 

int M;
bool bin[21]{ false };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> M;
	int iInput;
	string strInput;
	for (int i = 0; i < M; ++i)
	{
		cin >> strInput;
		if (strInput == "add")
		{
			cin >> iInput;
			bin[iInput] |= 1;
		}
		else if (strInput == "remove")
		{
			cin >> iInput;
			bin[iInput] = 0;
		}
		else if (strInput == "toggle")
		{
			cin >> iInput;
			bin[iInput] = !bin[iInput];
		}
		else if (strInput == "check")
		{
			cin >> iInput;
			cout << bin[iInput] << " ";
		}
		else if (strInput == "all")
		{
			for (int j = 1; j <= 20; ++j)
				bin[j] = 1;
		}
		else if (strInput == "empty")
		{
			for (int j = 1; j <= 20; ++j)
				bin[j] = 0;
		}
	}



	return 0;
}