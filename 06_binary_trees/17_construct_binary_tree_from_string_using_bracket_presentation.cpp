/*
    link: https://www.geeksforgeeks.org/construct-binary-tree-string-bracket-representation/
*/

class Solution{
public:
    int i = 0;
    
    void helper(Node* root, string s, int n)
    {
        if(i >= n) return;
        
        if(i < n && isdigit(s[i]))
        {
            int sum = 0;
            while(i < n && isdigit(s[i]))
            {
                sum = (sum * 10) + (s[i] - '0');
                i++;
            }
            
            root->data = sum;
        }
        
        if(i < n && s[i] == '(')
        {
            root->left = new Node(0);
            i++;
            helper(root->left, s, n);
            if(root->left->data == 0) //imp condition for tc --> 1()(3) --> that has blank child
            {
                root->left = NULL;
            }
        }
        
        if(i < n && s[i] == '(') //if we find the 2nd opening brace it means that we are at the right child
        {
            root->right = new Node(0);
            i++;
            helper(root->right, s, n);
            if(root->right->data == 0)
            {
                root->right = NULL;
            }
        }
        
        if(i >= n || s[i] == ')')
        {
            i++;
            return;
        }
    }
    Node *treeFromString(string str){
        Node* root = new Node(0);
        helper(root, str, str.length());
        return root;
    }
};


// ----------------------------------------------------------------------------------------------------------------------- //
/*
    Time Complexity: O(N2)
    Auxiliary Space: O(N)
*/

/* A binary tree node has data, pointer to left
child and a pointer to right child */
struct Node {
    int data;
    Node* left, * right;
};
/* Helper function that allocates a new node */
Node* newNode(int data)
{
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = node->right = NULL;
    return (node);
}

/* This function is here just to test */
void preOrder(Node* node)
{
    if (node == NULL)
        return;
    printf("%d ", node->data);
    preOrder(node->left);
    preOrder(node->right);
}

// function to return the index of close parenthesis
int findIndex(string str, int si, int ei)
{
    if (si > ei)
        return -1;

    // Inbuilt stack
    stack<char> s;

    for (int i = si; i <= ei; i++) {

        // if open parenthesis, push it
        if (str[i] == '(')
            s.push(str[i]);

        // if close parenthesis
        else if (str[i] == ')') {
            if (s.top() == '(') {
                s.pop();

                // if stack is empty, this is
                // the required index
                if (s.empty())
                    return i;
            }
        }
    }
    // if not found return -1
    return -1;
}

// function to construct tree from string
Node* treeFromString(string str, int si, int ei)
{
    // Base case
    if (si > ei)
        return NULL;

    // new root
    Node* root = newNode(str[si] - '0');
    int index = -1;

    // if next char is '(' find the index of
    // its complement ')'
    if (si + 1 <= ei && str[si + 1] == '(')
        index = findIndex(str, si + 1, ei);

    // if index found
    if (index != -1) {

        // call for left subtree
        root->left = treeFromString(str, si + 2, index - 1);

        // call for right subtree
        root->right
            = treeFromString(str, index + 2, ei - 1);
    }
    return root;
}

// Driver Code
int main()
{
    string str = "4(2(3)(1))(6(5))";
    Node* root = treeFromString(str, 0, str.length() - 1);
    preOrder(root);
}








// ----------------------------------------------------------------------------------------------------------------------- //
/*
    another recursive approach
*/
#include <bits/stdc++.h>
using namespace std;

// custom data type for tree building
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

// Below function accepts sttring and a pointer variable as
// an argument
// and draw the tree. Returns the root of the tree
Node* constructtree(string s, int* start)
{
    // Assuming there is/are no negative
    // character/characters in the string
    if (s.size() == 0 || *start >= s.size())
        return NULL;

    // constructing a number from the continuous digits
    int num = 0;
    while (*start < s.size() && s[*start] != '('
        && s[*start] != ')') {
        int num_here = (int)(s[*start] - '0');
        num = num * 10 + num_here;
        *start = *start + 1;
    }

    // creating a node from the constructed number from
    // above loop
    struct Node* root = new Node(num);

    // check if start has reached the end of the string
    if (*start >= s.size())
        return root;

    // As soon as we see first right parenthesis from the
    // current node we start to construct the tree in the
    // left
    if (*start < s.size() && s[*start] == '(') {
        *start = *start + 1;
        root->left = constructtree(s, start);
    }
    if (*start < s.size() && s[*start] == ')')
        *start = *start + 1;

    // As soon as we see second right parenthesis from the
    // current node we start to construct the tree in the
    // right
    if (*start < s.size() && s[*start] == '(') {
        *start = *start + 1;
        root->right = constructtree(s, start);
    }
    if (*start < s.size() && s[*start] == ')')
        *start = *start + 1;
    return root;
}
void preorder(Node* root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
int main()
{
    string s = "4(2(3)(1))(6(5))";
    // cin>>s;
    int start = 0;
    Node* root = constructtree(s, &start);
    preorder(root);
    return 0;
}