#include <iostream>
#include <queue>
using namespace std;
int main()
{
    queue<int>q;
     q.push(5);
   q.push(3);
   q.push(44);
   q.push(9);
   
   while(!q.empty())
   {
      cout<<q.front()<<" ";
      q.pop();
   }
   
    return 0;
 
}