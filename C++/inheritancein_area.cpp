#include<iostream>
using namespace std;

class Shape {
    public :
     float  r;
     int l ,b ;
      void radius(){
        cout<<"Enter Radius : ";
        cin>>r;
      }
      void len_bre(){
        cout<<"\nEnter length and breath : ";
        cin>>l>>b;
      }
};

class Circle : virtual Shape {
    public :
    void area_of_circle (){
        cout<<"Area of circle is : "<<3.14 * r * r<<endl;
    }
};
  class Rectangle : virtual public Shape {
       public :
       void area_of_rectangle(){
        cout<<"Area of rectangle : "<<l*b;
       }
  };
  
  class Areas : public Circle , public Rectangle {};
  int main(){
    // Circle c1;
    // c1.radius();
    // c1.area_of_circle();
    // Rectangle r1;
    // r1.len_bre();
    // r1.area_of_rectangle();
    Areas a1;
    a1.radius();
    a1.area_of_circle();
    a1.len_bre();
    a1.area_of_rectangle();
    return 0;
  }
