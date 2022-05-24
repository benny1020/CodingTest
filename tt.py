#include <string>
#include <vector>

using namespace std;

typedef struct point {
    int x;
    int y;
}point;

int check(char target, point *r, point *l) {
    char arr[2][10] = { {'1','2','3','4','5','6','7','8','9','0'},{'Q','W','E','R','T','Y','U','I','O','P'}};
    point t;
    for(int i=0;i<2;i++) {
        for(int j=0;j<10;j++) {
            if(arr[i][j] == target) {
                t.x = i;
                t.y = j;
            }

        }
    }
    int r_value = 0;
    int l_value = 0;
    if(t.x > r->x) {
        r_value = r_value + t.x-r->x;
    } else {
        r_value = r_value + r->x - t.x;
    }

    if(t.y > r->y) {
        r_value = r_value + t.y-r->y;
    } else {
        r_value = r_value + r->y - t.y;
    }

    if(t.x > l->x) {
        l_value = l_value + t.x-l->x;
    } else {
        l_value = l_value + l->x - t.x;
    }

    if(t.y > l->y) {
        l_value = l_value + t.y-l->y;
    } else {
        l_value = l_value + l->y - t.y;
    }

    return l_value;


    if(r_value > l_value) {
        r->x = t.x;
        r->y = t.y;
        return 1;
    }
    if(r_value < l_value) {
        l->x = t.x;
        l->y = t.y;
        return 0;
    }
    if(r_value == l_value) {
        if(t.y<5) {
            l->x = t.x;
            l->y = t.y;
            return 0;
        }else {
            r->x = t.x;
            r->y = t.y;
            return 1;
        }
    }

}
//vector<int>
int solution(string line) {
    char arr[2][10] = { {'1','2','3','4','5','6','7','8','9','0'},{'Q','W','E','R','T','Y','U','I','O','P'}};
    vector<int> answer;
    point r;
    point l;
    l.x = 1;
    l.y = 0;
    r.x = 1;
    r.y = 9;

    for(int i=0;i<line.length();i++) {
        return check(line[i],&r,&l)
        answer.push_back(check(line[i],&r,&l));
    }
    //return answer;
    return
}
