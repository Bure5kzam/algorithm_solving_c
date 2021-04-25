from collections import defaultdict
def solution(genres, plays):
    # answer :list= list()
    answer = list()

    # 초기값을 해당 자료형으로 갖는 defaultdict 생성   
    gd = defaultdict(int)
    pd = defaultdict(list)

    # zip으로 장르 plays의 인덱스를 연결.
    for g, p in zip(genres, range(len(plays))):
        #장르별 플레이 횟수 총합
        gd[g] += plays[p]
        # 장르별 [곡인덱스, 재생수] 저장
        pd[g].append([p, plays[p]])

    # gd의 키를 gd의 value값 기준으로 정렬한 리스트 생성
    gd_sorted = sorted(gd.keys(), key=lambda x: gd[x],reverse=True)
    

    for i in gd_sorted:
        p = sorted(pd[i], key=lambda x : x[1], reverse=True);
        print(p)
        for j in p[:2]:
            answer.append(j[0])


    return answer
def main():
    genres = ["classic", "pop", "classic", "classic", "pop"]
    plays = [500, 600, 150, 800, 2500]
    print(solution(genres, plays))

main()