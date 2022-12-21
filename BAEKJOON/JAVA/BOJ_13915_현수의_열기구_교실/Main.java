package BOJ_13915_현수의_열기구_교실;
import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        while (input.hasNext()) {
            Set<String> set = new TreeSet<String>();
            int n = input.nextInt();
            for (int i = 0; i < n; i++) {
                String bit = "0000000000";
                StringBuilder sb = new StringBuilder(bit);
                String str = input.next();
                for (int j = 0; j < str.length(); j++) {
                    sb.setCharAt(Character.getNumericValue(str.charAt(j)), '1');
                    bit = sb.toString();
                }
                set.add(bit);
            }
            System.out.println(set.size());
        }
        input.close();
    }
}
