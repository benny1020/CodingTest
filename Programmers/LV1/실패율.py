def solution(N, stages):
    arr = [0 for i in range(N+1)]
    
    for stage in stages:
        arr[stage-1] += 1
    res = []
    fail = len(stages)
    
    for a in range(N):
        if fail == 0:
            res.append(0)
        else:
            res.append(arr[a]/fail)
            fail = fail-arr[a]
    ar = dict()
    for r in range(len(res)):
        ar[r]=res[r]
    
    ar = sorted(ar.items(),reverse=True,key = lambda x : x[1])
    
    ans = []
    for a in ar:
        ans.append(a[0]+1)

    return ans