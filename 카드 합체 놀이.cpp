//15903번
#include<iostream>
#include<queue>

using namespace std;

int main() {
	long long n, m;
	long long l;
	cin >> n >> m;
	priority_queue<long long, vector<long long>, greater<long long> > min_heap;

	for (int i = 0; i < n; i++) {
		cin >> l;
		min_heap.push(l);
	}
	
	for (int i = 0; i < m; i++) {
		long long temp = min_heap.top();
		min_heap.pop();
		temp += min_heap.top();
		min_heap.pop();
		min_heap.push(temp);
		min_heap.push(temp);
	}

	long long sum = 0;

	while (!min_heap.empty()) {
		sum += min_heap.top();
		min_heap.pop();
	}

	cout << sum << endl;

	return 0;
}
