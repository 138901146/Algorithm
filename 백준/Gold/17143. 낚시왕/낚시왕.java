import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        
        int R = Integer.parseInt(st.nextToken());
        int C = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        
        int[][][] land = new int[R][C][2];
        int[][] shark = new int[M + 1][3];
        
        for (int i = 1; i < M + 1; i++) {
            st = new StringTokenizer(br.readLine(), " ");
            land[Integer.parseInt(st.nextToken()) - 1][Integer.parseInt(st.nextToken()) - 1][0] = i; // i번째 상어의 위치
            shark[i][0] = Integer.parseInt(st.nextToken()); // 속력
            shark[i][1] = Integer.parseInt(st.nextToken()); // 이동 방향
            shark[i][2] = Integer.parseInt(st.nextToken()); // 크기
        }
        
        int answer = 0;
        for (int i = 0; i < C; i++) {
            int current = i % 2;
            int next = (i + 1) % 2;
            for (int j = 0; j < R; j++) {
                if (land[j][i][current] > 0) {
                    answer += shark[land[j][i][current]][2];
                    land[j][i][current] = 0;
                    break;
                }
            }
            for (int j = 0; j < C; j++) { // C는 가로 개수
                for (int k = 0; k < R; k++) {
                    if (land[k][j][current] > 0) {
                        int index = land[k][j][current];
                        int y = k;
                        int x = j;
                        
                        land[k][j][current] = 0;
                        switch (shark[index][1]) {
                        case 1:
                            y -= shark[index][0];
                            while (y < 0) { 
                                y += ((R - 1) * 2);
                            }
                            if(y==0 || y>=R)
                            	shark[index][1]=2;
                            if (y >= R) {
                                y = (2 * (R - 1)) - y;
                            }
                            break;
                        case 2:
                            y += shark[index][0];
                            while (y >= R) {
                                y -= ((R - 1) * 2);
                            }
                            if(y==R-1 || y<0)
                            	shark[index][1]=1;
                            if (y < 0) {
                                y = -y;
                            }
                            break;
                        case 3:
                            x += shark[index][0];
                            while (x >= C) {
                                x -= ((C - 1) * 2);
                            }
                            if(x==C-1 || x<0) {
                            	shark[index][1]=4;
                            }
                            if (x < 0) {
                                x = -x;
                            }
                            break;
                        case 4:
                            x -= shark[index][0];
                            while (x < 0) { 
                                x += ((C - 1) * 2);
                            }
                            if(x==0 || x>=C)
                            	shark[index][1]=3;
                            if (x >= C) {
                                x = (2 * (C - 1)) - x;
                            }
                            break;
                        default:
                            break;
                        }
                        if (land[y][x][next] > 0) {
                            if (shark[land[y][x][next]][2] < shark[index][2]) {
                                land[y][x][next] = index;
                            }
                        } else {
                            land[y][x][next] = index;
                        }
                    }
                }
            }
        }
        System.out.println(answer);
    }
    
}