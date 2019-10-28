//1890번
#include<iostream>
using namespace std;
int arr[100][100] = { 0 };
long long arr2[100][100] = { 0 };
long long count = 0;

int main() {
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}
	arr2[0][0] = 1;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == N - 1 && j == N - 1) { cout << arr2[N - 1][N - 1] << endl; return 0; }
			if(j+arr[i][j] < N)	arr2[i][j + arr[i][j]] += arr2[i][j];
			if(i+arr[i][j] < N) arr2[i + arr[i][j]][j] += arr2[i][j];
		}
	}

	return 0;
}
