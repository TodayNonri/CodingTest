#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int N;
int arr[39] = { 0, 5, 13 };
string s = "Messi Gimossi";

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);    cout.tie(NULL);
    cin >> N;
    N--;
    for (int i = 3; i <= 39; ++i)
        arr[i] = arr[i - 1] + arr[i - 2] + 1;

    for (int i = 39; i >= 2; --i)
        if (N >= arr[i])
            N -= (arr[i] + 1);

    if (N == 5 || N == -1)
        cout << "Messi Messi Gimossi";
    else
        cout << s[N];


    return 0;
}