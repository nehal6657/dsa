#include<iostream>
using namespace std;


class Rectangle{
    private:
    int len, breadth;


    public:
    Rectangle(int l, int b){
        len = l;
        breadth = b;
    }
    void printLnB(){
        cout<<len<<" "<<breadth;
    }

    int area(){
        return len*breadth;
    }
    
    void changelen(int y){
        len = y;
    }
};
int main(){
    Rectangle R(11,2);
    cout<<R.area();
    R.printLnB();




    return 0;
}