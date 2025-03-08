#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int N, K;
bool visited[101] = { false };

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> K;

    vector<int> vNum(K);
    for (int i = 0; i < K; ++i)
        cin >> vNum[i];

    vector<int> vFlug;

    int iCount = 0;
    for (int i = 0; i < K; ++i)
    {
        if (!visited[vNum[i]])
        {
            if (vFlug.size() == N)
            {
                int iLastIdx = 0, iPos = 0;
                for (int j : vFlug)
                {
                    int iHere = INT_MAX;
                    for (int k = i + 1; k < K; ++k)
                    {
                        if (j == vNum[k])
                        {
                            iHere = k;
                            break;
                        }
                    }
                    if(iLastIdx < iHere)
                    {
                        iLastIdx = iHere;
                        iPos = j;
                    }
                }
                visited[iPos] = false;
                iCount++;
                vFlug.erase(find(vFlug.begin(), vFlug.end(), iPos));
            }
            vFlug.push_back(vNum[i]);
            visited[vNum[i]] = true;
        }

    }
    cout << iCount;
	return 0;
}
