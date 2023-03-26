#include <iostream>

using namespace std;
int stringtoint(string s, int l)
{  if(l==0)
{
    return 0;
}
  char ch=s[l-1];
    int ele=ch-'0';
    return stringtoint(s,l-1)*10 +ele ;
}
int main()
{   string s;
    cin>>s;
    int l=s.length();
    cout<<stringtoint(s,l);
    return 0;
}