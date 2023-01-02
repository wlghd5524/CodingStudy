package BOJ_18221_교수님_저는_취업할래요;
import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        int[][] arr = new int[n][n];
        Point proPoint = new Point();
        Point myPoint = new Point();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                arr[i][j] = input.nextInt();
                if (arr[i][j] == 5) {
                    proPoint.setX(j);
                    proPoint.setY(i);
                }
                if (arr[i][j] == 2) {
                    myPoint.setX(j);
                    myPoint.setY(i);
                }
            }
        }
        if (Math.sqrt(Math.pow(myPoint.getX() - proPoint.getX(), 2) + Math.pow(myPoint.getY() - proPoint.getY(), 2)) < 5) {
            System.out.println(0);
        } 
        else {
            int cnt = 0;
            for (int i = Math.min(proPoint.getY(), myPoint.getY()); i <= Math.max(proPoint.getY(), myPoint.getY()); i++) {
                for (int j = Math.min(proPoint.getX(), myPoint.getX()); j <= Math.max(proPoint.getX(), myPoint.getX()); j++) {
                    if (arr[i][j] == 1) {
                        cnt++;
                    }
                }
            }
            if (cnt >= 3) {
                System.out.println(1);
            } else {
                System.out.println(0);
            }
        }
        input.close();
    }
}
class Point {
    private int x;
    private int y;

    public void setX(int x) {
        this.x = x;
    }

    public void setY(int y) {
        this.y = y;
    }

    public int getX() {
        return x;
    }

    public int getY() {
        return y;
    }
}