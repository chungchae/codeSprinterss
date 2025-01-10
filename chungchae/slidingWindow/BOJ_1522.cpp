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

// BOJ_1522 (sliding_window)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string arr;
    cin >> arr;

    //a ����
    int count = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == 'a')
            count++;
    }
    //�����̹Ƿ�, �迭 �÷���
    arr = arr + arr;

    //��ȯ�� �ּڰ�
    int min_count = count;
    //������ �� b ����
    int b_count = 0;

    //�����̵� ������
    for (int i = 0; i < arr.size() - count; i++) {
        for (int j = 0; j < count; j++)
        {
            if (arr[i + j] == 'b')
                b_count++;
        }
        if (b_count < min_count)
            min_count = b_count;
        b_count = 0;
    }
    cout << min_count;

}