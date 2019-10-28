//2206번
#include<iostream>
#include<queue>

using namespace std;
int N, M;
char str[1000][1001];
bool arr[2][1000][1000];

struct Node {
	bool count = false;
	int num = 1;
	int i = 0;
	int j = 0;
};

void BFS() {
	Node temp;
	queue<Node> q;
	temp.i = 0;
	temp.j = 0;
	arr[0][0][0] = 1;
	arr[1][0][0] = 1;
	q.push(temp);
	while (!q.empty()) {
		Node temp2 = q.front();
		q.pop();
		if (temp2.i == N - 1 && temp2.j == M - 1) {
			cout << temp2.num << endl;
			return;
		}
		if (temp2.count) {
			if (temp2.j + 1 < M && str[temp2.i][temp2.j + 1] == '0' && !arr[1][temp2.i][temp2.j+1]) {
				Node temp3;
				temp3.i = temp2.i;
				temp3.j = temp2.j + 1;
				temp3.count = true;
				temp3.num = temp2.num + 1;
				arr[1][temp2.i][temp2.j + 1] = 1;
				q.push(temp3);
			}
			if (temp2.j - 1 >= 0 && str[temp2.i][temp2.j - 1] == '0' && !arr[1][temp2.i][temp2.j - 1]) {
				Node temp3;
				temp3.i = temp2.i;
				temp3.j = temp2.j - 1;
				temp3.count = true;
				temp3.num = temp2.num + 1;
				arr[1][temp2.i][temp2.j - 1] = 1;
				q.push(temp3);
			}
			if (temp2.i + 1 < N && str[temp2.i + 1][temp2.j] == '0' && !arr[1][temp2.i + 1][temp2.j]) {
				Node temp3;
				temp3.i = temp2.i + 1;
				temp3.j = temp2.j;
				temp3.count = true;
				temp3.num = temp2.num + 1;
				arr[1][temp2.i + 1][temp2.j] = 1;
				q.push(temp3);
			}
			if (temp2.i - 1 >= 0 && str[temp2.i - 1][temp2.j] == '0' && !arr[1][temp2.i - 1][temp2.j]) {
				Node temp3;
				temp3.i = temp2.i - 1;
				temp3.j = temp2.j;
				temp3.count = true;
				temp3.num = temp2.num + 1;
				arr[1][temp2.i - 1][temp2.j] = 1;
				q.push(temp3);
			}
		}
		else {
			if (temp2.j + 1 < M && !arr[0][temp2.i][temp2.j + 1]) {
				if (str[temp2.i][temp2.j + 1] == '1') {
					Node temp3;
					temp3.i = temp2.i;
					temp3.j = temp2.j + 1;
					temp3.count = true;
					temp3.num = temp2.num + 1;
					arr[1][temp2.i][temp2.j + 1] = 1;
					q.push(temp3);
				}
				else {
					Node temp3;
					temp3.i = temp2.i;
					temp3.j = temp2.j + 1;
					temp3.num = temp2.num + 1;
					arr[0][temp2.i][temp2.j + 1] = 1;
					q.push(temp3);
				}
			}
			if (temp2.j - 1 >= 0 && !arr[0][temp2.i][temp2.j - 1]) {
				if (str[temp2.i][temp2.j - 1] == '1') {
					Node temp3;
					temp3.i = temp2.i;
					temp3.j = temp2.j - 1;
					temp3.count = true;
					temp3.num = temp2.num + 1;
					arr[1][temp2.i][temp2.j - 1] = 1;
					q.push(temp3);
				}
				else {
					Node temp3;
					temp3.i = temp2.i;
					temp3.j = temp2.j - 1;
					temp3.num = temp2.num + 1;
					arr[0][temp2.i][temp2.j - 1] = 1;
					q.push(temp3);
				}
			}
			if (temp2.i + 1 < N && !arr[0][temp2.i + 1][temp2.j]) {
				if (str[temp2.i + 1][temp2.j] == '1') {
					Node temp3;
					temp3.i = temp2.i + 1;
					temp3.j = temp2.j;
					temp3.count = true;
					temp3.num = temp2.num + 1;
					arr[1][temp2.i + 1][temp2.j] = 1;
					q.push(temp3);
				}
				else {
					Node temp3;
					temp3.i = temp2.i + 1;
					temp3.j = temp2.j;
					temp3.num = temp2.num + 1;
					arr[0][temp2.i + 1][temp2.j] = 1;
					q.push(temp3);
				}
			}
			if (temp2.i - 1 >= 0 && !arr[0][temp2.i - 1][temp2.j]) {
				if (str[temp2.i - 1][temp2.j] == '1') {
					Node temp3;
					temp3.i = temp2.i - 1;
					temp3.j = temp2.j;
					temp3.count = true;
					temp3.num = temp2.num + 1;
					arr[1][temp2.i - 1][temp2.j] = 1;
					q.push(temp3);
				}
				else {
					Node temp3;
					temp3.i = temp2.i - 1;
					temp3.j = temp2.j;
					temp3.num = temp2.num + 1;
					arr[0][temp2.i - 1][temp2.j] = 1;
					q.push(temp3);
				}
			}
		}
	}

	cout << -1 << endl;
	return;
}

int main() {
	cin >> N >> M;


	for (int i = 0; i < N; i++) {
		cin >> str[i];
	}

	BFS();

	return 0;
}
