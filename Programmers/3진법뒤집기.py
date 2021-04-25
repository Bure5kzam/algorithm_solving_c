def solution(n):
    answer = 0
    
    #1
    ret = ""
    while(n):
        ret +=str(n)
        n/=3
    print(ret)
    return answer