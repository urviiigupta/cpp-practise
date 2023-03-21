#include <iostream>
using namespace std;
void s (int arr[4][4],int tr, int tc )
{ int sr=0,sc=0;
int er=tr-1,ec=tc-1;
while(sc<=ec && sr<=er)
{
    for(int i=sc;i<=ec;i++)
    {
        cout<<arr[sr][i]<<" ";
    }
    sr++;
    for(int j=sr;j<=er;j++)
    {
        cout<<arr[j][ec]<<" ";
    }
    ec--;
    for(int k=ec;k>=sc;k--)
   { 
       cout<<arr[er][k]<<" ";
    
   }
   er--;
   for(int l=er;l>=sr;l--)
   {
       cout<<arr[l][sc]<<" ";
       
   }
   sc++;

}
    
}

int main()
{
    int arr[4][4]={{1,2,3,4},
        {1,2,3,4},
        {1,2,3,4},{
            1,2,3,4}};
    s( arr, 4,4);
    
}

