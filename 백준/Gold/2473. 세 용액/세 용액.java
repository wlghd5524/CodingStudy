//package BOJ_2473_세_용액;
import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        long[] arr = new long[n];
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }
        sc.close();
        Arrays.sort(arr);
        long min = Long.MAX_VALUE;
        long[] result = { 0, 0, 0 };
        for (int i = 0; i < n; i++) {
            int a = i + 1;
            int b = n - 1;
            while (a < b) {
                long tmp = arr[i] + arr[a] + arr[b];
                if (Math.abs(tmp) < Math.abs(min)) {
                    min = tmp;
                    result[0] = arr[i];
                    result[1] = arr[a];
                    result[2] = arr[b];
                }
                if (tmp == 0) {
                    break;
                } else if (tmp < 0) {
                    a++;
                } else if (tmp > 0) {
                    b--;
                }
            }
        }
        System.out.print(result[0] + " " + result[1] + " " + result[2]);
    }
}
