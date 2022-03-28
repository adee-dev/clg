#include<bits/stdc++.h>
using namespace std;

struct node{
    int roll;
    struct node* left;
    struct node* right;

};

class tree{

    public:

        node* newNode(int data){
            node* temp = new node;
            temp->roll = data;
            temp->left = temp->right = NULL;
            return temp;

        }

        void recursive_preorder(node* root){

            if(root == NULL){
                return;
            }

            cout<<root->roll<<" ";

            recursive_preorder(root->left);

            recursive_preorder(root->right);

        }
        void recursive_postorder(node* root){

            if(root == NULL){
                return;
            }

            recursive_postorder(root->left);

            recursive_postorder(root->right);

            cout<<root->roll<<" ";

        }
        void recursive_inorder(node* root){

            if(root == NULL){
                return;
            }

            recursive_inorder(root->left);
            
            cout<<root->roll<<" ";

            recursive_inorder(root->right);

        }
};

int main() {
    
    tree tt;

     struct node* root = tt.newNode(1);
     root->left = tt.newNode(2);
     root->right = tt.newNode(3);
     root->left->left = tt.newNode(4);
     root->left->right = tt.newNode(5);

    tt.recursive_preorder(root);
    cout<<endl;
    tt.recursive_postorder(root);
    cout<<endl;
    tt.recursive_inorder(root);
return 0;
}