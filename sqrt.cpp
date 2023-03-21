// sqrt till what decimal point 
#include <iostream>
using namespace std;

int main()
{
    //13 -----> 3.60555127
    // upto 2 decimal point 
    // first find integerpart
int num,places,x=0;
float i=0,j=1;
cin>>num;
cin>>places;
while(x<=places){
while(i*i<=num)
{
    i=i+j;
}
 i=i-j;
 j=j/10;
 x=x+1;
}
cout<<i;
return 0;}

