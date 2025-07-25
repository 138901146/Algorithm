# [Diamond V] 프리즌 브레이크 - 1886 

[문제 링크](https://www.acmicpc.net/problem/1886) 

### 성능 요약

메모리: 2872 KB, 시간: 0 ms

### 분류

너비 우선 탐색, 이분 탐색, 이분 매칭, 그래프 이론, 그래프 탐색

### 제출 일자

2025년 6월 8일 20:04:34

### 문제 설명

<p>N×M 크기의 감옥이 있다. 감옥은 스코필드가 미리 뚫어 놓은 탈출구, 벽, 그리고 빈 칸으로 이루어져 있는데 각각의 모든 빈 칸에는 사람이 한 명씩 있다. 감옥 안에 있는 모든 사람들은 탈출구를 통해 탈옥을 해 내야 한다. 물론, 최대한 빨리 모든 사람이 탈출하도록 하고 싶다.</p>

<p>각 사람이 한 칸을 이동하는 데에는 1초가 걸리며, 하나의 탈출구를 통해서는 1초에 한 사람만 탈출을 할 수 있다. 그리고 사람들이 탈출하는 동안에는 하나의 빈 칸에 여러 명의 사람들이 있어도 된다. 감옥의 정보가 주어져 있을 때, 사람들이 모두 탈출하려면 모두 몇 초의 시간이 걸리는지 구하는 프로그램을 작성하시오.</p>

<p>감옥의 가장자리는 반드시 벽 또는 탈출구이며, 안쪽에는 탈출구가 없다. 탈출구가 없을 수도 있고, 감옥에는 빈 칸이 하나 이상 있다.</p>

### 입력 

 <p>첫째 줄에 감옥의 행의 수와 열의 수, N, M이 공백을 사이에 두고 주어진다. 그리고 N개의 줄에 걸쳐서 감옥의 정보가 주어진다. ‘X'는 벽을 의미하고 '.'은 빈 칸, 'D'는 스코필드가 미리 뚫어 놓은 탈출구 위치를 의미한다.</p>

### 출력 

 <p>첫째 줄에 모든 사람이 탈출을 하는 최소시간을 출력한다. 만약에 모두 탈출하는 것이 불가능하다면 “impossible"을 출력한다.</p>

