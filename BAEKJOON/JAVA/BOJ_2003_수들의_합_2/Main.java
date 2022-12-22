package BOJ_2003_수들의_합_2;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        int m = input.nextInt();
        int[] arr = new int[n];
        int[] dp = new int[n + 1];
        for (int i = 0; i < n; i++) {
            arr[i] = input.nextInt();
            if (i == 0) {
                dp[i] = arr[i];
            } else {
                dp[i] = dp[i - 1] + arr[i];
            }

        }
        int cnt = 0;
        if (n == 1) {
            if (m == arr[0]) {
                System.out.println(1);
            } else {
                System.out.println(0);
            }
        } else {
            int a = 0;
            int b = 0;
            while (a < n) {
                if (a == 0) {
                    if (dp[b] < m) {
                        b++;
                        if (b == n) {
                            a++;
                            b = a;
                        }
                    } else if (dp[b] > m) {
                        a++;
                        if (a > b) {
                            b = a;
                        }

                    } else {
                        cnt++;
                        a++;
                        if (a > b) {
                            b = a;
                        }
                    }
                } else {
                    if (dp[b] - dp[a - 1] < m) {
                        b++;
                        if (b == n) {
                            a++;
                            b = a;
                        }
                    } else if (dp[b] - dp[a - 1] > m) {
                        a++;
                        if (a > b) {
                            b = a;
                        }
                    } else {
                        cnt++;
                        a++;
                        if (a > b) {
                            b = a;
                        }
                    }
                }
            }
            System.out.println(cnt);
        }
        input.close();
    }
}
