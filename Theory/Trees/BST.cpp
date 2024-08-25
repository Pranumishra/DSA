    #include <iostream>
    using namespace std;
    #include<queue> //for level order traversal.
    #include<stack>//for inorder traversal using stack.

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






    TreeNode* insertInBST(TreeNode* &root, int data){
        if(root==NULL){
            root= new TreeNode(data);
            return root;
        }

        if(data>=root->data){
            root->right=insertInBST(root->right,data);
        }
        else{
            root->left=insertInBST(root->left,data);
        }

        return root;
    }

    void createBST(TreeNode* &root){
        int data;
        cout<<"enter the values : ";
        cin>>data;
        while(data!=-1){
            insertInBST(root,data);
            cout<<"enter the values : ";
            cin>>data;
        }

    }






    TreeNode* minValue(TreeNode* root){
        if(root==NULL){
            return NULL;
        }
        while(root->left!=NULL){
            root=root->left;
        }
        return root;
    }

    TreeNode* maxValue(TreeNode* root){
        if(root==NULL){
            return NULL;
        }
        while(root->right!=NULL){
            root=root->right;
        }
        return root;
    }

    bool searchInBST(TreeNode* root,int target){
        //base case 
        if(root==NULL){
            return false;
        }
        if(root->data==target){
            return true;
        }
        if(root->data<target){
            return searchInBST(root->right,target);
        }
        else{
            return searchInBST(root->left,target);
        }
    }




    TreeNode* deleteNode(TreeNode* root,int target){
        //jab root null ho iska matlab target nahi mila therefore return null
        if(root==NULL){
            return NULL;
        }

        //FINDING THE target.
        if(root->data==target){
            //target mil gaya to usko delete karna hai
            if(root->left==NULL && root->right==NULL){
                delete root;
                return NULL;
            }
            else if(root->left==NULL && root->right!=NULL){
                TreeNode* newNode=root->right;
                delete root;
                return newNode;
            }
            else if(root->left!=NULL && root->right==NULL){
                TreeNode* newNode=root->left;
                delete root;
                return newNode;
            }
            else{
                // when left and right subtree both are not null
                TreeNode* leftmax=maxValue(root->left);
                root->data=leftmax->data;
                //we are connecting the detenode to root->left because we need to join the updated left subtree to the root.
                root->left=deleteNode(root->left,leftmax->data);
            }
        }
        else if(root->data<target){
            root->right = deleteNode(root->right,target);
        }
        else{
            root->left = deleteNode(root->left,target);
        }
    }



    TreeNode* createBSTfromInorder(vector<int>&inorder,int start,int end){

        if(start>end){
            return NULL;
        }

        int mid=(end+start)/2;
        TreeNode* root=new TreeNode(inorder[mid]);
        root->left=createBSTfromInorder(inorder,start,mid-1);
        root->right=createBSTfromInorder(inorder,mid+1,end);
        return root;
    }

//INORDER TRAVERSAL USING STACK
    void preorderTraversal(TreeNode* root){
        stack<TreeNode*>st;
        if(root==NULL){
            return;
        }
        while(root!=NULL){
            st.push(root);
            root=root->left;
        }
        while(1){
            if(st.empty()){
                break;
            }
            TreeNode* curr=st.top();
            st.pop();
            cout<<curr->data<<" ";
            curr=curr->right;
            while(curr!=NULL){
                st.push(curr);
                curr=curr->left;
            }

         }
    }
    int main(){
        TreeNode* root=NULL;
        createBST(root);
        levelTraversal(root);

        // cout<<endl;
        // cout<< minValue(root)->data;
        // cout<<endl;
        // cout<< maxValue(root)->data;

        // cout<<endl;
        // cout<< searchInBST(root,25);
        // cout<<endl;
        // cout<< searchInBST(root,60);
        // cout<<endl;
        // cout<< searchInBST(root,70);

        cout<<endl;
        preorderTraversal(root);
        // deleteNode(root,60);
        // levelTraversal(root);

        // cout<<endl;
        // vector<int>inorder={1,2,3,4,5,6,7};
        // TreeNode* root= createBSTfromInorder(inorder,0,6);
        // levelTraversal(root);
    }
 