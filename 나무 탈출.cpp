//15900번
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int N;
int a, b;
vector<int> v[500001];
bool arr[500001];
int Count = 0;

struct Node {
	int a = 0;
	int c = 0;
};

void BFS() {
	queue<Node> q;
	Node tmp;
	tmp.a = 1;
	tmp.c = 0;
	q.push(tmp);
	while (!q.empty()) {
		Node temp = q.front();
		arr[temp.a] = true;
		q.pop();
		int cc = 0;
		while (!v[temp.a].empty()) {
			vector<int>::iterator it = v[temp.a].begin();
			if (!arr[*it]) {
				Node temp2;
				temp2.a = *it;
				temp2.c = temp.c + 1;
				q.push(temp2);
				cc++;
			}
			v[temp.a].erase(it);
		}
		if (cc == 0) {
			Count += temp.c;
		}
	}
	if (Count % 2 == 1) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
	return;
}

int main() {
	cin >> N;
	for (int i = 1; i <= N - 1; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	BFS();


	return 0;
}
