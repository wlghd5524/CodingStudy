package BOJ_1247_부호;
import java.math.BigInteger;
import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        for(int i = 0;i<3;i++) {
            int n = input.nextInt();
            BigInteger sum = new BigInteger("0");
            for(int j = 0;j<n;j++) {
                BigInteger tmp = new BigInteger(input.next());
                sum = sum.add(tmp);
            }
            if(sum.toString().charAt(0) == '-') {
                System.out.println("-");
            }
            else if(sum.toString().charAt(0) == '0') {
                System.out.println("0");
            }
            else {
                System.out.println("+");
            }
        }
        input.close();
    }
}
