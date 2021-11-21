#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 1000000;

int N;
long long M;
long long tree[MAX];


bool possible(long long height){

    long long len = 0;//잘린 길이
    for (int i = 0; i < N; i++)
        if (tree[i] - height > 0) len += tree[i] - height;


    if (len >= M)//자른 길이가 원하는 길이와 같거나 더 많다면
        return true;

    return false;//자른 길이의 합이 부족하면

}



int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    long long low = 1, high = 0;

    for (int i = 0; i < N; i++){
        cin >> tree[i];
        high = max(high, tree[i]);
    }

    long long result = 0;

    while (low <= high){
        long long mid = (low + high) / 2;//mid가 잘린 후 남을 나무의 길이
        if (possible(mid)) {
            result = max(result, mid);
            low = mid + 1;// 남는 길이를 더 많이 해서 잘라본다(자른 길이가 더 많을 수도 있으니까)
        }
        else {
            high = mid - 1; //남는 길이를 더 적게 해서 잘라본다.(더 많이 잘라본다)
        }
    }

    cout << result << "\n";
}



