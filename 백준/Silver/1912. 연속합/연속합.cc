#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <cmath>
#include <list>
using namespace std;



int main()
{
	int n, iResult(-1001);
	int iSum = 0;
    int iInput;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; ++i)
	{
		cin>>iInput;
        iSum+=iInput;
        iResult = max(iResult, iSum);
        if(iSum<0) iSum = 0;
	}

    cout << iResult;

	return 0;
}
