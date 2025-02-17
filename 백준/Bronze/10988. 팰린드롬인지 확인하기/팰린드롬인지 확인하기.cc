#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main()
{
	string str, strHalf;
	cin >> str;
	
	strHalf = str;
	reverse(strHalf.begin(), strHalf.end());
	if (strHalf == str)
		cout << 1 << "\n";
	else
		cout << 0 << "\n";

}
