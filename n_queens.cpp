//n queens

#include <iostream>

using namespace std;
int c=0;
bool canplace(int solboard[100][100],int n, int i, int j)
{
    //vertical
    for(int m=i-1;m>=0;m--)
    {
        if(solboard[m][j]==1)
        {
            return false;
        }
    }
    // right diagonal
    int u=i-1;
    int v=j+1;
    while(u>=0 && v<=n)
        {
            if(solboard[u][v]==1){
                return false;
            }
            u--;
            v++;
        }
    //left diagnol 
    int p=i-1;
    int q=j-1;
    while(p>=0 && q>=0)
        {
            if(solboard[p][q]==1){
                return false;
            }
            p--;
            q--;
        }
    return true;
    
    
}
bool nqueen(int solboard[100][100],int n, int i)
{
    //base case
    if(i==n)
        {
            for(int l=0;l<n;l++)
            {
                for(int m=0;m<n;m++)
                {
                    cout<<solboard[l][m]<<" ";
                }
                cout<<endl;
            }
            cout<<endl;
            c++;
            return false;
        }
        
    
    
    
    //recursive case
    for(int j=0;j<n;j++)
    {
        if(canplace(solboard,n,i,j)==true)
            {
                solboard[i][j]=1;
                bool ans=nqueen(solboard,n,i+1);
                if(ans==true)
                {
                    return true;
                }
                solboard[i][j]=0;
                
                
            }
    }
    return false;
}
int main()
{
    int solboard[100][100]={0};
    int n;
    cin>>n;
    nqueen(solboard,n,0);
    
    cout<<"total solutions  "<<c;
    return 0;
}
