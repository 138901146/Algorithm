import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.StringTokenizer;

public class Main {
	static HashMap<String,Integer> map;
	static int[] parent;
	static int[] child;

	public static void main(String[] args) throws IOException {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		StringBuilder sb=new StringBuilder();
		String[] name=new String[2];
		int[] index=new int[2];
		
		int T=Integer.parseInt(br.readLine());
		
		for(int t=0;t<T;t++) {
			int F=Integer.parseInt(br.readLine());
			int count=0;
			
			map=new HashMap<>();
			parent=new int[F<<1];
			child=new int[F<<1];
			
			for(int f=0;f<F;f++) {
				st=new StringTokenizer(br.readLine());
				
				for(int i=0;i<2;i++) {
					name[i]=st.nextToken();
					index[i]=map.getOrDefault(name[i],-1);
					
					if(index[i]<0) {
						index[i]=count++;
						parent[index[i]]=index[i];
						child[index[i]]=1;
						map.put(name[i],index[i]);
					}
				}
				
				if(findParent(index[0])!=findParent(index[1]))
					union(index[0],index[1]);

				sb.append(child[findParent(index[0])]).append("\n");
			}
		}
		
		System.out.print(sb.toString());
	}
	
	static int findParent(int x) {
		if(parent[x]==x)
			return x;
		return parent[x]=findParent(parent[x]);
	}
	
	static void union(int x,int y) {
		int parentX=findParent(x), parentY=findParent(y);
		
		child[parentX]+=child[parentY];
		parent[parentY]=parentX;
	}
}