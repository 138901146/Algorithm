import java.util.*;

class Solution {
    public static int[] solution(int[][] edges) {
        int[] answer = new int[4];
        int[] from = new int[1000001];
        int[] to = new int[1000001];
        List<Integer>[] adjacentList = new ArrayList[1000001];

        for(int i = 0; i < edges.length; ++i) {
            if(from[edges[i][0]] == 0) {
                adjacentList[edges[i][0]] = new ArrayList<>();
            }

            adjacentList[edges[i][0]].add(edges[i][1]);
            ++from[edges[i][0]];
            ++to[edges[i][1]];
        }

        for(int i = 0; i <= 1000000; ++i) {
            if(to[i] == 0 && from[i] > 1) {
                answer[0] = i;
            }
        }

        for(int i = 0; i < adjacentList[answer[0]].size(); ++i) {
            int root = adjacentList[answer[0]].get(i);
            int current = root;

            while(true) {
                if(from[current] == 0) {
                    ++answer[2];
                    break;
                } else if(adjacentList[current].size() != 1) {
                    ++answer[3];
                    break;
                }
                
                current = adjacentList[current].get(0);
                
                if(current == root) {
                    ++answer[1];
                    break;
                }
            }
        }
        
        return answer;
    }
}