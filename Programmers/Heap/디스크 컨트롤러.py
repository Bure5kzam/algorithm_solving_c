import heapq
import math

def solution(jobs):
    answer = 0
    l = 0
    h=[]
    idx = 0
    jobs = sorted(jobs)
    while(True):
        for i in jobs[idx:]:
            if(i[0]<=l):
                heapq.heappush(h,i[::-1])
                idx+=1

        if(len(h)):
            poped = heapq.heappop(h)
            print(poped)
            l+=poped[0]
            answer += (l-poped[1])
        else:
            if(idx<len(jobs)):
                l=jobs[idx][0]
            else:
                return math.floor(answer/len(jobs))


def main():
    l = [[0, 3], [0, 3], [10,3]]
    print(solution(l))

main()
# l=[]
# for i in range(5,0,-1):
#     l.append(i)

# print(l[::-1])