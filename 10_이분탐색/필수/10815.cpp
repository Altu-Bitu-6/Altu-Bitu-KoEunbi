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
    }

    sort(cards.begin(), cards.end());

    cin >> m;
    while (m--) {
        cin >> key;
        if (binary_search(cards.begin(), cards.end(), key))
            cout << "1 ";
        else
            cout << "0 ";
    }

}