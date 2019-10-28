//1712번
#include<iostream>

using namespace std;
int A, B, C;


int main() {
	cin >> A >> B >> C;

	int c = C - B;
	if (c <= 0) {
		cout << -1 << endl;
	}
	else {
		cout << A / c + 1 << endl;
	}

	return 0;
}
