import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb=new StringBuilder();
		StringTokenizer st;
		int N=Integer.parseInt(br.readLine());
		int[] _switch=new int[N];
		
		st=new StringTokenizer(br.readLine());
		for(int n=0;n<N;n++)
			_switch[n]=Integer.parseInt(st.nextToken());
		
		int M=Integer.parseInt(br.readLine());
		int[] gender=new int[M];
		int[] number=new int[M];
		
		for(int m=0;m<M;m++) {
			st=new StringTokenizer(br.readLine());
			gender[m]=Integer.parseInt(st.nextToken());
			number[m]=Integer.parseInt(st.nextToken());
		}
		
		for(int m=0;m<M;m++)
			if(gender[m]==1) {
				for(int n=0;n<N;n++)
					if((n+1)%number[m]==0)
						_switch[n]++;
			}
			else {
				int count=0;
				
				while(number[m]+count<=N && number[m]-count>0)
					if(_switch[number[m]-1+count]%2!=_switch[number[m]-1-count]%2)
						break;
					else
						count++;
				
				count--;
				for(int i=number[m]-1-count;i<=number[m]-1+count;i++)
					_switch[i]++;
			}
		
		for(int n=0;n<N;n++)
			sb.append(_switch[n]%2+(n%20==19?"\n":" "));
		System.out.println(sb.toString());
	}
}