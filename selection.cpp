// selection sort 
#include <iostream>

using namespace std;

int main()
{
    int l[]={4,3,1,5,2};
   int len=sizeof(l)/sizeof(l[0]),i=0,j=0,min,temp;
   for(i=0;i<len-1;i++)
   {    min=i;
       for(j=i;j<=len-1;j++)
       {
           if(l[j]<l[min])
           {
               min=j;
           }
          
       }
       temp=l[min];
       l[min]=l[i];
       l[i]=temp;
       
   }
    i=0;
    for(i=0;i<len;i++)
    {
        cout<<l[i]<<"  ";
    }

    return 0;
}
