package BOJ_2587_대표값2;
import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int[] arr = new int[5];
        int sum = 0;
        for (int i = 0; i < 5; i++) {
            arr[i] = input.nextInt();
            sum += arr[i];
        }
        Arrays.sort(arr);
        System.out.println(sum / 5);
        System.out.println(arr[2]);
        input.close();
    }
}
