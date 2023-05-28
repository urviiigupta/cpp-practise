#include <iostream>
#include <cmath>
using namespace std;
bool canplace(int mat[9][9],int i,int j,int num,int n)
{
    int l,m;
    //vertical check 
    for(l=0;l<n;l++)
    {
        if(mat[l][j]==num)
        {
            return false;
        }
    }
    //horizontal check 
    for(m=0;m<n;m++)
    {
        if(mat[i][m]==num)
        {
            return false;
        }
    }
    //box check
    int sq=sqrt(n);
    int si=(i/sq)*sq;
    int sj=(j/sq)*sq;
    for(l=si;l<si+sq;l++)
    {
        for(m=sj;m<si+sq;m++)
        {
            if(mat[l][m]==num)
            {
                return false;
            }
        }
    }
    return true;
}
bool sudokosolver(int mat[9][9],int i,int j,int n)
{
    //base case
    if(i==n)
    {
        for(int l=0;l<n;l++)
        {
            for(int m=0;m<n;m++)
            {
                cout<<mat[l][m]<<" ";
            }
            cout<<endl;
        }
        return true;
    }
    //rec case
    if(j==n)
    {
       sudokosolver(mat,i+1,0,n); 
    }
    if(mat[i][j]!=0)
    {
        sudokosolver(mat,i,j+1,n);
    }
    else
    {
        for(int num=1;num<=n;num++)
        {
            if(canplace(mat,i,j,num,n)==true)
            {
                mat[i][j]=num;
                int ans=sudokosolver(mat,i,j+1,n);
                if(ans==true)
                {
                    return true;
                }
                mat[i][j]=0;
                
            }
        }
        return false;
        
    }
    
    
}
int main()
{
    int mat[9][9]={
        {0,3,0,0,7,0,0,0,0},
        {6,0,0,1,9,5,0,0,0},
        {0,9,8,0,0,0,0,6,0},
        {8,0,0,0,6,0,0,0,3},
        {4,0,0,8,0,3,0,0,1},
        {7,0,0,0,2,0,0,0,6},
        {0,6,0,0,0,0,2,8,0},
        {0,0,0,4,1,9,0,0,5},
        {0,0,0,0,8,0,0,7,9}
        
    };
    sudokosolver(mat,0,0,9);

    return 0;
}
