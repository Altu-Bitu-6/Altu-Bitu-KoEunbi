#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(NULL);

    int n, m, key;

    cin >> n;
    vector <int> cards(n);

    for (int i = 0; i < n; i++) {
        cin >> cards[i];
    } //카드 입력 받기

    sort(cards.begin(), cards.end()); //정렬

    cin >> m;
    while (m--) {
        cin >> key;
        if (binary_search(cards.begin(), cards.end(), key)) //값이 카드 안에 있으면
            cout << "1 "; //1 출력
        else
            cout << "0 ";
    }

}
