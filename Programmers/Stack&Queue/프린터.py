import collections
def solution(p, location):
    target = p[location]
    c = collections.Counter(p)
    pp = sorted(c.keys(),reverse=True)
    print(pp)

    start = 0
    count = 0;
    ppcounter = 0
    while pp[ppcounter] > target:
        for i in range(len(p)):
            index = (start + i)%len(p)
            print("i  : ", i)
            if(p[index] == pp[ppcounter]):
                istart = index
                print(istart)
        start = istart
        count += c[pp[ppcounter]]
        ppcounter += 1;

    print(start, count, location)
    while start != location:
        print("St : " ,start)
        if p[start] == pp[ppcounter]:
            count+=1

        start = (start + 1) % len(p)
    print("start : ", start, count+1)
    return count+1

def main():
    # priorities = [1,1,1,1]
    # location =0
    #
    # priorities = [1,1,9,1,1,1]
    # location = 0

    priorities = [2,1,5,4,3]
    location = 1
    #
    priorities = [2,9,7,7,7,10,9,7,7,1]
    location =4



    print(solution(priorities, location))

main()