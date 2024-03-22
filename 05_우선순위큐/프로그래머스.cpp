#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;
struct cmp1 {
    bool operator()(vector<int> a, vector<int> b) {
        if (a[0] == b[0]) {
            return a[1] > b[1];
        }
        else {
            return a[0] > b[0];
        }
    }
};

struct cmp2 {
    bool operator()(vector<int> a, vector<int> b) {
        return a[1] > b[1];
    }
};

int solution(vector<vector<int>> jobs) {
    int n, cnt, t = 0, answer = 0;
    priority_queue<vector<int>, vector<vector<int>>, cmp1> time;
    priority_queue<vector<int>, vector<vector<int>>, cmp2> job;

    for (int i = 0; i < jobs.size(); i++) {
        time.push(jobs[i]);
    }

    n = time.size();
    cnt = n;


    while (cnt--) {
        if (job.size() == 0) {
            job.push(time.top());
            time.pop();
            t += job.top()[0] - t;
        }

        t += job.top()[1];
        answer += t - job.top()[0];

        job.pop();

        while (1) {
            if (time.size() > 0 && time.top()[0] < t) {
                job.push(time.top());
                time.pop();
            }
            else {
                break;
            }
        }

    }

    return answer / n;
