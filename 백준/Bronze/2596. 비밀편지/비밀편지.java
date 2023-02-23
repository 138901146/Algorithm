import java.util.Scanner;

public class Main {
	public static void main(String[] args){
		String[] encode= {"000000","001111","010011","011100","100110","101001","110101","111010"};
		Scanner sc=new Scanner(System.in);
		int N=sc.nextInt();
		char[] decode=new char[N];
		String input=sc.next();
		boolean decodable=true;
		
		for(int n=0;n<N;n++) {
			boolean match=false;
			for(int i=0;i<8;i++)
				if(input.substring(6*n,6*n+6).equals(encode[i])) {
					match=true;
					decode[n]=(char)('A'+i);
					break;
				}
			
			if(!match) {
				int oneCountIndex=-1;
				for(int i=0;i<8;i++) {
					int count=0;
					
					for(int j=0;j<6;j++)
						if(input.charAt(6*n+j)!=encode[i].charAt(j))
							count++;
					
					if(count==1) {
						if(oneCountIndex==-1)
							oneCountIndex=i;
						else
							oneCountIndex=-2;
					}
				}
				
				if(oneCountIndex>=0)
					decode[n]=(char)('A'+oneCountIndex);
				else {
					decodable=false;
					System.out.println(n+1);
					break;
				}
			}
		}
		
		if(decodable)
			for(int n=0;n<N;n++)
				System.out.print(decode[n]);

		sc.close();
	}
}