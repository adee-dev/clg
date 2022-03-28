#include<bits/stdc++.h>
using namespace std;

struct node {
    int roll;
    struct node *left, *right;
};

class Stack{
    int top;
    node* arr[10];

    public:
        Stack(){
            top = -1;
        }

        void push(node* p){
            top++;
           arr[top] = p;
        }

        node* pop(){
            node* q;
            q = arr[top];
            top--;
            return q;
        }

        bool isEmpty(){
            if(top == -1){
                return true;
            }
            else{
                return false;
            }
        }    
};

class Tree{
    

    public:
        node* newNode(int data){
            node *temp = new node;
            temp->roll = data;
            temp->left = temp->right = NULL;
            return temp;
        } 

       void preOrder(node* root){
           node* t = root;
           Stack st;

           while(t != NULL){
               cout<<t->roll<<" ";
               st.push(t);
               t = t->left;  
           }

           while(!st.isEmpty()){
                t = st.pop();
                t = t->right;
            
                while(t!= NULL){
                    cout<<t->roll<<" ";
                    st.push(t);
                    t = t->left;
                }
           }
        } 

        void postOrder(node* root){
            node* t = root;
            Stack st;

            
        }

};

int main() {
     Tree tt;

     node* root = tt.newNode(1);
     root->left = tt.newNode(2);
     root->right = tt.newNode(3);
     root->left->left = tt.newNode(4);
     root->left->right = tt.newNode(5);

     tt.preOrder(root);

return 0;
}