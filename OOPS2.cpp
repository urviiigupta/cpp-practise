//OOPS 

#include <iostream>
using namespace std;
class car
    {   public:
        string name;
        string colour;
        int price;
        int seats;
        
        //parameterized constructor 
        car(string n, string c, int p, int s)
        {
            cout<<"coding"<<endl;
            name=n;
            colour=c;
            price=p;
            seats=s;
        }
     };
int main()
{   
    //whenever an object is created , constructor is called
    car x("BMW","white",50,5); //x is called an object 
    
     // . opereator 
    //objectname.buckettoaccess
    
    cout<<x.name<<endl;
    cout<<x.colour<<endl;
    cout<<x.price<<endl;
    cout<<x.seats<<endl;
    
    return 0;
}
