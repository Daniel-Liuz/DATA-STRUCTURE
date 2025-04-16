# include<iostream>
#include <vector>
#include <string>
using namespace std;
bool isSubstring(const string&s,const string &word)
{
  int sIndex=0,wIndex=0;
  while(sIndex<s.length()&&wIndex<word.length())
  {
    if(s[sIndex]==word[wIndex])
    {
      wIndex++;
    }
    sIndex++;
  }
  if(wIndex==word.length())
  {
    return 1;
  }
  else
    return 0;
}
int countSub(const string&s,const vector<string>&words)
{
  int count=0;
  for(const string& word:words)
  {
    if (isSubstring(s,word))
    {
      count++;
    }
  }
  return count;
}
int main()
{
  string s;
  int n;
  cin>>s;
  cin>>n;
  vector<string> words(n);
  for (int i=0;i<n;i++)
  {
    cin>>words[i];
  }
  cout<<countSub(s,words)<<endl;
}