from functools import reduce
def solution(answers):
    a = [[1,2,3,4,5],
     [2,1,2,3,2,4,2,5],
     [3,3,1,1,2,2,4,4,5,5]]

    s = {1:0, 2:0, 3:0}
    for i, e in enumerate(answers):
        for j in range(0, 3):
            s[j+1] += 1 if (e == a[j][i%len(a[j])]) else 0
    s = sorted(s.items(), key=lambda x : x[1], reverse=True)
    
    answer =[s[0][0]]
    for prev, cur in zip(s, s[1:]):
        if(prev[1] == cur[1]):
            answer.append(cur[0])
        else:
            break

    return answers

l = [[1,2,3,4,5], [1,3,2,4,2], [3,3,1,1,2]]

for e in l:
    solution(e)