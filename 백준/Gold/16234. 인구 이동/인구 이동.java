import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer(br.readLine());
		
		int N=Integer.parseInt(st.nextToken()), L=Integer.parseInt(st.nextToken()), R=Integer.parseInt(st.nextToken()), count=0;
		int[][] country=new int[N][N], move={{-1,0},{0,-1},{0,1},{1,0}};
		int[] queue=new int[N*N];
		boolean changed=true;

		for(int i=0;i<N;i++) {
			st=new StringTokenizer(br.readLine());
			for(int j=0;j<N;j++)
				country[i][j]=Integer.parseInt(st.nextToken());
		}
		
		while(changed) {
			boolean[][] visited=new boolean[N][N];
			changed=false;
			
			for(int i=0;i<N;i++)
				for(int j=0;j<N;j++)
					if(!visited[i][j]) {
						int front=0, rear=0, sum=0;
						
						queue[rear++]=100*i+j;
						visited[i][j]=true;
						
						while(front<rear) {
							int x=queue[front]/100, y=queue[front]%100;
							
							sum+=country[x][y];
							for(int k=0;k<4;k++)
								if(x+move[k][0]>=0 && x+move[k][0]<N && y+move[k][1]>=0 && y+move[k][1]<N && !visited[x+move[k][0]][y+move[k][1]] && Math.abs(country[x][y]-country[x+move[k][0]][y+move[k][1]])>=L && Math.abs(country[x][y]-country[x+move[k][0]][y+move[k][1]])<=R) {
									visited[x+move[k][0]][y+move[k][1]]=true;
									queue[rear++]=100*(x+move[k][0])+y+move[k][1];
								}
							front++;
						}

						if(rear>1)
							changed=true;
						sum/=rear;
						for(int k=0;k<rear;k++)
							country[queue[k]/100][queue[k]%100]=sum;
						}
			count++;
		}

		System.out.println(count-1);
	}
}