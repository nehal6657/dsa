#include<iostream>
using namespace std;

template <class T>
class Rectangle{
    private:
    T len, breadth;


    public:
    Rectangle(T l, T b){
        len = l;
        breadth = b;
    }
    void printLnB(){
        cout<<len<<" "<<breadth;
    }

    int area(){
        return len*breadth;
    }
    
    void changelen(T y){
        len = y;
    }
};
int main(){
    Rectangle<float> R(11.55,2.01);
    cout<<R.area();
    R.printLnB();




    return 0;
}