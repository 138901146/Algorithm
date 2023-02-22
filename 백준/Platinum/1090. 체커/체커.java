import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		StringBuilder sb=new StringBuilder();

		int N=Integer.parseInt(br.readLine());
		int[] x=new int[N], y=new int[N], minMove=new int[N+1];
		
		for(int n=0;n<N;n++) {
			st=new StringTokenizer(br.readLine());
			x[n]=Integer.parseInt(st.nextToken());
			y[n]=Integer.parseInt(st.nextToken());
			minMove[n+1]=Integer.MAX_VALUE;
		}
		
		minMove[1]=0;
		for(int n=2;n<=N;n++)
			for(int i=0;i<N;i++)
				for(int j=0;j<N;j++) {
					int[] distance=new int[N];
					int temp=0;
					
					for(int k=0;k<N;k++)
						distance[k]=Math.abs(x[i]-x[k])+Math.abs(y[j]-y[k]);
					
					Arrays.sort(distance);
					
					for(int k=0;k<n;k++)
						temp+=distance[k];
					
					minMove[n]=Integer.min(minMove[n],temp);
				}
		
		for(int n=1;n<=N;n++)
			sb.append(minMove[n]+" ");
		System.out.println(sb.toString());
	}
}