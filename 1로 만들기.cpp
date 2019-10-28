//1463번
#include<iostream>

using namespace std;

int N;
long long dp[1000001];


int main() {
	cin >> N;
	for (int i = 2; i <= N; i++) {
		long long min = 100000000;
		if (i % 3 == 0 && dp[i/3] + 1 < min) {
			min = dp[i / 3] + 1;
		}
		if (i % 2 == 0 && dp[i/2] + 1 < min) {
			min = dp[i / 2] + 1;
		}
		if (dp[i - 1] + 1 < min) {
			min = dp[i - 1] + 1;
		}
		dp[i] = min;
	}

	cout << dp[N] << endl;

	return 0;
}
