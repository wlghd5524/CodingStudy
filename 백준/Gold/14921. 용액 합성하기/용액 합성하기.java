//package BOJ_14921_용액_합성하기;
import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }
        sc.close();
        int a = 0;
        int b = n - 1;
        int min = Integer.MAX_VALUE;
        while (a < b) {
            if (Math.abs(arr[a] + arr[b]) < Math.abs(min)) {
                min = arr[a] + arr[b];
            }
            if (arr[a] + arr[b] < 0) {
                a++;
            } 
            else if (arr[a] + arr[b] > 0) {
                b--;
            } 
            else {
                min = 0;
                break;
            }
        }
        System.out.print(min);
    }
}
