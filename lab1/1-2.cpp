#include <iostream>
using namespace std;
int main(){
  int m,n,target;
  cin >>m>>n;
  int a[100][100]={0};
  for (int i=0;i<n;i++)
  {
    for(int j=0;j<m;j++)
    {
      cin>>a[i][j];
    }
  }
  cin>>target;
  int i=0,j=m-1;//从右上角开始遍历
  while(i<n&&j>=0) {
    if (a[i][j] == target) {
      cout << "true";
      return 0;
    }
    else if (a[i][j] < target) {
      i++;
      j=m-1;
    }
    else
    {
      j--;
    }
  }
  cout<<"false";
  return 0;
}