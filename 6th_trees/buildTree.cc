# include <iostream>
# include <bits/stdc++.h>
using namespace std;
// 1) Make a class with data, self referential pointers left and right
// 2) Use function of return type TreeNode* and make a tree without passing anything

class Treenode
{   public:
    int data;
    Treenode* left;
    Treenode* right;
    Treenode(int x)
    {
        data=x;
        left=NULL;
        right=NULL;
    }
};

Treenode* buildTree()
{
    int x;
    cin >> x;
    if (x == -1)
    return NULL;
    Treenode* root = new Treenode(x);
    root->left= buildTree();
    root->right =buildTree();
    return root;
}

void printTree(Treenode* root)
{
    if(root==NULL)
    return;
    cout << root->data;
    printTree(root->left);
    printTree(root->right);
}

int height(Treenode* root)
{
    if(root==NULL)
    return 0;
    int lh = height(root->left);
    int rh = height(root->right);
    return max(lh,rh) + 1;
}

void sumatk(Treenode* root,int &ans,int k)
{
    if(k==1) {cout << root->data;ans = ans + root->data;return ;}

    sumatk(root->left,ans,k-1);
    sumatk(root->right,ans,k-1);
}

void zigzag(Treenode* root)
{
    stack <Treenode*> current;
    stack <Treenode*> next;
    current.push(root);
    bool rtl=false;
    while(!current.empty())
    {
        Treenode* cur = current.top();
        current.pop();
        cout << cur->data;
        if(rtl)
        {
            if(cur->right) next.push(cur->right);
            if(cur->left) next.push(cur->left); 
        }
        else{
            if(cur->left) next.push(cur->left);
            if(cur->right) next.push(cur->right);
        }
        if(current.empty())
        {
            cout << endl;
            swap(current,next);
            rtl= 1-rtl;
        }
    }

}

void printKthorder(Treenode* root,int k)
{
    if(root==NULL) return;
    if(k==1)
    {
        cout << root->data;
    }
    printKthorder(root->left,k-1);
    printKthorder(root->right,k-1);
}

void level(Treenode* root)
{

    int hieght = height(root);
    for (int i=1;i<= hieght;i++)
    {
        printKthorder(root,i);
        cout << endl;
    }
}

struct Pair
{
    Treenode* node;
    int level;
};


void bfs(Treenode* root)
{
    queue<Pair> q;
    Pair rootpair;
    rootpair.node = root;
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
        cout << f.node->data ;
        if(f.node->left) {
            Pair leftpair;
            leftpair.node = f.node->left;
            leftpair.level = f.level + 1;
            q.push(leftpair);
        }
        if(f.node->right) 
        {
            Pair rightpair;
            rightpair.node = f.node->right;
            rightpair.level = f.level + 1;
            q.push(rightpair);
        }
    }
return;
}

int sumofnodes(Treenode* root)
{
    if(root == NULL)
    {return 0;}
    return root->data + sumofnodes(root->left) + sumofnodes(root->right) ;
}

int count(Treenode* root)
{
    if(root==NULL)
    {
        return 0;
    }
    return 1+ count(root->left) + count(root->right);
}

int sumreplacement(Treenode* root)
{// Logic :- if leaf node then return data else calc. left and right sum , store data in temp variable (to store data while changing it), make root equal to left and right sum
// then return temp+ls+rs
    if (root == NULL)
    {
        return 0;
    }

    if(root->left== NULL && root->right==NULL)
    {
        return root->data;
    }

    int ls = sumreplacement(root->left);
    int rs = sumreplacement(root->right);

    int temp = root->data;
    root->data = ls+ rs;
    return temp+ls+rs;

}

int diameter(Treenode* root)
{
    if(root==NULL)
    {
        return 0;
    }
    int h1 = height(root->left);
    int h2 = height(root->right);

    int op1,op2,op3;
    op1 = h1 + h2;
    op2 = diameter(root->left);
    op3 = diameter(root->right);
    return max(op1,max(op2,op3));
}

struct pa
{
    int dia;
    int height; 
};


pa opt_diameter(Treenode* root)
{   pa p;
    if(root==NULL)
    {
        p.dia=p.height=0; return p;
    } 

    pa left = opt_diameter(root->left);
    pa right = opt_diameter(root->right);
    p.height = max(left.height, right.height) + 1;
    p.dia = max(left.height+right.height,max(left.dia,right.dia));
    return p;
}

bool isbal(Treenode* root)
{
if (root == NULL) return true;
int lfheight = height(root->left);
int rfheight = height(root->right);
bool curbal = abs(lfheight-rfheight) <= 1;
return curbal * isbal(root->left) * isbal(root->right);
}

struct Pair2{
    int ht;
    bool isBal;
    Pair2(int h, bool b){
        ht = h;
        isBal = b;
    }
    void print(){
        cout << "ht " << ht << " isBal " << isBal << endl;
    }
};


Pair2 isBal2(Treenode* root){
    if (root == NULL){
        Pair2 p(0, true);
        return p;
    }

    Pair2 ans(0, false);
    Pair2 lAns = isBal2(root->left);
    if (lAns.isBal == false) return ans;

    Pair2 rAns = isBal2(root->right);
    if (rAns.isBal == false) return ans;

    ans.ht = max(lAns.ht, rAns.ht) + 1;
    ans.isBal = abs(lAns.ht - rAns.ht) <= 1 && lAns.isBal && rAns.isBal;
    return ans;
}


Treenode* buildBalTree(int arr[], int s ,int e)
{  
    if(s>e)
    {   
        return NULL;
    }
    int mid = (s+e)/2;
    Treenode* root = new Treenode(arr[mid]);
    root->left = buildBalTree(arr,s,mid-1);
    root->right = buildBalTree(arr,mid+1,e);
    return root;
}

Treenode* create(int in[],int pre[], int s, int e)
{static int i=0;
    if(s>e)
    {
        return NULL;
    }
    Treenode* root = new Treenode(pre[i]);
    int idx = -1;
    for(int j=s;s<=e;j++)
    {
        if(in[j]==pre[i])
        {
            idx = j;
            break;
        }
    }
    i++;
    root->left = create(in,pre,s,idx-1);
    root->right = create(in,pre,idx+1,e);
    return root;
}


int main()
{
// Lecture 0
Treenode* root;
root = buildTree();

// Lecture 1 
//printTree(root);    Pre Order Traversal

// Lecture 2
//level(root);  Level Order Traversal 1

// Lecture 3 Level Order 2
// bfs(root); 

// Lecture 4
// cout << sumofnodes(root) << endl << count(root); Count and sum of nodes

//Lecture 5 In sum replacement
// sumreplacement(root);
// bfs(root);

//Lectur 6 Diameter of tree
//cout << diameter(root);

// Lecture 7 Opt. Diameter
// pa p= opt_diameter(root);
// cout << p.dia;

// Lecture 8 
// auto p = isBal2(root);
// cout << p.isBal;

// Lecture 9 Build from array
// int arr[]={1,2,3,4,5,6,7,8,9};
// root = buildBalTree(arr,0,8);
// bfs(root);

// Lecture 10
// int in[]={1,2,3,4,5};
// int pre[]={3,2,1,5,4};
// root = create(in,pre,0,4);
// bfs(root);
// zigzag(root);

int ans =0;
sumatk(root,ans,2);
cout << ans;
}