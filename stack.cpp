  #include <iostream>
  #include <vector>

  using namespace std;

  class stack
  {
    vector<int> v;
    public:
    void push (int d)
    {
        v.push_back(d);
    }

    void pop()
    {
        v.pop_back();
    }
    int top()
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
  { stack s;
    s.push(4);
    s.push(3);
    s.push(8);
    s.push(2);
    while(!s.empty())
  {
    cout<<s.top()<<" ";
    s.pop();

  }
    return 0;
  }