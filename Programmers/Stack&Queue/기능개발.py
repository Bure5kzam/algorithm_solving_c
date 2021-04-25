# def solution(progresses, speeds):
    # My code
    # answer = []
    # while progresses:
    #     count=0
    #     progresses += speeds
    #     progresses = [x + y for x, y in zip(progresses,speeds)]
    #
    #     if progresses[0] >= 100:
    #         dellist = []
    #         for i in range(len(progresses)):
    #             if(progresses[i] >= 100):
    #                 count+=1;
    #                 dellist.append(i)
    #             else:
    #                 break
    #         for i, x in enumerate(dellist):
    #             del progresses[x-i]
    #             del speeds[x-i]
    #
    #         answer.append(count)
    # return answer

def solution_(progresses, speeds):
    Q = []
    for p, s in zip(progresses, speeds):
        print("p : %d, s : %d" % (p,s))
        if len(Q) == 0 or Q[-1][0] < -((p - 100) // s):
            Q.append([-((p - 100) // s), 1])
        else:
            Q[-1][1] += 1
    return [q[1] for q in Q]



def main():
    # progresses = [93, 30, 55]
    # speeds = [1, 30, 5]
    # answer = [2, 1]

    progresses = [95, 90, 99, 99, 80, 99]
    speeds = [1, 1, 1, 1, 1, 1]
    answer = [1, 3, 2]
    print(solution_(progresses, speeds))
main()