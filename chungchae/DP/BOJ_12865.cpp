#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric>
#include <stack>
#include <queue>

using namespace std;

// BOJ_12865 (DP)

int N, K;
vector<int> wt;
vector<int> val;
vector < vector<int>> DP;

// ���� �뷮, �뷮 �迭, ��ġ �迭, ���� ����
int func(int W, int* wt, int* val, int n) {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= W; j++) {
			if (wt[i - 1] > j)
				DP[i][j] = DP[i - 1][j];
			else {
				int ValWith = val[i - 1] + DP[i - 1][j - wt[i - 1]]; // �ִ� ���
				int ValWithout = DP[i - 1][j]; // �ȳִ� ���
				DP[i][j] = max(ValWith, ValWithout); // �� ū �� ����
			}
		}
	}
	return DP[n][W];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	
	cin >> N >> K;

	wt.resize(N);
	val.resize(N);
	//DP �迭 �ʱ�ȭ
	DP = vector<vector<int>>(N + 1, vector<int>(K + 1, 0));

	for (int i = 0; i < N; i++) {
		cin >> wt[i] >> val[i];
	}
	
	cout << func(K, wt.data(), val.data(), N) << "\n";
}