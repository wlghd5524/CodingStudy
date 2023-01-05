//package BOJ_1977_완전제곱수;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int min = 0;
        int sum = 0;
        for (int i = n; i <= m; i++) {
            for (int j = 1; j <= i; j++) {
                if (j * j == i) {
                    if (min == 0) {
                        min = i;
                    }
                    sum += i;
                    break;
                }
            }
        }
        if (sum == 0) {
            System.out.println(-1);
        } 
        else {
            System.out.println(sum);
            System.out.println(min);
        }
    }
}
