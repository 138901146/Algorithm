import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.StringTokenizer;

public class Main {

    static int[] occupied;
    static long[][] answer;
    static boolean[] visited;
    static Map<Long, Integer> valueToIndex;

    static boolean dfs(int current) {
        for (int i = 0; i < 3; ++i) {
            int next = valueToIndex.get(answer[current][i]);
            if (!visited[next]) {
                visited[next] = true;

                if (occupied[next] == 0 || dfs(occupied[next])) {
                    occupied[next] = current;
                    return true;
                }
            }
        }

        return false;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        int N = Integer.parseInt(br.readLine());

        int[][] equation = new int[N + 1][2];
        answer = new long[N + 1][3];
        valueToIndex = new HashMap<>();
        List<Long> indexToValue = new ArrayList<>();

        for (int n = 1; n <= N; ++n) {
            st = new StringTokenizer(br.readLine());

            for (int i = 0; i < 2; ++i)
                equation[n][i] = Integer.parseInt(st.nextToken());

            answer[n][0] = (long) equation[n][0] + equation[n][1];
            answer[n][1] = (long) equation[n][0] - equation[n][1];
            answer[n][2] = (long) equation[n][0] * equation[n][1];

            for (int i = 0; i < 3; ++i) {
                int index = valueToIndex.getOrDefault(answer[n][i], -1);

                if (index == -1) {
                    indexToValue.add(answer[n][i]);
                    valueToIndex.put(answer[n][i], indexToValue.size() - 1);
                }
            }
        }

        int size = indexToValue.size();
        occupied = new int[size];
        visited = new boolean[size];

        for (int n = 1; n <= N; ++n) {
            Arrays.fill(visited, false);
            dfs(n);
        }

        int[] result = new int[N + 1];
        int count = 0;
        for (int i = 0; i < size; ++i)
            if (occupied[i] > 0) {
                ++count;
                result[occupied[i]] = i;
            }

        if (count != N)
            System.out.println("impossible");
        else {
            StringBuilder sb = new StringBuilder();
            for (int n = 1; n <= N; ++n) {
                char operation;

                if ((long) equation[n][0] + equation[n][1] == indexToValue.get(result[n]))
                    operation = '+';
                else if ((long) equation[n][0] - equation[n][1] == indexToValue.get(result[n]))
                    operation = '-';
                else
                    operation = '*';

                sb.append(equation[n][0] + " " + operation + " " + equation[n][1] + " = "
                    + indexToValue.get(result[n]) + "\n");
            }

            System.out.print(sb);
        }
    }
}