#include <iostream>
//#include <bits/stdc++.h>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int input[9];
	for (int i = 0; i < 9; i++)
	{
		cin >> input[i];
	}

	sort(input, input + 9);

	do {
		int sum = 0;
		for (int i = 0; i < 7; ++i)
			sum += input[i];

		if (sum == 100) break;
	} while (next_permutation(input, input + 9));

	for (int i = 0; i < 7; i++)
		cout << input[i] << "\n";
}
