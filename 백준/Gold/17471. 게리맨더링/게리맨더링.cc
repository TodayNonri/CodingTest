#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int N, iResult = INT_MAX;

int People[11];
vector<int> vNeighbor[11];
int visitedR[11] = { 0 };
int visitedB[11] = { 0 };

pair<int, int> dfs(int here, int value) 
{
	visitedB[here] = 1;
	pair<int, int> pResult = { 1, People[here] };
	for (int there : vNeighbor[here]) {
		if (visitedR[there] != value) continue;
		if (visitedB[there]) continue;
		pair<int, int> _temp = dfs(there, value);
		pResult.first += _temp.first;
		pResult.second += _temp.second;
	}
	return pResult;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;

	for (int i = 1; i <= N; ++i)
		cin >> People[i];

	int iCount;
	for (int i = 1; i <= N; ++i)
	{
		cin >> iCount;
		int iInput;
		for (int j = 0; j < iCount; ++j)
		{
			cin>>iInput;
			vNeighbor[i].push_back(iInput);
			vNeighbor[iInput].push_back(i);
		}
	}

	for (int i = 1; i < (1 << N) - 1; i++)
	{
		fill(visitedR, visitedR + 11, 0);
		fill(visitedB, visitedB + 11, 0);
		int idx1 = -1, idx2 = -1;
		for (int j = 0; j < N; j++)
		{
			if (i & (1 << j))
			{ 
				visitedR[j + 1] = 1; idx1 = j + 1; 
			}
			else 
				idx2 = j + 1;
		}
		pair<int, int> comp1 = dfs(idx1, 1);
		pair<int, int> comp2 = dfs(idx2, 0);
		if (comp1.first + comp2.first == N) 
			iResult = min(iResult, abs(comp1.second - comp2.second));
	}
	if (iResult == INT_MAX)
	{
		cout << -1;
		return 0 ;
	}
	cout << iResult;

	return 0;
}