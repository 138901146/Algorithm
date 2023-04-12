import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer(br.readLine());
		StringBuilder sb=new StringBuilder();
		
		int N=Integer.parseInt(st.nextToken()), M=Integer.parseInt(st.nextToken()), front=0, rear=0, count=1;
		int[] primitiveCount=new int[N+1], definitiveCount=new int[N+1], queue=new int[N], subject=new int[N+1];
		int[][] definitive=new int[N+1][], order=new int[M][2];
		
		for(int m=0;m<M;m++) {
			st=new StringTokenizer(br.readLine());
			for(int i=0;i<2;i++)
				order[m][i]=Integer.parseInt(st.nextToken());
			primitiveCount[order[m][1]]++;
			definitiveCount[order[m][0]]++;
		}
		
		for(int n=1;n<=N;n++) {
			definitive[n]=new int[definitiveCount[n]];
			definitiveCount[n]=0;
			if(primitiveCount[n]==0)
				queue[rear++]=n;
		}
		
		for(int m=0;m<M;m++)
			definitive[order[m][0]][definitiveCount[order[m][0]]++]=order[m][1];
		
		
		while(front<rear) {
			int previousRear=rear;
			
			while(front<previousRear) {
				subject[queue[front]]=count;
				for(int i=0;i<definitiveCount[queue[front]];i++) {
					primitiveCount[definitive[queue[front]][i]]--;
					if(primitiveCount[definitive[queue[front]][i]]==0)
						queue[rear++]=definitive[queue[front]][i];
				}

					front++;
			}

				count++;
		}
		
		for(int n=1;n<=N;n++)
			sb.append(subject[n]+" ");
		
		System.out.println(sb.toString());
	}
}