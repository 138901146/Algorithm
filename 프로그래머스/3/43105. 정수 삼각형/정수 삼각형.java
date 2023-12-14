class Solution {
    public int solution(int[][] triangle) {
        int answer = 0;
        
        for(int i = 1; i < triangle.length; ++i) {
            for(int j = 0; j <= i; ++j) {
                int left = j - 1 >= 0 ? j - 1 : 0, right = j == i ? j - 1 : j;
                triangle[i][j] += triangle[i - 1][left] > triangle[i - 1][right] ? triangle[i - 1][left] : triangle[i - 1][right];
                answer = Integer.max(answer, triangle[i][j]);
            }
        }
        
        return answer;
    }
}