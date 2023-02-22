import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		StringTokenizer st=new StringTokenizer(br.readLine());
		int N=Integer.parseInt(st.nextToken()), M=Integer.parseInt(st.nextToken());
		int front=0, rear=0, count=1;
		int[][] miro=new int[N][M];
		boolean[][] visited=new boolean[N][M];
		int[] queue=new int[N*M];
		
		for(int n=0;n<N;n++) {
			String str=br.readLine();
			for(int m=0;m<M;m++)
				miro[n][m]=str.charAt(m)-'0';
		}
		
		visited[0][0]=true;
		queue[rear++]=0;
		
		while(front<rear && !visited[N-1][M-1]) {
			int previousRear=rear;
			
			while(front<previousRear && !visited[N-1][M-1]) {
				int x=queue[front]/1000, y=queue[front]%1000;
				
				if(x+1<N &&  miro[x+1][y]==1 &&!visited[x+1][y]) {
					visited[x+1][y]=true;
					queue[rear++]=1000*(x+1)+y;
				}
				if(y+1<M && miro[x][y+1]==1 && !visited[x][y+1]) {
					visited[x][y+1]=true;
					queue[rear++]=1000*x+y+1;
				}
				if(x>0 &&  miro[x-1][y]==1 &&!visited[x-1][y]) {
					visited[x-1][y]=true;
					queue[rear++]=1000*(x-1)+y;
				}
				if(y>0 && miro[x][y-1]==1 && !visited[x][y-1]) {
					visited[x][y-1]=true;
					queue[rear++]=1000*x+y-1;
				}

				front++;
			}
			count++;
		}

		System.out.println(count);
	}
}