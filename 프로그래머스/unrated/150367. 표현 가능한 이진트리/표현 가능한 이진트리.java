class Solution {
    public int[] solution(long[] numbers) {
        int[] answer=new int[numbers.length], bit=new int[64], level=new int[64], queue=new int[64];
        
        for(int i=1;i<64;i++) {
            int count=0, temp=i;
            while((temp&1)==0) {
                count++;
                temp>>=1;
            }
            level[i]=count;
        }
        
        for(int i=0;i<numbers.length;i++) {
            long temp=numbers[i];
            int size=0, front=0, rear=0, count=0;
            
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
                bit[j]=(int)(temp&1L);
                count+=bit[j];
            }
            
            if(bit[(size+1)/2]==1)
                queue[rear++]=(size+1)/2;
            while(front<rear) {
                if(level[queue[front]]>0) {
                    if(bit[queue[front]+(1<<level[queue[front]]-1)]==1)
                        queue[rear++]=queue[front]+(1<<level[queue[front]]-1);
                    if(bit[queue[front]-(1<<level[queue[front]]-1)]==1)
                        queue[rear++]=queue[front]-(1<<level[queue[front]]-1);
                }
                front++;
            }
            
            answer[i]=count==rear?1:0;
        }
        
        return answer;
    }
}