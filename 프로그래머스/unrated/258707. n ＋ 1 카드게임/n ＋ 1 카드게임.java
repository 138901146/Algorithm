import java.util.HashSet;
import java.util.Set;

public class Solution {

    public int solution(int coin, int[] cards) {
        int size = cards.length;
        int half = (size >> 1) + 1;
        Set<Integer> have = new HashSet<>();
        Set<Integer> discard = new HashSet<>();
        int answer = 1;

        for (int i = 0; i < size / 3; ++i) {
            have.add(cards[i]);
        }

        for (int i = size / 3; i < size; i += 2) {
            boolean success = false;
            for (int j = 1; j <= half; ++j) {
                if (have.contains(j) && have.contains(size + 1 - j)) {
                    have.remove(j);
                    have.remove(size + 1 - j);
                    success = true;
                    break;
                }
            }

            if (success) {
                discard.add(cards[i]);
                discard.add(cards[i | 1]);
                ++answer;
                continue;
            } else if (coin == 0) {
                break;
            }

            discard.add(cards[i]);
            discard.add(cards[i | 1]);

            for (int j = 1; j <= half; ++j) {
                if (have.contains(j) && discard.contains(size + 1 - j)) {
                    discard.remove(size + 1 - j);
                    have.remove(j);
                    success = true;
                    break;
                } else if (have.contains(size + 1 - j) && discard.contains(j)) {
                    have.remove(size + 1 - j);
                    discard.remove(j);
                    success = true;
                    break;
                }
            }

            if (success) {
                ++answer;
                --coin;
                continue;
            } else if (coin < 2) {
                break;
            }

            for (int j = 1; j <= half; ++j) {
                if (discard.contains(j) && discard.contains(size + 1 - j)) {
                    discard.remove(j);
                    discard.remove(size + 1 - j);
                    success = true;
                    break;
                }
            }

            if (success) {
                coin -= 2;
                ++answer;
            } else {
                break;
            }
        }

        return answer;
    }
}