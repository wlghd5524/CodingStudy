package BOJ_10101_삼각형_외우기; 
import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int a = input.nextInt();
        int b = input.nextInt();
        int c = input.nextInt();
        if(a==b && b==c && c==60) {
            System.out.println("Equilateral");
        }
        else if(a+b+c == 180) {
            if(a==b || b==c || a==c) {
                System.out.println("Isosceles");
            }
            else {
                System.out.println("Scalene");
            }
        }
        else {
            System.out.println("Error");
        }
        input.close();
    }
}
