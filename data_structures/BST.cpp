#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node *LC, *RC;
};

class BST{
    Node *root;
    public:
    BST(){
        root = NULL;
    }
    void insert(int k){
        Node *p, *r;
        Node *t = root;
        if(root == NULL) {
            p = new Node;
            p->data = k;
            p->LC = NULL; p->RC = NULL;
            root = p;
            return;
        }
        while(t!=NULL){
            r = t;
            if(k < t->data){
                t=t->LC;
            }
            else if(k>t->data){
                t=t->RC;
            }
            else{
                return;
            }


        }
        p = new Node;
        p->data = k;
        p->LC = NULL; p->RC = NULL;
        if(k<r->data){
            r->LC =p;
        }
        else{
            r->RC = p;
        }
       
    }
    Node* getRoot(){ return root; }
    void inorder(Node* p) {
    if (p){
        inorder(p->LC);
        cout << p->data << ", ";
        inorder(p->RC);
    }
    }
    Node* search(int k){
        Node *t =root;
        if(root ==NULL) return NULL;
        while(t){
            if(t->data == k) return t;
            else if (t->data <k)  t=t->RC;
            else t = t->LC;

        }
        return NULL;
        
    }
    int height(Node *p){
        if(p==NULL) return 0;
        int x,y;
        x = height(p->LC);
        y  = height(p->RC);
        return x>y ? x+1: y+1;
    }
    Node* inpre(Node *p){
        while(p && p->RC) p=p->RC;
        return p;
    }
    Node* insucc(Node *p){
        while(p && p->LC) p=p->LC;
        return p;
    }
    Node* delete1(int k,Node *p){
        if(p==NULL) return NULL;
        else if(p->LC==NULL && p->RC==NULL){
            if(p==root) root=NULL;
            delete(p);
            return NULL;
        }
        else{
            if(k<p->data){
                p->LC = delete1(k,p->LC);
            }
            else if(k>p->data){
                p->RC = delete1(k,p->RC);
            }
            else{
                if(height(p->LC) > height(p->RC)){
                    Node *q = inpre(p->LC);
                    p->data = q->data;
                    p->LC = delete1(q->data,p->LC);
                }
                else{
                    Node *q = insucc(p->RC);
                    p->data = q->data;
                    p->RC = delete1(q->data,p->RC);
                }
            }

        }
        return p;
    }
    

};

Node* BSTfromPreorder(vector<int> &v){
        int i = 0;
        Node *p,*t,*root;
        t = new Node;
        t->LC =NULL; t->RC=NULL; t->data = v[0];
        root=t; p = t;
        stack<Node*> s;
        i++;
        while(i<v.size()){
            if(v[i] < p->data){
                s.push(p);
                t = new Node;
                t->LC = NULL;t->RC=NULL; t->data = v[i];
                p->LC = t;
                p = p->LC;
                i++;
            }
            else{
                if(s.empty()){
                    t = new Node;
                    t->LC = NULL;t->RC=NULL; t->data = v[i];
                    p->RC = t;
                    p=p->RC;
                    i++;
                }
                else if(!s.empty() && v[i]<=s.top()->data){
                    t = new Node;
                    t->LC = NULL;t->RC=NULL; t->data = v[i];
                    p->RC = t;
                    p=p->RC;
                    i++;
                    //s.pop();
                }
                else{
                    p = s.top();
                    s.pop();
                }
            }


        }
        return root;

    }
void inorder(Node *root){
    if(root!=NULL) {
        inorder(root->LC);
        cout<<root->data<<" ";
        inorder(root->RC);
    }

}
int height(Node *p){
        if(p==NULL) return 0;
        int x,y;
        x = height(p->LC);
        y  = height(p->RC);
        return x>y ? x+1: y+1;
    }
Node* inpre(Node *p){
    while(p && p->RC) p=p->RC;
    return p;
}
Node* insucc(Node *p){
    while(p && p->LC) p=p->LC;
    return p;
}


int main(){
    BST b1;
    b1.insert(10);
    b1.insert(14);
    b1.insert(25);
    b1.insert(13);
    b1.insert(28);
    b1.insert(32);
    b1.insert(15);
    b1.insert(30);
    b1.inorder(b1.getRoot());
    int y = b1.height(b1.getRoot());
    cout<<"height : "<<y<<endl;
    Node *tmp = b1.search(12);
    if(tmp) cout<<tmp->data<<" nr \n";
    else cout<<"data not found\n";

    b1.delete1(10,b1.getRoot());
    b1.inorder(b1.getRoot());


    // vector<int> v={30,20,10,15,25,40,50,45};
    // Node* r = BSTfromPreorder(v);
    // cout<<endl;
    // inorder(r);
    // cout<<endl;



    return 0;
}