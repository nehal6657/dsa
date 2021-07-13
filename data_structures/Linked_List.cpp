#include<iostream>
using namespace std;
typedef long long int ll;

class Node{
    public:
    int data;
    Node *next;
};

class Linked_List{
    Node *head, *tail;
    int s;
    public:
    Linked_List(){
        head = NULL;
        tail = NULL;
        s=0;
    }

    void addNode(int n){
        
        Node *tmp= new Node;
        tmp->data = n;
        tmp->next = NULL;
        if(head == NULL)
        {
            head = tmp;
            tail = tmp;
        }
        else{
            tail->next = tmp;
            tail = tail->next;
        }
        s++;

        //delete tmp;
        

    }
    void display(){
        if(head==NULL){
            cout<<"no elements in list\n";
        }
        else{
            Node *tmp = new Node;
            tmp = head;
            while(tmp!=NULL){
                cout<<tmp->data<<" ";
                tmp=tmp->next;
            }
            //delete tmp;


        }
        // cout<<"\ndisplay using recursion: ";
        // rec_display(head);
        cout<<"\n";

        // cout<<"\ndisplay using recursion in reverse: ";
        // rev_display(head);
        // cout<<"\n";
        
    }
    void rec_display(Node *p){
        if(p!=NULL){
            cout<<p->data<<" ";
            rec_display(p->next);
        }
    }
    void rev_display(Node *p){
        if(p!=NULL){
            rec_display(p->next);
            cout<<p->data<<" ";
        }

    }
    void size(){
        cout<<s<<"\n";
    }

    ll sum(){
        ll s1 =0;
        Node *tmp = new Node;
        tmp = head;
        while(tmp!=NULL){
            s1+=tmp->data;
            tmp=tmp->next;
        }
        //delete tmp;

        return s1;
    }

    int maxx(){
        int m = INT16_MIN;
        Node *tmp = new Node;
        tmp = head;
        while(tmp!=NULL){
            if(tmp->data > m){
                m=tmp->data;
            }
            tmp=tmp->next;
        }
        //delete tmp;

        return m;
        
    }
    Node * linear_search(int k){
        Node *tmp = new Node;
        tmp = head;
        while(tmp!=NULL){
            if(tmp->data == k){
                return tmp;
            }
            tmp=tmp->next;
        }
        //delete tmp;

        return NULL;

    }

    Node * mod_search(int k){
        Node *tmp = new Node;
        Node *q = NULL;
        tmp = head;
        while(tmp!=NULL){
            if(tmp->data == k){
                q->next = tmp->next;
                tmp->next = head;
                head=tmp;
                cout<<"key is found\n";
                return tmp;
            }
            q = tmp;
            tmp=tmp->next;
        }
       // delete tmp;

        cout<<"key is not found\n";
        return NULL;

    }
    void inserthead(int n){
        Node *tmp = new Node;
        tmp->data =n;
        tmp->next = head;
        head = tmp;
        s++;
        //delete tmp;


    }
    void insert_pos(int n,int pos){
        Node *tmp = new Node;
        tmp->data = n;
        Node *p = head;
        for(int i=0;i<pos-1;i++){
            p=p->next;
        }
        tmp->next=p->next;
        p->next = tmp;
        s++;
        //delete tmp;

    }
    void ins_sort(int n){
        Node *p,*tmp;
        tmp = new Node;
        tmp->data = n;
        tmp->next = NULL;
        p = head;
        int  f=0;
        while(p->next!=NULL){
            if(p->data <= n && p->next->data >=n && f==0){
                tmp->next = p->next;
                p->next = tmp;
                f =1;
            }
            p = p->next;
        }
        if(!f){
            p=tail;
            p->next = tmp;
            tmp->next = NULL;
            tail = tmp;
        }


        s++;
 //       delete tmp;
 

    }

    int del(int pos){
        int x = -1;
        Node *p,*q;
        p = head;
        if(pos == 1 && head!=NULL){
            
            head = p->next;
            x = p->data;
            head = NULL;
            delete p;
        }
        else{
            q = NULL;
            for(int i =0;i<pos-1 && p;i++){
                q = p;
                p = p->next;
            }
            if(p){
                q->next=p->next;
                p->next=NULL;
                x = p->data;
                delete p;
            }
        
        }
        return x;
    }

    bool issorted(){
        int f = 1;
        Node *p = head;
        while(p->next != NULL){
            if(p->data > p->next->data){
                f=0;
            }
            p=p->next;
        }
        return f;
    }

    void remove_dup(){
        //works on sorted linked list
        Node *p,*q;
        p=head;
        q=p->next;
        while(q!=NULL){
            if(p->data == q->data){
                p->next = q->next;
                delete q;
                q = p->next;

            }
            else{
                p=q;
                q=q->next;
            }
        }

    }

    void rev_elee(){
        Node *p = head;
        int i =0;
        int A[s]={0};
        while(p!=NULL){
            A[i]=p->data;
            i++;
            p=p->next;
        }
        p = head;i--;
        while(p!=NULL){
            p->data = A[i];
            p=p->next;i--;
        }
    }

    void rev_links(){
        Node *p = head;
        tail= head;
        Node *q,*r;
        r = NULL;
        q = NULL;
        while(p!=NULL){
            r=q;q=p;p=p->next;
            q->next = r;
        }
        head = q;
    }

    void rec_rev(Node *p, Node *q = NULL){
        if(p!=NULL){
            rec_rev(p,p->next);
            p->next = q;
        }
        else{
            tail = head;
            head = q;
        }

    }

    Node * get_head(){
        return head;
    }

    



};

Node* mergeList(Node *head1, Node *head2){
        if(!head1) return head2;
        if(!head2) return head1;
        //Node *h1 = head1;
        if(head2->data < head1->data){return mergeList(head2,head1);}
        Node *p =head1, *q=head2, *tmp = head1, *ans=head1;
        //ans->next = NULL;
        p=p->next;
        tmp->next=NULL;
        while(q!=NULL && p!=NULL){
            if(q->data < p->data){
                tmp->next=q;
                tmp=q;
                q=q->next;
                tmp->next=NULL;
            }
            else{
                tmp->next=p;
                tmp=p;
                p=p->next;
                tmp->next=NULL;
            }
        }
        if(p!=NULL) tmp->next= p;
        else if(q!=NULL) tmp->next = q;
        return ans;

        
    }
Node *first=NULL,*second=NULL,*third=NULL;
Node* Merge(struct Node *p,struct Node *q)
{
 struct Node *last;
 if(p->data < q->data)
 {
 third=last=p;
 p=p->next;
 third->next=NULL;
 }
 else
 {
 third=last=q;
 q=q->next;
 third->next=NULL;
 }
 while(p && q)
 {
 if(p->data < q->data)
 {
 last->next=p;
 last=p;
 p=p->next;
 last->next=NULL;

 }
 else
 {
 last->next=q;
 last=q;
 q=q->next;
 last->next=NULL;

 }
 }
 if(p)last->next=p;
 if(q)last->next=q;
 return third;

}
int main(){
    Linked_List L;
    L.addNode(4);
    L.addNode(5);
    L.addNode(10);
    L.addNode(14);
    L.display();

    cout<<"number of elements is: ";
    L.size();

    ll s1 = L.sum();
    cout<<"sum of all elements is:"<<s1<<"\n";

    cout<<"max number in list is: "<<L.maxx()<<"\n";
    Node *p = L.linear_search(14);
    cout<<"linear search result: "<<p->data<<" "<<p->next<<" \n";
    p = L.mod_search(14);

    L.display();

    L.inserthead(15);
    L.display();

    // inserting after given position

    L.insert_pos(13,4);
    L.display();

    Linked_List L1;
    for(int i=0;i<5;i++){
        L1.addNode(i*2 + 2);
        L1.addNode(i*2 + 2);
    }
    L1.display();
    L1.ins_sort(5);
    L1.display();
    L1.ins_sort(11);
    L1.display();

    cout<<"delete from L pos "<<L.del(10)<<" deleted\n";
    L.display();
    cout<<"delete from L pos "<<L.del(4)<<" deleted \n";
    L.display();
    
    cout<<L.issorted()<<"\n";
    cout<<L1.issorted()<<"\n";

    L1.display();
    L1.remove_dup();
    cout<<"after removeing duplicates\n";
    L1.display();

    L1.rev_elee();
    L1.display();
    L1.rev_links();
    L1.display();
    // Node *first = L1.get_head();
    // L1.rec_rev(first,NULL);
    // L1.display();

    Linked_List L2;
    for(int i=0;i<5;i++){
        L2.addNode(i*2 + 1);
        //L1.addNode(i*2 + 2);
    }
    L1.display();
    L2.display();

    Node *tmp = mergeList(L2.get_head(),L1.get_head());
    cout<<"mergelist"<<endl;
    while(tmp){
        cout<<tmp->data<<" ";
        tmp=tmp->next;

    }
    cout<<"\n";




    return 0;
}