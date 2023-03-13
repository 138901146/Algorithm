class Solution {
    public int[] solution(String today, String[] terms, String[] privacies) {
        int todayYear=2000+10*(today.charAt(2)-'0')+today.charAt(3)-'0';
        int todayMonth=10*(today.charAt(5)-'0')+today.charAt(6)-'0';
        int todayDate=10*(today.charAt(8)-'0')+today.charAt(9)-'0';
        int[] months=new int[26];
        int size=0;
        int[] answer=new int[privacies.length];
        
        for(int i=0;i<terms.length;i++)
            for(int j=2;j<terms[i].length();j++) {
                months[terms[i].charAt(0)-'A']*=10;
                months[terms[i].charAt(0)-'A']+=terms[i].charAt(j)-'0';
            }
        
        for(int i=0;i<privacies.length;i++) {
            int year=2000+10*(privacies[i].charAt(2)-'0')+privacies[i].charAt(3)-'0';
            int month=10*(privacies[i].charAt(5)-'0')+privacies[i].charAt(6)-'0';
            int date=10*(privacies[i].charAt(8)-'0')+privacies[i].charAt(9)-'0';
            int term=privacies[i].charAt(11)-'A';
            boolean append=false;
            
            date--;
            if(date<1) {
                date=28;
                month--;
            }
            month+=months[term];
            while(month>12) {
                month-=12;
                year++;
            }
            
            if(year<todayYear)
                append=true;
            else if(year==todayYear) {
                if(month<todayMonth)
                    append=true;
                else if(month==todayMonth && date<todayDate)
                    append=true;
            }
            
            if(append)
                answer[size++]=i+1;
        }
        int[] returnValue=new int[size];
        for(int i=0;i<size;i++)
            returnValue[i]=answer[i];
        
        return returnValue;
    }
}