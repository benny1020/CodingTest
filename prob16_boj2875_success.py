#boj 2875 대회 or 인턴
"""
문제
백준대학교에서는 대회에 나갈 때 2명의 여학생과 1명의 남학생이 팀을
결성해서 나가는 것이 원칙이다. (왜인지는 총장님께 여쭈어보는 것이 좋겠다.)


백준대학교는 뛰어난 인재들이 많아 올해에도 N명의 여학생과 M명의 남학생이
팀원을 찾고 있다. 대회에 참여하려는 학생들 중 K명은 반드시
인턴쉽 프로그램에 참여해야 한다. 인턴쉽에 참여하는 학생은 대회에 참여하지
못한다.

백준대학교에서는 뛰어난 인재들이 많기 때문에, 많은 팀을 만드는 것이 최선이다.

여러분은 여학생의 수 N, 남학생의 수 M, 인턴쉽에 참여해야하는 인원 K가 주어질 때 만들 수 있는 최대의 팀 수를 구하면 된다.

입력
첫째 줄에 N, M, K가 순서대로 주어진다. (0 ≤ M ≤ 100, 0 ≤ N ≤ 100, 0 ≤ K ≤ M+N),

출력
만들 수 있는 팀의 최대 개수을 출력하면 된다.
"""
# 먼저 인턴을 고려하지 않고 팀의 수를 구하고
# while 문을 이용해 팀 하나씩 해체하면서 조건 만족하는지 확인 후 팀 출력
# 주의해야할 점
# 애초에 인턴이 여자남자 수 합보다 큰 경우
# 인턴이 0인경우 
woman, man, intern = input().split()


man = int(man)
woman = int(woman)
intern = int(intern)

if woman + man < intern :
    print(0)
    exit(1)

if woman//2 > man:
    woman = woman -man*2
    team = man
    man = 0
    while(intern > woman + man and intern != 0):
        man+=1
        woman+=2
        team-=1
    print(team)

else:
    man -= (woman//2)
    team = woman//2
    woman %= 2
    while(intern > woman + man and intern != 0):
        man+=1
        woman+=2
        team-=1
    print(team)
