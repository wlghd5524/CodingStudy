//package BOJ_16486_운동장_한_바퀴;
import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int d1 = sc.nextInt();
        int d2 = sc.nextInt();
        double result = 0;
        result += d1 * 2;
        result += d2 * 2 * 3.141592;
        System.out.println(result);
    }
}
