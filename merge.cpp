void sort(int a[],int b[],int m,int n)
{ int i,j,k;
i=m-1;
j=n-1;
k=m+n-1;

while(i>=0 and j>=0)
{ if(a[i]>=b[j])
  {  
    a[k]=a[i];
    i--;}
    else
    {
        a[k]=b[j];
        j--;
    }
    k--;
}

while(i>=0)
{
    a[k]=a[i];
    i--;
    k--;
}
while(j>=0)
{
    a[k]=b[j];
    j--;
    k--;
}
    
}

#include <iostream>

using namespace std;

int main()
{
    int a[7]={3,7,9};
    int b[4]={2,5,8,10};
    int m=3,n=4;
    sort(a,b,m,n);
    int i;
    for(i=0;i<=m+n-1;i++)
    {
        cout<<a[i]<<" ";
        
    }

    return 0;
}
