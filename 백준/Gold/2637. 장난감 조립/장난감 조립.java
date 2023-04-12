import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		StringBuilder sb=new StringBuilder();
		
		int N=Integer.parseInt(br.readLine()), M=Integer.parseInt(br.readLine()), front=0, rear=0, basicCount=0;
		int[] primitiveCount=new int[N+1], definitiveCount=new int[N+1], basic=new int[100], queue=new int[100];
		int[][] toy=new int[N+1][N+1], definitive=new int[N+1][], relation=new int[M][3];
		int[][][] primitive=new int[N+1][][];
		
		for(int m=0;m<M;m++) {
			st=new StringTokenizer(br.readLine());
			for(int i=0;i<3;i++)
				relation[m][i]=Integer.parseInt(st.nextToken());
			primitiveCount[relation[m][0]]++;
			definitiveCount[relation[m][1]]++;
		}
		
		for(int n=1;n<=N;n++) {
			primitive[n]=new int[primitiveCount[n]+1][2];
			definitive[n]=new int[definitiveCount[n]];
			primitive[n][0][0]=primitiveCount[n];
			primitiveCount[n]=definitiveCount[n]=0;
		}
		
		for(int m=0;m<M;m++) {
			primitive[relation[m][0]][primitiveCount[relation[m][0]]+1][0]=relation[m][1];
			primitive[relation[m][0]][++primitiveCount[relation[m][0]]][1]=relation[m][2];
			definitive[relation[m][1]][definitiveCount[relation[m][1]]++]=relation[m][0];
		}
		
		for(int n=1;n<=N;n++)
			if(primitiveCount[n]==0) {
				queue[rear++]=n;
				toy[n][n]=1;
				basic[basicCount++]=n;
			}
		
		while(front<rear) {
			for(int i=1;i<=primitive[queue[front]][0][0];i++)
				for(int j=0;j<basicCount;j++)
					toy[queue[front]][basic[j]]+=primitive[queue[front]][i][1]*toy[primitive[queue[front]][i][0]][basic[j]];

			for(int i=0;i<definitiveCount[queue[front]];i++) {
				primitiveCount[definitive[queue[front]][i]]--;
				if(primitiveCount[definitive[queue[front]][i]]==0)
					queue[rear++]=definitive[queue[front]][i];
			}

			if(queue[front]==N)
				break;

			front++;
		}
		
		for(int i=0;i<basicCount;i++)
			if(toy[N][basic[i]]>0)
				sb.append(basic[i]+" "+toy[N][basic[i]]+"\n");
		
		System.out.print(sb.toString());
	}
}