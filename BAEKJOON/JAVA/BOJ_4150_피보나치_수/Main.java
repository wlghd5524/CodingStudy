package BOJ_4150_피보나치_수;
import java.math.BigInteger;
import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        BigInteger[] arr = new BigInteger[n+1];
        arr[1] = new BigInteger("1");
        if(n>1) {
            arr[2] = new BigInteger("1");
        }
        for(int i = 3;i<=n;i++) {
            arr[i] = arr[i-1].add(arr[i-2]);
        }
        System.out.println(arr[n]);
        input.close();
    }
}
