import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		int N=Integer.parseInt(br.readLine()), count=1;
		long descending=0;
		
		if(N>1023) {
			System.out.println(-1);
			return;
		}
		
		while(count<N) {
			long temp=descending;
			int digit=0;

			while(temp%10+1==(temp/10)%10) {
				temp/=10;
				digit++;
			}

			if(temp==9) {
				descending=0;
				for(int i=digit+1;i>0;i--) {
					descending+=i;
					descending*=10;
				}
			}
			else {
				temp=1;
				for(int i=0;i<digit;i++)
					temp*=10;
				descending+=temp;
				descending-=descending%temp;
				temp=0;
				for(int i=digit-1;i>=0;i--) {
					temp*=10;
					temp+=i;
				}
				descending+=temp;
			}

			count++;
		}
		
		System.out.println(descending);
	}
}