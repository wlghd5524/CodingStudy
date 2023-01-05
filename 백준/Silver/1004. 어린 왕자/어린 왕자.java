//package BOJ_1004_어린왕자;
import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for (int i = 0; i < t; i++) {
            int start_x = sc.nextInt();
            int start_y = sc.nextInt();
            int end_x = sc.nextInt();
            int end_y = sc.nextInt();
            int n = sc.nextInt();
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                int cx = sc.nextInt();
                int cy = sc.nextInt();
                int cr = sc.nextInt();
                if (Math.pow(cx - start_x, 2) + Math.pow(cy - start_y, 2) < Math.pow(cr, 2)) {
                    if (Math.pow(cx - end_x, 2) + Math.pow(cy - end_y, 2) > Math.pow(cr, 2)) {
                        cnt++;
                    }
                } 
                else {
                    if (Math.pow(cx - end_x, 2) + Math.pow(cy - end_y, 2) < Math.pow(cr, 2)) {
                        cnt++;
                    }
                }
            }
            System.out.println(cnt);
            
        }
        sc.close();
    }
}
