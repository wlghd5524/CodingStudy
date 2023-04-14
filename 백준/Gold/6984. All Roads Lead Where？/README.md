# [Gold V] All Roads Lead Where? - 6984 

[문제 링크](https://www.acmicpc.net/problem/6984) 

### 성능 요약

메모리: 2136 KB, 시간: 0 ms

### 분류

그래프 이론, 그래프 탐색, 트리, 너비 우선 탐색, 깊이 우선 탐색

### 문제 설명

<p>There is an ancient saying that "All Roads Lead to Rome". If this were true, then there is a simple algorithm for finding a path between any two cities. To go from city A to city B, a traveller could take a road from A to Rome, then from Rome to B. Of course, a shorter route may exist.</p>

<p>The network of roads in the Roman Empire had a simple structure: beginning at Rome, a number of roads extended to the nearby cities. From these cities, more roads extended to the next further cities, and so on. Thus, the cities could be thought of as existing in levels around Rome, with cities in the ith level only connected to cities in the i-1st and i+1st levels (Rome was considered to be at level 0). No loops existed in the road network. Any city in level i was connected to a single city in level i-1, but was connected to zero or more cities in level i+1. Thus, to get to Rome from a given city in level i, a traveller could simply walk along the single road leading to the connected i-1 level city, and repeat this process, with each step getting closer to Rome.</p>

<p>Given a network of roads and cities, your task is to find the shortest route between any two given cities, where distance is measured in the number of intervening cities.</p>

### 입력 

 <p>The first line of input contains two numbers in decimal notation separated by a single space. The first number (m) is the number of roads in the road network to be considered. The second number (n) represents the number of queries to follow later in the file.</p>

<p>The next m lines in the input each contain the names of a pair of cities separated by a single space. A city name consists of at most ten letters, the first of which is in uppercase. No two cities begin with the same letter. The name Rome always appears at least once in this section of input; this city is considered to be at level 0, the lowest-numbered level. The pairs of names indicate that a road connects the two named cities. The first city named on a line exists in a lower level than the second named city. The road structure obeys the rules described above. No two lines of input in this section are repeated.</p>

<p>The next n lines in the input each contain the names of a pair of cities separated by a single space. City names are as described above. These pairs of cities are the query pairs. Your task for each query pair is to find the shortest route from the first named city to the second. Each of the cities in a query pair is guaranteed to have appeared somewhere in the previous input section describing the road structure.</p>

### 출력 

 <p>For each of the n query pairs, output a sequence of uppercase letters indicating the shortest route between the two query pair cities. The sequence must be output as consecutive letters, without intervening whitespace, on a single line. The first output line corresponds to the first query pair, the second output line corresponds to the second query pair, and so on. The letters in each sequence indicate the first letter of the cities on the desired route between the query pair cities, including the query pair cities themselves. A city will never be paired with itself in a query.</p>

