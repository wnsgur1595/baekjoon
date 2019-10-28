//1707번
#include<iostream>
#include<queue>
#include<vector>
using namespace std;

vector<int> arr[5][20001];
int arr2[5][20001];

struct Node {
	int a = 0;
	int b = 0;
};

void BFS(int pos) {
	queue<Node> q;
	vector<int>::iterator it;
	for (int i = 1; i < 20001; i++) {
		it = arr[pos][i].begin();
		while(!arr[pos][i].empty()){
				Node temp;
				temp.a = i;
				temp.b = *it;
				q.push(temp);
				arr2[pos][i] = 1;
				arr2[pos][*it] = 2;
				arr[pos][i].erase(it);
				it = arr[pos][i].begin();
		}
		while (!q.empty()) {
			Node temp = q.front();
			q.pop();
			it = arr[pos][temp.b].begin();
			while(!arr[pos][temp.b].empty()) {
				if (!arr2[pos][*it]) {
					if (arr2[pos][temp.b] == 1) arr2[pos][*it] = 2;
					else if (arr2[pos][temp.b] == 2) arr2[pos][*it] = 1;
					Node temp2;
					temp2.a = temp.b;
					temp2.b = *it;
					q.push(temp2);
				}
				else {
					if (arr2[pos][temp.b] == arr2[pos][*it]) {
						cout << "NO" << endl;
						return;
					}
				}
				arr[pos][temp.b].erase(it);
				it = arr[pos][temp.b].begin();
			}
		}
	}
	cout << "YES" << endl;
	return;
}

int main() {
	int K, V, E;
	int a, b;
	cin >> K;
	for (int i = 0; i < K; i++) {
		cin >> V >> E;
		for (int j = 0; j < E; j++) {
			cin >> a >> b;
			arr[i][a].push_back(b);
			arr[i][b].push_back(a);
		}

		BFS(i);
	}
	return 0;
}
