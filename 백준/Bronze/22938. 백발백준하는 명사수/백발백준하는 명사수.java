//package BOJ_22938_백발백준하는_명사수;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        double x1 = sc.nextInt();
        double y1 = sc.nextInt();
        double r1 = sc.nextInt();
        double x2 = sc.nextInt();
        double y2 = sc.nextInt();
        double r2 = sc.nextInt();
        boolean result = true;
        if (Math.sqrt(Math.pow(x2 - x1, 2) + Math.pow(y2 - y1, 2)) >= r1 + r2) {
            result = false;
        }
        if (result == true) {
            System.out.println("YES");
        } else {
            System.out.println("NO");
        }
        sc.close();
    }
}
