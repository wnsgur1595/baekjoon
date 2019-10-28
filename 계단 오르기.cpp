//2579번
#include<iostream>

using namespace std;

int arr[301] = { 0 };
int arr2[301][2] = { 0 }; // 마지막 1이 1번 , 마지막 1이 2번

int main() {
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}

	arr2[1][0] = arr[1];
	arr2[2][1] = arr[1] + arr[2];
	arr2[2][0] = arr[2];

	for (int i = 3; i <= N; i++) {
		for (int j = 0; j < 2; j++) {
			if (arr2[i][0] < arr2[i - 2][j] + arr[i]) arr2[i][0] = arr2[i - 2][j] + arr[i];
			if (arr2[i][1] < arr2[i - 1][0] + arr[i]) arr2[i][1] = arr2[i - 1][0] + arr[i];
		}
	}
	
	if (arr2[N][0] > arr2[N][1]) cout << arr2[N][0];
	else cout << arr2[N][1];

	return 0;
}
