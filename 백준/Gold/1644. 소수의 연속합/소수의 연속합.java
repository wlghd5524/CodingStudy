//package BOJ_1644_소수의_연속합;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        if(n==1) {
            System.out.print(0);
        }
        else {
            boolean prime[] = new boolean[n + 1];
            prime[0] = prime[1] = true;
            for (int i = 2; i * i <= n; i++) {
                if (!prime[i]) {
                    for (int j = i * i; j <= n; j += i) {
                        prime[j] = true;
                    }
                }
            }
            List<Integer> prime_list = new ArrayList<Integer>();
            for (int i = 1; i <= n; i++) {
                if (!prime[i]) {
                    prime_list.add(i);
                }
            }
            int a = 0;
            int b = 0;
            int sum = prime_list.get(a);
            int cnt = 0;
            while (a < prime_list.size()) {
                if (sum == n) {
                    cnt++;
                    sum -= prime_list.get(a);
                    a++;
                } 
                else if (sum < n) {
                    b++;
                    if (b == prime_list.size()) {
                        break;
                    }
                    sum += prime_list.get(b);
                } 
                else {
                    sum -= prime_list.get(a);
                    a++;
                }
                if (a > b) {
                    b = a;
                }
            }
            System.out.print(cnt);
        }
        sc.close();
    }
}
