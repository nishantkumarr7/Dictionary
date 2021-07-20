#include<bits/stdc++.h>
using namespace std;
class node{
    public:
       int data;
       node* left;
       node* right;

       node(int d){
             data=d;
             left=NULL;
             right=NULL;
       }
};

node* Buildtree(){
   int d;
   cin>>d;

   node* root=new node(d);
   if(d==-1){
       return NULL;
   }
   root->left=Buildtree();
   root->right=Buildtree();
   return root;
}

void printtree(node* root){
    if(root==NULL){
        return;
    }

    cout<<root->data<<" ";
     printtree(root->left);
     printtree(root->right);
}
void inorder(node* root){
    if(root == NULL)
      return;

      inorder(root->left);
      cout<<root->data<<" ";
      inorder(root->right);
      
}

int main(){
    node* tree=Buildtree();
    printtree(tree);
    return 0;
}