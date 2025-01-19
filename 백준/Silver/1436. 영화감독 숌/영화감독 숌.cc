#include <iostream>

using namespace std;

int main()
{
    int iInputCount{ 0 };
    cin >> iInputCount;

    int result = 666;
    if (iInputCount == 1)
    {
        cout << result << endl;
        return 0;
    }
    result = 1665;
    int iCopy = result;
    int iSixCount{0}, iCheckCount{1};
    while (iCheckCount != iInputCount)
    {
        ++result;
        iCopy = result;
        while (iCopy != 0)
        {
            if ((iCopy - 666)%1000 == 0)
            {
                ++iCheckCount;
                break;
            }

            iCopy /= 10;
        }
    }

    cout << result << endl;
}

