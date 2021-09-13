#include <iostream>
#include <stdlib.h>
using namespace std;

typedef struct yerime{
  int num;
  struct yerime * yeppi;
}yerime;

int main()
{

  yerime * head;
  yerime * cur;
  head = (yerime *)malloc(sizeof(yerime));
  head->num = 100;
  cur = head;
  cur->yeppi = (yerime *)malloc(sizeof(yerime));
  cur = cur->yeppi;
  cur->num = 200;
  cur = cur->yeppi;
  cur = (yerime *)malloc(sizeof(yerime));
  cur->num = 300;
  cur = cur->yeppi;
  cur = (yerime *)malloc(sizeof(yerime));
  cur->num = 400;
  cur = cur->yeppi;
  cur = (yerime *)malloc(sizeof(yerime));
  cur->num = 500;
  cur->yeppi = head;


/*



  head -> yeppi = (yerime *)malloc(sizeof(yerime));
  (head->yeppi)->yeppi = (yerime *)malloc(sizeof(yerime));
  ((head->yeppi)->yeppi )-> yeppi= (yerime *)malloc(sizeof(yerime));
  (((head->yeppi)->yeppi )-> yeppi) -> yeppi = (yerime *)malloc(sizeof(yerime));


  head ->  num = 100;
  (head -> yeppi) ->  num = 200;
  ((head->yeppi)->yeppi)->  num = 300;
  (((head->yeppi)->yeppi)->yeppi)-> num= 400;
  ((((head->yeppi)->yeppi)->yeppi)->yeppi)-> num= 500;

  ((((head->yeppi)->yeppi )-> yeppi) -> yeppi) ->yeppi = head;
*/
  //cur = head;
  //cur = cur->yeppi;
  //cout << head->num << endl;
  cout<<(head-> yeppi)->num << endl;
  cout<<((head->yeppi)-> yeppi)->num << endl;
  cout<<(((head->yeppi)-> yeppi)->yeppi)->num << endl;
  cout<<((((head->yeppi)-> yeppi)->yeppi)->yeppi)->num <<endl;
  cout << (((((head->yeppi)->yeppi )-> yeppi) -> yeppi) ->yeppi)->num <<endl;
  //cout<<(((((head->yeppi)->yeppi)->yeppi)->yeppi)->yeppi)->num<<endl;


}
