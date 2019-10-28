//10835번
#include<iostream>
using namespace std;
#define max(a,b) a > b ? a : b

int A[2000] = { 0 };
int B[2000] = { 0 };
int arr[2000][2000] = { 0 };
int N = 0;
int ex(int apos, int bpos) {
	if (apos >= N || bpos >= N) return 0;
	if (arr[apos][bpos] != -1) return arr[apos][bpos];

	int max1 = max(ex(apos + 1, bpos + 1), ex(apos + 1, bpos));
	if (A[apos] > B[bpos]) max1 = max(ex(apos, bpos + 1) + B[bpos], max1);

	return arr[apos][bpos] = max1;
}

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	for (int i = 0; i < N; i++) {
		cin >> B[i];
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			arr[i][j] = -1;
		}
	}

	cout << ex(0, 0) << endl;


	return 0;
}
