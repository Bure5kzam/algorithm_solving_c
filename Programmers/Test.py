from functools import reduce
from collections import defaultdict
ks = [["cpp","java", "python"], ["backend", "frontend"], ["junior", "senior"], ["chicken", "pizza"]]
def solution(info, query):
    heap=defaultdict()
    heap["cpp"]={}
    heap["java"]={}
    heap["python"]={}
    for i in heap.keys():
        heap[i]={"backend":{}, "frontend":{}}
        for j in heap[i].keys():
            heap[i][j] = {"junior" : {}, "senior" : {}}
            for k in heap[i][j].keys():
                heap[i][j][k] = {"chicken":[], "pizza":[]}
    answer = []
    for i in range(len(info)):
        info[i] = info[i].split(" ")
        # print(heap[info[i][0]])
        heap[info[i][0]][info[i][1]][info[i][2]][info[i][3]].append([i, info[i][4]])
    
    for q in query:
        q = q.split(" and ")
        q.extend(q[3].split(" "))
        del q[3]
        
        for i in range(4):
            q[i] = [q[i]] if q[i] != '-' else ks[i]
        
        sum = 0
        for ii in q[0]:
            for jj in q[1]:
                for kk in q[2]:
                    for ll in q[3]:
                        for e in heap[ii][jj][kk][ll]:
                            if int(q[4]) <= int(e[1]):
                                sum+=1
        answer += [sum]
    print(answer)
        
        
        
    return answer

solution(["java backend junior pizza 150","python frontend senior chicken 210","python frontend senior chicken 150","cpp backend senior pizza 260","java backend junior chicken 80","python backend senior chicken 50"],	["java and backend and junior and pizza 100","python and frontend and senior and chicken 200","cpp and - and senior and pizza 250","- and backend and senior and - 150","- and - and - and chicken 100","- and - and - and - 150"])