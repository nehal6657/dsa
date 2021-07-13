#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

class Stackk{
    int size;
    int top;
    int *s;

    public:
    Stackk(int n){
        size=0;
        top=-1;
        s = new int[n];
    }
    bool isFull(){
        if(top==size-1) return true;
        return false;
    }
    bool isEmpty(){
        if(top==-1) return true;
        return false;
        
    }
    void push(int n){
        if(isFull()){
            cout<<"stack is full "<<n<<" cannot be inserted\n";

        }
        else{
            top++;
            s[top] = n;
        }
    }
    int pop(){
        int x = -1;
        if(isEmpty()){cout<<"stack underflow\n";}
        else{
            x = s[top];
            top--;
        }
        return x;
    }
    void display(){
        for(int i =top;i>=0;i--){
            cout<<s[i]<<" ";
        }
        cout<<"\n";

    }
    int peek(int pos){
        int i = top-pos+1;
        if(i>0 && i<top){
            return s[i];
        }
        else{
            cout<<"invalid position\n";
            return -1;
        }

    }
    int getTop(){
        if(top==-1) return -1;
        return s[top];
    }


};