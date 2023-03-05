import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer(br.readLine());
		
		int R=Integer.parseInt(st.nextToken()), C=Integer.parseInt(st.nextToken());
		char[][] map=new char[R][C+1];
		int[] waterQueue=new int[R*C], hedgehogQueue=new int[R*C];
		boolean[][] visited=new boolean[R][C];
		int count=0, waterFront=0, waterRear=0, hedgehogFront=0, hedgehogRear=0;
		boolean arrived=false;
		
		for(int r=0;r<R;r++) {
			String str=br.readLine();
			map[r]=str.toCharArray();
			for(int c=0;c<C;c++)
				if(map[r][c]=='*')
					waterQueue[waterRear++]=r<<6|c;
				else if(map[r][c]=='S') {
					visited[r][c]=true;
					hedgehogQueue[hedgehogRear++]=r<<6|c;
					map[r][c]='.';
				}
		}

		while(hedgehogFront<hedgehogRear) {
			int previousRear=waterRear;
			
			while(waterFront<previousRear)
			{
				int y=waterQueue[waterFront]>>6, x=waterQueue[waterFront]&(1<<6)-1;

				if(y>0 && map[y-1][x]=='.')
				{
					map[y-1][x]='*';
					waterQueue[waterRear++]=(y-1)<<6|x;
				}
				if(y<R-1 && map[y+1][x]=='.')
				{
					map[y+1][x]='*';
					waterQueue[waterRear++]=(y+1)<<6|x;
				}
				if(x>0 && map[y][x-1]=='.')
				{
					map[y][x-1]='*';
					waterQueue[waterRear++]=y<<6|x-1;
				}
				if(x<C-1 && map[y][x+1]=='.')
				{
					map[y][x+1]='*';
					waterQueue[waterRear++]=y<<6|x+1;
				}
				waterFront++;
			}
			
			previousRear=hedgehogRear;
			
			while(hedgehogFront<previousRear)
			{
				int y=hedgehogQueue[hedgehogFront]>>6, x=hedgehogQueue[hedgehogFront]&(1<<6)-1;

				if(y>0)
					if(map[y-1][x]=='D')
					{
						arrived=true;
						break;
					}
					else if(!visited[y-1][x] && map[y-1][x]=='.')
					{
						visited[y-1][x]=true;
						hedgehogQueue[hedgehogRear++]=(y-1)<<6|x;
					}

				if(y<R-1)
					if(map[y+1][x]=='D')
					{
						arrived=true;
						break;
					}
					else if(!visited[y+1][x] && map[y+1][x]=='.')
					{
						visited[y+1][x]=true;
						hedgehogQueue[hedgehogRear++]=(y+1)<<6|x;
					}

				if(x>0)
					if(map[y][x-1]=='D')
					{
						arrived=true;
						break;
					}
					else if(!visited[y][x-1] && map[y][x-1]=='.')
					{
						visited[y][x-1]=true;
						hedgehogQueue[hedgehogRear++]=y<<6|x-1;
					}

				if(x<C-1)
					if(map[y][x+1]=='D')
					{
						arrived=true;
						break;
					}
					else if(!visited[y][x+1] && map[y][x+1]=='.')
					{
						visited[y][x+1]=true;
						hedgehogQueue[hedgehogRear++]=y<<6|x+1;
					}

				hedgehogFront++;
			}

			count++;
			if(arrived)
				break;
		}

		System.out.println(arrived?count:"KAKTUS");
	}
}