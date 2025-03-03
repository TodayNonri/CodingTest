#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <cstring>

using namespace std;

int N, M;
vector<int> vTruth;
vector<vector<int>> vParty;
bool isKnown[51]; 

void bfs() 
{
    queue<int> q;

    for (int truth : vTruth) 
    {
        q.push(truth);
        isKnown[truth] = true;
    }

    while (!q.empty())
    {
        int current = q.front();
        q.pop();

        for (int partyIndex = 0; partyIndex < M; ++partyIndex) 
        {
            bool found = false;
            for (int person : vParty[partyIndex]) 
            {
                if (person == current) 
                {
                    found = true;
                    break;
                }
            }

            if (found)
            {
                for (int person : vParty[partyIndex]) 
                {
                    if (!isKnown[person]) 
                    {
                        isKnown[person] = true;
                        q.push(person);
                    }
                }
            }
        }
    }
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;
    int iInput;

    cin >> iInput;
    for (int i = 0; i < iInput; ++i)
    {
        int iInput2;
        cin >> iInput2;
        vTruth.push_back(iInput2);
    }

    for (int i = 0; i < M; ++i) 
    {
        cin >> iInput;
        vector<int> party;
        for (int j = 0; j < iInput; ++j) 
        {
            int iInput2;
            cin >> iInput2;
            party.push_back(iInput2);
        }
        vParty.push_back(party);
    }

    bfs();

    int iCount = 0;
    for (int i = 0; i < M; ++i)
    {
        bool canLie = true;
        for (int person : vParty[i]) 
        {
            if (isKnown[person]) 
            {
                canLie = false;
                break;
            }
        }
        if (canLie) 
        {
            iCount++;
        }
    }

    cout << iCount;
    return 0;
}

