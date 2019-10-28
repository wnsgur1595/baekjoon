//9095번
#include<iostream>

using namespace std;

int DP[11] = { 0 };

int main() {
	int T;
	cin >> T;

	int* n = new int[T];
	DP[1] = 1;
	DP[2] = 2;
	DP[3] = 4;

	for (int i = 4; i < 11; i++) {
		if (i - 1 > 0) DP[i] += DP[i - 1];
		if (i - 2 > 0) DP[i] += DP[i - 2];
		if (i - 3 > 0) DP[i] += DP[i - 3];
	}

	for (int i = 0; i < T; i++) {
		cin >> n[i];
		cout << DP[n[i]] << endl;
	}

	return 0;
}
