#include <iostream>
#include<vector>
using namespace std;
int MaxArray(const vector<int>&nums)
{
  int currentMax=nums[0];
  int MaxSum=nums[0];
  for(int i=1;i<nums.size();i++)
  {
    currentMax=max(nums[i],currentMax+nums[i]);
    MaxSum=max(MaxSum,currentMax);
  }
  return MaxSum;
}
int main()
{
  vector<int>nums;
  int num;
  while(cin>>num)
  {
    nums.push_back(num);
  }
  int result =MaxArray(nums);
  cout<<result<<endl;
}