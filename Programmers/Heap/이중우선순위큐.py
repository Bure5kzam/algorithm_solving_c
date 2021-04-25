import heapq
def solution(operations):
    answer = []
    min = []
    max = []
    for a in operations:
        if(a[:1] == "I"):
            heapq.heappush(min,int(a[2:]))
            heapq.heappush(max,-1 * int(a[2:]))
        elif a == "D 1":
            if(len(max)):
                poped = heapq.heappop(max)
                min.remove(-1 * poped)
        else:
            if (len(min)):
                poped = heapq.heappop(min)
                max.remove(-1 * poped)

        print("min : " , min)

    return [0,0] if not len(min) else [-1 * heapq.heappop(max), heapq.heappop(min)]

def main():
    l1 = ["I 1000000", "I 16", "I -16", "D -1", "D -1"]
    l2 = ["I 7", "I 5", "I -5", "D-1"]
    l3 = 	["I -45", "I 653", "D 1", "I -642", "I 45", "I 97", "D 1", "D -1", "I 333"]
    print(solution(l1))

main()