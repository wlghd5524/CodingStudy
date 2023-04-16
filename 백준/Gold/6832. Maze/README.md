# [Gold V] Maze - 6832 

[문제 링크](https://www.acmicpc.net/problem/6832) 

### 성능 요약

메모리: 2032 KB, 시간: 0 ms

### 분류

그래프 이론, 그래프 탐색, 너비 우선 탐색, 깊이 우선 탐색

### 문제 설명

<p>In order to make a few dollars, you have decided to become part of a scientific experiment. You are fed lots of pizza, then more pizza and then you are asked to find your way across the city on a scooter powered only by pizza. Of course, the city has lots of intersections, and these intersections are very controlled. Some intersections are forbidden for you to enter; some only let you move north/south as you leave the intersection; others let you move only east/west as you leave the intersection; and the rest let you go in any compass direction (north, south, east or west).</p>

<p>Thankfully your scientific friends have given you a map of the city (on the back of a pizza box), with an arrangement of symbols indicating how you can move around the city. Specifically, there are 4 different symbols on the box:</p>

<ul>
	<li>The symbol + indicates we can move in any direction (north/south/east/west) from this location.</li>
	<li>The symbol - indicates we can move only east or west from this location.</li>
	<li>The symbol | indicates we can move only north or south from this location.</li>
	<li>The symbol * indicates we cannot occupy this location.</li>
</ul>

<p>Your task is to determine how many intersections you must pass through to move from the northwest corner of the city to the south-east corner of the city.</p>

### 입력 

 <p>The input begins with a number t (1 ≤ t ≤ 10) on its own line, which indicates how many different cases are contained in this file. Each case begins with a number r on one line, followed by a number c on the next line (1 ≤ r, c ≤ 20). The next r lines contain c characters, where each character is one of {+, *, -, |}. You may assume the north-west corner of the city can be occupied (i.e., it will not be marked with *).</p>

### 출력 

 <p>The output will be t lines long, with one integer per line. The integer on line i (1 ≤ i ≤ t) indicates the minimum number of intersections required to pass through as you move from the north-west corner of the city to the south-east corner of the city. If there is no way to get from the north-west corner to the south-east corner, output −1 for that test case.</p>

