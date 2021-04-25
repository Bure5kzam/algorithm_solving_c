import collections
def solution(clothes):

    # 해쉬 매핑함수 Collections.Conter() 생성
    c = collections.Counter();
    for i in range(len(clothes)):
        # c[key]로 value 값 갱신.
        c[clothes[i][1]]+=1;

    answer = 1;
    for i in c.keys():
        answer *= (c[i]+1)
    return answer-1

def main():
    p = [["crow_mask", "face"], ["blue_sunglasses", "face"], ["smoky_makeup", "face"]]
    print(solution(p))

main()