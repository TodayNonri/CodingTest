#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main()
{
	string str, temp;
	cin >> str;
	
	temp = str;
	reverse(temp.begin(), temp.end());
	if (temp == str)
		cout << 1 << "\n";
	else
		cout << 0 << "\n";

	return 0;
}