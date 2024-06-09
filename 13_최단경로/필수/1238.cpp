#include <iostream> //iostream include
#include <vector> // vector 사용을 위해 
#include <queue> // queue 사용을 위해

using namespace std;//namespace 사용
typedef pair<int, int> ci;// 정점과 가중치를 담는 pair 정의
const int INF = 2e5; //최대 V-1개의 간선을 지나게 됨 -> V * (가중치 최대값)

vector<int> dijkstra(int start, int v, vector<vector<ci>>& graph) { //다익스트라 알고리즘 함수
	vector<int> dist(v + 1, INF); // 각 정점까지의 최단 경로 저장
	priority_queue<ci> pq; // first: 시작점으로부터의 거리, second: 정점
	
	dist[start] = 0;// 시작 정점 초기화
	pq.push({ 0, start }); //큐에 시작정점 추가
	while (!pq.empty()) { //큐가 빌때까지 반복
		int w = -pq.top().first; // 현재 정점까지의 경로값 (최소합을 위해 음수 반환)
		int n = pq.top().second; // 현재 탐색하려는 정점
		pq.pop(); //해당 정점 제거
		if (w > dist[n]) { // 이미 더 작은 값으로 기록된 정점
			continue; //무시하기
		}
		for (auto [nxt_node, nxt_weight] : graph[n]) { //현재 정점과 인접한 정점들에 대해
			if (dist[nxt_node] > dist[n] + nxt_weight) { //더 짧은 경로를 찾은 경우
				dist[nxt_node] = dist[n] + nxt_weight; //최단 경로 갱신
				pq.push({ -dist[nxt_node],nxt_node }); //해당 정점을 큐에 추가
			}
		}
	}
	return dist; //최단 경로 반환
}

int main() {
	int v, e, k, a, b, w;//정점수, 간선 수 , 파티장소, 시작 정점, 도착 정점, 가중치
	int answer = 0;//결과 저장 변수
	//입력
	cin >> v >> e >> k; //입력 받기
	vector<vector<ci>> graph(v + 1, vector<ci>(0)); // 인접 리스트
	while (e--) { //간선 수 만큼 반복
		cin >> a >> b >> w; //입력 받기
		graph[a].push_back({ b, w }); // 방향 그래프
	}
	
	vector<int> go(v + 1), back;//연산

	// 정점 i 에서 파티 장소까지 걸리는 시간
	for (int i = 1; i <= v; i++) {
		vector<int> tmp = dijkstra(i, v, graph); //다익스트라  사용
		go[i] = tmp[k]; //최단 경로 저장
	}

	// 파티 장소에서 다른 정점들까지 걸리는 시간
	back = dijkstra(k, v, graph); //다익스트라 다시 사용

	//총 걸리는 시간 비교
	for (int i = 1; i <= v; i++) {
		answer = max(answer, go[i] + back[i]); //가장 오래 걸리는 시간을 갱신
	}
	// 출력
	cout << answer;
	return 0;
}