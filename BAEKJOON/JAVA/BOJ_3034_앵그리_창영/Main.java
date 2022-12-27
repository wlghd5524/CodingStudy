package BOJ_3034_앵그리_창영;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        int w = input.nextInt();
        int h = input.nextInt();
        for (int i = 0; i < n; i++) {
            int tmp = input.nextInt();
            if (tmp <= w || tmp <= h || tmp * tmp <= (w * w) + (h * h)) {
                System.out.println("DA");
            } else {
                System.out.println("NE");
            }
        }
        input.close();
    }
}