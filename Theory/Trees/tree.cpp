#include <iostream>
using namespace std;
#include<queue>

class TreeNode{
    public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};

TreeNode* createTree(){
    int data;
    cout<<"Enter the value of node : ";
    cin>>data;

    if(data==-1){
        return NULL;
    }
    TreeNode* newNode = new TreeNode(data);
    newNode->left=createTree();
    newNode->right=createTree();
    return newNode;
}

void preOrderTraversal(TreeNode* &root){
    if(root==NULL){
        return;
    }
    //curr element
    cout<<root->data<<" ";
    //left element
    preOrderTraversal(root->left);
    //right element
    preOrderTraversal(root->right);
}

void inOrderTraversal(TreeNode* &root){
    if(root==NULL){
        return;
    }

    //left element
    inOrderTraversal(root->left);
    //curr element
    cout<<root->data<<" ";
    //right element
    inOrderTraversal(root->right);
}

void postOrderTraversal(TreeNode* &root){
    if(root==NULL){
        return;
    }

    //left element
    postOrderTraversal(root->left);
    //right element
    postOrderTraversal(root->right);
    //curr element
    cout<<root->data<<" ";
}

void levelTraversal(TreeNode* &root){

    //implementing initial stage
    queue<TreeNode*>q;
    q.push(root);
    q.push(NULL);


    //implementing the remaining
    TreeNode* curr=NULL;
    while(!q.empty()){
        curr=q.front();
        q.pop();
        if(curr==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<curr->data<<" ";
            if(curr->left!=NULL){
                q.push(curr->left);
            }

            if(curr->right!=NULL){
                q.push(curr->right);
            }
        }

    }


}


void getKthAncestor(TreeNode* &root, int child ,int k, vector<int>arr,int& ans){
    if(root==NULL){
        return;
    }

    arr.push_back(root->data);
    if(root->data==child){
        int n=arr.size();
        if(n-k-1>=0)
        ans= arr[n-k-1];
    }
    getKthAncestor(root->left,child,k,arr,ans);
    getKthAncestor(root->right,child,k,arr,ans);
}
int main(){
    TreeNode* rootNode;
    rootNode=createTree();
    // cout<<rootNode->data;

    // cout<<endl;
    // preOrderTraversal(rootNode);
    // cout<<endl;
    // inOrderTraversal(rootNode);
    // cout<<endl;
    // postOrderTraversal(rootNode);

    // cout<<endl;
    // levelTraversal(rootNode);


    int child=50;
    int k=2;
    vector<int>arr;
    cout<<endl;
    int ans=0;
    getKthAncestor(rootNode,child,k,arr,ans);
    cout<<ans;

}