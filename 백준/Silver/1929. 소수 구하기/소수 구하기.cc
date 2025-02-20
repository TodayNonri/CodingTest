#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;
int N, M;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> M >> N;
    vector<bool> is_prime(N + 1, true);
    is_prime[0] = is_prime[1] = false;

    for (int i = 2; i * i <= N; ++i) 
    {
        if (is_prime[i]) 
        {
            for (int j = i * i; j <= N; j += i) 
            {
                is_prime[j] = false; 
            }
        }
    }

    for (int i = M; i <= N; ++i)
    {
        if (is_prime[i]) 
        {
            cout << i << "\n";
        }
    }


	return 0;
}
