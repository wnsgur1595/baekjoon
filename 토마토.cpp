//7576번
#include<iostream>
#include<queue>

using namespace std;

int N, M;
int Count = 0;

int arr[1000][1000];
//bool arr2[1000][1000];

struct Node {
	int i = 0;
	int j = 0;
	int d = 0;
};

queue<Node> q;

void BFS() {
	while (!q.empty()) {
		Node temp = q.front();
		q.pop();
		if (temp.i + 1 < N && arr[temp.i + 1][temp.j] == 0) {
			Node temp2;
			arr[temp.i + 1][temp.j] = 1;
			temp2.i = temp.i + 1;
			temp2.j = temp.j;
			temp2.d = temp.d + 1;
			q.push(temp2);
			Count--;
			if (Count == 0) {
				cout << temp2.d << endl;
				return;
			}
		}
		if (temp.i - 1 >= 0 && arr[temp.i - 1][temp.j] == 0) {
			Node temp2;
			arr[temp.i - 1][temp.j] = 1;
			temp2.i = temp.i - 1;
			temp2.j = temp.j;
			temp2.d = temp.d + 1;
			q.push(temp2);
			Count--;
			if (Count == 0) {
				cout << temp2.d << endl;
				return;
			}
		}
		if (temp.j + 1 < M && arr[temp.i][temp.j + 1] == 0) {
			Node temp2;
			arr[temp.i][temp.j + 1] = 1;
			temp2.i = temp.i;
			temp2.j = temp.j + 1;
			temp2.d = temp.d + 1;
			q.push(temp2);
			Count--;
			if (Count == 0) {
				cout << temp2.d << endl;
				return;
			}
		}
		if (temp.j - 1 >= 0 && arr[temp.i][temp.j - 1] == 0) {
			Node temp2;
			arr[temp.i][temp.j - 1] = 1;
			temp2.i = temp.i;
			temp2.j = temp.j - 1;
			temp2.d = temp.d + 1;
			q.push(temp2);
			Count--;
			if (Count == 0) {
				cout << temp2.d << endl;
				return;
			}
		}
	}

	if (q.empty()) {
		cout << -1 << endl;
	}

}

int main() {
	cin >> M >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 0) Count++;
			if (arr[i][j] == 1) {
				Node temp;
				temp.i = i;
				temp.j = j;
				q.push(temp);
			}
		}
	}

	if (Count == 0) {
		cout << Count << endl;
		return 0;
	}

	BFS();

	return 0;
}
