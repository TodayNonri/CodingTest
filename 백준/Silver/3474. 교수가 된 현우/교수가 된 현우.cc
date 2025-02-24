#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int T;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;
	int iInput;
	for (int i = 0; i < T; ++i)
	{
		cin >> iInput;
		int two = 0, five = 0;
		for (int j = 2; j <= iInput; j*=2)
		{
			two += iInput / j;
		}
		for (int j = 5; j <= iInput; j *=5)
		{
			five += iInput / j;
		}

		cout << min(two, five)<<"\n";
	}

	return 0;
}
