package BOJ_16478_원의_분할;
import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        double a = input.nextInt();
        double b = input.nextInt();
        double c = input.nextInt();
        double result = a * c / b;
        System.out.println(result);
        input.close();
    }
}
