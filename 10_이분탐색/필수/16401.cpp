#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int binarySearch(int n, int m, vector <int>& v) { //이분탐색
    int l = 1, r = v[v.size() - 1]; //과자 길이의 최솟값(1)과 최댓값을 l과 r으로
    int mid, cnt, size;

    while (l <= r) {
        mid = (l + r) / 2; //추정 길이의 중앙값
        cnt = 0;

        for (int i = 0; i < n; i++) {
            cnt += v[i] / mid; 
        }//해당 길이로 나눠줄 수 있는 과자의 수 계산
        
        if (cnt >= m) { //과자의 수가 충분해지면 빠져나오기
            l = mid + 1;
            size = mid;
        }
        else if (cnt < m) { //과자의 수가 모자랄 때 = 과자의 길이가 너무 길다!
            r = mid - 1;
        }
    }

    return size; //계산된 최댓값 리턴
}
int main()
{
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(NULL);

    int cou, s;
    cin >> cou >> s;

    vector <int> snaks(s);
    for (int i = 0; i < s; i++) {
        cin >> snaks[i];
    } //입력받기

    sort(snaks.begin(), snaks.end());//길이 정렬

    cout << binarySearch(s, cou, snaks);

}
