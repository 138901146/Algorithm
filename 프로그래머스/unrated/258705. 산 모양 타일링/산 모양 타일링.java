public class Solution {

    public int solution(int n, int[] tops) {
        int[][] dp = new int[2][2];
        int current = 1;
        int previous = 0;

        dp[0][0] = 2 + tops[0];
        dp[0][1] = 1;
        for (int i = 1; i < n; ++i, current^=1, previous^=1) {
            dp[current][0] = (dp[previous][0] * (2 + tops[i]) + dp[previous][1] * (1 + tops[i])) % 10007;
            dp[current][1] = (dp[previous][0] + dp[previous][1]) % 10007;
        }

        return (dp[n & 1 ^ 1][0] + dp[n & 1 ^ 1][1]) % 10007;
    }
}