#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
long long A, B, C, result = 0;
long long go(long long n, long long m)
{
	if (m == 1) return n % C;
	long long value = go(n, m / 2);

	value = (value * value) % C;
	if (m % 2)
		value = (value * n) % C;

	return value;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	cin >> A >> B >> C;
	cout<<go(A, B);

	return 0;
}
