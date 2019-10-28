//2573번
#include<iostream>
#include<queue>

using namespace std;

int year = 0;
int check = 0;

struct Node {
	int i = 0;
	int j = 0;
	int c = 0;
};

struct Node1 {
	int s = 0;
	int y = 0;
};

int N, M;
Node1 arr[300][300];
Node1 arr2[300][300];

queue<Node> q;

void DFS(Node temp) {
	if (arr2[temp.i][temp.j].y != year) {
		return;
	}
	
	if (!arr[temp.i][temp.j+1].s && arr2[temp.i][temp.j].s > 0) {
		arr2[temp.i][temp.j].s--;
	}
	if (!arr[temp.i][temp.j-1].s && arr2[temp.i][temp.j].s > 0) {
		arr2[temp.i][temp.j].s--;
	}
	if (!arr[temp.i+1][temp.j].s && arr2[temp.i][temp.j].s > 0) {
		arr2[temp.i][temp.j].s--;
	}
	if (!arr[temp.i-1][temp.j].s && arr2[temp.i][temp.j].s > 0) {
		arr2[temp.i][temp.j].s--;
	}

	arr2[temp.i][temp.j].y++;

	if (arr[temp.i][temp.j+1].s) {
		Node temp2;
		temp2.i = temp.i;
		temp2.j = temp.j + 1;
		DFS(temp2);
	}
	if (arr[temp.i][temp.j-1].s) {
		Node temp2;
		temp2.i = temp.i;
		temp2.j = temp.j - 1;
		DFS(temp2);
	}
	if (arr[temp.i+1][temp.j].s) {
		Node temp2;
		temp2.i = temp.i + 1;
		temp2.j = temp.j;
		DFS(temp2);
	}
	if (arr[temp.i-1][temp.j].s) {
		Node temp2;
		temp2.i = temp.i - 1;
		temp2.j = temp.j;
		DFS(temp2);
	}
}


void BFS() {
	while (1) {
		Node temp = q.front();
		DFS(temp);
		year++;
		while (!q.empty()) {
			Node temp2 = q.front();
			if (arr2[temp2.i][temp2.j].y != year) {
				cout << year-1 << endl;
				return;
			}
			if (temp2.c != check) {
				check++;
				break;
			}
			q.pop();
			arr[temp2.i][temp2.j].s = arr2[temp2.i][temp2.j].s;
			arr[temp2.i][temp2.j].y = arr2[temp2.i][temp2.j].y;
			if (arr2[temp2.i][temp2.j].s) {
				temp2.c++;
				q.push(temp2);
			}
		}
		if (q.empty()) {
			cout << 0 << endl;
			return;
		}
	}
}




int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j].s;
			if (arr[i][j].s) {
				arr2[i][j].s = arr[i][j].s;
				Node temp;
				temp.i = i;
				temp.j = j;
				q.push(temp);
			}
		}
	}

	BFS();

	return 0;
}
