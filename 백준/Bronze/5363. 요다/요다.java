import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());

        for (int i = 0; i < N; ++i) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            StringBuilder sb = new StringBuilder();
            String primary = st.nextToken();
            String secondary = st.nextToken();
            while (st.hasMoreTokens())
                sb.append(st.nextToken()).append(' ');
            sb.append(primary).append(' ').append(secondary);

            System.out.println(sb);
        }
    }
}