package BOJ_13458_시험_감독;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = input.nextInt();
        }
        int b = input.nextInt();
        int c = input.nextInt();
        long cnt = 0;
        for (int i = 0; i < n; i++) {
            arr[i] -= b;
            cnt++;
            if (arr[i] <= 0) {
                continue;
            }
            cnt += arr[i] / c;
            arr[i] %= c;
            if (arr[i] > 0) {
                cnt++;
            }
        }
        System.out.println(cnt);
        input.close();
    }
}
