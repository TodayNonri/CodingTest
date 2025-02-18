#include <iostream>
using namespace std;

int main()
{
    int n;
    while (cin >> n) 
    {  
        int num = 1; 
        int length = 1; 

        while (num % n != 0)
        {  
            num = (num * 10 + 1) % n; 
            length++;
        }

        cout << length << endl;
    }
    return 0;
}