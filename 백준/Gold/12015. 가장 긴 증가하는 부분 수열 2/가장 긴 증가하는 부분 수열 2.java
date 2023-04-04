import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		int length=0, A;
		int[] LIS;
		
		int N=Integer.parseInt(br.readLine());
		LIS=new int[N];
		
		StringTokenizer st=new StringTokenizer(br.readLine());
		for(int i=0;i<N;i++) {
			int left=0, right=length, mid;
			LIS[i]=1<<25;
			A=Integer.parseInt(st.nextToken());
			
			while(left<right) {
				mid=(left+right)/2;
				if(LIS[mid]>A)
					right=mid-1;
				else if(LIS[mid]<A)
					left=mid+1;
				else
					break;
			}
			mid=(left+right)/2;
			
			if(A<=LIS[mid])
				LIS[mid]=A;
			else
				LIS[mid+1]=A;
			if(mid==length)
				length++;
		}
		
		System.out.println(length);
	}
}