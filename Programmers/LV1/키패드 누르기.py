def solution(numbers, hand):
    phone = [[3,1],[0,0],[0,1],[0,2],[1,0],[1,1],[1,2],[2,0],[2,1],[2,2]]
    left = [3,0]
    right = [3,2]
    answer=''
    left_num = [1,4,7]
    right_num = [3,6,9]
    for number in numbers:
        if number in left_num:
            use_hand = "left"
        elif number in right_num:
            use_hand = "right"
        else:
            left_count = abs(phone[number][0] - left[0]) + abs(phone[number][1] - left[1])
            right_count = abs(phone[number][0] - right[0]) + abs(phone[number][1] - right[1])
            if left_count == right_count:
                use_hand = hand
            elif left_count > right_count:
                use_hand = "right"
            else:
                use_hand = "left"
        if use_hand == "right":
            answer +='R'
            right = phone[number]
        else:
            answer +='L'
            left = phone[number]
        
    
    return answer