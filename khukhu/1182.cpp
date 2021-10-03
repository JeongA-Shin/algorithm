#include <iostream>
using namespace std;

const int MAX = 20;
int N, S;
int arr[MAX];
int result = 0;

void numOfSubset(int idx, int sum){
    sum += arr[idx]; //우선 해당 숫자를 더한다
    //종료조건(더 이상 더할 게 없음)
    if (idx >= N) return;
    //조건 성립시
    if (sum == S) result++;


    //그리고 두 가지 경우로 나뉨
    //해당 숫자를 안 더했을 경우
    numOfSubset(idx + 1, sum - arr[idx]);
    //해당 숫자를 더헀을 경우
    numOfSubset(idx + 1, sum);
}



int main(void){
    cin >> N >> S;//정수의 개수,  정수S

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    numOfSubset(0, 0);
    cout << result << endl;
}
