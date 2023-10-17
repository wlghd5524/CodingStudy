import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int X = input.nextInt();
		int[] dp = new int[X + 1];
		dp[X] = 0;
		for (int i = 1; i < X; i++) {
			dp[i] = Integer.MAX_VALUE; // X를 제외한 모든 dp 값을 최댓값으로 초기화
		}
		for (; X != 1; X--) { // 최소값 찾기
			if (X % 3 == 0) { // 3으로 나누어 떨어질 때
				dp[X / 3] = Math.min(dp[X / 3], dp[X] + 1); // 원래 저장되어 있던 dp값과 연산 이후 값 중 작은 값을 dp에 저장
			}
			if (X % 2 == 0) { // 2으로 나누어 떨어질 때
				dp[X / 2] = Math.min(dp[X / 2], dp[X] + 1);
			}
			if (X > 1) {
				dp[X - 1] = Math.min(dp[X - 1], dp[X] + 1);
			}
		}
		System.out.println(dp[1]);
	}
}
