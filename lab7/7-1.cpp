# include<iostream>
#include<vector>
#include<unordered_map>
#include<stack>
#include<sstream>
using namespace std;
vector<int>nextGreaterElement(vector<int>&nums1,vector<int>&nums2) {
    unordered_map<int,int>nextGreaterMap;//哈希表
    stack<int>s;
    //遍历nums2，利用栈求下一个更大元素
    for(int num:nums2) {
        while(!s.empty()&&s.top()<num) {
            nextGreaterMap[s.top()]=num;//更新下一个更大的元素
            s.pop();//既然找到了下一个更大的元素，就出栈
        }
        s.push(num);//将当前元素压入栈中
    }
    //对num1中的每个元素查找对应的下一个更大元素
    vector<int>result;
    for(int num:nums1) {
        if(nextGreaterMap.find(num)!=nextGreaterMap.end()) {
            result.push_back(nextGreaterMap[num]);
        }
        else {
            result.push_back(-1);
        }
    }
    return result;
}
int main() {
    string input1,input2;
    getline(cin,input1);
    getline(cin,input2);
    //将输入的字符串转化为整数数组
    vector<int>nums1,nums2;
    int num;
    //解析nums1
    stringstream ss1(input1);
    while(ss1>>num) {
        nums1.pushback(num);
        if(ss1.peek()==',') {
            ss1.ignore();
        }
    }
    stringstream ss2(input2);
    while(ss2>>num) {
        nums2.pushback(num);
        if(ss2.peak()==',') {
            ss2.ignore();
        }
    }
    vector<int>result=nextGreaterElement(nums1,nums2);
    for(int i=0;i<result.size();i++) {
        if(i!=0)
            cout<<",";
        cout<<result[i];
    }
    return 0;
}