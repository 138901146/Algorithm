public class Solution {

    int size;
    int[][] sum;
    int[] selected;
    boolean init = true;
    int end;
    int[][] status;
    int bit;
    int[] order;
    int[][] dice;
    int best = 0;

    public void combination(int start, int done) {
        if (done == end) {
            bit = 0;
            for (int i = 0; i < end; ++i) {
                bit |= 1 << selected[i];
            }

            if (init) {
                calculate_sum(0);
            } else {
                calculate_status();
            }

            return;
        }

        for (int i = start; i < size; ++i) {
            selected[done] = i;
            combination(i + 1, done + 1);
        }
    }

    public void calculate_sum(int current) {
        if (current == end) {
            int total = 0;

            for (int i = 0; i < end; ++i) {
                total += order[i];
            }

            ++sum[bit][total];
            return;
        }

        for (int i = 0; i < 6; ++i) {
            order[current] = dice[selected[current]][i];
            calculate_sum(current + 1);
        }
    }

    public void calculate_status() {
        int xor = ((1 << size) - 1) ^ bit;

        for (int i = 1; i <= 500; ++i) {
            if (sum[bit][i] > 0) {
                for (int j = 1; j <= 500; ++j) {
                    if (sum[xor][j] > 0) {
                        if (i > j) {
                            status[bit][0] += sum[bit][i] * sum[xor][j];
                        } else if (i < j) {
                            status[bit][2] += sum[bit][i] * sum[xor][j];
                        } else {
                            status[bit][1] += sum[bit][i] * sum[xor][j];
                        }
                    }
                }
            }
        }

        if (status[bit][0] > status[best][0]) {
            best = bit;
        }
    }

    public int[] solution(int[][] givenDice) {
        size = givenDice.length;
        sum = new int[1 << size][501];
        end = size >> 1;
        selected = new int[end];
        order = new int[end];
        dice = new int[size][6];

        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < 6; ++j) {
                dice[i][j] = givenDice[i][j];
            }
        }

        init = true;
        combination(0, 0);

        init = false;
        status = new int[1 << size][3];
        combination(0, 0);

        int[] answer = new int[end];
        int count = 0;
        for (int i = 0; i < size; ++i) {
            if ((best & (1 << i)) != 0) {
                answer[count++] = i + 1;
            }
        }

        return answer;
    }
}