from collections import deque

def solution(bridge_length, weight, truck_weights):
    #cnt : 시간
    #curWeight : 현재 무게
    cnt=0
    curW = 0
    bridge_w = deque()
    bridge_d = deque()
    front = 0
        
    

    while True:
        cnt++

        idx = 0
        for w, d in zip(bridge_w, bridge_d):
            d++
            if(bridge_d == bridge_length) idx++
        while idx--:
            bridge_d.popleft
            curW += bridge_w.popleft

    for e in truck_weights[front:]:
        

        


a = Q_PAIR([3,3,3])
