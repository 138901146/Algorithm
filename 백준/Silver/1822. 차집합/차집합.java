import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashSet;
import java.util.List;
import java.util.Set;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        StringBuilder sb = new StringBuilder();
        int A = Integer.parseInt(st.nextToken());
        int B = Integer.parseInt(st.nextToken());
        Set<Integer> set = new HashSet<>();

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < A; ++i)
            set.add(Integer.parseInt(st.nextToken()));

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < B; ++i) {
            int value = Integer.parseInt(st.nextToken());

            if(set.contains(value))
                set.remove(value);
        }

        sb.append(set.size());

        if (set.size() > 0) {
            List<Integer> list = new ArrayList<>();

            for (int value : set)
                list.add(value);

            Collections.sort(list);

            sb.append("\n");
            for (int value : list)
                sb.append(value + " ");
        }

        System.out.print(sb);
    }
}