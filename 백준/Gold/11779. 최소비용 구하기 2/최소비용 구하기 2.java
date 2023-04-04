import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	static int[] city, pq;
	static int size=1;
	
	static void add(int value) {
		pq[size++]=value;
		int index=size-1;
		
		while(index>1)
			if(city[pq[index]]<=city[pq[index>>1]]) {
				int temp=pq[index];
				pq[index]=pq[index>>1];
				pq[index>>1]=temp;
				index>>=1;
			}
			else
				break;
	}
	
	static int get() {
		boolean set=false;
		int value=pq[1], index=1;
		pq[1]=pq[--size];
		
		while(index<size && !set) {
			if((index<<1)+1<size) {
				if(city[pq[(index<<1)+1]]<city[pq[index<<1]]) {
					if(city[pq[index]]>=city[pq[(index<<1)+1]]) {
						int temp=pq[index];
						pq[index]=pq[(index<<1)+1];
						pq[(index<<1)+1]=temp;
						index=(index<<1)+1;
					}
					else
						set=true;
				}
				else {
					if(city[pq[index]]>=city[pq[index<<1]]) {
						int temp=pq[index];
						pq[index]=pq[index<<1];
						pq[index<<1]=temp;
						index<<=1;
					}
					else
						set=true;
				}
			}
			else if((index<<1)+1==size) {
				if(city[pq[index]]>=city[pq[index<<1]]) {
					int temp=pq[index];
					pq[index]=pq[index<<1];
					pq[index<<1]=temp;
					index<<=1;
				}
				else
					set=true;
			}
			else
				set=true;
		}
		
		return value;
	}
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		StringBuilder sb=new StringBuilder();
		
		int n=Integer.parseInt(br.readLine());
		int m=Integer.parseInt(br.readLine());

		city=new int[n+1];
		pq=new int[1000*(n+1)];
		int[] previous=new int[n+1];
		int[] busCount=new int[n+1];
		int[][] bus=new int[m][3];
		int[][][] localBus=new int[n+1][][];
		
		for(int i=1;i<=n;i++)
			city[i]=1<<29;
		
		for(int i=0;i<m;i++) {
			st=new StringTokenizer(br.readLine());
			for(int j=0;j<3;j++)
				bus[i][j]=Integer.parseInt(st.nextToken());
			busCount[bus[i][0]]++;
		}
		
		st=new StringTokenizer(br.readLine());
		int source=Integer.parseInt(st.nextToken());
		int destination=Integer.parseInt(st.nextToken());
		
		for(int i=1;i<=n;i++) {
			localBus[i]=new int[busCount[i]][2];
			busCount[i]=0;
			previous[i]=source;
		}
		
		for(int i=0;i<m;i++) {
			localBus[bus[i][0]][busCount[bus[i][0]]][0]=bus[i][1];
			localBus[bus[i][0]][busCount[bus[i][0]]++][1]=bus[i][2];
		}
		
		city[source]=0;
		for(int i=0;i<busCount[source];i++)
			if(localBus[source][i][1]<city[localBus[source][i][0]])
				city[localBus[source][i][0]]=localBus[source][i][1];

		for(int i=1;i<=n;i++)
			add(i);
		
		while(size>1) {
			int target=get();

			for(int i=0;i<busCount[target];i++)
				if(city[localBus[target][i][0]]>city[target]+localBus[target][i][1]) {
					city[localBus[target][i][0]]=city[target]+localBus[target][i][1];
					previous[localBus[target][i][0]]=target;
					add(localBus[target][i][0]);
				}
		}
		
		int temp=destination, move=0;
		while(temp!=source) {
			temp=previous[temp];
			move++;
		}
		sb.append(city[destination]+"\n"+(move+1)+"\n"+source+" ");
		int[] route=new int[move+1];
		temp=destination;
		while(temp!=source) {
			route[--move]=temp;
			temp=previous[temp];
		}
		for(int i=0;route[i]!=destination;i++)
			sb.append(route[i]+" ");
		sb.append(destination);

		System.out.println(sb.toString());
	}
}