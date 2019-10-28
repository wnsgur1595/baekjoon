//1937번
#include<iostream>
#include<queue>

using namespace std;

int arr[500][500] = { 0 };
int arr2[500][500] = { 0 };

struct Node {
	int tree;
	int i;
	int j;
};

struct cmp {
	bool operator()(Node* t, Node* s) {
		return t->tree > s->tree;
	}
};

int main() {
	int n;
	cin >> n;
	priority_queue<Node*, vector<Node*>, cmp> h;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			Node* temp = new Node;
			cin >> arr[i][j];
			temp->tree = arr[i][j];
			temp->i = i;
			temp->j = j;
			h.push(temp);
			arr2[i][j] = 1;
		}
	}

	while (!h.empty()) {
		Node* temp = h.top();
		h.pop();
		if (temp->j+1 < n && arr[temp->i][temp->j+1] > arr[temp->i][temp->j] && arr2[temp->i][temp->j + 1] < arr2[temp->i][temp->j] + 1) {
			arr2[temp->i][temp->j + 1] = arr2[temp->i][temp->j] + 1;
		}
		if (temp->j - 1 >= 0 && arr[temp->i][temp->j - 1] > arr[temp->i][temp->j] && arr2[temp->i][temp->j - 1] < arr2[temp->i][temp->j] + 1) {
			arr2[temp->i][temp->j - 1] = arr2[temp->i][temp->j] + 1;
		}
		if (temp->i + 1 < n && arr[temp->i + 1][temp->j] > arr[temp->i][temp->j] && arr2[temp->i + 1][temp->j] < arr2[temp->i][temp->j] + 1) {
			arr2[temp->i + 1][temp->j] = arr2[temp->i][temp->j] + 1;
		}
		if (temp->i - 1 >= 0 && arr[temp->i - 1][temp->j] > arr[temp->i][temp->j] && arr2[temp->i - 1][temp->j] < arr2[temp->i][temp->j] + 1) {
			arr2[temp->i - 1][temp->j] = arr2[temp->i][temp->j] + 1;
		}
	}

	int max = arr2[0][0];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (max < arr2[i][j]) max = arr2[i][j];
		}
	}

	cout << max << endl;



	return 0;
}
