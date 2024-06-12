// C++ program to demonstrate insertion
// in a BST recursively.
#include <iostream>
using namespace std;


class BST
{
public:
    // default constructor
    BST();
    ~BST();

    //Parmeterized constructor
    BST(int);

    //Insert function
    BST* Insert(BST*, int);

    //Inorder traversal
    void Inorder(BST*);

    ///search
    BST* Search(BST* root, int key);

    int data;
    BST *left, *right ; // pointer to implentation pimpl idiom 
};


BST::~BST()
{
    delete left;
    delete right;
}
//Default constructor definition
BST::BST() : data(0) , left(NULL), right(NULL)
{}

//Parmeterized constructor definition
BST::BST(int value)
{
    data = value ;
    left = right = NULL ; 
}
//Insert function definition
BST* BST::Insert(BST* root, int value)
{
    if (!root)
    {
        //insert the first node, if root is null
        return new BST(value);
    }

    //insert data
    if (value > root->data)
    {
        //insert right node data, if the 'value'
        //to be inserted is greater than 'root' node data

        //process right nodes
        root->right = Insert(root->right, value);
    }
    else 
    {
        //insert left node data, if the 'value'
        //to be inserted is greater then 'root' node data

        //process left nodes
        root->left = Insert(root->left, value);
    }

    return root ;
}

BST* BST::Search(BST* root, int key)
{
    //Base Cases: root is null or key is present at root
    if(root == NULL || root->data == key)
    {  return root;   }

    //key is greater than root's key
    if (root->data < key)
    {  return Search(root->right, key);}

    //key is smaller than root's key
    return Search(root->left, key);
}

//Inorder traversal definition
//this gives data in sorted order
void BST::Inorder(BST* root)
{
    if(!root)
    {return ; }
    Inorder(root->left);
    cout << root->data << endl ;
    Inorder(root->right);
}
    

// driver code
int main ()
{
    BST b , *root = NULL;
    root = b.Insert(root ,50 );
    b.Insert(root, 30);
    b.Insert(root, 20);
    b.Insert(root, 40);
    b.Insert(root, 70);
    b.Insert(root, 60);
    b.Insert(root, 80);

    BST* keyChild = b.Search(root, 80);

    if(keyChild->data == 80)
    {cout << "Found matched Key\n" ;}

    b.Inorder(root);
    delete keyChild ;
    delete root;

    return 0;
}



// This code is contributed by pkthapa
