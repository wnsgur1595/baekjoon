//4883번
#include<iostream>
#define MIN(a,b) a < b ? a : b
using namespace std;

int N;
int t = 1;
int arr[100000][3];
long long dp[100000][3];

int main() {
	while (1) {
		scanf("%d", &N);
		if (N == 0) return 0;
		for (int i = 0; i < N; i++) {
			scanf("%d %d %d", &arr[i][0], &arr[i][1], &arr[i][2]);
		}

		dp[0][0] = 10000;
		dp[0][1] = arr[0][1];
		dp[0][2] = arr[0][2] + arr[0][1];

		for (int i = 1; i < N; i++) {
			dp[i][0] = MIN(dp[i - 1][0] + arr[i][0], dp[i - 1][1] + arr[i][0]);

			long long Min = MIN(dp[i - 1][0], dp[i - 1][1]);
			long long Min2 = MIN(dp[i - 1][2], dp[i][0]);
			dp[i][1] = MIN(Min + arr[i][1], Min2 + arr[i][1]);

			long long Min3 = MIN(dp[i - 1][1], dp[i - 1][2]);
			dp[i][2] = MIN(dp[i][1] + arr[i][2], Min3 + arr[i][2]);
		}

		printf("%d. %d\n", t, dp[N - 1][1]);
		t++;
	}

	return 0;
}
