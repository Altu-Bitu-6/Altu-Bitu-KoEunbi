#include <iostream>
#include <string>
#include <deque>

using namespace std;

void clearGround(deque <int>& dosu, deque<int>& g1, deque<int>& g2) {
    int n;

    while (!g2.empty()) {
        n = g2.back();
        g2.pop_back();
        dosu.push_back(n);
    }

    while (!g1.empty()) {
        n = g1.back();
        g1.pop_back();
        dosu.push_back(n);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m;
    int d, s;
    string winner;
    deque <int> dodo;
    deque <int> susu;
    deque <int> do_g;
    deque <int> su_g;

    cin >> n >> m;

    while (n--) {
        cin >> d >> s;
        dodo.push_front(d);
        susu.push_front(s);
    }

    int round = 0;
    while (round < m) {

        if (round % 2 == 0) {
            d = dodo.front();
            dodo.pop_front();
            do_g.push_front(d);
        }
        else {
            s = susu.front();
            susu.pop_front();
            su_g.push_front(s);
        }

        round++;
        if (susu.empty()) {
            winner = "do";
            break;
        }
        else if (dodo.empty()) {
            winner = "su";
            break;
        }

        if (!do_g.empty() && !su_g.empty() && do_g.front() + su_g.front() == 5) {
            clearGround(susu, su_g, do_g);
            continue;
        }

        if (!do_g.empty() && do_g.front() == 5) {
            clearGround(dodo, do_g, su_g);
            continue;
        }
        else if (!su_g.empty() && su_g.front() == 5) {
            clearGround(dodo, do_g, su_g);
            continue;
        }

    }

    if (dodo.size() > susu.size())
        winner = "do";
    else if (susu.size() > dodo.size())
        winner = "su";
    else
        winner = "dosu";

    cout << winner;

    return 0;
}
