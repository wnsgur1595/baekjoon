//2869번
#include<iostream>

using namespace std;

long long V;
long long A, B;

int main() {
	cin >> A >> B >> V;
	long long count = 0;
	if (V > A) {
		long long t = V - A;
		long long t2 = A - B;
		long long temp = 0;
		if (t % t2 == 0) {
			temp = t / t2;
			cout << temp + 1 << endl;
		}
		else {
			temp = t / t2 + 1;
			cout << temp + 1 << endl;
		}
	}
	else {
		cout << 1 << endl;
	}


	return 0;
}
