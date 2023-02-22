import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution {
	static int N;
	static int[][] distance;
	
    public static int backtrack(int current,int searched,int searchCount,int sum) {
        if(searchCount==N)
            return sum+distance[current][N+1];
        else if(searchCount==0)
        	sum=0;

        int min=Integer.MAX_VALUE;

        for(int i=1;i<=N;i++)
    	    if((searched&(1<<i))==0)
    	    	min=Integer.min(min, backtrack(i,searched|(1<<i),searchCount+1,sum+distance[current][i]));

        return min;
    }
    
	public static void main(String args[]) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		StringBuilder sb=new StringBuilder();

		int T=Integer.parseInt(br.readLine());

		for(int t=1;t<=T;t++) {
			N=Integer.parseInt(br.readLine());
            int[][] locate=new int[N+2][2];
            distance=new int[N+2][N+2];
            
            st=new StringTokenizer(br.readLine());
            for(int i=0;i<2;i++)
                locate[0][i]=Integer.parseInt(st.nextToken());
            for(int i=0;i<2;i++)
                locate[N+1][i]=Integer.parseInt(st.nextToken());
            for(int n=1;n<=N;n++)
                for(int i=0;i<2;i++)
                    locate[n][i]=Integer.parseInt(st.nextToken());
            
            for(int i=0;i<N+2;i++) {
                distance[i][i]=0;
                for(int j=i+1;j<N+2;j++)
                    distance[i][j]=distance[j][i]=Math.abs(locate[i][0]-locate[j][0])+Math.abs(locate[i][1]-locate[j][1]);
            }

            sb.append("#"+t+" "+backtrack(0,0,0,Integer.MAX_VALUE)+"\n");
		}
		
		System.out.println(sb.toString());
	}
}