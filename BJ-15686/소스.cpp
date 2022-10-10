#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <climits>
#define P pair<int,int>

using namespace std;

int N, M;
vector<P> house;
vector<P> chiken;
vector<P> picked;
bool visit[14];
int min_distance = INT_MAX;

int Distance(P a, P b) {
	return abs(a.first - b.first) + abs(a.second - b.second);
}

void trace(int n, int m) {
	if (m == M) {

	}
	for (int i = n; i < chiken.size(); i++) {
		if (visit[i] == true) continue;
		visit[i] = true;
		picked.push_back(chiken[i]);
		trace(i, m + 1);
		picked.pop_back();
		visit[i] = false;
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int temp;
			cin >> temp;
			if (temp == 1) {
				house.push_back({ i,j });
			}
			else if (temp == 2) {
				chiken.push_back({ i,j });
			}
		}
	}
}