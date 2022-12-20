
//package BOJ_17390_이건_꼭_풀어야_해;
import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        String[] input = bf.readLine().split(" ");
        int n = Integer.parseInt(input[0]);
        int q = Integer.parseInt(input[1]);
        ArrayList<Integer> arr = new ArrayList<>();
        arr.add(0);
        int[] dp = new int[n + 1];
        dp[0] = 0;
        input = bf.readLine().split(" ");
        for (int i = 0; i < n; i++) {
            int tmp = Integer.parseInt(input[i]);
            arr.add(tmp);
        }
        Collections.sort(arr);
        for (int i = 1; i <= n; i++) {
            dp[i] = dp[i - 1] + arr.get(i);
        }
        for (int i = 0; i < q; i++) {
            input = bf.readLine().split(" ");
            int l = Integer.parseInt(input[0]);
            int r = Integer.parseInt(input[1]);
            if (l == r) {
                bw.write(Integer.toString(arr.get(r)) + "\n");
            } else {
                bw.write(Integer.toString(dp[r] - dp[l - 1]) + "\n");
            }
        }
        bw.flush();
        bw.close();
    }
}
