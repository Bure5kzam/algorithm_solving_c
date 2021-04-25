
def solution(phone_book):
    # 리스트 정렬
    p = sorted(phone_book)

    # 리스트를 매칭하는 zip함수로 반복문 하나로 진행
    for i, j in zip(p, p[1:]):
        print(i, j)

        if(i == j[:len(i)]):
            return False;
    return True

def main():
    p = ["119", "1132", "1192212"]
    print(solution(p))

main()
