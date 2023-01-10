//package BOJ_1629_곱셈;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        int c = sc.nextInt();
        System.out.println(solution(a, b, c));
        sc.close();
    }

    public static long solution(int a, int b, int c) {
        if (b == 0) {
            return 1;
        }
        long n = solution(a, b / 2, c);
        long tmp = n * n % c;
        if (b % 2 == 0) {
            return tmp;
        } else {
            return a * tmp % c;
        }
    }
}
