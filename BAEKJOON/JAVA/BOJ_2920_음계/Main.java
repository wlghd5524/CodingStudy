package BOJ_2920_음계;
import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int[] arr = new int[8];
        boolean is_ascend = true;
        boolean is_descend = true;
        for (int i = 0; i < 8; i++) {
            arr[i] = input.nextInt();
            if (i != 0) {
                if (arr[i] - 1 != arr[i - 1]) {
                    is_ascend = false;
                }
                if (arr[i] + 1 != arr[i - 1]) {
                    is_descend = false;
                }
            }
        }
        if (is_ascend) {
            System.out.println("ascending");
        } 
        else if (is_descend) {
            System.out.println("descending");
        } 
        else {
            System.out.println("mixed");
        }
        input.close();
    }
}
