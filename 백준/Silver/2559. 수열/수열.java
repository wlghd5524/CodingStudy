//package BOJ_2559_수열;
import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        int[] tem = new int[n];
        for (int i = 0; i < n; i++) {
            tem[i] = sc.nextInt();
        }
        sc.close();
        int a = 0;
        int b = k - 1;
        int max = Integer.MIN_VALUE;
        while (b < n) {
            int sum = 0;
            for (int i = a; i <= b; i++) {
                sum += tem[i];
            }
            if (sum > max) {
                max = sum;
            }
            a++;
            b++;
        }
        System.out.print(max);
    }
}
