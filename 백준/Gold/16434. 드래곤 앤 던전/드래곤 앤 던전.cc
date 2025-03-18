#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Room 
{
    int iType, iAttack, iHP;
};

int N;
long long initialAttack;
vector<Room> vRooms;

bool canClear(long long maxHP) 
{
    long long curHP = maxHP;
    long long baseAttack = initialAttack;

    for (const auto& room : vRooms) 
    {
        if (room.iType == 1) 
        { 
            long long monsterAttack = room.iAttack;
            long long monsterHP = room.iHP;

            long long hitsToKill = (monsterHP + baseAttack - 1) / baseAttack;
            long long hitsToDie = (curHP + monsterAttack - 1) / monsterAttack;

            if (hitsToKill > hitsToDie) 
                return false; 

            curHP -= (hitsToKill - 1) * monsterAttack;
        }
        else 
        { 
            baseAttack += room.iAttack;
            curHP = min(maxHP, curHP + room.iHP);
        }
    }
    return true;
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> initialAttack;
    vRooms.resize(N);

    for (int i = 0; i < N; ++i)
    {
        cin >> vRooms[i].iType >> vRooms[i].iAttack >> vRooms[i].iHP;
    }

    long long left = 1, right = 1e18, result = 1e18;

    while (left <= right)
    {
        long long mid = (left + right) / 2;
        if (canClear(mid)) 
        {
            result = mid;
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }

    cout << result << "\n";
    return 0;
}
