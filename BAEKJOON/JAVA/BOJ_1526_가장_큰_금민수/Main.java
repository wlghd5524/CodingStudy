package BOJ_1526_가장_큰_금민수;
import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int n = input.nextInt();
		int result = 0;
		for(int i = n;i>=0;i--) {
			String s = Integer.toString(i);
			boolean no = false;
			for(int j = 0;j<s.length();j++) {
				if(s.charAt(j)!='4' && s.charAt(j)!='7') {
					no = true;
					break;
				}
			}
			if(no) {
				no = false;
				continue;
			}
			result = i;
            break;
		}
		System.out.println(result);
		input.close();
	}
}
