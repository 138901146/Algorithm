class Solution {
    public long solution(int cap, int n, int[] deliveries, int[] pickups) {
        int deliveriesTop=n-1, pickupsTop=n-1, truck;
        long answer = 0;
        
        while(deliveriesTop>=0 && deliveries[deliveriesTop]==0)
            deliveriesTop--;
        while(pickupsTop>=0 && pickups[pickupsTop]==0)
            pickupsTop--;
        while(deliveriesTop>=0 || pickupsTop>=0) {
            answer+=2*(Integer.max(deliveriesTop,pickupsTop)+1);
            if(deliveriesTop>=0) {
                truck=0;
                while(deliveriesTop>=0 && cap-truck>=deliveries[deliveriesTop])
                    truck+=deliveries[deliveriesTop--];
                if(deliveriesTop>=0 && truck<cap)
                    deliveries[deliveriesTop]-=cap-truck;
            }
            if(pickupsTop>=0) {
                truck=0;
                while(pickupsTop>=0 && cap-truck>=pickups[pickupsTop])
                    truck+=pickups[pickupsTop--];
                if(pickupsTop>=0 && truck<cap)
                    pickups[pickupsTop]-=cap-truck;
            }
        }
        
        return answer;
    }
}