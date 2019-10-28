//1520번
#include<iostream>
#include<queue>

using namespace std;

int M = 0;
int N = 0;
int arr[500][500] = { 0 };
int arr2[500][500] = { 0 };
int arr3[500][500] = { 0 };

struct Node {
	int high;
	int i;
	int j;
};

struct cmp {
	bool operator()(Node* t, Node* s) {
		return t->high < s->high;
	}
};

int main() {

	cin >> M >> N;
	arr2[0][0] = 1;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}

	priority_queue<Node*, vector<Node*>, cmp> h;
	Node* start = new Node;
	start->high = arr[0][0];
	start->i = 0;
	start->j = 0;
	h.push(start);
	while (!h.empty()) {
		Node* temp = h.top();
		h.pop();
		if (temp->j + 1 < N && temp->high > arr[temp->i][temp->j + 1]) {
			arr2[temp->i][temp->j + 1] += arr2[temp->i][temp->j];
			if (arr3[temp->i][temp->j + 1] == 0) {
				arr3[temp->i][temp->j + 1] = 1;
				Node* temp2 = new Node;
				temp2->high = arr[temp->i][temp->j + 1];
				temp2->i = temp->i;
				temp2->j = temp->j + 1;
				h.push(temp2);
			}
		}
		if (temp->j - 1 >= 0 && temp->high > arr[temp->i][temp->j - 1]) {
			arr2[temp->i][temp->j - 1] += arr2[temp->i][temp->j];
			if (arr3[temp->i][temp->j - 1] == 0) {
				arr3[temp->i][temp->j - 1] = 1;
				Node* temp2 = new Node;
				temp2->high = arr[temp->i][temp->j - 1];
				temp2->i = temp->i;
				temp2->j = temp->j - 1;
				h.push(temp2);
			}
		}
		if (temp->i + 1 < M && temp->high > arr[temp->i + 1][temp->j]) {
			arr2[temp->i + 1][temp->j] += arr2[temp->i][temp->j];
			if (arr3[temp->i + 1][temp->j] == 0) {
				arr3[temp->i + 1][temp->j] = 1;
				Node* temp2 = new Node;
				temp2->high = arr[temp->i + 1][temp->j];
				temp2->i = temp->i + 1;
				temp2->j = temp->j;
				h.push(temp2);
			}
		}
		if (temp->i - 1 >= 0 && temp->high > arr[temp->i - 1][temp->j]) {
			arr2[temp->i - 1][temp->j] += arr2[temp->i][temp->j];
			if (arr3[temp->i - 1][temp->j] == 0) {
				arr3[temp->i - 1][temp->j] = 1;
				Node* temp2 = new Node;
				temp2->high = arr[temp->i - 1][temp->j];
				temp2->i = temp->i - 1;
				temp2->j = temp->j;
				h.push(temp2);
			}
		}
	}

	cout << arr2[M - 1][N - 1] << endl;

	return 0;
}
