/*
You should use the standard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful.
*/

#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int Answer;

int main(int argc, char** argv)
{
	int T, test_case;
	int len,t;
	string str_b;
	/*
	   The freopen function below opens input.txt file in read only mode, and afterward,
	   the program will read from input.txt file instead of standard(keyboard) input.
	   To test your program, you may save input data in input.txt file,
	   and use freopen function to read from the file when using cin function.
	   You may remove the comment symbols(//) in the below statement and use it.
	   Use #include<cstdio> or #include <stdio.h> to use the function in your program.
	   But before submission, you must remove the freopen function or rewrite comment symbols(//).
	 */

	// freopen("input.txt", "r", stdin);

	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{

		cin >> len;
        cin >> t;
        int a[len];
        for(int j=1;j<=len;j++)
            a[j] = 0;
        cin >> str_b;

        for(int j=1;j<=len;j++)
        {
            if(str_b[j-1] == '1')
            {

                if(j>t && j<=len-t) // 둘다 만족하는경우
                {
                    if(j+t >len)
                    {
                        if(j-2*t>=1)
                        {
                            if(str_b[j-1-2*t] == '1')
                                a[j-t]=1;
                        }
                        else
                            a[j-t]=1;
                    }
                    else
                    {
                        if(a[j-t] == 0)
                        {
                            if(j+2*t<=len)
                            {
                                if(str_b[j-1+2*t]=='1')
                                    a[j+t]=1;
                                else
                                    a[j-t]=1;
                            }
                            else
                                a[j+t]=1;

                        }

                    }

                    continue;
                }
                if(j>t)
                {
                    if(j-2*t >=1)
                    {
                        if(str_b[j-1-2*t]=='1')
                            a[j-t]=1;
                    }
                    else
                        a[j-t] = 1;
                }
                if(j<=len-t)
                {
                    if(j+2*t <=len)
                    {
                        if(str_b[j-1+2*t]=='1')
                            a[j+t]=1;
                    }
                    else
                        a[j+t] = 1;
                }
            }

        }
        cout << "Case #" << test_case+1 << endl;
        Answer = 0;
        for(int k=1;k<=len;k++)
            cout << a[k];
        cout <<endl;

	}

	return 0;//Your program should return 0 on normal termination.
}
