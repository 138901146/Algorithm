class Solution {
    public int solution(String word) {
        boolean found=false;
		char[] str = { 'X', 'X', 'X', 'X', 'X' };
		int answer = 0;

		while (word.length() < 5)
			word = word.concat("X");

		while (!found) {
			int i = 4;
			answer++;

			if (str[4] == 'X') {
				while (i > 0)
					if (str[i - 1] == 'X')
						i--;
					else
						break;
				str[i] = 'A';
			} else {
				switch (str[i]) {
				case 'A':
					str[i] = 'E';
					break;
				case 'E':
					str[i] = 'I';
					break;
				case 'I':
					str[i] = 'O';
					break;
				case 'O':
					str[i] = 'U';
					break;
				case 'U':
					while (i > 0 && str[i] == 'U') {
						str[i] = 'X';
						i--;
					}
					switch (str[i]) {
					case 'A':
						str[i] = 'E';
						break;
					case 'E':
						str[i] = 'I';
						break;
					case 'I':
						str[i] = 'O';
						break;
					case 'O':
						str[i] = 'U';
						break;
					default:
						return -1;
					}
					break;
				}
			}
			found=true;
			for(int j=0;j<5;j++)
				if(word.charAt(j)!=str[j])
					found=false;
		}

		return answer;
    }
}