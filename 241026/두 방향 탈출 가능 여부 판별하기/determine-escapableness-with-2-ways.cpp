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

int n, m; // x축 y축
int graph[100][100]; // Graph
bool visited[100][100]; // 방문여부
int dx[2] = { 0,1 };
int dy[2] = { 1,0 };

void input() {
	scanf("%d %d", &n, &m);
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
		visited[cx][cy] = true;

		for (int i = 0; i < 2; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (graph[nx][ny] == 0)continue;
			if (visited[nx][ny] == false) {
				s.push(make_pair(nx, ny));
			}
		}
	}
}
void solution() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			visited[i][j] = false;
		}
	}
	dfs(0, 0);
	if (visited[n - 1][m - 1] == true) printf("1");
	else printf("0");
}
int main() {
	input();
	solution();
	return 0;
}