# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;
//快速选择算法，用于找到数组中第K个最大的元素
int quickSelect(vector<int>&nums,int left,int right,int k) {
    //选择数组中的最后一个元素作为基准
    int pivot =nums[right];
    int i=left;
    //将小于pivot的元素移到左边，大于pivot的元素移到右边
    for(int j=left;j<right;j++) {
        if(nums[j]>pivot) {
            swap(nums[i],nums[j]);
            i++;
        }
    }
    swap(nums[right],nums[i]);//将基准放到正确的位置
    //如果i的位置正好是 第K个大的元素，返回
    if(i==k) {
        return nums[i];
    }
    //如果i的位置大于k，说明第K大的元素在左边部分
    else if (i>k) {
        return quickSelect(nums,left,i-1,k);
    }
    //如果i的位置小于k，说明第K大的元素在右边部分
    else {
        return quickSelect(nums,i+1,right,k);
    }
}
int main() {
    int n,k;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++) {
        cin>>nums[i];
    }
    cin>>k;//输入k值
    //调用快速选择算法,k的值是从0开始的，所以需要传递k-1
    cout<<quickSelect(nums,0,n-1,k-1)<<endl;
    return 0;
}
