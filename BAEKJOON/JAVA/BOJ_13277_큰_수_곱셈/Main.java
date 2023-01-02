package BOJ_13277_큰_수_곱셈;
import java.math.BigInteger;
import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        BigInteger a = input.nextBigInteger();
        BigInteger b = input.nextBigInteger();
        System.out.println(a.multiply(b));
        input.close();
    }
}
