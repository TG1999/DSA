# include <iostream>
# include <bits/stdc++.h>
using namespace std;

class node
{   public:
    int data;
    node* left;
    node* right;
    node(int x)
    {
        data=x;
        left=NULL;
        right=NULL;
    }
};

struct Pair
{
    node* tree;
    int level;
};

node* insert(node* root, int d)
{
    if(root == NULL) return new node(d);
    if(d <= root->data) root->left = insert (root->left,d);
    else root->right = insert (root->right,d);
}

node* build()
{
int d;
cin >> d; 
node *root =NULL;
while(d!=-1)
{
    root = insert(root,d);
    cin >> d;
}
return root;
}

void bfs(node* root)
{
    queue<Pair> q;
    Pair rootpair;
    rootpair.tree = root;
    rootpair.level = 0;
    
    q.push(rootpair);
    int lastlevel = 0;

    while(!q.empty())
    {   
        Pair f = q.front();
        q.pop();
        if(lastlevel!=f.level)
        {
            cout << endl;
        }
        
        lastlevel = f.level;
        cout << f.tree->data << " " ;
        if(f.tree->left) {
            Pair leftpair;
            leftpair.tree = f.tree->left;
            leftpair.level = f.level + 1;
            q.push(leftpair);
        }
        if(f.tree->right) 
        {
            Pair rightpair;
            rightpair.tree = f.tree->right;
            rightpair.level = f.level + 1;
            q.push(rightpair);
        }
    }
return;
}
int mIN= -1000000;
int mAX= 1000000;
bool find(node* root,int key)
{
    if(root==NULL)
    return false;
    if(root->data==key) return true;
    if(key>root->data){
    find(root->right,key);}
    if(key<=root->data){
    find(root->left,key);}
}

bool isBst(node* root, int min=mIN, int max=mAX)
{

    if(root==NULL)
    return true;
    if (root->data >= min && root->data <= max && isBst(root->left,min, root->data ) && isBst(root->right,root->data, max))
    {return true;} 
    return false;
}

node* buildTree()
{
    int x;
    cin >> x;
    if (x == -1)
    return NULL;
    node* root = new node(x);
    root->left= buildTree();
    root->right =buildTree();
    return root;
}

int main()
{
node* root = build();
bfs(root);
cout << endl;
cout << isBst(root);
}