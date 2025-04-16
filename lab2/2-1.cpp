#include <iostream>
#include <vector>
using namespace std;

// 查找目标值第一次出现的位置
int findFirst(const vector<int>& nums, int target) {
  int left = 0, right = nums.size() - 1;
  int index = -1; // 初始化为 -1 表示未找到
  while(left <= right) {
    int mid = left + (right - left) / 2;
    if(nums[mid] == target) {
      index = mid;    // 找到一个匹配项
      right = mid - 1; // 继续往左寻找更靠前的匹配项
    }
    else if(nums[mid] < target) {
      left = mid + 1;
    }
    else {
      right = mid - 1;
    }
  }
  return index;
}

// 查找目标值最后一次出现的位置
int findLast(const vector<int>& nums, int target) {
  int left = 0, right = nums.size() - 1;
  int index = -1;
  while(left <= right) {
    int mid = left + (right - left) / 2;
    if(nums[mid] == target) {
      index = mid;    // 找到一个匹配项
      left = mid + 1; // 继续往右寻找更靠后的匹配项
    }
    else if(nums[mid] < target) {
      left = mid + 1;
    }
    else {
      right = mid - 1;
    }
  }
  return index;
}

int main(){
  int n, target;
  cin >> n;

  vector<int> nums(n);

  // 当 n > 0 时，读取数组的 n 个数字
  for(int i = 0; i < n; i++){
    cin >> nums[i];
  }

  cin >> target;

  // 如果数组为空，或者没找到目标值，则直接输出 -1,-1
  if(n == 0) {
    cout << "-1,-1";
    return 0;
  }

  int first = findFirst(nums, target);
  int last = findLast(nums, target);
  cout << first << "," << last;

  return 0;
}
