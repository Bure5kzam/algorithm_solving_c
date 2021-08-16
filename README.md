#푼 문제 리스트

#Rule
1. 파일명은 "출처_[번호]_문제명.확장자"로 작성. 문제 명 사이에 공백은 없음.
2. 작성할 때는 [출처/[번호]/해설유무] 문제명 [솔루션명]으로 작성.

# 태그

memoization, greedy, tree, graph, matrix, bit, character, brute-force, permutation,permutation-recursive combination, dynamic

# 2021-04 
## C
- [백준/15683](https://www.acmicpc.net/problem/15683) 감시 [해설](https://bure5kzam.github.io/posts/%EB%B0%B1%EC%A4%80-%EA%B0%90%EC%8B%9C/)
  - 맵, CCTV 모델과 성능, CCTV개수가 주어질 때, 최소의 사각지대를 출력하라.
  - permutaion, brutal-force
- [백준/2156](https://www.acmicpc.net/problem/2156) 포도주시식 [해설](https://bure5kzam.github.io/posts/%EB%B0%B1%EC%A4%80-%ED%8F%AC%EB%8F%84%EC%A3%BC%EC%8B%9C%EC%8B%9D/)
  - 효주는 포도주를 3잔 연속 먹지 못한다. 최대한 많이 먹을 수 있는 값을 출력하라
  - dynamic, brute-force, memmoization
- [백준/3187](https://www.acmicpc.net/problem/3187) 양치기 꿍 [해설](https://bure5kzam.github.io/posts/%EB%B0%B1%EC%A4%80-%EC%96%91%EC%B9%98%EA%B8%B0-%EA%BF%8D/)
  - 벽으로 둘러쌓인 공간에서 살아남는 양과 늑대의 수를 출력하라
  - bfs
  - queue, pair
- [백준/1011](https://www.acmicpc.net/problem/1011) Fly me to the Alpha Centauri 
  - 가속도가 적용되는 텔레포트 기계로 소행성에 도착하라
  - greedy
- [백준/1068/ppt] 트리 [트리/그래프/행령]
- [백준/1520] 내리막길 [트리/그래프/행렬]
- [백준/14889/ppt] 스타트와 링크 [순열/조합][메모이제이션][비트]
- [백준/16964/ppt] DFS 스폐셜 저지 [트리/그래프/행렬]
- [백준/1107] 리모컨 [탐색]
- [백준/2234/주석] 성곽 [탐색][비트]
- [백준/1149] RGB거리 [메모이제이션]
  - 선형 자료구조에서 인접 원소는 다르게 처리하기 
- [백준/18405] 경쟁적전염 [탐색]
- [프로그래머스] 신규 아이디 추천 [문자열]
  -   - [STL]istringstream
- [프로그래머스] 합승 택시 요금 [트리/그래프/행렬]
  - Dijkstra * 2

## Python
- [프로그래머스/주석] 완주하지 못한 선수 [해쉬]
- [프로그래머스/주석] 전호번호 목록 [해쉬]
- [프로그래머스/주석] 위장 [해쉬]
- [프로그래머스] 문자열 다루기 기본  
- [프로그래머스] 다리를 지나는 트럭 [스택]
- [프로그래머스] 기능 개발 []
- [프로그래머스] 다리를 지나는 트럭 [스택/큐]
  - [module] deque
- [프로그래머스] 디스크컨트롤러 [트리/그래프/행렬]
  - [module] heapq
- [프로그래머스] 메뉴 리뉴얼 [트리/그래프/행렬]
  - [module] defaultdict
- [프로그래머스] 모의 고사 []
  - [module] sorted, zip
- [프로그래머스] 문자열 내 마음대로 정렬하기 [문자열]
  - [module] sorted, lambda
- [프로그래머스] 소수찾기 []
- [프로그래머스] 이중우선순위큐 []
- [프로그래머스] 주식가격 []
- [프로그래머스] 체육복 []
- [프로그래머스] 크레인 인형 뽑기 게임 []
- [프로그래머스] 프린터 []
  - [module] collections.counter

# 2021-05
## C

- **[백준/1197] 최소 스패닝 트리 [트리/그래프/행렬]**
  - Prim
- [백준/3190] 뱀 [구현]
  - 시간별 이동
  - 이동 후 분기 처리
- [백준/6987] 월드컵 [순열/백트래킹]
  - 상태를 인접행렬로 표현
- **[백준/21609/주석] 상어중학교 [BFS/구현]**
  - 90도 회전
  - 중력
  - BFS
- **[백준/4485]녹색옷 입은 애가 젤다지[트리/그래프/행렬]**
  - Dijkstra



# 2021-06

# 2021-08

## C

- [백준/19582](https://www.acmicpc.net/problem/19582) 200년간 폐관수련했더니 PS 최강자가 된 건에 대하여 [해설](https://bure5kzam.github.io/posts/%EB%B0%B1%EC%A4%80-200%EB%85%84%EA%B0%84-%ED%8F%90%EA%B4%80%EC%88%98%EB%A0%A8%ED%96%88%EB%8D%94%EB%8B%88-PS-%EC%B5%9C%EA%B0%95%EC%9E%90%EA%B0%80-%EB%90%9C-%EA%B1%B4%EC%97%90-%EB%8C%80%ED%95%98%EC%97%AC/)
  - 폐관수련을 해온 연두는 최소한 N-1개의 알고리즘 대회에 참가할 수 있는지 확인하고 싶다.
  - dynamic
- [백준/2225](https://www.acmicpc.net/problem/2225) 합분해 [해설](https://bure5kzam.github.io/posts/%EB%B0%B1%EC%A4%80-200%EB%85%84%EA%B0%84-%ED%8F%90%EA%B4%80%EC%88%98%EB%A0%A8%ED%96%88%EB%8D%94%EB%8B%88-PS-%EC%B5%9C%EA%B0%95%EC%9E%90%EA%B0%80-%EB%90%9C-%EA%B1%B4%EC%97%90-%EB%8C%80%ED%95%98%EC%97%AC/)
  - N개의 정수 K개의 합이 N이 되는 경우의 수를 출력하라
  - permutation-recursive, dynamic
- 백준/1937 욕심쟁이 판다 
  - 판다는 현재 좌표보다 값이 높은 좌표로만 이동한다.
  - dfs, dynamic