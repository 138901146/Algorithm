import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		StringBuilder sb = new StringBuilder();

		for (int t = 0; t < 4; t++) {
			st = new StringTokenizer(br.readLine());
			int result[][] = new int[6][3];
			int[] wdl = new int[3];
			for (int i = 0; i < 6; i++)
				for (int j = 0; j < 3; j++)
					result[i][j] = Integer.parseInt(st.nextToken());

			for (int i = 0; i < 6; i++)
				for (int j = 0; j < 3; j++)
					wdl[j] += result[i][j];

			if (wdl[0] != wdl[2] || wdl[1] % 2 != 0 || wdl[0] + wdl[1] + wdl[2] != 30)
				sb.append("0 ");
			else if (worldcupSimulation(result, 0, 1))
				sb.append("1 ");
			else
				sb.append("0 ");
		}

		System.out.println(sb.toString());
	}

	static boolean worldcupSimulation(int[][] worldcup, int pri, int sec) {
		if (pri == 4 && sec == 5) {
			for (int i = 0; i < 3; i++)
				if (worldcup[pri][i] != worldcup[sec][3 - i - 1])
					return false;
			int count = 0;
			for (int i = 0; i < 6; i++)
				for (int j = 0; j < 3; j++)
					count += worldcup[i][j];
			return count == 2;
		}

		int[][] temp = new int[6][3];
		boolean answer = false;
		int nextPri = pri, nextSec = 0;

		if (sec == 5) {
			nextPri++;
			nextSec = nextPri + 1;
		} else
			nextSec = sec + 1;

		for (int i = 0; i < 6; i++)
			for (int j = 0; j < 3; j++)
				temp[i][j] = worldcup[i][j];

		for (; nextSec < 6; nextSec++) {
			// pri 가 이길경우
			if (worldcup[pri][0] > 0 && worldcup[sec][2] > 0) {
				temp[pri][0]--;
				temp[sec][2]--;
				answer |= worldcupSimulation(temp, nextPri, nextSec);
				if (answer)
					return true;
				temp[pri][0]++;
				temp[sec][2]++;
			}
			// pri와 sec가 무승부로 진행될 경우
			if (worldcup[pri][1] > 0 && worldcup[sec][1] > 0) {
				temp[pri][1]--;
				temp[sec][1]--;
				answer |= worldcupSimulation(temp, nextPri, nextSec);
				if (answer)
					return true;
				temp[pri][1]++;
				temp[sec][1]++;
			}
			// pri가 질 경우
			if (worldcup[pri][2] > 0 && worldcup[sec][0] > 0) {
				temp[pri][2]--;
				temp[sec][0]--;
				answer |= worldcupSimulation(temp, nextPri, nextSec);
				if (answer)
					return true;
				temp[pri][2]++;
				temp[sec][0]++;
			}
		}

		return answer;
	}
}