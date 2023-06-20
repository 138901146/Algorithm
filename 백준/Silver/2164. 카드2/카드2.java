import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));

		int N=Integer.parseInt(br.readLine());
		
		if(N<3)
			System.out.println(N);
		else {
			int index=0;
			
			while(1<<++index<N);
			N-=1<<index-1;
			
			System.out.println(N<<1);
		}
	}
}