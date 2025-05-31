//
// Created by Daniel Liu on 25-5-31.
//
# include<iostream>
# include<vector>
# include<algorithm>
using namespace std;
//此处需要自定义一个比较函数，用于按区间结束时间升序排序
bool compareInterval(const vector<int>& a,const vector<int>& b) {
    //主要按结束时间a[1]和b[1]比较
    return a[1]<b[1];
}
int main() {
    int n;//读取区间数量
    cin>>n;
    //处理没有区间的边界的情况
    if (n==0) {
        cout<<"0"<<endl;
        return 0;//此时便要保存退出了
    }
    //创建一个二维数组vector来存储区间，下面表示的是n*2维矩阵
    vector<vector<int>> intervals(n,vector<int>(2));
    //读取每个区间的开始和结束时间
    for (int i=0;i<n;i++) {
        cin>>intervals[i][0]>>intervals[i][1];
        //在这里intervals[i][0]表示start_i
        //在这里intervals[i][1]表示end_i
    }
    //使用自定义比较函数，按结束时间对区间进行排序
    sort(intervals.begin(),intervals.end(),compareInterval);
    //贪心选择的过程
    int kept_count=0;//这里记录着我们能保留的非重叠区间的最大数量
    int last_kept_end=-100000;//初始化为负值，要小于endi的最小值可以确保第一个区间总能够被选中
    //进行贪心算法的迭代
    for (int i=0;i<n;i++) {
        //检查当前区间的开始时间是否大于等于>=上一个保留区间的结束时间
        if (intervals[i][0]>=last_kept_end) {//注意，这里还需要考虑取等的情况
            //如果不重叠，我们就保留这个区间，并更新上一个保留区间的 结束时间
            kept_count++;
            last_kept_end=intervals[i][1];
        }
    }
    //本地要求的是需要移除的最少区间数=总区间数量-最多能保留的非重叠区间数
    int min_removed_count=n-kept_count;
    cout<<min_removed_count<<endl;
    return 0;
}