import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws NumberFormatException, IOException  {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        
        int N=Integer.parseInt(br.readLine());
        int[][] cost=new int[N][3];
        
        for(int n=0;n<N;n++) {
        	st=new StringTokenizer(br.readLine());
        	for(int i=0;i<3;i++)
        		cost[n][i]=Integer.parseInt(st.nextToken());
        }
        for(int n=1;n<N;n++) {
        	cost[n][0]+=cost[n-1][1]<cost[n-1][2]?cost[n-1][1]:cost[n-1][2];
        	cost[n][1]+=cost[n-1][0]<cost[n-1][2]?cost[n-1][0]:cost[n-1][2];
        	cost[n][2]+=cost[n-1][0]<cost[n-1][1]?cost[n-1][0]:cost[n-1][1];
        }
        
        System.out.println(cost[N-1][0]<=cost[N-1][1]&&cost[N-1][0]<=cost[N-1][2]?cost[N-1][0]:cost[N-1][1]<=cost[N-1][0]&&cost[N-1][1]<=cost[N-1][2]?cost[N-1][1]:cost[N-1][2]);
    }
}