//Aditya Dayal
//20CO001
//SE Comp A

#include<iostream>
#include<stack>
#include<math.h>
using namespace std;
class node{
	
	public: 
		int num;
		node *left,*right;
	
};
class BST{
	
	node *root;
	public:
	BST(){
		
		root = NULL;
		
	}
	node *insert(int x,node *t)
	{
		
		if(t==NULL){
			
			t=new node;
			t->num = x;
			t->left = NULL;
			t->right = NULL;
			return t;
			
		}
		if(x<t->num){
			
			t->left = insert(x,t->left);
			return t;
			
		}
		if(x>t->num){
			
			t->right = insert(x,t->right);
			return t;
			
		}
		
		
	}
	int search(int x,node *t){
		
		if(t==NULL){
			
			return NULL;
			
		}
		if(x==t->num){
			
			return t->num;
			
		}
		if(x<t->num){
			
			search(x,t->left);
			
		}
		if(x>t->num){
			
			search(x,t->right);
			
		}
		
		
		
	}
	int minValue(node *t){
		
		if(t==NULL){
			
			return NULL;
			
		}
		while(t->left!=NULL){
			
			t=t->left;
			
		}
		return int(t->num);
	}
	node *mirrorImage(node *t){
		
		if(t==NULL){
			
			return t;
			
		}
		node *temp;
		mirrorImage(t->left);
		mirrorImage(t->right);
		temp = t->left;
		t->left = t->right;
		t->right = temp;
		
		return t;
		
	}
	int giveLongest(node *t){
		
		if(t==NULL){
			
			return NULL;
			
		}
		int leftlong = giveLongest(t->left);
		int rightlong = giveLongest(t->right);
		return max(leftlong,rightlong) + 1;
	}
	void preOrder(node *t){
		
		if(t==NULL){
			
			return;
			
		}
		cout<<t->num<<" ";
		preOrder(t->left);
		preOrder(t->right);
		
	}
	void postOrder(node *t){
		
		if(t==NULL){
			
			return;
			
		}
		postOrder(t->left);
		postOrder(t->right);
		cout<<t->num<<" ";
		
	}
	void inOrder(node *t){
		
		if(t!=NULL)
		{
		
		inOrder(t->left);
		cout<<t->num<<" ";
		inOrder(t->right);
		}
		
	}
	void call(){
		
		int ch,a,b,c,d;
		node *t;
		do{
			
			cout<<endl<<"Enter your Choice: "<<endl;
			cout<<"1) Create"<<endl;
			cout<<"2) Search"<<endl;
			cout<<"3) Display PreOrder"<<endl;
			cout<<"4) Display InOrder"<<endl;
			cout<<"5) Display PostOrder"<<endl;
			cout<<"6) Find MinValue"<<endl;
			cout<<"7) Get Mirror Image"<<endl;
			cout<<"8) Get Longest Path"<<endl;
			cout<<"9) Exit"<<endl;
			cin>>ch;
			switch(ch){
				
				
				case 1:
					cout<<"Enter the Element to Insert: "<<endl;
					cin>>a;
					root = insert(a,root);
					cout<<"Element Inserted..";
					break;
				case 2:
					cout<<"Enter the Element to Search: "<<endl;
					cin>>b;
					c = search(b,root);
					if(c==b){
						
						cout<<"Element Found..";
						
					}else{
						
						cout<<"Element not Found..";
						
					}
					break;
				case 3:
					preOrder(root);
					break;
				case 4:
					inOrder(root);
					break;
				case 5:
					postOrder(root);
					break;
				case 6: 
					c = minValue(root);
					cout<<"The Minimum Value is: "<<c;
					break; 
				case 7: 
					mirrorImage(root);
					cout<<"Mirror Created.."<<endl;
					break; 
				case 8: 
					d = giveLongest(root);
					cout<<"The number of nodes in the Longest Path are: "<<d<<endl;
					break; 
					
			}
			
		}while(ch!=9);
		
	}
	
};
int main(){
	
	BST t;
	t.call();
	
}
