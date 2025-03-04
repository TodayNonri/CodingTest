#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string strInput, strInput2;
    cin >> strInput >> strInput2;
    string strResult = "";
    bool isOlim = false;
    while (strInput.size() && strInput2.size())
    {
        int iCal = (strInput.back() - '0') + (strInput2.back() - '0');

        if (isOlim)
            iCal += 1;
        if (iCal >= 10)
        {
            isOlim = true;
            iCal -= 10;
        }
        else
            isOlim = false;
        strResult += char(iCal + '0');
        strInput.pop_back();
        strInput2.pop_back();
    }

    if (strInput.size())
    {
        while (strInput.size())
        {
            int iCal = (strInput.back() - '0');
            if (isOlim)
                iCal += 1;
            if (iCal >= 10)
            {
                isOlim = true;
                iCal -= 10;
            }
            else
                isOlim = false;
            strResult += char(iCal + '0');
            strInput.pop_back();
        }
    }
    else if(strInput2.size())
    {
        while (strInput2.size())
        {
            int iCal = (strInput2.back() - '0');
            if (isOlim)
                iCal += 1;
            if (iCal >= 10)
            {
                isOlim = true;
                iCal -= 10;
            }
            else
                isOlim = false;
            strResult += char(iCal + '0');
            strInput2.pop_back();
        }
    }
    if(isOlim)
        strResult += char('1');

    reverse(strResult.begin(), strResult.end());

    cout << strResult;

    return 0;
}