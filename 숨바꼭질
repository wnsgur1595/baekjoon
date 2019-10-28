//1697번
#include<iostream>
#include<queue>
using namespace std;

int N, K;
bool arr[100001];
struct Node {
	int pos = 0;
	int count = 0;
};

void BFS(int n, int k) {
	queue<Node> q;
	Node t;
	t.pos = n;
	q.push(t);
	while (!q.empty()) {
		Node temp = q.front();
		q.pop();
		if (temp.pos == k) {
			cout << temp.count << endl;
			return;
		}
		if (temp.pos + 1 <= 100000 && !arr[temp.pos + 1]) {
			Node temp2;
			temp2.pos = temp.pos + 1;
			temp2.count = temp.count + 1;
			arr[temp.pos + 1] = true;
			q.push(temp2);
		}
		if (temp.pos - 1 >= 0 && !arr[temp.pos - 1]) {
			Node temp2;
			temp2.pos = temp.pos - 1;
			temp2.count = temp.count + 1;
			arr[temp.pos - 1] = true;
			q.push(temp2);
		}
		if (temp.pos * 2 <= 100000 && !arr[temp.pos * 2]) {
			Node temp2;
			temp2.pos = temp.pos * 2;
			temp2.count = temp.count + 1;
			arr[temp.pos * 2] = true;
			q.push(temp2);
		}
	}

}

int main() {
	cin >> N >> K;
	BFS(N, K);

	return 0;
}
