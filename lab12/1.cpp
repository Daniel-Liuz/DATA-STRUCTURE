# include <iostream>
# include <vector>
using namespace std;
bool dfs(const vector<vector<int>> & graph,vector<int> & visited,int course) {
    if (visited[course]==1) {//1表示正在访问，遇到了正在访问的节点，表示此时成环
        return false;
    }
    if (visited[course]==2) {
        return true;//2表示已经被访问过
    }
    visited[course]=1;//标记当前课程正在访问
    for (int i=0;i<graph[course].size();i++) {//代入与这个节点有关的逐个检查
        int nextCourse=graph[course][i];
        if (!dfs(graph,visited,nextCourse)) {
            return false;
        }
    }
    visited[course]=2;
    return true;
}
bool canFinish(int numCourse,vector<vector<int>> & prerequisites)//判断是否可以完成所有课程的函数
{
    vector<vector<int>> graph(numCourse);//创建一个n行的邻接表
    vector<int> visited(numCourse,0);//在此处 0表示未访问，1表示正在访问，2表示访问完成
    //将传入的依赖关系放到图中
    for(int i=0;i<prerequisites.size();i++) {
        graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
    }
    //遍历每个课程，进行DFS，判断是否会成环
    for (int i=0;i<numCourse;i++) {
        if (visited[i]==0 && !dfs(graph,visited,i)) {//这个节点首先是未被访问过，才需要启动dfs进行检查，这里是类似于根节点一般的状态
            return false;//如果成环了，那就无法完成所有课程
        }
    }
    return true;//如果把所有课程遍历一遍以后，
}

int main() {
    int numCourses = 0;
    int n=0;
    cin >>numCourses>>n;
    vector<vector<int>> prerequisites(n,vector<int>(2));//读入课程依赖关系
    for (int i = 0; i < n; i++) {
        cin>>prerequisites[i][0]>>prerequisites[i][1];
    }
    if (canFinish(numCourses,prerequisites)) {
        cout<<"true"<<endl;
    }
    else {
        cout<<"false"<<endl;
    }
    return 0;
}