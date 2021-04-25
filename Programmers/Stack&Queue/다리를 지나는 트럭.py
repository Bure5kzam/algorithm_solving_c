def solution(bridge_length, weight, truck_weights):
    answer = 0
    q = []
    q2 = []
    for i in truck_weights:
        print("tw : ", i)
        q= q2.copy()
        q2=[]
        check=False;
        l = bridge_length;

        if q:
            start = q[0][1]+1
            l = bridge_length
            for j in q:
                print(j[0] + i)
                if j[0] + i <= weight and start<=j[2]:
                    q2.append([j[0]+i, start,j[2]])
                    l -= j[2] - start +1
                start = j[2]+1
        else:
            q.append([0,0,0])

        q2.append([i,q[-1][2]+1, q[-1][2]+l])
        print("q2: ", q2)
    answer = q2[-1][2]+1
    return answer

def main():
    # bridge_length = 2
    # weight = 10
    # truck_weights = [7,4,5,6]

    # bridge_length=100
    # weight=100
    # truck_weights=[10, 10, 10, 10, 10, 10, 10, 10, 10, 10]

    bridge_length = 100
    weight = 100
    truck_weights = [10]

    bridge_length = 10
    weight = 10
    truck_weights = [5,5,5,5,]

    print(solution(bridge_length,weight,truck_weights))
main()