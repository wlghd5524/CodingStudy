package BOJ_14654_스테판_쿼리;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        int[] a = new int[n];
        int[] b = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = input.nextInt();
        }
        for (int i = 0; i < n; i++) {
            b[i] = input.nextInt();
        }
        char last_winner = 0;
        int max_cnt = 0;
        int a_cnt = 0;
        int b_cnt = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] == b[i]) {
                if (last_winner == 'a') {
                    last_winner = 'b';
                    b_cnt++;
                    a_cnt = 0;
                } else {
                    last_winner = 'a';
                    a_cnt++;
                    b_cnt = 0;
                }
            } else if (a[i] == 1 && b[i] == 2) {
                last_winner = 'b';
                b_cnt++;
                a_cnt = 0;
            } else if (a[i] == 2 && b[i] == 3) {
                last_winner = 'b';
                b_cnt++;
                a_cnt = 0;
            } else if (a[i] == 3 && b[i] == 1) {
                last_winner = 'b';
                b_cnt++;
                a_cnt = 0;
            } else if (a[i] == 2 && b[i] == 1) {
                last_winner = 'a';
                a_cnt++;
                b_cnt = 0;
            } else if (a[i] == 3 && b[i] == 2) {
                last_winner = 'a';
                a_cnt++;
                b_cnt = 0;
            } else if (a[i] == 1 && b[i] == 3) {
                last_winner = 'a';
                a_cnt++;
                b_cnt = 0;
            }
            if (max_cnt < a_cnt) {
                max_cnt = a_cnt;
            } else if (max_cnt < b_cnt) {
                max_cnt = b_cnt;
            }
        }
        System.out.print(max_cnt);
        input.close();
    }
}
