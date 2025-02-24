#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	string strInput;
	int team1 = 0, team2 = 0;
	int prevTime = 0;
	int iTeam = 0;
	int iTime = 0;
	vector<int> vTeam1Win;
	vector<int> vTeam2Win;
	for (int i = 0; i < N; ++i)
	{
		cin >> iTeam;
		cin >> strInput;

		iTime = atoi(strInput.substr(0, 2).c_str());
		iTime = (60 * iTime) + atoi(strInput.substr(3, 2).c_str());
		if (team1 > team2)
		{
			int temp = iTime - prevTime;
			vTeam1Win.push_back(temp);
		}
		else if (team1 < team2)
		{
			int temp = iTime - prevTime;
			vTeam2Win.push_back(temp);
		}

		if (iTeam == 1)
			team1++;
		else
			team2++;

		prevTime = iTime;
	}
	prevTime = 48 * 60;
	if (team1 > team2)
	{
		int temp = prevTime - iTime;
		vTeam1Win.push_back(temp);
	}
	else if (team1 < team2)
	{
		int temp = prevTime - iTime;
		vTeam2Win.push_back(temp);
	}

	int iResult = 0;
	for (auto& i : vTeam1Win)
		iResult += i;
	
	printf("%02d:%02d\n", (iResult / 60), (iResult % 60));
	iResult = 0;

	for (auto& i : vTeam2Win)
		iResult += i;
	printf("%02d:%02d\n", (iResult / 60), (iResult % 60));


	return 0;
}
