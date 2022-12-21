package BOJ_15819_너의_핸들은;
import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        int k = input.nextInt();
        TreeSet<String> handles = new TreeSet<String>();
        for(int i = 0;i<n;i++) {
            String tmp = input.next();
            handles.add(tmp);
        }
        Iterator<String> iter = handles.iterator();
        int cnt = 1;
        while(iter.hasNext()) {
            if(cnt==k) {
                System.out.print(iter.next());
                break;
            }
            else {
                iter.next();
            }
            cnt++;
        }
        input.close();
    }
}
