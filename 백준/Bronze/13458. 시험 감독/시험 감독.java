//package BOJ_13458_시험_감독;
import java.util.*;
import java.io.*;
public class Main {
    public static void main(String[] args) throws IOException{
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        Scanner input = new Scanner(System.in);
        //int n = Integer.parseInt(bf.readLine());
        int n = input.nextInt();
        //ArrayList<Integer> arr = new ArrayList<Integer>();
        int[] arr = new int[n];
        for(int i = 0;i<n;i++) {
            arr[i] = input.nextInt();
        }
        /*
        String a = bf.readLine();
        String tmp = "";
        int index = 0;
        for(int i = 0;i<a.length();i++) {
            if(a.charAt(i)==' ') {
                arr[index] = Integer.parseInt(tmp);
                tmp = "";
                index++;
            }
            tmp+=a.charAt(i);
            if(i==a.length()-1) {
                arr[index] = Integer.parseInt(tmp);
                tmp = "";
                index++;
            }
        }
        */
        int b = input.nextInt();
        int c = input.nextInt();
        /*
        String s = bf.readLine();
        for(int i = 0;i<s.length();i++) {
            if(s.charAt(i)==' ') {
                b = Integer.parseInt(tmp);
                tmp = "";
            }
            tmp+=a.charAt(i);
            if(i == s.length()-1) {
                c = Integer.parseInt(tmp);
                tmp = "";
            }
            
        }
        */
        long cnt = 0;
        for(int i = 0;i<n;i++) {
            arr[i] -= b;
            cnt++;
            if(arr[i]<=0) {
                continue;
            }
            cnt += arr[i]/c;
            arr[i] %= c;
            if(arr[i]>0) {
                cnt++;
            }
        }
        System.out.println(cnt);
        input.close();
    }
}
