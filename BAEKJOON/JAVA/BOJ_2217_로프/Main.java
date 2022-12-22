package BOJ_2217_로프;
import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        Integer[] ropes = new Integer[n];
        for (int i = 0; i < n; i++) {
            ropes[i] = input.nextInt();
        }
        Arrays.sort(ropes, Collections.reverseOrder());
        int result = ropes[0];
        for (int i = 1; i < n; i++) {
            if (ropes[i] * (i + 1) > result) {
                result = ropes[i] * (i + 1);
            }
        }
        System.out.println(result);
        input.close();
    }
}
