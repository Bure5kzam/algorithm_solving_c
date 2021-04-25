# This is a sample Python script.

# Press Shift+F10 to execute it or replace it with your code.
# Press Double Shift to search everywhere for classes, files, tool windows, actions, and settings.

# def solution(participant, completion):
    #try 1
    #    1 〉    통과(0.01ms, 10.2MB)
    # 2 〉    통과(0.01ms, 10.2MB)
    # 3 〉    통과(2.90ms, 10.1MB)
    # 4 〉    통과(12.72ms, 10.3MB)
    # 5 〉    통과(9.45ms, 10.3MB)

    # a = participant;
    # for i in completion:
    #     for x, j in enumerate(participant):
    #         if i == j:
    #             del participant[x]
    #             break;
    # print(participant)

    #try2
    # d = {}
    # for i in completion:
    #     if not i in d.keys():
    #         d[i] = 1;
    #     else:
    #         d[i]+=1
    #
    # for j in participant:
    #     if not j in d.keys():
    #         return j
    #     else:
    #         if d[j] ==1:
    #             d.pop(j)
    #         else:
    #             d[j] -=1

from collections import Counter
def try3(a,b):
    a = Counter(a) - Counter(b)
    print(list(a)[0])
    print()


def main():
    a = ["marina", "josipa", "nikola", "vinko", "filipa"]
    b = ["josipa", "vinko", "marina", "nikola"]

    # print(solution(a, b))
    print(try3(a,b))

main()