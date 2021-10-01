
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef vector<string> vs;
typedef long long int ll;
typedef vector<int> vi;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
typedef ListNode Node;

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
        
        Node *tmp= new Node(n);
        tmp->val = n;
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
            Node *tmp = new Node(head->val);
            tmp = head;
            while(tmp!=NULL){
                cout<<tmp->val<<" ";
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
};

