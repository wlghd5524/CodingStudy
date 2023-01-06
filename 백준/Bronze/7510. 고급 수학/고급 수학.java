//package BOJ_7510_고급_수학;
import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for(int i = 0;i<t;i++) {
            int max = 0;
            List<Integer> list = new ArrayList<>();
            for(int j = 0;j<3;j++) {
                int tmp = sc.nextInt();
                list.add(tmp);
            }
            Collections.sort(list);
            System.out.println("Scenario #"+(i+1)+":");
            if(Math.pow(list.get(2),2) == Math.pow(list.get(0),2) + Math.pow(list.get(1),2)) {
                System.out.println("yes\n");
            }
            else {
                System.out.println("no\n");
            }
            
        }
    }
}
