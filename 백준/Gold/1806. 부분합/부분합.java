//package BOJ_1806_부분합;
import java.io.*;
import java.util.StringTokenizer;
public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        //StringTokenizer st = new StringTokenizer((bf.readLine()));
        String[] tmp = bf.readLine().split(" ");
        int n = Integer.parseInt(tmp[0]);
        int s = Integer.parseInt(tmp[1]);
        //st = new StringTokenizer((bf.readLine()));
        tmp = bf.readLine().split(" ");
        int[] arr = new int[n];
        for(int i = 0;i<n;i++) {
            arr[i] = Integer.parseInt(tmp[i]);
        }
        int a = 0;
        int b = 0;
        int sum = 0;
        int cnt = Integer.MAX_VALUE;
        sum += arr[a];
        while(a<n) {
            if(sum < s) {
                b++;
                if(b==n) {
                    break;
                }
                sum+=arr[b];
            }
            else {
                if(b-a+1 < cnt) {
                    cnt = b-a+1;
                }
                sum-=arr[a];
                a++;
                if(a>b) {
                    b = a;
                }
            }
        }
        if(cnt == Integer.MAX_VALUE) {
            cnt = 0;
        }
        System.out.print(cnt);
    }
}
