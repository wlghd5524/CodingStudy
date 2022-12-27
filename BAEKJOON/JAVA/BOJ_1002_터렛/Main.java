//package BOJ_1002_터렛;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        for (int i = 0; i < n; i++) {
            double x1 = input.nextDouble();
            double y1 = input.nextDouble();
            double r1 = input.nextDouble();
            double x2 = input.nextDouble();
            double y2 = input.nextDouble();
            double r2 = input.nextDouble();
            double distance = Math.sqrt(Math.pow(x2 - x1, 2) + Math.pow(y2 - y1, 2));
            if (distance == 0) {
                if (r1 == r2) {
                    System.out.println(-1);
                } else {
                    System.out.println(0);
                }
            } else {
                if (distance < r1 + r2) {
                    if (distance + r1 < r2 || distance + r2 < r1) {
                        System.out.println(0);
                    } else if (distance + r1 == r2 || distance + r2 == r1) {
                        System.out.println(1);
                    } else {
                        System.out.println(2);
                    }
                } else if (distance > r1 + r2) {
                    System.out.println(0);
                } else if (distance == r1 + r2) {
                    System.out.println(1);
                }
            }
        }
        input.close();
    }
}
