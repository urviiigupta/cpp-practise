#include <iostream>
using namespace std;
class car
    {   public:
        string name;
        string colour;
        int price;
        int seats;
        
        //default constructor 
        car()
        {
            cout<<"hello"<<endl;
        }
     };
int main()
{   
    //whenever an object is created , constructor is called
    car  x; //x is called an object 
    car y;
    cout<<"after cons"<<endl;
     // . opereator 
    //objectname.buckettoaccess
    x.name="bmw";
    x.colour="white";
    x.price=50;
    x.seats=5;
    
    cout<<x.name<<endl;
    cout<<x.colour<<endl;
    cout<<x.price<<endl;
    cout<<x.seats<<endl; 
    
    return 0;
}
