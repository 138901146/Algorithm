import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
	static int N, redCount=0, blueCount;
	static int[] a;
	static int[][] vertex;
	static int[] vertexCount;
	static int[][] red;
	static int[][] blue;

	public static void main(String[] args) throws IOException {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb=new StringBuilder();

		N=Integer.parseInt(br.readLine());
		int[][] edge=new int[N-1][2];
		a=new int[N+1];
		vertex=new int[N+1][];
		vertexCount=new int[N+1];
		red=new int[N+1][];
		blue=new int[N+1][];
		Long[] query=new Long[N+1];
		int u;
		
		StringTokenizer st=new StringTokenizer(br.readLine());
		for(int n=1;n<=N;n++) {
			a[n]=Integer.parseInt(st.nextToken());
			redCount+=a[n];
			query[n]=-1L;
		}
		blueCount=N-redCount;
		
		for(int n=0;n<N-1;n++) {
			st=new StringTokenizer(br.readLine());
			for(int i=0;i<2;i++) {
				edge[n][i]=Integer.parseInt(st.nextToken());
				vertexCount[edge[n][i]]++;
			}
		}
		
		for(int n=1;n<=N;n++) {
			vertex[n]=new int[vertexCount[n]];
			red[n]=new int[vertexCount[n]];
			blue[n]=new int[vertexCount[n]];
			vertexCount[n]=0;
		}
		
		for(int n=0;n<N-1;n++) {
			red[edge[n][0]][vertexCount[edge[n][0]]]=blue[edge[n][0]][vertexCount[edge[n][0]]]=-1;
			vertex[edge[n][0]][vertexCount[edge[n][0]]++]=edge[n][1];
			red[edge[n][1]][vertexCount[edge[n][1]]]=blue[edge[n][1]][vertexCount[edge[n][1]]]=-1;
			vertex[edge[n][1]][vertexCount[edge[n][1]]++]=edge[n][0];
		}
		
		int Q=Integer.parseInt(br.readLine());
		
		for(int q=0;q<Q;q++) {
			u=Integer.parseInt(br.readLine());
			
			if(query[u]==-1) {
				query[u]=0L;
				
				for(int i=0;i<vertexCount[u];i++) {
					if(red[u][i]==-1)
						dfs(u,i);
					
					query[u]+=Long.valueOf(redCount-a[u]-red[u][i])*blue[u][i];
					query[u]+=Long.valueOf(blueCount-(a[u]^1)-blue[u][i])*red[u][i];
				}
				
				query[u]>>=1;
			}
			
			sb.append(query[u]).append("\n");
		}
		
		System.out.print(sb.toString());
	}
	
	public static void dfs(int parent,int index) {
		int v=vertex[parent][index];

		red[parent][index]=a[v];
		blue[parent][index]=a[v]^1;

		for(int i=0;i<vertexCount[v];i++)
			if(vertex[v][i]!=parent)
			{
				if(red[v][i]==-1)
					dfs(v,i);
				
				red[parent][index]+=red[v][i];
				blue[parent][index]+=blue[v][i];
			}
	}
}