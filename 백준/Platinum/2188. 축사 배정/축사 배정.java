import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

    static int[] S;
    static List<Integer>[] cow;
    static boolean[] visited;

    static boolean dfs(int current) {
        for (Integer next : cow[current]) {
            if (!visited[next]) {
                visited[next] = true;

                if (S[next] == 0 || dfs(S[next])) {
                    S[next] = current;
                    return true;
                }
            }
        }

        return false;
    }

    public static void main(String[] args) throws IOException {
        int count;
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        cow = new List[N + 1];
        S = new int[M + 1];
        visited = new boolean[M + 1];

        for (int n = 1; n <= N; ++n) {
            st = new StringTokenizer(br.readLine());

            count = Integer.parseInt(st.nextToken());
            cow[n] = new ArrayList<>();

            while (count-- > 0) {
                cow[n].add(Integer.parseInt(st.nextToken()));
            }
        }

        for (int n = 1; n <= N; ++n) {
            Arrays.fill(visited, false);
            dfs(n);
        }

        count = 0;
        while (M > 0) {
            if (S[M--] > 0) {
                ++count;
            }
        }

        System.out.println(count);
    }
}