#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(NULL);

    int cou, s, flag = 0, ans = 0;
    cin >> cou >> s;

    vector <int> snaks(s);
    for (int i = 0; i < s; i++) {
        cin >> snaks[i];
    }

    sort(snaks.begin(), snaks.end());

    if (s < cou) {
        while (snaks.size() < cou) {
            s = snaks.size();
            snaks[s - 1] /= 2;
            snaks.resize(s + 1, snaks[s - 1]);
            sort(snaks.begin(), snaks.end());
        }
    }

    cout << snaks[snaks.size() - cou];

}