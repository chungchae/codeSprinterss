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

using namespace std;

// BOJ_11003 (sliding_window)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    //(index, value)
    typedef pair<int, int> Node;

    int N, L;
    cin >> N >> L;

    deque<Node> arr;

    for (int i = 0; i < N; i++) {
        int now;
        cin >> now;
        //�߰��ϴ� ����� value�� �� ������, ���� ��带 ����
        while (arr.size() && arr.back().second > now) {
            arr.pop_back();
        }
        //���� ��� �߰�
        arr.push_back(Node(i, now));
        //�ε����� �ʰ��ϸ� front��带 ����
        if (arr.front().first <= i - L) {
            arr.pop_front();
        }
        cout << arr.front().second << ' ';
    }
}