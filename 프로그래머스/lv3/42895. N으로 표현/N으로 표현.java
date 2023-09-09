class Solution {
    public int solution(int N, int number) {
        int[] count=new int[100000];
		int[] multi=new int[5];
		int tenPlusOne=1;
		
		count[N]=1;
		multi[0]=N;
		for(int i=11*N;i<100000;i=i*10+N) {
			count[i]=count[(i-N)/10]+1;
			multi[tenPlusOne++]=i;
		}
		
		for(int i=0;i<8;i++)
			for(int j=1;j<multi[tenPlusOne-1];j++)
				if(count[j]>0 && count[j]<8) {
					for(int k=1;k<multi[tenPlusOne-1];k++)
						if(count[k]>0 && count[j]+count[k]<9) {
							if(j-k>0)
								count[j-k]=count[j-k]==0 || count[j-k]>count[j]+count[k]?count[j]+count[k]:count[j-k];
							if(j+k<32001)
								count[j+k]=count[j+k]==0 || count[j+k]>count[j]+count[k]?count[j]+count[k]:count[j+k];
							if(j/k>0)
								count[j/k]=count[j/k]==0 || count[j/k]>count[j]+count[k]?count[j]+count[k]:count[j/k];
							if(j*k<32001)
								count[j*k]=count[j*k]==0 || count[j*k]>count[j]+count[k]?count[j]+count[k]:count[j*k];
						}
				}
		
		return count[number]==0 || count[number]>8?-1:count[number];
    }
}