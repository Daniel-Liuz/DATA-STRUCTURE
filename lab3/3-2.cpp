#include <iostream>
#include <vector>
using namespace std;
void merge(vector<int>& nums,int left,int mid,int right)
{
  vector<int>temp(right-left+1);
  int i=left,j=mid+1,k=0;
  //从两个子数组中，逐步比较元素并将较小值存入临时数组
  while(i<=mid&&j<=right)
  {
    if(nums[i]<=nums[j])
    {
      temp[k++]=nums[i++];
    }
    else
    {
      temp[k++]=nums[j++];
    }
  }
  //如果左边子数组还有剩余元素，依次存入
  while(i<=mid)
  {
    temp[k++]=nums[i++];
  }
  //如果右边子数组还有剩余元素，依次存入
  while(j<=right)
  {
    temp[k++]=nums[j++];
  }
  //将排序好的临时数组复制回原数组的对应区间
  for(int p=0;p<k;p++)
  {
    nums[left+p]=temp[p];
  }
}
void mergeSort(vector<int>&nums,int left,int right){
  if (left>=right){
    return;//递归终止条件
  }
  int mid=left+(right-left)/2;
  mergeSort(nums,left,mid);
  mergeSort(nums,mid+1,right);
  merge(nums,left,mid,right);
}
int main()
{
  vector<int>nums;
  int num;
  while(cin>>num)
  {
    nums.push_back(num);
  }
  mergeSort(nums,0,nums.size()-1);
  for(int i=0;i<nums.size();i++)
  {
    cout<<nums[i]<<" ";
  }
  cout<<endl;
  return 0;
}