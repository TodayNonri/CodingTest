#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

string str, result;
char mid;
int iCount[200], flag;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> str;
	for (char a : str) iCount[a]++;
	for (int i = 'Z'; i >= 'A'; --i)
	{
		if (iCount[i])
		{
			if (iCount[i] & 1) //  홀수일 경우
			{
				mid = char(i);
				flag++;
				iCount[i]--;
			}
			if (flag == 2)break;
			for (int j = 0; j < iCount[i]; j += 2)
			{
				result = char(i) + result;
				result += char(i);
			}
		}
	}

	if (mid) result = result.substr(0, result.size() / 2) + mid + result.substr(result.size() / 2);
	if (flag == 2) cout << "I'm Sorry Hansoo";
	else cout << result;


	return 0;
}
