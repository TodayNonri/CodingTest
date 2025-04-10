#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int arr[10] = { 6, 2, 5, 5, 4, 5, 6, 3, 7, 6 }, T, N;
string dp[104], dp2[104], MAX_STR = "11111111111111111111111111111111111111111111111111111";
string get_min_str(string arr, string b)
{
	if (arr.size() == b.size())
		return (arr < b ? arr : b);
	if (arr.size() < b.size())
		return arr;
	else 
		return b;
}
string findMax(int here) 
{
	string ret = "";
	if (here & 1)
	{ ret += '7'; here -= 3; }
	while (here) 
	{
		ret += '1';
		here -= 2;
	}
	return ret;
}
string findMin(int here) 
{
	if (here == 0)
		return "";
	string& ret = dp[here];
	if (ret != MAX_STR) 
		return ret;
	for (int i = 0; i <= 9; i++) 
	{
		if (here - arr[i] < 0)
			continue;
		if (here == N && i == 0) 
			continue;
		ret = get_min_str(ret, to_string(i) + findMin(here - arr[i]));
	}
	return ret;
}
int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);

	cin >> T;
	while (T--) 
	{
		cin >> N;
		fill(dp, dp + 104, MAX_STR);
		cout << findMin(N) << " " << findMax(N) << "\n";
	}
}