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
    /**
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
    */

   for (l = si; l < si + sq; l++) {
    for (m = sj; m < sj + sq; m++) {
        if (mat[l][m] == num) {
            return false;
        }
    }
}

    
    return true;
}


void printmatrix(int mat[9][9],int n)
{
    cout<<"  -- print -- " <<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<mat[i][j];
        }
        cout<<endl;

    }
    return;
}
bool sudokosolver(int mat[9][9],int i,int j,int n)
{
    //base case
    if(i==n)
    {   cout<<"baseee caseee"<<endl;
        for(int l=0;l<n;l++)
        {
            for(int m=0;m<n;m++)
            {
                cout<<mat[l][m]<<"  ";
            }
            cout<<endl;
        }
        return true;
    }
    //rec case
    if(j==n)
    {
       return sudokosolver(mat,i+1,0,n); 
    }
    if(mat[i][j]!=0)
    {
        return sudokosolver(mat,i,j+1,n);
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
    int mat[9][9]= {
        {4,0,1,0,9,0,0,0,0},
        {0,0,8,1,0,6,4,3,0},
        {3,9,0,4,0,5,0,7,2},
        {0,0,0,0,0,7,2,0,0},
        {1,3,0,0,0,0,0,5,8},
        {0,0,5,8,0,0,0,0,0},
        {7,4,0,5,0,9,0,6,1},
        {0,1,2,6,0,3,5,0,0},
        {0,0,0,0,1,0,3,0,4} ;
    }
        
    
    sudokosolver(mat,0,0,9);

    return 0;
}

