#include <iostream>
using namespace std;

int main() {
	int s[1004] = { 0 };
	int n;
	cin >> n;
	s[1] = 1;
	s[2] = 2;
	for (int i = 3; i <= n; i++) {
		s[i] = s[i - 1] + s[i - 2];
		if (s[i] == 0)continue;
		else s[i] %= 10007;
	}

	cout << s[n];
}