class Solution {
    public int[] solution(long[] numbers) {
        int[] answer=new int[numbers.length], bit=new int[64], left=new int[64], right=new int[64], level=new int[64];
        
        for(int i=1;i<64;i++) {
            int count=0, temp=i;
            while((temp&1)==0) {
                count++;
                temp>>=1;
            }
            level[i]=count;
        }
        
        for(int i=0;i<numbers.length;i++) {
            answer[i]=1;
            long temp=numbers[i];
            int size=0;
            
            while(temp>0) {
                size++;
                temp>>=1;
            }
            
            temp=0;
            while(size>=1<<temp)
                temp++;
            size=(1<<temp)-1;

            temp=numbers[i];
            for(int j=size;j>0;j--,temp>>=1) {
                left[j]=right[j]=0;
                bit[j]=(int)(temp&1L);
            }
            
        for(int j=2;j<=size;j++)
            left[j]=bit[j-1]==1?0:left[j-1]+1;
        for(int j=size-1;j>0;j--)
            right[j]=bit[j+1]==1?0:right[j+1]+1;

        for(int j=1;j<=size;j++)
            if(bit[j]==0 && (left[j]<(1<<level[j])-1 || right[j]<(1<<level[j])-1)) {
                answer[i]=0;
                break;
            }
        }
        
        return answer;
    }
}