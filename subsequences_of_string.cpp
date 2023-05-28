#include <iostream>

using namespace std;
void substring(char inp[10000],int i,char out[10000],int j )
{
    if(inp[i]=='\0')
    {
        out[j]='\0';
        cout<<out<<endl;
        return;
    }
    //with a 
    out[j]=inp[i];
    substring(inp,i+1,out,j+1);
    //without a
    substring(inp,i+1,out,j);
}
int main()
{
    char inp[10000],out[10000];
    cin>>inp; //abc
    substring(inp,0,out,0);

    return 0;
}
