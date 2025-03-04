#include <iostream>
#include <vector>

using namespace std;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string strInput;

    cin >> strInput;

    while (!strInput.empty())
    {
        switch (strInput[0])
        {
        case 'p':
            if (strInput[1] == 'i')
                strInput = strInput.substr(2);
            else
            {
                cout << "NO";
                return 0;
            }
            
            break;
        case 'k':
            if (strInput[1] == 'a')
                strInput = strInput.substr(2);
            else
            {
                cout << "NO";
                return 0;
            }
            break;
        case 'c':
            if (strInput[1] == 'h' && strInput[2] == 'u')
                strInput = strInput.substr(3);
            else
            {
                cout << "NO";
                return 0;
            }
            break;
        default:
            cout << "NO";
            return 0;
        }
    }

    cout << "YES";

    return 0;
}