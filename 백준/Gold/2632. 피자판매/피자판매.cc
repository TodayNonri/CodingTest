#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int N, A, B;
vector<int> vPizzaA, vPizzaB;
unordered_map<int, int> countA, countB;

void GetPizzaPice(const vector<int>& pizza, unordered_map<int, int>& countMap)
{
    int iSize = pizza.size();

    for (int i = 0; i < iSize; ++i) 
    {
        int iSum = 0;
        for (int j = 0; j < iSize - 1; ++j) 
        { 
            iSum += pizza[(i + j) % iSize];  
            if (iSum > N)
                break;  
            countMap[iSum]++;
        }
    }

    int totalSum = 0;
    for (int x : pizza)
        totalSum += x;
    if (totalSum <= N) 
        countMap[totalSum]++;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> A >> B;

    vPizzaA.resize(A);
    vPizzaB.resize(B);

    for (int i = 0; i < A; ++i) 
        cin >> vPizzaA[i];
    for (int i = 0; i < B; ++i)
        cin >> vPizzaB[i];

    GetPizzaPice(vPizzaA, countA);
    GetPizzaPice(vPizzaB, countB);

    int iResult = 0;

    iResult += countA[N];

    iResult += countB[N];

    for (const auto& [sumA, cntA] : countA) 
        if (countB.count(N - sumA)) 
            iResult += cntA * countB[N - sumA];

    cout << iResult << "\n";
    return 0;
}
