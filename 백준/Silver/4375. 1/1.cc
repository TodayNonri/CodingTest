#include <iostream>
using namespace std;

int main() {
    int n;
    while (cin >> n) {  // EOF까지 입력 받음
        int num = 1;  // 1로만 이루어진 수 시작
        int length = 1; // 자리수

        while (num % n != 0) {  // n의 배수가 될 때까지 반복
            num = (num * 10 + 1) % n;  // 모듈러 연산 사용
            length++;
        }

        cout << length << endl;  // 자리수 출력
    }
    return 0;
}