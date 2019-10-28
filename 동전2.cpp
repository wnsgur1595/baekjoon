//2294번
#include<iostream>
#include<algorithm>
using namespace std;

int n;
int k;
int dp[10001];
int a[10000];

int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] <= 10000) {
			dp[a[i]] = 1;
		}
	}
	sort(a, a + n);
	
	for (int i = 2; i <= 10000; i++) {
		int min = 1000000;
		for (int j = 0; j < n; j++) {
			if (dp[i] != 0 || a[j] >= i) break;
			if (dp[i-a[j]] != 0 && dp[a[j]] != 0 && dp[i - a[j]] + dp[a[j]] < min) {
				min = dp[i - a[j]] + dp[a[j]];
			}
		}
		if (min != 1000000) {
			dp[i] = min;
		}
	}

	if (dp[k] == 0) {
		cout << -1 << endl;
	}
	else {
		cout << dp[k] << endl;
	}

	return 0;
}
