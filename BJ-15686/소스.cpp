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
int min_distance = INT_MAX; // answer

int Distance(P a, P b) {
	return abs(a.first - b.first) + abs(a.second - b.second);
}

void trace(int n, int m) {
	if (m == M) {
		int result = 0;
		for (int i = 0; i < house.size(); i++) {
			int temp_distance = 0;
			for (int j = 0; j < picked.size(); j++) {
				temp_distance = min(temp_distance, Distance(house[i], picked[j]));
			}
			result += temp_distance;
		}
		min_distance = min(min_distance, result);
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
	trace(0, 0);
	cout << min_distance << endl;
	return 0;
}