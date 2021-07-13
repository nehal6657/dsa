#include<iostream>
using namespace std;
typedef long long int ll;

class Node{
    public:
    int data;
    Node *next;
};

class Circular_LL{
    Node *head, *tail;
    int s;
    public:
    Circular_LL(){
        head = NULL;
        tail = NULL;
        s=0;
    }

    void addNode(int n){
        Node *tmp = new Node;
        tmp->data = n;
        tmp->next = NULL;
        if(head==NULL){
            head = tmp;
            tail=head;
            head->next = head;

        }
        else{
            tmp->next = tail->next;
            tail->next = tmp;
            tail=tmp;
        }
        s++;

    }
    void display(){
        Node * p = head;
        do{
            cout<<p->data<<" ";
            p=p->next;

        }while(p!=head);

    }
    void insert(int n,int pos){
        Node *tmp = new Node;
        tmp->data = n;
        tmp->next = NULL;
        if(pos<0 || pos>s){
            cout<<"invalid position\n";

        }
        else{
        
        if(pos==0){
            if(head ==NULL){
                head=tmp;
                head->next = head;
                tail=head;
            }
            else{
            tail->next = tmp;
            tmp->next = head;
            tail = tmp;
            }
            s++;
        }
        else{
            Node *p = head;
            for(int i=0;i<pos-1;i++){              
                p=p->next;
            }
            tmp->next = p->next;
            p->next = tmp;
            s++;

        }
        }


    }
    int del(int pos){
        int x = -1;
        if(s<pos){
            cout<<"invalid deletion\n";
        }
        else{
            Node *p = head;
            if(pos==1){
                x = head->data;
                if(tail==head){
                    delete head;
                    head = NULL;
                    tail = NULL;
                }
                else{
                    tail->next = head->next;
                    delete head;
                    head= tail->next;
                }
            }
            else{
                p = head;
                for(int i=0;i<pos-1;i++){
                    p=p->next;
                }
                Node *q = p->next;
                x = q->data;
                delete q;
            }

        }
        return x;
    }

};

int main(){

    Circular_LL C1;
    C1.addNode(2);
    C1.addNode(3);
    C1.addNode(7);
    C1.addNode(4);
    C1.insert(4,4);
    
    C1.display();
    cout<<C1.del(1)<<"\n";
    C1.display();
    

    return 0;
}