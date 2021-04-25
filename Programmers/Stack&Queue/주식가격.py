def solution(prices):
    # try 1
    # answer = [0] * len(prices)
    # s = []
    # for i,x in enumerate(prices):
    #     if i != 0 and s[len(s)-1][1] > x:
    #         s_pop(s, i, x, answer,True)
    #     s.append(list([i,x]))
    # s_pop(s,len(prices)-1,0,answer,efficiency=False)
    # return answer

def s_pop(s, index, value, answer, efficiency = True):
    while (len(s)-1>=0):
        if s[len(s) - 1][1] > value:
            answer[s[len(s) - 1][0]] = index - s[len(s) - 1][0]
            del s[len(s) - 1]
        else:
            if efficiency == True:
                break;

def main():
    prices = [1, 2, 3, 2, 3]
    # prices = [1, 2, 3, 2,1]
    print(solution(prices))


main()