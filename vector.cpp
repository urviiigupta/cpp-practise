#include <iostream>
#include <vector> //stl standard template library
using namespace std;
/*  class vector<int>
{
    push_back();
}   */
vector<int> f(vector<int> v)//vectors are passed by value 

{
    vector<int>p;
    p.push_back(3);
    p.push_back(4);
    p.push_back(5);
    p.push_back(6);
    return p;
}
int main()
{
    //vector<datatype> nameofvector;
    vector<int> v;
    //insert elements in vector 
    //vectorname.push_back(data);
    v.push_back(4);
    v.push_back(2);
    v.push_back(5);
    v.push_back(7);
    v.push_back(9);

    //vectorname.size();
    cout<<v.size()<<endl;
    cout<<v.capacity()<<endl;
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
    v.pop_back();
    cout<<v.size()<<endl;
    cout<<v.capacity()<<endl;

    for(auto i=v.begin();i!=v.end();i++)
    {
        cout<<*i<<" ";
    }
    cout<<endl;

    return 0;
}
