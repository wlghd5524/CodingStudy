//package BOJ_1940_주몽;
import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }
        sc.close();
        Arrays.sort(arr);
        int a = 0;
        int b = 1;
        int cnt = 0;
        while (a < n - 1) {
            if (arr[a] + arr[b] == m) {
                cnt++;
                a++;
                b = a+1;
            } else if (arr[a] + arr[b] < m) {
                b++;
            } else {
                a++;
                b = a + 1;
            }
            if (a == b) {
                b = a + 1;
            }
            if (b == n) {
                a++;
                b = a + 1;
            }
        }
        System.out.print(cnt);
    }
}
