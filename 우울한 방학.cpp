//17392번
#include<iostream>

using namespace std;

int M, N;
int arr[1000];

int main() {
	cin >> N >> M;
	long long sum = 0;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		sum += (arr[i] + 1);
	}
	
	long long d = M - sum;	//날짜 - 배열값의합 (총 우울함)
	if (d <= 0) {
		cout << 0 << endl;
		return 0;
	}
	long long t = N + 1;		//약속개수+1 -> 우울할수있는 공간의 수
	long long a = d / t;		//총 우울함 / 약속 공간의 수
	if (N == 0) {
		long long s = 0;
		for (int i = 1; i <= a; i++) {
			s += i * i;
		}
		cout << s << endl;
		return 0;
	}
	if (d % t == 0) {
		long long s = 0;
		for (int i = 1; i <= a; i++) {
			s += i * i;
		}
		s *= t;
		cout << s << endl;
		return 0;
	}
	else {
		long long s = 0;
		long long s1 = 0;
		long long temp = d % t;
		long long temp2 = t - temp;
		for (int i = 1; i <= a; i++) {
			s += i * i;
		}
		s1 = (s + (a + 1) * (a + 1));
		s *= temp2;
		s1 *= temp;
		cout << s1 + s << endl;
		return 0;
	}

	return 0;
}

