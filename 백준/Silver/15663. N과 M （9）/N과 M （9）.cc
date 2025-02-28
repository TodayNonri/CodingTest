#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> vNum, vResult;
vector<bool> vUsed;

void Func(int depth) 
{
    if (depth == M)
    {
        for (int num : vResult) 
            cout << num << " ";
        cout << "\n";
        return;
    }

    int prev = -1;  
    for (int i = 0; i < N; ++i)
    {
        if (vUsed[i] || vNum[i] == prev)
            continue;

        vUsed[i] = true;
        vResult.push_back(vNum[i]);
        prev = vNum[i];  
        Func(depth + 1);
        vResult.pop_back();
        vUsed[i] = false;
    }
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;
    vNum.resize(N);
    vUsed.resize(N, false);

    for (int i = 0; i < N; ++i)
        cin >> vNum[i];

    sort(vNum.begin(), vNum.end()); 

    Func(0);
    return 0;
}
