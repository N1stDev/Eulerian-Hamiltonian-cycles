#include<iostream>
#include<vector>

using namespace std;

vector<int> s;
vector<int> c;

bool check(vector<vector<int>> graph) {
	for (size_t i = 0; i < graph.size(); i++) {
		int count = 0;
		for (size_t j = 0; j < graph[i].size(); j++) {
			if (graph[i][j] == 1) {
				count++;
			}
		}
		if (count % 2 == 1) {
			return 0;
		}
	}
	return 1;
}

void solution(vector<vector<int>> matr) {
	for (size_t i = 0; i < matr.size(); i++) {
		int key = 0;
		for (size_t j = 0; j < matr[i].size(); j++) {
			if (matr[i][j] == 1) {
				s.push_back(j);
				matr[i][j] = 0;
				matr[j][i] = 0;
				i = j-1;
				key = 1;
				break;
			}
		}
		if (key == 0) {
			c.push_back(s.back());
			s.pop_back();
			if (s.size() == 0) {
				return;
			}
			i = s.back() - 1;
		}
	}
}

int main() {

	vector<vector<int>> adj_matr = { 
		{0, 0, 0, 0, 0, 1, 1, 0, 0, 0},
		{0, 0, 0, 0, 1, 0, 0, 1, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 1, 1, 0},
		{0, 0, 0, 0, 0, 1, 0, 1, 1, 1},
		{0, 1, 0, 0, 0, 1, 1, 0, 1, 0},
		{1, 0, 0, 1, 1, 0, 1, 0, 0, 0},
		{1, 0, 0, 0, 1, 1, 0, 1, 0, 0},
		{0, 1, 1, 1, 0, 0, 1, 0, 0, 0},
		{0, 0, 1, 1, 1, 0, 0, 0, 0, 1},
		{0, 0, 0, 1, 0, 0, 0, 0, 1, 0},
	};

	if (!check(adj_matr)) {
		cout << "Graph doesn't have eulerian cycle" << endl;
		return 0;
	}
	s.push_back(0);
	solution(adj_matr);

	for (size_t i= 0; i < c.size(); i++) {
		cout << c[i] << " ";
	}

	return 0;
}