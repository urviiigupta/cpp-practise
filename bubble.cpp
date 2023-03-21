// bubble sort 
#include <iostream>

using namespace std;

int main()
{
    int l[]={7,6,3,2,6,4,6,9};
    int len=sizeof(l)/sizeof(l[0]);
    int i=0,j=0,temp;
    for(i=0;i<len-1;i++)
    { bool swap=false;
        for(j=0;j<(len-i-1);j++)
        {
            if(l[j]>l[j+1])
            {	swap=true;
                temp=l[j];
                l[j]=l[j+1];
                l[j+1]=temp;
            }
        }
	if (swap==false)
	{
		break;	}
    }
    i=0;
    for(i=0;i<len;i++)
    {
        cout<<l[i]<<" ";
    }

    return 0;
}
