from functools import reduce
def solution(arr):
    answer = [1,2,3,]

    # answer = reduce(lambda acc, cur : acc + ([cur] if (acc[-1]!=cur) else []), arr, [-1])
    
    # for e in arr[1:]:
    #     if(answer[-1] != e):
    #     answer.append(e)

    # def no_continuous(s):
    #     a = []
    # for i in s:
    #     if a[-1:] == [i]: continue
    #     a.append(i)
    # return a
    
    return answer[1:]

solution([4,4,4,3,3])