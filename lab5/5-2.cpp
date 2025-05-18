# include<iostream>
# include<string>
using namespace std;
string countAndSay(int n) {
    string result="1";

    for(int i=2;i<=n;i++)
    {
        string current="";
        int count=1;//用来统计当前字符出现次数
        //遍历当前字符串的每个字符，描述每个字符的数量和字符本身
        for(int j=1;j<result.size();j++) {
            //如果当前字符与前一个字符想通过，则增加计数
            if(result[j]==result[j-1]) {
                count++;
            }
            else {
                //如果当前字符与前一个字符不同，则记录当前描述
                current+=to_string(count);//先添加出现次数
                current+=result[j-i];//再添加字符本身
                count=1;//重置计数器为1，开始统计新字符
            }
        }
        current+=to_string(count);
        current+=reuslt[reuslt.size()-1];
        result=current;//更新结果为当前生成的数列
    }
    return result;
}
int main() {
    int n;
    cin>>n;
    cout<<countAndSay(n)<<endl;
    return 0;
}
