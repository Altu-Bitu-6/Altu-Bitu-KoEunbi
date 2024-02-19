#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(){
    int N, M, i, result=0;
    map<string, int> set_S;
    string key;

    cin >> N;
    cin >> M;

    string input[M];
    
    for(i=0; i<N; i++){
        cin >> key;
        set_S[key] = i;
    }
    for(i=0; i<M; i++){
        cin >> key;
        if(set_S.find(key) != set_S.end())
            result++;
    }

    cout << result;

}