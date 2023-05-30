import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	static int[] start, end, stemp, etemp;
	
	static void merge(int left,int right) {
		int i=left, mid=(left+right)/2, j=mid+1;
		
		for(int k=left;k<=right;k++)
			if(j>right) {
				stemp[k]=start[i];
				etemp[k]=end[i++];
			}
			else if(i>mid || end[i]>end[j] || end[i]==end[j] && start[i]>start[j]) {
				stemp[k]=start[j];
				etemp[k]=end[j++];
			}
			else {
				stemp[k]=start[i];
				etemp[k]=end[i++];
			}
		
		for(int k=left;k<=right;k++) {
			start[k]=stemp[k];
			end[k]=etemp[k];
		}
	}
	
	static void mergeSort(int left,int right) {
		if(left<right) {
			int mid=(left+right)/2;
			mergeSort(left,mid);
			mergeSort(mid+1,right);
			merge(left,right);
		}
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;

		int N=Integer.parseInt(br.readLine()), count=0, last=-1;
		start=new int[N];
		end=new int[N];
		stemp=new int[N];
		etemp=new int[N];
		
		for(int n=0;n<N;n++) {
			st=new StringTokenizer(br.readLine());
			start[n]=Integer.parseInt(st.nextToken());
			end[n]=Integer.parseInt(st.nextToken());
		}
		
		mergeSort(0,N-1);
		
		for(int n=0;n<N;n++)
			if(start[n]>=last) {
				count++;
				last=end[n];
			}

		System.out.println(count);
	}
}