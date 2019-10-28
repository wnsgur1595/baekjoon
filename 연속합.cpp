//1912번
#include<iostream>

using namespace std;
struct Node {
	int a = 0;
	int b = 0;
};

Node arr[100000];

int main() {
	int n;
	int count = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i].a;
		if (arr[i].a >= 0) {
			arr[i].b = 1; count = 1;
		}
	}

	long long max1 = 0;
	long long sub1 = 0;
	long long max2 = 0;
	int i = 0;
	if (count == 1) {
		while (i < n) {
			while (arr[i].b && i < n) {
				max1 += arr[i].a;
				i++;
			}
			if (max1 > max2) max2 = max1;
			while (arr[i].b == 0 && i < n) {
				sub1 -= arr[i].a;
				i++;
			}
			if (sub1 >= max1) {
				max1 = 0;
				sub1 = 0;
			}
			else {
				max1 -= sub1;
				sub1 = 0;
			}
		}
		cout << max2 << endl;
	}
	else if (count != 1) {
		long long max3 = arr[0].a;
		for (int j = 0; j < n; j++) {
			if (arr[j].a > max3) max3 = arr[j].a;
		}
		cout << max3 << endl;
	}

	return 0;
}
