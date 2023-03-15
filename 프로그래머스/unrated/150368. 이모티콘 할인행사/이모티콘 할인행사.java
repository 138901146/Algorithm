class Solution {
    public int[] solution(int[][] users, int[] emoticons) {
        int[] answer = new int[2], salePercent=new int[emoticons.length];
        
        for(int flag=0;flag<(1<<(2*emoticons.length));flag++) {
            int temp=flag, plusCount=0, salesSum=0;
            
            for(int i=0;i<emoticons.length;i++) {
                salePercent[i]=10*((temp&3)+1);
                temp>>=2;
            }
            
            for(int i=0;i<users.length;i++) {
                int sum=0;
                for(int j=0;j<emoticons.length;j++)
                    if(salePercent[j]>=users[i][0])
                        sum+=(emoticons[j]/100)*(100-salePercent[j]);

                if(sum>=users[i][1])
                    plusCount++;
                else
                    salesSum+=sum;
            }
            
            if(plusCount>answer[0]) {
                answer[0]=plusCount;
                answer[1]=salesSum;
            }
            else if(plusCount==answer[0] && salesSum>answer[1])
                answer[1]=salesSum;
        }
        
        return answer;
    }
}