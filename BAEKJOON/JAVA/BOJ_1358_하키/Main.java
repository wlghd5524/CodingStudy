package BOJ_1358_하키;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int w = input.nextInt();
        int h = input.nextInt();
        int x = input.nextInt();
        int y = input.nextInt();
        int p = input.nextInt();
        int cnt = 0;
        for (int i = 0; i < p; i++) {
            int point_x = input.nextInt();
            int point_y = input.nextInt();
            if ((x <= point_x && y <= point_y) && (x + w >= point_x && y + h >= point_y)) {
                cnt++;
            } else if (Math.sqrt(Math.pow(point_x - x, 2) + Math.pow(point_y - (y + (h / 2)), 2)) <= h / 2) {
                cnt++;
            } else if (Math.sqrt(Math.pow(point_x - (x + w), 2) + Math.pow(point_y - (y + (h / 2)), 2)) <= h / 2) {
                cnt++;
            }
        }
        System.out.println(cnt);
        input.close();
    }
}
