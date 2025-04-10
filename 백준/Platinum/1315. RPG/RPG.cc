#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

struct game
{
	int x, y, c;
};
vector<game> a;
int N, dp[1001][1001];
bool visited[101];

int rpg(int STR, int INT) 
{
	int& iResult = dp[STR][INT];
	if (iResult != -1) return iResult;

	iResult = 0;
	int pnt = 0;
	vector<int> v;
	for (int i = 0; i < N; i++) 
	{
		if (a[i].x <= STR || a[i].y <= INT) 
		{
			iResult++;
			if (!visited[i]) 
			{
				visited[i] = true;
				pnt += a[i].c;
				v.push_back(i);
			}
		}
	}

	for (int p = 0; p <= pnt; p++) 
	{
		int nextSTR = min(1000, STR + p);
		int nextINT = min(1000, INT + pnt - p);
		iResult = max(iResult, rpg(nextSTR, nextINT));
	}
	for (int here : v)
		visited[here] = false;

	return iResult;
}

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) 
	{
		int STR, INT, PNT;
		cin >> STR >> INT >> PNT;
		a.push_back({ STR, INT, PNT });
	}
	memset(dp, -1, sizeof(dp));
	cout << rpg(1, 1);
}