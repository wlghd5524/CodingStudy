//package BOJ_1292_쉽게_푸는_문제;
import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int a = input.nextInt();
        int b = input.nextInt();
        int[] arr = new int[b+1];
        arr[0] = 0;
        arr[1] = 1;
        int index = 2;
        for(int i = 2;index<=b;i++) {
            for(int j = 0;j<i;j++) {
                arr[index] = arr[index-1] + i;
                index++;
                if(index>b) {
                    break;
                }
            }
        }
        System.out.println(arr[b]-arr[a-1]);
    }
}
