from collections import defaultdict


def solution(s):
    answer = True
    
    # val 1 : len
    if len(s) != 4 and len(s) != 6:
        answer |= False;

    # val 2 : num
    if s.isdecimal() == False:
        answer = False
    return answer

def main():
    a = ["a234", "1234"]
    for i in a:
        print(solution(i))

main()