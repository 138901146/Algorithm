import java.util.*;

class Solution {
    public int solution(String[] friends, String[] gifts) {
        int size = friends.length;
        Map<String, Integer> nameToIndex = new HashMap<>();
        int[] score = new int[size];
        int[][] status = new int[size][size];
        int sender;
        int receiver;
        StringTokenizer st;
        int max = 0;
        int[] result = new int[size];

        for (int i = 0; i < size; ++i) {
            nameToIndex.put(friends[i], i);
        }

        for (int i = 0; i < gifts.length; ++i) {
            st = new StringTokenizer(gifts[i]);

            sender = nameToIndex.get(st.nextToken());
            receiver = nameToIndex.get(st.nextToken());

            ++status[sender][receiver];
            ++score[sender];
            --score[receiver];
        }

        for (int i = 0; i < size; ++i) {
            for (int j = i + 1; j < size; ++j) {
                if (status[i][j] > status[j][i]) {
                    ++result[i];
                } else if (status[j][i] > status[i][j]) {
                    ++result[j];
                } else if (score[i] > score[j]) {
                    ++result[i];
                } else if (score[j] > score[i]) {
                    ++result[j];
                }
            }
        }

        for (int i = 0; i < size; ++i) {
            max = Integer.max(max, result[i]);
        }

        return max;
    }
}