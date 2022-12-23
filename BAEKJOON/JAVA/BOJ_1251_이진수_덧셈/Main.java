package BOJ_1251_이진수_덧셈;
import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        String a = input.next();
        String b = input.next();
        while(a.length()!=b.length()) {
            if(a.length() > b.length()) {
                b = "0"+b;
            }
            else {
                a = "0"+a;
            }
        }
        StringBuffer sbf = new StringBuffer(a);
        a = sbf.reverse().toString();
        sbf = new StringBuffer(b);
        b = sbf.reverse().toString();
        String result = "0";
        for(int i = 0;i<a.length();i++) {
            int tmp = (a.charAt(i)-'0') + (b.charAt(i)-'0') + result.charAt(i)-'0';
            if(tmp>1) {
                tmp -= 2;
                result += "1";
            }
            else {
                result += "0";
            }
            StringBuilder sbd = new StringBuilder(result);
            sbd.setCharAt(i, (char)(tmp+'0'));
            result = sbd.toString();
        }
        if(result.length()>1) {
            while(result.charAt(result.length()-1)=='0' && result.length()!=1) {
                result = result.substring(0,result.length()-1);
            }
        }
        sbf = new StringBuffer(result);
        result = sbf.reverse().toString();
        System.out.print(result);
        input.close();
    }
}