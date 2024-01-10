import java.util.Arrays;

class Solution {
    public int solution(int[] people, int limit) {
        int answer=0, left=0, right=people.length-1;

		Arrays.sort(people);
		
		while(left<=right) {
			int weight=people[right--];
			
			if(weight+people[left]<=limit && left<=right)
				weight+=people[left++];
			++answer;
		}

		return answer;
    }
}