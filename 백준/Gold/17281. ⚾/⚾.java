import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	static int[] permutation=new int[]{1,2,3,4,5,6,7,8};
	
	public static void main(String[] args) throws IOException {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		int N=Integer.parseInt(br.readLine()), maxScore=0;
		int[][] order=new int[N][9];
		
		for(int n=0;n<N;n++) {
			st=new StringTokenizer(br.readLine());
			for(int i=0;i<9;i++)
				order[n][i]=Integer.parseInt(st.nextToken());
		}
		
		do {
			int score=0, innings=0, out=0, runner=0, mount=0;
			int[] base=new int[] {0,0,0};

			while(innings<N) {
				if(runner%9<3)
					mount=permutation[(runner-runner/9)%8];
				else if(runner%9>3)
					mount=permutation[(runner-runner/9-1)%8];
				else
					mount=0;
				
				switch(order[innings][mount]) {
				case 0:
					out++;
					if(out==3) {
						out=0;
						innings++;
						base[0]=base[1]=base[2]=0;
					}
					break;
				case 1:
					score+=base[2];
					base[2]=base[1];
					base[1]=base[0];
					base[0]=1;
					break;
				case 2:
					score+=base[1]+base[2];
					base[2]=base[0];
					base[1]=1;
					base[0]=0;
					break;
				case 3:
					score+=base[0]+base[1]+base[2];
					base[2]=1;
					base[1]=base[0]=0;
					break;
				case 4:
					score+=base[0]+base[1]+base[2]+1;
					base[0]=base[1]=base[2]=0;
					break;
				}
				runner++;
			}
			maxScore=Integer.max(maxScore,score);
		}
		while(nextPermutation());

		System.out.println(maxScore);
	}
	
	static boolean nextPermutation() {
		for(int i=6;i>=0;i--)
			if(permutation[i]<permutation[i+1]) {
				int j=7;
				while(permutation[j]<permutation[i])
					j--;
				int temp=permutation[i];
				permutation[i]=permutation[j];
				permutation[j]=temp;

				for(j=1;j<=(8-i)/2;j++) {
					temp=permutation[i+j];
					permutation[i+j]=permutation[8-j];
					permutation[8-j]=temp;
				}
				return true;
			}
		return false;
	}
}