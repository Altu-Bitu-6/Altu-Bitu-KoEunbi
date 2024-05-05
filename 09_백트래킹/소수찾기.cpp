#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <math.h>

using namespace std;

bool isPrime(int n) {
    if (n < 2)
        return false;

    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return false;
    return true;
}

int solution(string s) {
    int answer = 0;
    vector<char> c;
    vector<int> num;

    for (int i = 0; i < s.size(); i++)
        c.push_back(s[i]);
    sort(c.begin(), c.end());

    do {
        string temp = "";
        for (int i = 0; i < c.size(); i++) {
            temp.push_back(c[i]);
            num.push_back(stoi(temp));
        }
    } while (next_permutation(c.begin(), c.end()));

    sort(num.begin(), num.end());
    num.erase(unique(num.begin(), num.end()), num.end());
    // 중복 지우기

    for (int i = 0; i < num.size(); i++)
        if (isPrime(num[i]))
            answer++;

    return answer;
}