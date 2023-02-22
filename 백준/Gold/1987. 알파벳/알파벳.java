import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	static String[] board;
	static int R, C;
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer(br.readLine());
		
		R=Integer.parseInt(st.nextToken());
		C=Integer.parseInt(st.nextToken());
		board=new String[R];
		
		for(int i=0;i<R;i++)
			board[i]=br.readLine();
		
		System.out.println(maxMove(0,1<<board[0].charAt(0)-'A'));
	}
	
	static int maxMove(int index,int bit) {
		int[] move=new int[4];
		int x=index/100, y=index%100, max=0;
		
		for(int i=0;i<26;i++)
			if((bit&1<<i)!=0)
				max++;
		
		if(x>0 && (bit&(1<<board[x-1].charAt(y)-'A'))==0)
			move[0]=maxMove(100*(x-1)+y,bit|1<<(board[x-1].charAt(y)-'A'));
		if(x<R-1 && (bit&(1<<board[x+1].charAt(y)-'A'))==0)
			move[1]=maxMove(100*(x+1)+y,bit|1<<(board[x+1].charAt(y)-'A'));
		if(y>0 && (bit&(1<<board[x].charAt(y-1)-'A'))==0)
			move[2]=maxMove(100*(x)+y-1,bit|1<<(board[x].charAt(y-1)-'A'));
		if(y<C-1 && (bit&(1<<board[x].charAt(y+1)-'A'))==0)
			move[3]=maxMove(100*(x)+y+1,bit|1<<(board[x].charAt(y+1)-'A'));
		
		for(int i=0;i<4;i++)
			max=Integer.max(max, move[i]);

		return max;
	}
}