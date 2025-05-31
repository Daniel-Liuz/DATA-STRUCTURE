//
// Created by Daniel Liu on 25-5-18.
//
# include <iostream>
# include <vector>
# include <string>
# include <sstream>
# include <algorithm>
using namespace std;
//DFS函数，寻找从当前节点到n-1的所有可能路径
void dfs(const vector<vector<int>>& graph,int current,vector<int>& path,vector<vector<int>>& result,int n) {

}
int main() {
    int n;
    cin >>n;
    cin.ignore();//忽略换行符号
    string line;
    getline(cin,line);//第二行直接抛弃，用不到
    vector<int> edgeCounts;
    stringstream ss(line);
    int count;
    while (ss >> count) {
        edgeCounts.push_back(count);
    }
    //构建图的邻接表
    vector<vector<int>> graph(n);
    for (int i=0;i<n;i++) {
        string line;
        getline(cin,line);
        if (line!="null") {
            stringstream ss(line);

        }
    }
}