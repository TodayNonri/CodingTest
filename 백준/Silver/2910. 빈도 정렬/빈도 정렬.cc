#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;
int N, C;
int arr[1001];
map<int, int> mp, mp_first;
vector<pair<int, int>> v;

bool cmp(pair<int, int> a, pair<int, int> b)
{
	if (a.first == b.first)
	{
		return mp[a.second] < mp[b.second];
	}

	return a.first > b.first;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> C;

	for (int i = 0; i < N; ++i)
	{
		cin >> arr[i];
		if (mp_first[arr[i]] == 0)
		{
			mp[arr[i]] = i + 1;
		}

		mp_first[arr[i]]++;
	}

	for (auto it : mp_first)
	{
		v.push_back({ it.second, it.first });
	}

	sort(v.begin(), v.end(), cmp);

	for (auto i : v)
	{
		for (int j = 0; j < i.first; j++)
			cout << i.second << " ";
	}
	
	return 0;
}
