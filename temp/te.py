def solution(board, moves):
    new=[]
    cnt=0
    cnt1=0
    for i in moves:
        cnt=0
        for j in range(len(moves)):
            if board[j][i-1]!=0 :
                new.append(board[j][i-1])
                if len(new)!=1 and (new[len(new)-1]==new[len(new)-2]):
                    new.remove(new[len(new)-1])
                    new.remove(new[len(new)-1])
                    cnt1+=2
                board[j][i-1]=0
                break
            if board[j][i-1]==0:
                cnt+=1
                if cnt==len(board):
                    break

    return cnt1



"""
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
"""
