#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> vTree[26];
vector<int> vLoop;
bool visited[26] = { false };

void FirstLoop(int iHere)
{
    if (iHere == -1)
        return;
    vLoop.push_back(iHere);
    FirstLoop(vTree[iHere][0]);
    FirstLoop(vTree[iHere][1]);
}

void MiddleLoop(int iHere) 
{
    if (iHere == -1)
        return;
    MiddleLoop(vTree[iHere][0]); 
    vLoop.push_back(iHere);
    MiddleLoop(vTree[iHere][1]); 
}

void LastLoop(int iHere)
{
    if (iHere == -1) 
        return;
    LastLoop(vTree[iHere][0]);
    LastLoop(vTree[iHere][1]);
    vLoop.push_back(iHere);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N;
    cin >> N;

    char iRoot, iChildren1, iChildren2;
    for (int i = 0; i < N; ++i) 
    {
        cin >> iRoot >> iChildren1 >> iChildren2;
        vTree[iRoot - 'A'].push_back((iChildren1 != '.') ? iChildren1 - 'A' : -1);
        vTree[iRoot - 'A'].push_back((iChildren2 != '.') ? iChildren2 - 'A' : -1);
    }

    FirstLoop(0);
    for (auto v : vLoop) cout << char(v + 'A');
    cout << "\n";
    vLoop.clear();

    MiddleLoop(0);
    for (auto v : vLoop) cout << char(v + 'A');
    cout << "\n";
    vLoop.clear();

    LastLoop(0); 
    for (auto v : vLoop) cout << char(v + 'A');
    cout << "\n";

    return 0;
}
