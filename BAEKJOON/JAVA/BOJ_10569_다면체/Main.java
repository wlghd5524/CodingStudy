//package BOJ_10569_다면체;
import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int t = input.nextInt();
        for(int i = 0;i<t;i++) {
            int v = input.nextInt();
            int e = input.nextInt();
            System.out.println(e-v+2);
        }
        input.close();
    }
}
