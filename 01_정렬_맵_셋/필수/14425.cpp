#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(){
    int n, m, i, result=0;
    map<string, int> set_S;
    string key;

    cin >> n;
    cin >> m;

    string input[m];
    
    for(i=0; i<n; i++){
        cin >> key;
        set_S[key] = i;
    }
    for(i=0; i<m; i++){
        cin >> key;
        if(set_S.find(key) != set_S.end())
            result++;
    }

    cout << result;
    return 0;
}