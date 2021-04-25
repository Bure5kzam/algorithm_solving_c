def solution(prices):
    answer = [0] *len(prices)
    st = []
    for i, e in enumerate(prices):
        while st and prices[st[-1]] > e:
            top = st.pop()
            answer[top] = i - top
        st.append(i)
    while st:
        top = st.pop()
        answer[top] = len(prices) - top-1


    return answer
def main():
    prices = [1, 2, 3, 2, 3]
    # prices = [1, 2, 3, 2,1]
    print(solution(prices))

main()
