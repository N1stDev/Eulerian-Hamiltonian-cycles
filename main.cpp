#include<iostream>
#include<vector>

using namespace std;

vector<int> path;
vector<bool> visited;
int success = 0;

void solution(vector<vector<int>> matr, int cur) {
	path.push_back(cur);
	visited[cur] = 1;
	if (path.size() == matr.size()) {
		if (matr[path[0]][path.back()] == 1) {
			path.push_back(path[0]);
			success = 1;
		}
		else {
			visited[cur] = 0;
			path.pop_back();
		}
		return;
	}
	for (size_t i = 0; i < matr[cur].size(); i++) {
		if (matr[cur][i] == 1 && visited[i] == 0) {
			solution(matr, i);
		}
	}
	if (success == 1) {
		return;
	}
	visited[cur] = 0;
	path.pop_back();
}

int main() {

	vector<vector<int>> adj_matr = {
		{0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0},
		{1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0},
		{0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 0},
		{1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0},
		{1, 0, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0},
		{0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
		{0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0},
		{0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1},
		{0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1},
		{0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1},
		{0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 1},
		{0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0}
	};

	for (size_t i = 0; i < adj_matr.size(); i++) {
		visited.push_back(0);
	}

	solution(adj_matr, 0);

	for (size_t i = 0; i < path.size(); i++) {
		cout << path[i]+1 << " ";
	}
	
	return 0;
}