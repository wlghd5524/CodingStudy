package BOJ_1924_2007년;
import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int[] month = { 6, 2, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
        String[] week = { "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT" };
        int x = input.nextInt();
        int y = input.nextInt();
        int result = (1 + month[x - 1] + y) % 7;
        System.out.println(week[result]);
        input.close();
    }
}
