#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>

#include <algorithm>
#include <stdlib.h>
#include <cstring>
#include <cmath>

#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
using namespace std;

int n; // x축 y축
int graph[1001][1001]; // Graph
bool visited[1001][1001]; // 방문여부
bool discovered[1001][1001]; // 방문여부
int dx[4] = { -1, 0,0,1 };
int dy[4] = { 0,1,-1,0 };

int c = 0;

void input() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &graph[i][j]);
		}
	}
}
// 반복문
void dfs(int sx, int sy) {
	// stack
	stack<pair<int, int>> s = stack<pair<int, int>>();
	s.push(make_pair(sx, sy));
	while (s.empty() == false) {
		int cx = s.top().first;
		int cy = s.top().second;
		s.pop();
		// 방문 처리
		c++;
		visited[cx][cy] = true;

		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
			if (graph[nx][ny] == 0)continue;
			if (visited[nx][ny] == false && discovered[nx][ny] == false) {
				s.push(make_pair(nx, ny));
				discovered[nx][ny] = true;
			}
		}
	}
}
int static compare(const void* first, const void* second)
{
	if (*(int*)first > *(int*)second)
		return 1;
	else if (*(int*)first < *(int*)second)
		return -1;
	else
		return 0;
}
void solution() {
	// 방문 기록 초기화
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			visited[i][j] = false;
			discovered[i][j] = false;
		}
	}
	int villageNum = 0;
	vector<int> peopleNum = vector<int>();
	// 모든 정점 방문
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visited[i][j] == false && graph[i][j] == 1) {
				c = 0;
				dfs(i, j);
				villageNum++;
				peopleNum.push_back(c);
			}
		}
	}
	sort(peopleNum.begin(), peopleNum.end());
	printf("%d\n", villageNum);
	for (int i = 0; i < peopleNum.size(); i++) {
		printf("%d\n",peopleNum[i]);
	}
}
int main() {
	input();
	solution();
	return 0;
}