#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node *insert(struct Node *ptr,int key){
    if(ptr==NULL){
        ptr=(struct Node*)malloc(sizeof(struct Node));
        ptr->data=key;
        ptr->left=NULL;
        ptr->right=NULL;
    }
    else if(key<ptr->data){
        ptr->left=insert(ptr->left,key);
    }
    else if(key>ptr->data){
        ptr->right=insert(ptr->right,key);
    }
    return ptr;
}

int height(struct Node *root){
    if(root==NULL){
        return 0;
    }
    int r_height=height(root->right);
    int l_height=height(root->left);
    int ht=r_height;
    if(l_height >r_height){
        ht=l_height;
    }
    return ht+1;
}

void inorder(Node *root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void preorder(Node *root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node *root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

void levelorder(Node *root){
    Node *tmp;
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        tmp=q.front();
        cout<<tmp->data<<" ";
        q.pop();
        if(tmp->left){
            q.push(tmp->left);
        }
        if(tmp->right){
            q.push(tmp->right);
        }
    }
}

bool find(Node *root,int Skey){
    if(root==NULL){
        return false;
    }
    if(root->data==Skey){
        return true;
    }
    else if(root->data > Skey){
        find(root->left,Skey);
    }
    else if(root->data <Skey){
        find(root->right,Skey);
    }
}
int main()
{
    struct Node *root=NULL;
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
        root=insert(root,arr[i]);
    }
    printf("%d",height(root));
    cout<<endl;
    inorder(root);
    cout<<endl;
    preorder(root);
    cout<<endl;
    postorder(root);
    cout<<endl;
    levelorder(root);
    cout<<endl;
    cout<<"Enter the Key to be searched"<<endl;
    int Skey;
    cin>>Skey;
    cout<<find(root,Skey)<<endl;
    return 0;
}
