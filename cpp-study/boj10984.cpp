#include <iostream>

using namespace std;

int main(void) {
    int n;
    cin >> n;
    int num;
    int grad;
    double total;
    int grad_total;
    double score;
    while(n--) {
        cin >> num;
        total = 0;
        grad_total =0;
        while(num--) {
            cin  >> grad >> score;
            total+=score*grad;
            grad_total +=grad;
        }
        printf("%d %.1f\n",grad_total,total/grad_total);
    }
    return 0;
}
