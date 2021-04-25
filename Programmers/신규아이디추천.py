from functools import reduce
def solution(new_id):

    new_id = new_id.lower()
    # acc + cur if (cur.isalpha() or cur.isdigit() or cur == "-" or cur == "_" or cur == '.')
    new_id = reduce(lambda acc, cur : acc+ (cur if (cur.isalpha() or cur.isdigit() or cur == "-" or cur == "_" or cur == '.') else ""),list(new_id), "")
    # print(new_id)
    acc = ""
    prev = 0

    new_id = reduce(lambda acc, cur: acc + (cur if (len(acc) == 0 or acc[-1] != '.' or cur != '.') else ""), list(new_id), "")
    # print("3 : " + new_id)

    new_id = new_id[1:] if (new_id.startswith('.')) else new_id
    new_id = new_id[:-1] if(new_id.endswith('.')) else new_id
    # print("4 : " + new_id)

    new_id = new_id if (len(new_id) !=0) else str("a")
    # print("5 : " + new_id)

    new_id = new_id[:15]
    new_id = new_id[:-1] if (new_id.endswith('.')) else new_id
    # print("6 : " + new_id)

    if(len(new_id) <= 2):
        for e in range(len(new_id), 3):
            new_id += new_id[-1]
    # print("7 : " + new_id)
    
    d = {1:3}
    
    return new_id

lst = ["...!@BaT#*..y.abcdefghijklm", "z-+.^.", 	"=.=", "123_.def", 	"abcdefghijklmn.p"]
for e in lst:
    solution(e)