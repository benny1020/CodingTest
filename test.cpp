#include <iostream>

using namespace std;

int num = 1;

void go()
{
	num++;
	cout << num << endl;
	if(num == 4)
		return;
	else
		go();
	num--;
}
int main(void)
{
	go();
	cout << num;
	return 0;
}
