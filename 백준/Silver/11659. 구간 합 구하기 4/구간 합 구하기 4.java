//package BOJ_11659_구간_합_구하기_4;
import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int[] dp = new int[n+1];
        dp[0] = 0;
        for(int i = 1;i<=n;i++) {
            int tmp = sc.nextInt();
            dp[i] = dp[i-1] + tmp;
        }
        for(int i = 0;i<m;i++) {
            int x = sc.nextInt();
            int y = sc.nextInt();
            System.out.println(dp[y]-dp[x-1]);
            /*
            if(x==y) {
                System.out.println(dp[x]);
            }
            else if(x==1) {
                System.out.println(dp[y]);
            }
            else {
                System.out.println(dp[y]-dp[x-1]);
            }
            */
        }
    }
}
