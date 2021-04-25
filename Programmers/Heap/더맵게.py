import heapq
# def solution(scovile, K):
    #try fail
    # h=[-1]
    # answer = 0
    # for i in scovile:
    #     append(h, i)
    # while(h[1] < K):
    #     answer+=1
    #     top = h[1]
    #     pop(h,1)
    #     top2 = h[1]
    #     pop(h,1)
    #     append(h,top+top2*2)
    #     print(top, top2, h)
    # return answer
# def append(h, k):
#     h.append(k)
#     l = len(h)-1
#     while l != 0 and h[l]<h[l//2]:
#         temp = h[l]
#         h[l] = h[l//2]
#         h[l//2]= temp
#         l//=2
# def pop(h, l):
#     while(1):
#         left = h[l*2] if l*2 <= len(h)-1 else 1e9
#         right = h[l*2+1] if l*2+1 <= len(h)-1 else 1e9
#         if(left == 1e9 and right == 1e9):
#             break
#         elif (left<=right):
#             h[l] = left;
#             l*=2
#         else:
#             h[l] = right;
#             l = l*2+1
#         h[l]=1e9

def try2(l, condition):
    h = []
    count = 0
    for e in l:
        heapq.heappush(h, e)

    min1 = heapq.heappop(h)
    while(min1 < condition):
        if(len(h)!=0):
            min2 = heapq.heappop(h)
        else:
            return -1
        num = min1 + 2 * min2
        heapq.heappush(h, num)
        count = count +1
        if(len(h)!=0):
            min1 = heapq.heappop(h)
        else:
            return -1

    return count





def main():
    scovile = [1, 2, 3, 9, 10, 12]
    # scovile = [1, 2, 3, 5]

    K = 7
    # print(solution(scovile, K))
    print(try2(scovile, K))
main()