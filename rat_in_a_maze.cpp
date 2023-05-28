//rat in a maze 
#include <iostream>
using namespace std;
int c=0;
bool ratinamaze(char maze[4][5],int sol[4][4],int i, int j,int rows, int cols)
{
    //base case
    if(i==rows-1 && j==cols-1)
    {
        sol[i][j]=1;
        //print sol matrix
        for(int l=0;l<rows;l++)
    {
        for(int m=0;m<cols;m++)
        {
            cout<<sol[l][m]<<" ";
        }
        cout<<endl;
    }
    // return true; for one path 
    sol[i][j]=0;
    cout<<"----------"<<endl;
    c++;
    return false; //for multiple paths
    }
    
    //rec case
    sol[i][j]=1;
    //forward
    if(j<=cols-2 && maze[i][j+1]!='B')
    {
       bool ans= ratinamaze(maze,sol,i,j+1,rows,cols);
       if(ans==true)
       {
           return true;
       }
    }
    //downward
    if(i<=rows-2 && maze[i+1][j]!='B')
    {
        bool ans=ratinamaze(maze,sol,i+1,j,rows,cols);
        if(ans==true)
        {
            return true;
        }
    }
    sol[i][j]=0;
    
    return false;
    
}
int main()
{
    char maze[4][5]={
        "UBUU",
        "UUUU",
        "BBUU",
        "UBBU"
    };
    int sol[4][4]={0};
    ratinamaze(maze,sol,0,0,4,4);
    cout<<"total paths  "<<c;
    

    return 0;
}
