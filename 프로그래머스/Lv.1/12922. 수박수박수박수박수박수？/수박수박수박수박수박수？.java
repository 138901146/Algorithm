import java.util.*;

class Solution {
    public String solution(int n) {
        StringBuilder sb = new StringBuilder();
        
        for(int i=0;i<n;++i)
            sb.append((i&1)!=0?'박':'수');
        
        return sb.toString();
    }
}