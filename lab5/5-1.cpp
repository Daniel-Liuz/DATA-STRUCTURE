#include <iostream>
using namespace std;

int recursive(int a,int b){
  if(b==0)
  {
    return 0;
  }
  if(b<0)//根据规律 a * (-b) = - (a * b)
  {
    return -recursive(a,-b);
  }
  if(b%2!=0)  // 当 b 为奇数时，利用递归将乘法问题分解为：a * b = a + a * (b - 1)
  {
    return a+ recursive(a,b-1);
  }
  // 当 b 为偶数时，根据乘法性质：a * b = 2 * (a * (b/2))
  // 递归计算 a * (b/2)
  int half = recursive(a, b / 2);
  // 返回将上面得到的结果加上自身，即：half + half = a * b
  return half+half;
}
int main()
{
  int a,b;
  cin>>a>>b;
  cout<<recursive(a,b)<<endl;
  return 0;
}