import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

class Node {
    int lastIndex, value;

    public Node(int lastIndex, int value) {
        this.lastIndex = lastIndex;
        this.value = value;
    }
}

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        List<Node>[] LIS = new List[N];
        int length = 0;

        for (int i = 0; i < N; ++i) {
            int A = Integer.parseInt(st.nextToken());

            LIS[i] = new ArrayList<>();
            LIS[i].add(new Node(-1, 2000000000));

            int left = 0, right = length, mid;
            while (left < right) {
                mid = left + right >> 1;
                int compare = LIS[mid].get(LIS[mid].size() - 1).value;

                if (compare > A)
                    right = mid - 1;
                else if (compare < A)
                    left = mid + 1;
                else
                    break;
            }
            right = Math.max(0, right);
            mid = left + right >> 1;

            if (A <= LIS[mid].get(LIS[mid].size() - 1).value) {
                if (LIS[mid].get(0).value == 2000000000)
                    LIS[mid].clear();
                LIS[mid].add(new Node(mid > 0 ? LIS[mid - 1].size() - 1 : 0, A));
            } else {
                if (LIS[mid + 1].get(0).value == 2000000000)
                    LIS[mid + 1].clear();
                LIS[mid + 1].add(new Node(LIS[mid].size() - 1, A));
            }

            if (mid == length)
                ++length;
        }

        StringBuilder sb = new StringBuilder(length + "\n");
        int[] backtrace = new int[length];

        for (int i = length - 1, index = LIS[i].size() - 1; i >= 0; --i) {
            backtrace[i] = LIS[i].get(index).value;
            index = LIS[i].get(index).lastIndex;
        }

        for (int i = 0; i < length; ++i)
            sb.append(backtrace[i]).append(' ');

        System.out.print(sb);
    }
}