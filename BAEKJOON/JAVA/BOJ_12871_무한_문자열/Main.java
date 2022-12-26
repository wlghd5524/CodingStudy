package BOJ_12871_무한_문자열;
import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        String a_tmp = input.next();
        String b_tmp = input.next();
        String a = a_tmp;
        String b = b_tmp;
        while (a.length() != b.length()) {
            if (a.length() > b.length()) {
                b = b + b_tmp;
            } else if (a.length() < b.length()) {
                a = a + a_tmp;
            }
        }
        if (a.equals(b)) {
            System.out.println(1);
        } else {
            System.out.println(0);
        }
        input.close();
    }
}
