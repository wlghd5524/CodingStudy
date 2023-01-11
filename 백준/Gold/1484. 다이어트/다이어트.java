//package BOJ_1484_다이어트;
import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int g = sc.nextInt();
        sc.close();
        int x = 1;
        int y = 1;
        boolean is_possible = false;
        while(x < 100000) {
            if(x*x - y*y < g) {
                x++;
            }
            else if(x*x - y*y > g) {
                y++;
            }
            else if(x*x - y*y == g) {
                System.out.println(x);
                x++;
                is_possible = true;
            }
        }
        if(!is_possible) {
            System.out.print(-1);
        }
        
    }
}
