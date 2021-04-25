from itertools import combinations
from collections import defaultdict
def solution(orders, course):
    N = max(course)
    
    count = [defaultdict(int) for x in range(len(course))]
    mx = [0 for x in range(len(course))]
    for h in orders:
        print("human : ", h)
        n = len(h)
        for i, r in enumerate(course):
            
            ret = list(combinations(sorted(h),r))
            for aa in ret:
                print(aa)
                count[i]["".join(aa)] +=1
                if(mx[i] < count[i]["".join(aa)]):
                    mx[i] = count[i]["".join(aa)]
            
                
    #sorted
    answer = []
    print(count[0])
    for i, e in enumerate(course):
        if(mx[i] < 2):
            continue
        for e2 in count[i].keys():
            if(count[i][e2] == mx[i]):
                answer.append(e2)
    answer = sorted(answer)
    return answer

solution(["XYZ", "XWY", "WXA"], [2,3,4])