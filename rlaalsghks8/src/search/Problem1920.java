package search;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Problem1920 {

    public static int[] A;

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        A = new int[N];

        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        for (int i = 0; i < N; i++) {
            A[i] = Integer.parseInt(st.nextToken());
        }

        Arrays.sort(A);

        int M = Integer.parseInt(br.readLine());
        st = new StringTokenizer(br.readLine(), " ");
        StringBuilder sb = new StringBuilder();

        for (int i = 0; i < M; i++) {
            if (binarySearch(Integer.parseInt(st.nextToken())) >= 0) {
                sb.append(1).append('\n');
            } else {
                sb.append(0).append('\n');
            }
        }

        // 결과를 한 번에 출력
        System.out.print(sb.toString());
    }

    public static int binarySearch(int key) {
        int lo = 0;
        int hi = A.length - 1;

        while (lo <= hi) {
            int mid = (lo + hi) / 2;

            if (key < A[mid]) {
                hi = mid - 1;
            } else if (key > A[mid]) {
                lo = mid + 1;
            } else {
                return mid;
            }
        }
        return -1;
    }
}
