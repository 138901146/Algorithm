import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	static int GCD(int x,int y) {
		int temp;
		
		if(x<y) {
			temp=x;
			x=y;
			y=temp;
		}
		
		while(y>0) {
			temp=x%y;
			x=y;
			y=temp;
		}
		
		return x;
	}
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		StringBuilder sb=new StringBuilder();

		int N=Integer.parseInt(br.readLine()), gcd;
		int[] arr=new int[100];
		for(int n=0;n<N;n++) {
			int count=0, max=0;
			
			st=new StringTokenizer(br.readLine());
			while(st.hasMoreTokens())
				arr[count++]=Integer.parseInt(st.nextToken());
			
			for(int i=0;i<count;i++)
				for(int j=i+1;j<count;j++) {
					gcd=GCD(arr[i],arr[j]);
					max=gcd>max?gcd:max;
				}
			
			sb.append(max+"\n");
		}
		
		System.out.print(sb.toString());
	}
}