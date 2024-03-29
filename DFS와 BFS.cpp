//1260번
#include<iostream>
#include<queue>
using namespace std;

int arr[1001][1001];
bool arr2[1001][1001];
bool arr3[1001][1001];

void DFS(int n) {
	cout << n << ' ';
	for (int i = 1; i < 1001; i++) {
		arr2[i][n] = true;
	}
	for (int i = 1; i < 1001; i++) {
		if (arr[n][i] == 1 && !arr2[n][i]) {
			arr2[n][i] = true;
			DFS(i);
		}
	}
}

void BFS(int n) {
	queue<int> q;
	q.push(n);
	while (!q.empty()) {
		int temp = q.front();
		q.pop();
		cout << temp << ' ';
		for (int i = 1; i < 1001; i++) {
			arr3[i][temp] = true;
		}
		for (int i = 1; i < 1001; i++) {
			if (arr[temp][i] && !arr3[temp][i]) {
				arr3[temp][i] = true;
				for (int j = 1; j < 1001; j++) {
					arr3[j][i] = true;
				}
				q.push(i);
			}
		}
	}
}

int main() {
	int N, M, V;
	cin >> N >> M >> V;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		arr[a][b] = 1;
		arr[b][a] = 1;
	}

	DFS(V);
	cout << endl;
	BFS(V);
	cout << endl;



	return 0;
}
