import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
	static int N, M, CCTVCount=0;
	static int[] CCTV;
	static int[][] office;
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		StringTokenizer st=new StringTokenizer(br.readLine());
		N=Integer.parseInt(st.nextToken());
		M=Integer.parseInt(st.nextToken());
		office=new int[N][M];
		for(int n=0;n<N;n++) {
			st=new StringTokenizer(br.readLine());
			for(int m=0;m<M;m++) {
				office[n][m]=Integer.parseInt(st.nextToken());
				 
				if(office[n][m]>0 && office[n][m]<6)
					CCTVCount++;
			}
		}
		
		CCTV=new int[CCTVCount];
		CCTVCount=0;
		for(int n=0;n<N;n++)
			for(int m=0;m<M;m++)
				if(office[n][m]>0 && office[n][m]<6)
					CCTV[CCTVCount++]=10*n+m;

		System.out.println(blindSpot(0));
	}
	
	static int blindSpot(int current) {
		if(current==CCTVCount) {
			int area=0;
			
			for(int i=0;i<CCTVCount;i++) {
				int x=CCTV[i]/10, y=CCTV[i]%10;
				
				if((office[x][y]&1<<3)!=0) {
					while(x>0 && office[x-1][y]!=6) {
						x--;
						if(office[x][y]==0)
							office[x][y]=-1;
					}
					x=CCTV[i]/10;
					y=CCTV[i]%10;
				}
				if((office[x][y]&1<<4)!=0) {
					while(x<N-1 && office[x+1][y]!=6) {
						x++;
						if(office[x][y]==0)
							office[x][y]=-1;
					}
					x=CCTV[i]/10;
					y=CCTV[i]%10;
				}
				if((office[x][y]&1<<5)!=0) {
					while(y>0 && office[x][y-1]!=6) {
						y--;
						if(office[x][y]==0)
							office[x][y]=-1;
					}
					x=CCTV[i]/10;
					y=CCTV[i]%10;
				}
				if((office[x][y]&1<<6)!=0) {
					while(y<M-1 && office[x][y+1]!=6) {
						y++;
						if(office[x][y]==0)
							office[x][y]=-1;
					}
					x=CCTV[i]/10;
					y=CCTV[i]%10;
				}
			}
			
			for(int n=0;n<N;n++)
				for(int m=0;m<M;m++)
					if(office[n][m]==-1)
						office[n][m]=0;
					else if(office[n][m]==0)
						area++;

			return area;
		}
		
		int x=CCTV[current]/10, y=CCTV[current]%10, min=64, temp;
		
		switch(office[x][y]) {
		case 1:
			office[x][y]|=1<<3;
			temp=blindSpot(current+1);
			min=Integer.min(temp, min);
			office[x][y]^=1<<3;
			office[x][y]|=1<<4;
			temp=blindSpot(current+1);
			min=Integer.min(temp, min);
			office[x][y]^=1<<4;
			office[x][y]|=1<<5;
			temp=blindSpot(current+1);
			min=Integer.min(temp, min);
			office[x][y]^=1<<5;
			office[x][y]|=1<<6;
			temp=blindSpot(current+1);
			min=Integer.min(temp, min);
			office[x][y]^=1<<6;
			break;
		case 2:
			office[x][y]|=3<<3;
			temp=blindSpot(current+1);
			min=Integer.min(temp, min);
			office[x][y]^=3<<3;
			office[x][y]|=3<<5;
			temp=blindSpot(current+1);
			min=Integer.min(temp, min);
			office[x][y]^=3<<5;
			break;
		case 3:
			office[x][y]|=5<<3;
			temp=blindSpot(current+1);
			min=Integer.min(temp, min);
			office[x][y]^=5<<3;
			office[x][y]|=9<<3;
			temp=blindSpot(current+1);
			min=Integer.min(temp, min);
			office[x][y]^=9<<3;
			office[x][y]|=3<<4;
			temp=blindSpot(current+1);
			min=Integer.min(temp, min);
			office[x][y]^=3<<4;
			office[x][y]|=5<<4;
			temp=blindSpot(current+1);
			min=Integer.min(temp, min);
			office[x][y]^=5<<4;
			break;
		case 4:
			office[x][y]|=14<<3;
			temp=blindSpot(current+1);
			min=Integer.min(temp, min);
			office[x][y]^=14<<3;
			office[x][y]|=13<<3;
			temp=blindSpot(current+1);
			min=Integer.min(temp, min);
			office[x][y]^=13<<3;
			office[x][y]|=11<<3;
			temp=blindSpot(current+1);
			min=Integer.min(temp, min);
			office[x][y]^=11<<3;
			office[x][y]|=7<<3;
			temp=blindSpot(current+1);
			min=Integer.min(temp, min);
			office[x][y]^=7<<3;
			break;
		case 5:
			office[x][y]|=15<<3;
			temp=blindSpot(current+1);
			min=Integer.min(temp, min);
			office[x][y]^=15<<3;
			break;
		default:
			break;
		}

		return min;
	}
}