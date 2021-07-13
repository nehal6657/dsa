#include<iostream>
using namespace std;
//call by value
void swap(int a, int b){
    int tmp;
    tmp = a;
    a = b;
    b = tmp;
}

// call by address
void swap1(int *a, int *b){
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

//call by refrence
void swap2(int &a, int &b){
    int tmp;
    tmp = a;
    a = b;
    b = tmp;
}


int main(){
    int x,y;
    x = 10;
    y = 15;
    swap(x,y);
    cout<<x<<" "<<y;
    swap1(&x,&y);
    cout<<x<<" "<<y;
    x = 10;
    y = 15;
    swap2(x,y);
    cout<<x<<" "<<y;


    return 0;
}