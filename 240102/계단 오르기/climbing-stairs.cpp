#include<iostream>
using namespace std;

int main() {
	int s[1004] = { 0 };
	int n;
	cin >> n;
	s[2] = 1;
	s[3] = 1;
	for (int i = 4; i <= n; i++) {
		s[i] = s[i - 2] + s[i - 3];
		if (s[i] == 0)continue;
		else s[i] %= 10007;
	}

	cout << s[n];
}