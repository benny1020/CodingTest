def solution(id_list, report, k):
    # 각 id의 신고 수 dictionary 만들기
    dicc = dict()
    id_count = dict()
    for id in id_list:
        dicc[id] = []
        id_count[id]=0
    
    for rep in report:
        first_id, second_id = rep.split(' ')
        if first_id not in dicc[second_id]:
            dicc[second_id].append(first_id)
    
    
    for id in dicc:
        if len(dicc[id]) >=k:
            for i in dicc[id]:
                id_count[i]+=1;
                

    ans = []
    for i in id_count.values():
        ans.append(i)
        
    return ans