//2178번
#include<iostream>
#include<queue>

using namespace std;

int arr[100][100];
bool arr2[100][100];
int N, M;

struct Node {
	int i=0;
	int j=0;
	int count = 1;
};

void BFS() {
	queue<Node> q;
	Node n;
	q.push(n);
	arr2[0][0] = true;
	while (!q.empty()) {
		Node temp = q.front();
		q.pop();
		if (temp.i == N - 1 && temp.j == M - 1) {
			cout << temp.count << endl;
			return;
		}
		if (temp.i+1 < N && arr[temp.i + 1][temp.j] && !arr2[temp.i + 1][temp.j]) {
			Node temp2;
			temp2.i = temp.i + 1;
			temp2.j = temp.j;
			temp2.count = temp.count + 1;
			q.push(temp2);
			arr2[temp.i + 1][temp.j] = true;
		}
		if (temp.j + 1 < M && arr[temp.i][temp.j + 1] && !arr2[temp.i][temp.j + 1]) {
			Node temp2;
			temp2.i = temp.i;
			temp2.j = temp.j + 1;
			temp2.count = temp.count + 1;
			q.push(temp2);
			arr2[temp.i][temp.j + 1] = true;
		}
		if (temp.i - 1 >= 0 && arr[temp.i - 1][temp.j] && !arr2[temp.i - 1][temp.j]) {
			Node temp2;
			temp2.i = temp.i - 1;
			temp2.j = temp.j;
			temp2.count = temp.count + 1;
			q.push(temp2);
			arr2[temp.i - 1][temp.j] = true;
		}
		if (temp.j - 1 >= 0 && arr[temp.i][temp.j - 1] && !arr2[temp.i][temp.j - 1]) {
			Node temp2;
			temp2.i = temp.i;
			temp2.j = temp.j - 1;
			temp2.count = temp.count + 1;
			q.push(temp2);
			arr2[temp.i][temp.j - 1] = true;
		}
	}
}

int main() {
	char str[101];
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> str;
		for (int j = 0; j < M; j++) {
			arr[i][j] = str[j] - '0';
		}
	}
	BFS();

	return 0;
}
