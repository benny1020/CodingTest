def solution(nums):
    ans = len(set(nums))
    if ans > len(nums)/2:
        ans = len(nums)/2
    
    return ans