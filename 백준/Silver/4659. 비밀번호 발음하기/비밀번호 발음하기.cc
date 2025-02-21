#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<string> vStr;
	while (true)
	{
		string strInput;
		cin >> strInput;
		vStr.push_back(strInput);

		if (strInput == "end")
			break;
	}

	//<a> is acceptable.
	//<tv> is not acceptable.

	for (auto& str : vStr)
	{
		if (str == "end")
			break;
		//(a,e,i,o,u
		//no 모음 자음 3연속
		//같은글자 연속 안됨.
		if (str.find("a") == string::npos && str.find("e") == string::npos && str.find("i") == string::npos
			&& str.find("o") == string::npos && str.find("u") == string::npos)
		{
			str = "<" + str + "> " + "is not acceptable.";
			cout << str << "\n";
			continue;
		}
		int iCount1 = 0;
		int iCount2 = 0;
		bool bFlag = false;
		string strPrev = "";
		for (int i = 0; i < str.size(); ++i)
		{
			if (strPrev == string(1, str[i]))
			{
				if (strPrev != "e" && strPrev != "o")
				{
					str = "<" + str + "> " + "is not acceptable.";
					cout << str << "\n";
					bFlag = true;
					break;
				}
			}
			if (string(1, str[i]) == "a" || string(1, str[i]) == "e" || string(1, str[i]) == "i"
				|| string(1, str[i]) == "o" || string(1, str[i]) == "u")
			{
				iCount2 = 0;
				++iCount1;

				if (iCount1 >= 3)
				{
					str = "<" + str + "> " + "is not acceptable.";
					cout << str << "\n";
					bFlag = true;
					break;
				}
			}
			else
			{
				iCount1 = 0;
				++iCount2;
				if (iCount2 >= 3)
				{
					str = "<" + str + "> " + "is not acceptable.";
					cout << str << "\n";
					bFlag = true;
					break;
				}
			}

			strPrev = str[i];

		}
		if (bFlag == false)
		{
			str = "<" + str + "> " + "is acceptable.";
			cout << str << "\n";
		}
	}
	
	return 0;
}
