#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;
vector<int> v;

int main() 
{
    cin >> N;
    v.resize(N);
    vector<int> vNum(N, 1);

    for (int i = 0; i < N; ++i)
    {
        cin >> v[i];
    }

    int iResult = 1;

    for (int i = 1; i < N; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            if (v[i] > v[j])
                vNum[i] = max(vNum[i], vNum[j] + 1);
        }
        iResult = max(iResult, vNum[i]);
    }

    cout << iResult;

    return 0;
}