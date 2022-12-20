package BOJ_10769_행복한지_슬픈지;
import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        String str = input.nextLine();
        if(str.contains(":-)") == false && str.contains(":-(")==false) {
            System.out.print("none");
        }       
        else {
            int happy_cnt = 0;
            int sad_cnt = 0;
            while(str.contains(":-)") || str.contains(":-(")) {
                if(str.contains(":-)")) {
                    str = str.replaceFirst(":-\\)", "");
                    happy_cnt++;
                }
                else if(str.contains(":-(")) {
                    str = str.replaceFirst(":-\\(", "");
                    sad_cnt++;
                }
            }
            if(happy_cnt == sad_cnt) {
                System.out.print("unsure");
            }
            else if(happy_cnt > sad_cnt) {
                System.out.print("happy");
            }
            else if(happy_cnt < sad_cnt) {
                System.out.print("sad");
            }
        }
        input.close();
    }
}
