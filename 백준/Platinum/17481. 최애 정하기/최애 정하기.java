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

    static int[] bestPick;
    static List<Integer>[] fan;
    static boolean[] visited;

    static boolean dfs(int current) {
        for (Integer next : fan[current]) {
            if (!visited[next]) {
                visited[next] = true;

                if (bestPick[next] == 0 || dfs(bestPick[next])) {
                    bestPick[next] = current;
                    return true;
                }
            }
        }

        return false;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        Map<String, Integer> nameToIndex = new HashMap<>();
        int count;
        fan = new List[N + 1];
        bestPick = new int[M];
        visited = new boolean[M];

        for (int m = 0; m < M; ++m) {
            nameToIndex.put(br.readLine(), m);
        }

        for (int n = 1; n <= N; ++n) {
            st = new StringTokenizer(br.readLine());

            count = Integer.parseInt(st.nextToken());
            fan[n] = new ArrayList<>();

            while (count-- > 0) {
                fan[n].add(nameToIndex.get(st.nextToken()));
            }
        }

        for (int n = 1; n <= N; ++n) {
            Arrays.fill(visited, false);
            dfs(n);
        }

        count = 0;
        for (int m = 0; m < M; ++m) {
            if (bestPick[m] > 0) {
                ++count;
            }
        }

        if (count == N) {
            System.out.print("YES");
        } else {
            System.out.print("NO\n" + count);
        }
    }
}