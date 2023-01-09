//package BOJ_9020_골드바흐의_추측;
import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for(int i = 0;i<t;i++) {
            int n = sc.nextInt();
            int a = n/2;
            int b = n/2;
            for(int j = 0;j<n/2;j++) {
                if(isPrime(a) && isPrime(b)) {
                    System.out.println(a + " " +b);
                    break;
                }
                a--;
                b++;
            }
        }
        sc.close();
    }
    public static boolean isPrime(int n) {
        for (int i = 2; i<=(int)Math.sqrt(n); i++) {
          if (n % i == 0) {
              return false;
          }
        }
        return true;
    }
}
