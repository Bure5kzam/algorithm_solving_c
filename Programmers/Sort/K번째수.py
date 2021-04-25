def solution(array, commands):
    answer = []
    for i in commands:
        l = sorted(array[i[0]-1:i[1]])
        answer.append(l[i[2]-1])


    return answer



# Best Solution
# def solution(array, commands):
#     return list(map(lambda x:sorted(array[x[0]-1:x[1]])[x[2]-1], commands))

def main():
    array = [1, 5, 2, 6, 3, 7, 4]
    command = [[2, 5, 3], [4, 4, 1], [1, 7, 3]]

    print(solution(array,command))

main()