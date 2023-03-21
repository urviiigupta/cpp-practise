#include <iostream>

using namespace std;

int main()
{ int l[]={3,5,0,2,4};
int len=sizeof(l)/sizeof(l[0]),i,j,ele;
for(i=1;i<len;i++)
{
    ele=l[i];
    j=i-1;
    for(j=i-1;j>=0;j--)
    {
        if(l[j]>ele)
        {
            l[j+1]=l[j];
        }
        else
        {
            break;
        }
    }
    l[j+1]=ele;
}
for(i=0;i<len;i++)
{
    cout<<l[i]<<"  ";
}

    return 0;
}
