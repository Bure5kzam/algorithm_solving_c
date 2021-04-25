from collections import Counter


def solution(participant, completion):
    # Counter 생성자로 {key : value}를 {인자 : 개수} 로 받는 counter객체를 생성 할 수 있음
    a = (Counter(participant))
    b = (Counter(completion))


    # print(a)
    # print(b)
    # print(a-b)

    # Set 자료형처럼 -연산시 차집합 결과를 반환
    answer = Counter(participant) - Counter(completion)

    # Set 자료형에서 key값만 뽑아 리스트로 변환, v
    return list(answer.keys())[0]

def main():
    a = ["marina", "josipa", "nikola", "vinko", "filipa"]
    b = ["josipa", ")", "marina", "nikola"]

    print(solution(a, b))

main()