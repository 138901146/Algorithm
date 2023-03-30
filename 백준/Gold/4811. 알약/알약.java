import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb=new StringBuilder();
		
		int N;
		long[][] method=new long[31][31];
		
		for(int i=1;i<31;i++) {
			method[i][0]=1;
			for(int j=1;j<=i;j++)
				method[i][j]=method[i-1][j]+method[i][j-1];
		}
		
		N=Integer.parseInt(br.readLine());
		while(N>0) {
			sb.append(method[N][N]+"\n");
			N=Integer.parseInt(br.readLine());
		}
		
		System.out.println(sb.toString());
	}
}