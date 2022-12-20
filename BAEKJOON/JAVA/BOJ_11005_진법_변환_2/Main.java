package BOJ_11005_진법_변환_2;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        int b = input.nextInt();
        String result = "";
        while (n >= b) {
            if (n % b >= 10) {
                result += Character.toString(n % b + 55);
            } else {
                result += n % b;
            }
            n /= b;
        }
        if (n % b >= 10) {
            result += Character.toString(n % b + 55);
        } else {
            result += n % b;
        }
        StringBuffer sb = new StringBuffer(result);
        result = sb.reverse().toString();
        System.out.print(result);
        input.close();
    }
}
