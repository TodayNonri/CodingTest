#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N, iResult = 0;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string strInput, strBomb;
    cin >> strInput >> strBomb;
    string strResult = "";

    for (auto ch : strInput)
    {
        strResult += ch;
        if (strResult.size() >= strBomb.size() && strResult.substr(strResult.size() - strBomb.size()) == strBomb)
            strResult.erase(strResult.size() - strBomb.size());
    }
    if (strResult.empty())
        cout << "FRULA";
    else
        cout << strResult;

    return 0;
}