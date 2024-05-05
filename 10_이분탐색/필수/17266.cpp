#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(NULL);

    int n, m;
    int i, ans = 0;

    cin >> n;
    vector <int> road(n, 0);

    cin >> m;
    vector <int> light(m);

    for (i = 0; i < m; i++) {
        cin >> light[i];

        if (m == 1) {
            ans = (n - light[0] > light[0]) ? n - light[0] : light[0];
        }
        else if (i > 0 && (light[i] - (light[i] + light[i - 1]) / 2) > ans)
            ans = light[i] - (light[i] + light[i - 1]) / 2;
        else if (i == 0)
            ans = light[0];

    }
    if (n - light[m - 1] > ans)
        ans = n - light[m - 1];

    cout << ans;

}