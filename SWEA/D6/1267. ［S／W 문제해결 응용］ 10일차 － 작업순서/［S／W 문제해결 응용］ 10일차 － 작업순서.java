import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        StringBuilder sb = new StringBuilder();

        for (int t = 1; t <= 10; ++t) {
            st = new StringTokenizer(br.readLine());
            int V = Integer.parseInt(st.nextToken());
            int E = Integer.parseInt(st.nextToken());
            int left = V;
            int[] count = new int[V + 1];
            boolean[][] graph = new boolean[V + 1][V + 1];
            boolean[] done = new boolean[V + 1];

            st = new StringTokenizer(br.readLine());
            for (int e = 0; e < E; ++e) {
                int x = Integer.parseInt(st.nextToken());
                int y = Integer.parseInt(st.nextToken());
                graph[x][y] = true;
                ++count[y];
            }

            sb.append("#").append(t);
            while (left > 0) {
                for (int v = 1; v <= V; ++v) {
                    if (!done[v]) {
                        if (count[v] == 0) {
                            sb.append(" ").append(v);
                            done[v] = true;
                            --left;
                            for (int i = 1; i <= V; ++i) {
                                if (graph[v][i]) {
                                    graph[v][i] = false;
                                    --count[i];
                                }
                            }
                        }
                    }
                }
            }
            sb.append("\n");
        }
        System.out.print(sb);
    }
}