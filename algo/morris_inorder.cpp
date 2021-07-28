#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef vector<string> vs;
typedef long long int ll;


struct tNode {
    int data;
    struct tNode* left;
    struct tNode* right;
};
 
/* Function to traverse the binary tree without recursion
   and without stack */
void MorrisTraversal(tNode* root)
{
    tNode *curr = root;
    while(curr){
        if(!curr -> left){
            cout<<curr->data<<" ";
            curr= curr->right;
        }
        else{
            tNode *pre=curr->left;
            while(pre->right && pre->right!=curr) 
                pre = pre->right;
            if(pre->right == NULL){
                pre->right = curr;
                curr= curr->left;
            }
            else{
                cout<<curr->data<<" ";
                pre->right = NULL;
                curr = curr->right;
            }
        }
    }
    
}
 
/* UTILITY FUNCTIONS */
/* Helper function that allocates a new tNode with the
   given data and NULL left and right pointers. */
struct tNode* newtNode(int data)
{
    struct tNode* node = new tNode;
    node->data = data;
    node->left = NULL;
    node->right = NULL;
 
    return (node);
}
 
/* Driver program to test above functions*/
int main()
{
 
    /* Constructed binary tree is
            5
          /   \
         2     6
       /   \
      1     3
  */
    struct tNode* root = newtNode(5);
    root->left = newtNode(2);
    root->right = newtNode(6);
    root->left->left = newtNode(1);
    root->left->right = newtNode(3);
 
    MorrisTraversal(root);
 
    return 0;
}