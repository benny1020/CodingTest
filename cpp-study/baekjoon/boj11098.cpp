#include <iostream>
#include <map>
using namespace std;

int main(void) {
    int test_case, num;
    map<string,int> m;
    cin >> test_case;
    int max_price;
    string max_name;


    for(int i=0;i<test_case;i++) {
        max_price = 0;
        cin >> num;
        for(int j=0;j<num;j++) {
            int price;
            string name;
            cin >> price >> name;
            //cout << price  <<endl;
            if(price > max_price) {
                max_price = price;
                max_name =  name;
            }
                
        }
        cout << max_name<<endl;
        
    } 
    return 0;
}