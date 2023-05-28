#include <iostream>

using namespace std;
void permutation(char inp[10000],int i)
{   
    if (inp[i]=='\0')
    {   cout<<inp<<endl;
        return;
    }
    for(int j=i;inp[j]!='\0';j++)
   { swap(inp[i],inp[j]);
    permutation(inp,i+1);//abc and acb
    swap(inp[i],inp[j]); //very important 
       
   }
   
}
int main()
{
    char inp[10000];
    cin>>inp; //abc
    permutation(inp,0);

    return 0;
}
