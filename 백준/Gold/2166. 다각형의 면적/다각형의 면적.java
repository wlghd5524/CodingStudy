//package BOJ_2166_다각형의_면적;
import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        Point[] points = new Point[n];
        for (int i = 0; i < n; i++) {
            points[i] = new Point(sc.nextLong(), sc.nextLong());
        }
        sc.close();
        long sum_a = 0;
        long sum_b = 0;
        for (int i = 0; i < n - 1; i++) {
            sum_a += points[i].x * points[i + 1].y;
        }
        sum_a += points[n - 1].x * points[0].y;
        for (int i = 0; i < n - 1; i++) {
            sum_b += points[i].y * points[i + 1].x;
        }
        sum_b += points[n - 1].y * points[0].x;
        System.out.printf("%.1f", Math.abs(((double) sum_a - sum_b)) * 0.5);
    }

    public static class Point {
        private long x;
        private long y;

        public Point(long x, long y) {
            this.x = x;
            this.y = y;
        }
    }
}
