#include <iostream>
#include <queue>
#include <vector>
#include <cstring>  // memset 사용

using namespace std;

int N, K;
int visited[500001][2];  // 방문 여부 체크 (짝수/홀수 구분)

int bfs() {
    queue<pair<int, int>> q; // (현재 위치, 현재 시간)
    q.push({ N, 0 });
    visited[N][0] = 1;

    while (!q.empty()) {
        int now = q.front().first;
        int time = q.front().second;
        q.pop();

        int brother = K + time * (time + 1) / 2;  // 동생 위치 계산
        if (brother > 500000) return -1;  // 범위 초과 시 -1 반환

        // 동생이 현재 시간에 방문한 곳을 수빈이가 같은 초에서 방문한 적 있으면 종료
        if (visited[brother][time % 2]) return time;

        for (int next : {now + 1, now - 1, now * 2}) {
            if (next >= 0 && next <= 500000 && !visited[next][(time + 1) % 2]) {
                visited[next][(time + 1) % 2] = 1;
                q.push({ next, time + 1 });
            }
        }
    }

    return -1;  // 동생을 못 찾은 경우
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> K;
    memset(visited, 0, sizeof(visited)); // 방문 배열 초기화

    if (N == K) {
        cout << "0\n";
        return 0;
    }

    cout << bfs() << "\n";
    return 0;
}
