#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main()
{
	string str;
	cin >> str;
	int arr[26] = { 0, };
	for (auto a : str)
	{
		arr[a - 'a']++;
	}

	for (auto i : arr)
		cout << i << " ";
}
