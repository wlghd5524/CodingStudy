//package BOJ_2477_참외밭;
import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int k = sc.nextInt();
        int area = 0;
        int x_max = 0;
        int x_max_index = 0;
        int y_max = 0;
        int y_max_index = 0;
        int[] arr = new int[6];
        for(int i = 0;i < 6;i++) {
            int direction = sc.nextInt();
            arr[i] = sc.nextInt();
            if(direction == 1 || direction == 2) {
                if(arr[i] > x_max) {
                    x_max = arr[i];
                    x_max_index = i;
                }
            }
            else if(direction == 3 || direction == 4) {
                if(arr[i] > y_max) {
                    y_max = arr[i];
                    y_max_index = i;
                }
            }
        }
        int tmp_x;
        int tmp_y;
        if(x_max_index==0) {
            tmp_x = Math.max(arr[x_max_index+1], arr[5]) - Math.min(arr[x_max_index+1], arr[5]); 
        }
        else if(x_max_index == 5) {
            tmp_x = Math.max(arr[x_max_index-1], arr[0]) - Math.min(arr[x_max_index-1], arr[0]);
        }
        else {
            tmp_x = Math.max(arr[x_max_index-1], arr[x_max_index+1]) - Math.min(arr[x_max_index-1], arr[x_max_index+1]);
        }
        if(y_max_index==0) {
            tmp_y = Math.max(arr[y_max_index+1], arr[5]) - Math.min(arr[y_max_index+1], arr[5]); 
        }
        else if(y_max_index == 5) {
            tmp_y = Math.max(arr[y_max_index-1], arr[0]) - Math.min(arr[y_max_index-1], arr[0]);
        }
        else {
            tmp_y = Math.max(arr[y_max_index-1], arr[y_max_index+1]) - Math.min(arr[y_max_index-1], arr[y_max_index+1]);
        }

        area = (x_max * y_max) - (tmp_x*tmp_y);
        System.out.println(area*k);
        sc.close();
    }
}