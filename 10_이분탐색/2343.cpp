#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int binarySearch(int n, int m, vector <int>& v) {
    int l = 1, r = 0;
    int mid, cnt, temp, size = 0;

    for (int i = 0; i < v.size(); i++) {
        r += v[i];
    } //가능한 가장 큰 블루레이의 크기

    while (l <= r) {
        mid = (l + r) / 2; //블루레이 크기 추정치
        cnt = 0; //블루레이 개수
        temp = 0;

        for (int i = 0; i < n; i++) {
            if (v[i] > mid) { //강의 크기가 블루레이 크기보다 클 경우
                cnt = m + 1; //더 큰 범위로 넘어가게끔 
                break;
            }

            temp += v[i]; //강의 길이 누적합

            if (temp > mid) { //누적합이 블루레이 크기를 넘어가면
                cnt++; //개수 증가
                temp = v[i]; //해당 강의부터 다시 누적
            }
            if (i == n - 1) //마지막 강의의 경우
                cnt++; //개수 증가 
        }

        if (cnt > m) {//개수가 목표 개수보다 많다 -> 블루레이 용량 증가
            l = mid + 1;
        }
        else if (cnt <= m) {//너무 적거나 같다 -> 블루레이 용량 감소
            r = mid - 1;
            size = mid; 
        }

    }

    return size;
}

int main()
{
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(NULL);

    int n, m;
    cin >> n >> m;

    vector <int> lessons(n, 0); 
    for (int i = 0; i < n; i++) {
        cin >> lessons[i]; //레슨 배열 입력
    }

    cout << binarySearch(n, m, lessons);
}
