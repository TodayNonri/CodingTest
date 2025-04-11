#include <bits/stdc++.h>
using namespace std; 
int t, n; 
string dp[1001];   
map<char, char> mp; 
char a[6] = {'(', ')', '{', '}', '[', ']'};
bool check(string before, string after){ 
	if(before == "" && after == "") return false; 
	if(before == "") return true;   
	if(before.size() == after.size()) return after < before;
	return after.size() < before.size(); 
}
 
int main(){  
	for(int i = 0; i < 6; i++){
		mp[i + '1'] = a[i];
	}  
	dp[1] = "12"; 
	dp[2] = "34";
	dp[3] = "56"; 
	for(int idx = 1; idx <= 1000; idx++){   
		if(idx % 2 == 0 && check(dp[idx], '1' + dp[idx / 2] + '2'))dp[idx] = '1' + dp[idx / 2] + '2'; 
		if(idx % 3 == 0 && check(dp[idx], '3' + dp[idx / 3] + '4'))dp[idx] = '3' + dp[idx / 3] + '4'; 
		if(idx % 5 == 0 && check(dp[idx], '5' + dp[idx / 5] + '6'))dp[idx] = '5' + dp[idx / 5] + '6';   
		for(int i = 1; i <= idx; i++){
			if(check(dp[idx], dp[i] + dp[idx - i]))dp[idx] = dp[i] + dp[idx - i]; 
		}
	}  
	cin >> t; 
	while(t--){
		cin >> n;
		for(char a : dp[n]) cout << mp[a];
		cout << "\n"; 
	} 
}