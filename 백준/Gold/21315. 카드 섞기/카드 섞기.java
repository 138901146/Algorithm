import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int N=Integer.parseInt(br.readLine()), primaryK=0, secondaryK=0, index=0;
		int[] card=new int[N];
		StringTokenizer st=new StringTokenizer(br.readLine());
		for(int i=0;i<N;i++) {
			card[i]=Integer.parseInt(st.nextToken());
			
			if(card[i]==N)
				index=i;
		}
		
		while(1<<++primaryK<N-card[0]);
		while(1<<++secondaryK<index);

		System.out.println(primaryK+" "+secondaryK);
	}
}