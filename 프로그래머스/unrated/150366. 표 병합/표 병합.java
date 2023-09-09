import java.util.StringTokenizer;

class Solution {
	int[][] parent = new int[51][51];

	int findParent(int r, int c) {
		if (parent[r][c] == 100 * r + c)
			return parent[r][c];

		return parent[r][c] = findParent(parent[r][c] / 100, parent[r][c] % 100);
	}

	void union(int r1,int c1,int r2,int c2) {
		int root=findParent(r1,c1), temp=findParent(r2,c2);
		
		if(temp!=root)
			parent[temp/100][temp%100]=root;
	}
    
	public String[] solution(String[] commands) {
		int size = 0, r1, r2, c1, c2, count, root, temp, absorb;
		String value1, value2;
		StringTokenizer st;
		String[][] sheet = new String[51][51];
		int[] queue = new int[2500];
		for (int i = 0; i < commands.length; i++)
			if (commands[i].charAt(0) == 'P')
				size++;
		String[] answer = new String[size];
		size = 0;

		for (int r = 1; r < 51; r++)
			for (int c = 1; c < 51; c++)
				parent[r][c] = 100 * r + c;

		for (int i = 0; i < commands.length; i++) {
			st = new StringTokenizer(commands[i]);
			switch (commands[i].charAt(1)) {
			case 'P':
				if (st.countTokens() == 4) {
					st.nextToken();
					r1 = Integer.parseInt(st.nextToken());
					c1 = Integer.parseInt(st.nextToken());
					value1 = st.nextToken();
					root = findParent(r1, c1);

					sheet[root / 100][root % 100] = value1;
				} else {
					st.nextToken();
					value1 = st.nextToken();
					value2 = st.nextToken();

					for (int r = 1; r < 51; r++)
						for (int c = 1; c < 51; c++)
							if (sheet[r][c] != null && sheet[r][c].equals(value1))
								sheet[r][c] = value2;
				}
				break;
			case 'E':
				st.nextToken();
				r1 = Integer.parseInt(st.nextToken());
				c1 = Integer.parseInt(st.nextToken());
				r2 = Integer.parseInt(st.nextToken());
				c2 = Integer.parseInt(st.nextToken());

				root = findParent(r1, c1);
				absorb = findParent(r2, c2);
				count = 0;
				value1 = sheet[root / 100][root % 100] == null ? sheet[absorb / 100][absorb % 100]
						: sheet[root / 100][root % 100];


                union(r1,c1,r2,c2);
                
				sheet[root/100][root%100] = value1;
				break;
			case 'N':
				st.nextToken();
				r1 = Integer.parseInt(st.nextToken());
				c1 = Integer.parseInt(st.nextToken());

				root = findParent(r1, c1);
				value1 = sheet[root / 100][root % 100];

				count = 0;
				for (int r = 1; r < 51; r++)
					for (int c = 1; c < 51; c++)
						if ((r != r1 || c != c1) && findParent(r, c) == root)
							queue[count++] = 100 * r + c;

				for (int j = 0; j < count; j++) {
					parent[queue[j] / 100][queue[j] % 100] = queue[j];
					sheet[queue[j] / 100][queue[j] % 100] = null;
				}

				parent[r1][c1] = 100 * r1 + c1;
				sheet[r1][c1] = value1;
				break;
			case 'R':
				st.nextToken();
				r1 = Integer.parseInt(st.nextToken());
				c1 = Integer.parseInt(st.nextToken());
				root = findParent(r1, c1);

				answer[size++] = sheet[root / 100][root % 100] == null ? "EMPTY" : sheet[root / 100][root % 100];
				break;
			}
		}

		return answer;
	}
}