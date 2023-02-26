import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		int N=Integer.parseInt(br.readLine());
		int[][] grid=new int[N+1][N+1];
		int[][][] method=new int[N+1][N+1][3];
		
		for(int i=1;i<=N;i++) {
			st=new StringTokenizer(br.readLine());
			for(int j=1;j<=N;j++)
				grid[i][j]=Integer.parseInt(st.nextToken());
		}
		
		for(int i=2;i<=N;i++)
			if(grid[1][i]==0)
				method[1][i][0]=1;
			else
				break;
		
		for(int i=2;i<=N;i++)
			for(int j=1;j<=N;j++)
				if(grid[i][j]==0) {
					if(grid[i][j-1]==0)
						method[i][j][0]+=method[i][j-1][0]+method[i][j-1][2];
					if(grid[i-1][j]==0)
						method[i][j][1]+=method[i-1][j][1]+method[i-1][j][2];
					if(grid[i-1][j-1]==0 && grid[i-1][j]==0 && grid[i][j-1]==0)
						method[i][j][2]+=method[i-1][j-1][0]+method[i-1][j-1][1]+method[i-1][j-1][2];
				}
		
		System.out.println(method[N][N][0]+method[N][N][1]+method[N][N][2]);
	}
}