package BOJ_2475_검증수;
import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int sum = 0;
        for (int i = 0; i < 5; i++) {
            int num = input.nextInt();
            sum += num * num;
        }
        System.out.println(sum % 10);
        input.close();
    }
}
