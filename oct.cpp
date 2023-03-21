#include <iostream>
using namespace std;
int dig(int num);
int main()
{ int num;
cin>>num;
int len=dig(num);
int l[len],i=0;
while(i<len)
{
    l[i]=num%8;
    num=num/8;
    i++;
} i--;
while(i>=0)
{
    cout<<l[i];
    i--;
}


    return 0;
}
int dig(int num)
{int count=0;
    while(num>=1)
    { 
        num=num/10;
        count++;
    }
    return count;
}