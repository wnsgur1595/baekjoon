#include<iostream>
#include<queue>
using namespace std;

bool arr[50][50]; // 고슴도치가 방문한 곳
char str[50][51];
int R, C;
int ei, ej;
int si, sj;

struct Node {
	int i=0;
	int j=0;
	int day = 0;
};

queue<Node> q;
queue<Node> q2;

void BFS() {
	Node temp;
	temp.i = si;
	temp.j = sj;
	q.push(temp);
	int d = 0;
	int d2 = 0;
	while (1) {
		while (!q2.empty()) {
			Node wtemp2;
			wtemp2 = q2.front();
			if (d2 != wtemp2.day) {
				d2 = wtemp2.day;
				break;
			}
			q2.pop();
			if (wtemp2.j + 1 < C && (str[wtemp2.i][wtemp2.j + 1] == '.' || str[wtemp2.i][wtemp2.j + 1] == 'S') && !arr[wtemp2.i][wtemp2.j + 1]) {
				Node wtemp3;
				wtemp3.i = wtemp2.i;
				wtemp3.j = wtemp2.j + 1;
				wtemp3.day = wtemp2.day + 1;
				str[wtemp3.i][wtemp3.j] = '*';
				q2.push(wtemp3);
			}
			if (wtemp2.j - 1 >= 0 && (str[wtemp2.i][wtemp2.j - 1] == '.' || str[wtemp2.i][wtemp2.j - 1] == 'S') && !arr[wtemp2.i][wtemp2.j - 1]) {
				Node wtemp3;
				wtemp3.i = wtemp2.i;
				wtemp3.j = wtemp2.j - 1;
				wtemp3.day = wtemp2.day + 1;
				str[wtemp3.i][wtemp3.j] = '*';
				q2.push(wtemp3);
			}
			if (wtemp2.i + 1 < R && (str[wtemp2.i + 1][wtemp2.j] == '.' || str[wtemp2.i + 1][wtemp2.j] == 'S') && !arr[wtemp2.i + 1][wtemp2.j]) {
				Node wtemp3;
				wtemp3.i = wtemp2.i + 1;
				wtemp3.j = wtemp2.j;
				wtemp3.day = wtemp2.day + 1;
				str[wtemp3.i][wtemp3.j] = '*';
				q2.push(wtemp3);
			}
			if (wtemp2.i - 1 >= 0 && (str[wtemp2.i - 1][wtemp2.j] == '.' || str[wtemp2.i - 1][wtemp2.j] == 'S') && !arr[wtemp2.i - 1][wtemp2.j]) {
				Node wtemp3;
				wtemp3.i = wtemp2.i - 1;
				wtemp3.j = wtemp2.j;
				wtemp3.day = wtemp2.day + 1;
				str[wtemp3.i][wtemp3.j] = '*';
				q2.push(wtemp3);
			}
		}
		while (!q.empty()) {
			Node temp2;
			temp2 = q.front();
			if (temp2.day != d) {
				d = temp2.day;
				break;
			}
			q.pop();
			if (str[temp2.i][temp2.j] == 'D') {
				cout << temp2.day << endl;
				return;
			}

			if (temp2.j + 1 < C && (str[temp2.i][temp2.j + 1] == '.' || str[temp2.i][temp2.j + 1] == 'D') && !arr[temp2.i][temp2.j + 1]) {
				Node temp3;
				temp3.i = temp2.i;
				temp3.j = temp2.j + 1;
				temp3.day = temp2.day + 1;
				arr[temp3.i][temp3.j] = 1;
				q.push(temp3);
			}
			if (temp2.j - 1 >= 0 && (str[temp2.i][temp2.j - 1] == '.' || str[temp2.i][temp2.j - 1] == 'D') && !arr[temp2.i][temp2.j - 1]) {
				Node temp3;
				temp3.i = temp2.i;
				temp3.j = temp2.j - 1;
				temp3.day = temp2.day + 1;
				arr[temp3.i][temp3.j] = 1;
				q.push(temp3);
			}
			if (temp2.i + 1 < C && (str[temp2.i + 1][temp2.j] == '.' || str[temp2.i + 1][temp2.j] == 'D') && !arr[temp2.i + 1][temp2.j]) {
				Node temp3;
				temp3.i = temp2.i + 1;
				temp3.j = temp2.j;
				temp3.day = temp2.day + 1;
				arr[temp3.i][temp3.j] = 1;
				q.push(temp3);
			}
			if (temp2.i - 1 >= 0 && (str[temp2.i - 1][temp2.j] == '.' || str[temp2.i - 1][temp2.j] == 'D') && !arr[temp2.i - 1][temp2.j]) {
				Node temp3;
				temp3.i = temp2.i - 1;
				temp3.j = temp2.j;
				temp3.day = temp2.day + 1;
				arr[temp3.i][temp3.j] = 1;
				q.push(temp3);
			}
		}
		if (q.empty()) {
			cout << "KAKTUS" << endl;
			return;
		}
	}
}

int main() {
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		cin >> str[i];
		for (int j = 0; j < C; j++) {
			if (str[i][j] == 'D') {
				ei = i;
				ej = j;
			}
			else if (str[i][j] == '*') {
				Node wtemp;
				wtemp.i = i;
				wtemp.j = j;
				q2.push(wtemp);
			}
			else if (str[i][j] == 'S') {
				si = i;
				sj = j;
				arr[i][j] = 1;
			}
		}
	}
	BFS();

	return 0;
}
