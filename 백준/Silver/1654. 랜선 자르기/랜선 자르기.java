import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer(br.readLine());
		int K=Integer.parseInt(st.nextToken());
		long N=Long.parseLong(st.nextToken());
		long[] lan=new long[K];
		long min=0, max=999999999999L, mid, num;
		
		for(int k=0;k<K;k++)
			lan[k]=Long.parseLong(br.readLine());
		
		do {
			num=0;
			mid=(min+max)/2;
			
			for(int k=0;k<K;k++)
				num+=lan[k]/mid;
			
			if(N>num)
				max=mid;
			else
				min=mid;
		}
		while((min+max)/2!=mid);
		
		System.out.println(mid);
	}
}