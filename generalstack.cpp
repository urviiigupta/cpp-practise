#include <iostream>
  #include <vector>

  using namespace std;
template <typename U>
  class stack
  {
    vector<U> v;
    public:
    void push (U d)
    {
        v.push_back(d);
    }

    void pop()
    {
        v.pop_back();
    }
    U top()
    {
        return v[v.size()-1];
    }
    int size()
    {
        return v.size();
    }
    bool empty()
    {
        return v.size()==0;
    }


  };
  int main()
  { stack <char>s;
    s.push('A');
    s.push('B');
    s.push('C');
    s.push('D');
    while(!s.empty())
  {
    cout<<s.top()<<" ";
    s.pop();

  }
    return 0;
  }