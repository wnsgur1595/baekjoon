//10942번
#include<iostream>

using namespace std;
int arr[2000] = { 0 };
int v[2000][2000] = { 0 };

int main() {
    ios::sync_with_stdio(false);
	cin.tie(0);
	int N, M;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < N; i++) {
		v[i][i] = 1;
	}
	for (int i = 0; i < N - 1; i++) {
		if (arr[i] == arr[i + 1]) v[i][i + 1] = 1;
	}

	for(int pos = 3;pos<=N;pos++){
		for (int i = 0; i < N - pos + 1; i++) {
			if (arr[i] == arr[i + pos - 1] && v[i+1][i+pos-2]) {
				v[i][i + pos - 1] = 1;
			}
		}
	}

	cin >> M;
	int S, E;
	for (int i = 0; i < M; i++) {
		cin >> S >> E;
		cout << v[S - 1][E - 1] << '\n';
	}

	return 0;
}
