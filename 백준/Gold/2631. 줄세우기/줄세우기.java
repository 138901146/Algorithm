import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		
		int N=Integer.parseInt(br.readLine()), max=1;
		int[] children=new int[N], LIS=new int[N];
		
		for(int n=0;n<N;n++)
			children[n]=Integer.parseInt(br.readLine());
		
		for(int i=N-1;i>=0;i--) {
			LIS[i]=1;
			for(int j=i+1;j<N;j++)
				LIS[i]=children[i]<children[j]&&LIS[i]<=LIS[j]+1?LIS[j]+1:LIS[i];
			max=LIS[i]>max?LIS[i]:max;
		}
		
		System.out.println(N-max);
	}
}