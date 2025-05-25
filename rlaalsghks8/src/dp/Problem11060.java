package dp;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Problem11060 {
    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());

        int[] miro = new int[N+1];
        long[] dp = new long[10000];
        StringTokenizer st = new StringTokenizer(br.readLine()," ");
        for(int i=1; i<=N; i++){

            miro[i] = Integer.parseInt(st.nextToken());
            dp[i] = Integer.MAX_VALUE;
        }

        dp[1] = 0;
        for(int i=1; i<=N; i++){
            if(dp[i]>=Integer.MAX_VALUE)
                continue;
            for(int j=1; j<=miro[i]; j++){
                dp[i+j] = Math.min(dp[i+j],dp[i]+1);
            }
        }

        if(dp[N]>=Integer.MAX_VALUE){
            System.out.print(-1);
        }else{
            System.out.print(dp[N]);
        }


    }
}
