#include<iostream>
using namespace std;
struct  rect
{
    int l;
    int r;
    /* data */
};

int main(){
    rect r1 = {10,5};
    rect *p = &r1;

    cout<<r1.l<<" "<<r1.r<<endl;
    (*p).l = 1;
    (*p).r = 5;

    cout<<r1.l<<" "<<r1.r<<endl;

    p->l = 4;
    p->r = 15;
    cout<<r1.l<<" "<<r1.r<<endl;






    return 0;
}