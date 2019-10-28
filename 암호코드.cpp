//2011번
#include<iostream>
#include<string>
using namespace std;


long long arr2[5001] = { 0 };


int main() {
	string arr;
	cin >> arr;
	arr2[0] = 1;
	if (arr[0] != '0') {
		arr2[1] = 1;
	}
	else {
		cout << 0 << endl;
		return 0;
	}

	for (int i = 1; i < arr.size(); i++) {
		if ((arr[i - 1] == '0' && arr[i] == '0') || (arr[i - 1] >= '3' && arr[i] == '0')) {
			cout << 0 << endl;
			return 0;
		}
		else if ((arr[i - 1] == '0' && arr[i] != '0') || arr[i - 1] >= '3') {
			arr2[i+1] = arr2[i];
		}
		else if (arr[i - 1] == '2' && arr[i] >= '7') {
			arr2[i+1] = arr2[i];
		}
		else if(arr[i] != '0'){
			arr2[i+1] = arr2[i] + arr2[i - 1];
			arr2[i + 1] %= 1000000;
		}
		else {
			arr2[i + 1] = arr2[i - 1];
		}
	}

	cout << arr2[arr.size()] << endl;

	return 0;
}
