def solution(participant, completion):
    part = dict()
    part_complete = dict()
    for person in completion:
        if person in part.keys():
            part[person] += 1
        else:
            part[person] = 1
            
    for person in participant:
        if person not in part.keys() or part[person]==0:
            return person
        else:
            part[person] -=1
        
       