//package BOJ_11576_Base_Conversion;
import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        int m = sc.nextInt();
        List<Integer> list = new ArrayList<>();
        for (int i = 0; i < m; i++) {
            int num = sc.nextInt();
            list.add(num);
        }
        Collections.reverse(list);
        int sum = 0;
        for (int i = 0; i < list.size(); i++) {
            sum += list.get(i) * Math.pow(a, i);
        }
        list.clear();
        while (sum >= b) {
            list.add(sum % b);
            sum /= b;
        }
        list.add(sum);
        Collections.reverse(list);
        for (int i = 0; i < list.size(); i++) {
            System.out.print(list.get(i) + " ");
        }
        sc.close();
    }
}
