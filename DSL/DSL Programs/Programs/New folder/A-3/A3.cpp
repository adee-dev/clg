

/*NAME: Aaishwarya Darandale

ROLL NO:71
Problem statement :A3

For given expression eg. a-b*c-d/e+f construct inorder sequence and traverse it using
postorder traversal(non recursive).*/

#include<iostream>
#include<stack>
#include<cstring>
using namespace std;

// An expression tree node
struct et
{
    char value;
    et* left, *right;
};

int getWeight(char ch){
   switch (ch) {
      case '/':
      case '*': return 2;
      case '+':
      case '-': return 1;
      default : return 0;
   }
}

// convert infix expression to postfix using a stack
void infix2postfix(char infix[], char postfix[], int size)
{
   stack<char> s;
   int weight;
   int i = 0;
   int k = 0;
   char ch;

   while (i < size)
   {
      ch = infix[i];
      if (ch == '(')
      {
         // simply push the opening parenthesis
         s.push(ch);
         i++;
         continue;
      }
      if (ch == ')')
      {
         // if we see a closing parenthesis,pop of all the elements and append it to
         // the postfix expression till we encounter a opening parenthesis
         while (!s.empty() && s.top() != '(')
         {
            postfix[k++] = s.top();
            s.pop();
         }
          // pop off the opening parenthesis also
         if (!s.empty())
         {
            s.pop();
         }
         i++;
         continue;
      }
      weight = getWeight(ch);
      if (weight == 0)
      {  // we saw an operand simply append it to postfix expression
         postfix[k++] = ch;
      }
      else { // we saw an operator
         if (s.empty())
         {  // simply push the operator onto stack if stack is empty
            s.push(ch);
         }
         else { // pop of all the operators from the stack and append it to the postfix expression till we
            // see an operator with a lower precedence than the current operator
            while (!s.empty() && s.top() != '(' && weight <= getWeight(s.top()))
            {
               postfix[k++] = s.top();
               s.pop();
            }
            // push the current operator onto stack
            s.push(ch);
              }
         }
      i++;
   }
   // pop of the remaining operators present in the stack and append it to postfix expression
   while (!s.empty())
   {
      postfix[k++] = s.top();
      s.pop();
   }
}


// A utility function to check if 'c'
// is an operator
bool isOperator(char c)
{
    if (c == '+' || c == '-' ||
            c == '*' || c == '/' ||
            c == '^')
        return true;
    return false;
}

// Utility function to do inorder traversal
void inorder(et *t)
{
    if(t)
    {
        inorder(t->left);
	inorder(t->right);
        cout<<t->value;
        //inorder(t->right);
    }

}

// A utility function to create a new node
et* newNode(int v)
{
    et *temp = new et;
    temp->left = temp->right = NULL;
    temp->value = v;
    return temp;
};

// Returns root of constructed tree for given
// postfix expression
et* constructTree(char postfix[])
{
    stack<et *> st;
    et *t, *t1, *t2;

    // Traverse through every character of
    // input expression
    for (int i=0; i<strlen(postfix); i++)
    {
        // If operand, simply push into stack
        if (!isOperator(postfix[i]))
        {
            t = newNode(postfix[i]);
            st.push(t);
        }
        else // operator
        {
            t = newNode(postfix[i]);

            // Pop two top nodes
            t1 = st.top(); // Store top
            st.pop();      // Remove top
            t2 = st.top();
            st.pop();

            //  make them children
            t->right = t1;
            t->left = t2;

            // Add this subexpression to stack
            st.push(t);
        }
    }

    //  only element will be root of expression
    // tree
    t = st.top();
    st.pop();

    return t;
}

// Driver program to test above
int main()
{
     char infix[] = "a-b*c-d/e+f";
   int size = strlen(infix);
   char postfix[size];
   infix2postfix(infix,postfix,size);
  //  char postfix[] = postfix;
    et* r = constructTree(postfix);
    //cout<<"infix expression is \n");
    inorder(r);
    return 0;
}

