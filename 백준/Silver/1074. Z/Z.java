import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer(br.readLine());

		int N=Integer.parseInt(st.nextToken());
		int r=Integer.parseInt(st.nextToken());
		int c=Integer.parseInt(st.nextToken());
		int x=0, y=0, order=0;
		
		N--;
		while(x!=r || y!=c) {
			int shift=1<<N;
			
			if(x+shift<=r && y+shift<=c) {
				order+=3*shift*shift;
				x+=shift;
				y+=shift;
			}
			else if(x+shift<=r) {
				order+=2*shift*shift;
				x+=shift;
			}
			else if(y+shift<=c) {
				order+=shift*shift;
				y+=shift;
			}

			N--;
		}
		
		System.out.println(order);
	}
}