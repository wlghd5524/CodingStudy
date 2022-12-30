package BOJ_5585_거스름돈;
import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int money = 1000 - input.nextInt();
        int cnt = 0;
        while(money >= 500) {
            money -= 500;
            cnt++;
        }
        while(money >= 100) {
            money -= 100;
            cnt++;
        }
        while(money >= 50) {
            money -= 50;
            cnt++;
        }
        while(money >= 10) {
            money -= 10;
            cnt++;
        }
        while(money >= 5) {
            money -= 5;
            cnt++;
        }
        while(money >= 1) {
            money -= 1;
            cnt++;
        }
        System.out.println(cnt);
        input.close();
    }
}
