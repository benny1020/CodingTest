#include <iostream>
#include <vector>

using namespace std;
// 준비 - 호출 - 복원
// 아래와 같이 새로운 벡터 배열을 만들어서 복사한후 그것을 인자로 전달한다.

int go(vector<int> &a) {
  int n = a.size();
  if (n == 2)
    return 0;
  int ans = 0;
  for (int i = 1; i < n - 1; i++) {
    int energy = a[i - 1] * a[i + 1];
    vector<int> b(a);
    b.erase(b.begin() + i);
    energy += go(b);
    if (ans < energy) {
      ans = energy;
    }
  }
  return ans;
}
/*  내가 짠 코드
int go(int score,int n, vector<int>arr)
{
    if(n==2)
        return score;
    int ans = -1;

    for(int i=1;i<n-1;i++)
    {
        vector<int>temp_arr = arr;
        temp_arr.erase(temp_arr.begin()+i);
        int temp = go(score+(arr[i-1]*arr[i+1]),n-1,temp_arr);
        if(ans<temp)
            ans = temp;
    }
    return ans;
}
*/

int main(void) {
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  cout << go(arr) << endl;
  return 0;
}
