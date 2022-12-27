package BOJ_1297_TV크기;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        double d = input.nextDouble();
        double h = input.nextDouble();
        double w = input.nextDouble();
        double x = 0;
        double y = 0;
        x = Math.sqrt((w * w * d * d) / ((h * h) + (w * w)));
        y = Math.sqrt((d * d) - (x * x));
        int x_tmp = (int) x;
        int y_tmp = (int) y;
        System.out.print(Integer.toString(y_tmp) + " " + Integer.toString(x_tmp));
        input.close();
    }
}
