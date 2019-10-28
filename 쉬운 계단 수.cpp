//100844번
#include<iostream>

using namespace std;

int main() {
	long long arr[10] = { 0 };
	long long arr2[10] = { 0 };
	int N;
	long long a = 0;
	cin >> N;
	for (int i = 1; i < 10; i++) {
		arr[i] = 1;
	}

	for (int i = 0; i < N - 1; i++) {
		for (int i = 0; i < 10; i++) {
			if (i == 0) {
				arr2[i] = arr[i + 1];
			}
			else if (i == 9) {
				arr2[i] = arr[i - 1];
			}
			else {
				arr2[i] = arr[i - 1] + arr[i + 1];
			}
		}
		for (int i = 0; i < 10; i++) {
			arr[i] = arr2[i];
			arr[i] %= 1000000000;
		}
	}

	for (int i = 0; i < 10; i++) {
		a += arr[i];
	}

	cout << a % 1000000000 << endl;

	return 0;
}
