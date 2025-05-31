#include <iostream>
#include<vector>
#include<cmath>
#include<climits>
using namespace std;
struct Point {
    int x,y;//点的x和y的坐标
};
//计算两点之间曼哈顿距离
long long manhattanDistance(const Point & p1,const Point & p2) {
    return abs(p1.x-p2.x)+abs(p1.y-p2.y);
}
int main() {
    int n;//Point的个数
    cin>>n;
    if (n<=1) {
        if (n==1) {//如果这个时候只有1个点，还是需要读入这个点的坐标,但是结果置为0
            int temp_x,temp_y;
            cin>>temp_x>>temp_y;
        }
        cout<<0<<endl;
        return 0;
    }
    vector<Point> points(n);//因为有n个点，所以这里vector初始化为n
    for (int i=0;i<n;i++) {
        cin>>points[i].x>>points[i].y;//依次去读入每一个点的坐标
    }
    //Prim算法的实现
    //min_cost[i]存储点i连接到当前已构建的MST的最小代价
    //使用LLONG_max作为初始“无穷大"值
    vector<long long>min_cost(n,LLONG_MAX);
    //visited[i]标记点i是否已经被包含在MST（Minimum Spanning Tree最小生成树中）
    vector<bool>visited(n,false);//标记其是否在最小生成树中
    //初始化总代价函数
    long long total_min_cost=0;//最小总费用
    //Prim算法从第一个点（索引为0的点）开始构建MST
    min_cost[0]=0;//将第一个点加入MST的代价是0
    //MST最终会有n-1条边，但Prim算法会迭代n次来选择n个顶点加入MST
    for (int count=0;count<n;count++) {
        int u =-1;//u是作为当前迭代中，要加入MST的顶点的索引
        //使用LLONG_MAX作为寻找最小代价的初始值
        long long current_min_val=LLONG_MAX;
        //步骤1：选择顶点
        //在所有尚未加入MST的顶点中，找到一个拥有最小min_cost[v_idx]的顶点v_idx;
        for (int v_idx=0;v_idx<n;v_idx++) {
            if (!visited[v_idx]&&min_cost[v_idx]<current_min_val) {//如果此时这个节点不在MST树中，且这个点所需要消耗的步数是最小的
                current_min_val=min_cost[v_idx];//更新当前阶段能够找到的最小值
                u=v_idx;//并且把这个点也确立为下一个要连接的点
            }
        }
        if (u==-1) {//如果这样一趟下来，发现u的值没有被更新，这说明是没有下一个点了，但是这种情况是不会发生的
            break;
        }
        //步骤2：将选中的顶点u加入MST
        visited[u]=true;//现在要对他下手了，所以要把他放进MST中
        total_min_cost+=min_cost[u];//累加这条边的代价
        //步骤3:更新u的邻居min_cost
        //对于所有尚未加入MST的顶点v_idx（即u的“邻居”）
        for (int v_idx=0;v_idx<n;v_idx++) {
            if (!visited[v_idx]) {//如果这个节点还未被添加到MST中的话
                long long distance_uv=manhattanDistance(points[u],points[v_idx]);
                if (distance_uv<min_cost[v_idx]) {
                    min_cost[v_idx]=distance_uv;//更新为更小的来连接代价
                }
            }
        }
    }
    cout<<total_min_cost<<endl;
}
