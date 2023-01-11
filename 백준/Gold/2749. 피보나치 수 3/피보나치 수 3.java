//package BOJ_2749_피보나치_수_3;
import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long n = sc.nextLong();
        long[] dp = new long[1500001];
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= 1500000; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
            dp[i] %= 1000000;
        }
        n = n % 1500000;
        System.out.print(dp[(int) n]);
    }
}
