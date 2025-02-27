#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int K;
vector<int> vTree[10];
vector<int> vNum;

void CutNum(int iCenter, int iDepth, vector<int>& v)
{
    if (v.size() == 0)
        return;

    vTree[iDepth].push_back(v[iCenter]);

    vector<int> vLeft;
    vector<int> vRight;
    for (int i = 0; i < iCenter; ++i)
        vLeft.push_back(v[i]);
    CutNum(vLeft.size() / 2, iDepth + 1, vLeft);

    for (size_t i = iCenter+1; i < v.size(); ++i)
        vRight.push_back(v[i]);
    CutNum(vRight.size() / 2, iDepth + 1, vRight);

    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> K;
    int N = pow(2, K)-1;
    vNum.resize(N);
    for (int i = 0; i < N; ++i)
        cin >> vNum[i];
    
    int iCenter = (N / 2);

    CutNum(iCenter, 0, vNum);

    for (int i = 0; i < K; ++i)
    {
        for (auto j : vTree[i])
            cout << j <<" ";
        cout<<"\n";
    }

    return 0;
}
