#include<iostream>
#include<climits>
#define MAX_N 100
#define MAX_M 20
#define OFFSET 20
using namespace std;

long long dp[MAX_N + 1][MAX_M + 1 + OFFSET]; 
// dp[i][j] --> i번째 까지 고려했을 때 합이 j가 되는 수의 최대 수
int number[MAX_N + 1];

int main() {
	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		cin >> number[i];
	}
	
	//초기화
	for (int i = 0; i <= n; i++) {
		for (int j = -MAX_M; j <= MAX_M; j++) {
			dp[i][j + OFFSET] = 0;
		}
	}
	dp[0][0 + OFFSET] = 0;
	dp[1][number[1] + OFFSET]++;
	dp[1][-number[1] + OFFSET]++;
	//점화식 적용
	for (int i = 2; i <= n; i++) {
		for (int j = -MAX_M; j <= MAX_M; j++) {
			//만약 범위가 벗어난다면 고려하지 않는다.
			if (dp[i - 1][j+ OFFSET] == 0) continue;

			int num = number[i];
			// case1) 해당 수를 뻬는 경우
			if (j - num >= -MAX_M && j - num <= MAX_M) {
				dp[i][j - num + OFFSET] += dp[i - 1][j+OFFSET];
			}

			// case2) 해당 수를 더하는 경우
			if (j + num >= -MAX_M && j + num <= MAX_M) {
				dp[i][j + num + OFFSET] += dp[i - 1][j+OFFSET];
			}
		}
	}
	cout << dp[n][m+OFFSET];
}