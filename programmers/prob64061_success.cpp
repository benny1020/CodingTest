// https://programmers.co.kr/learn/courses/30/lessons/64061
def solution(board, moves):
    li = []
    answer = 0
   # answer = len(board)
    #return answer
    for i in range(len(moves)):
        for j in range(len(board) ):
            if board[j][moves[i]-1] != 0:
                li.append(board[j][moves[i]-1])
                board[j][moves[i]-1] = 0
                break
        if(len(li) >=2):
            if li[len(li)-2] == li[len(li)-1]:
                li.pop()
                li.pop()
                answer+=2




    return answer
