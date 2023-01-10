//package BOJ_2230_수_고르기;
import java.io.*;
import java.util.*;
public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        String[] tmp = bf.readLine().split(" ");
        int n = Integer.parseInt(tmp[0]);
        int m = Integer.parseInt(tmp[1]);
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(bf.readLine());
        }
        Arrays.sort(arr);
        int a = 0;
        int b = 1;
        int result = Integer.MAX_VALUE;
        while (a < n && b < n) {
            if (arr[b] - arr[a] >= m) {
                if (result > arr[b] - arr[a]) {
                    result = arr[b] - arr[a];
                }
                a++;
                if (a == b) {
                    b++;
                }
            } else {
                b++;
            }
        }
        System.out.print(result);
    }
}
