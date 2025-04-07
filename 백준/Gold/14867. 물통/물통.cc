#include <iostream>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;

int A, B, C, D;
map<pair<int, int>, int> m;
queue<pair<int, int>> q;

void enqueue(int a, int b, int d)
{
    if (m[{a, b}])
        return;
    m[{a, b}] = d + 1;
    q.push({ a, b });
}

int bfs(int a, int b)
{
    m[{a, b}] = 1;
    q.push({a, b});

    while (!q.empty())
    {
        a = q.front().first;
        b = q.front().second;
        q.pop();

        enqueue(A, b, m[{a, b}]);
        enqueue(a, B, m[{a, b}]);
        enqueue(0, b, m[{a, b}]);
        enqueue(a, 0, m[{a, b}]);
        enqueue(min(a + b, A), max(0, a+b - A), m[{a, b}]);
        enqueue(max(0, a+b - B), min(a+b, B), m[{a, b}]);
    }

    if (m[{C, D}])
        return m[{C, D}] - 1;
    else 
        return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> A >> B >> C >> D;

    cout << bfs(0, 0);


    return 0;
}
