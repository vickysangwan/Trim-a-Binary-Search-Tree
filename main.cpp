/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int L, int R)
    {
     //Recursive Approach
        if(root==NULL)
        {
            return NULL;
        }
        if(root->val<=L)
        {
            root->left=NULL;
        }
        if(root->val>=R)
        {
            root->right=NULL;
        }
        root->left=trimBST(root->left,L,R);
        root->right=trimBST(root->right,L,R);
        if(root->val>R)
        {
            return root->left;
        }
        else if(root->val<L)
        {
            return root->right;
        }
        else
        {
            return root;
        }



        //Iterative Approach
         if(root==NULL)
         {
             return NULL;
         }
         TreeNode* roott;
         roott=NULL;
         vector<int> bst;
         preorder(root,bst,L,R);
         for(int i=0;i<bst.size();i++)
         {
             TreeNode* temp;
             temp=(TreeNode*)malloc(sizeof(TreeNode));
             temp->val=bst[i];
             temp->left=NULL;
             temp->right=NULL;
             if(roott==NULL)
             {
                 roott=temp;
             }
             else
             {
                 TreeNode* curr,*ptr;
                 curr=roott;
                 while(curr)
                 {
                     ptr=curr;
                     if(curr->val < temp->val)
                     {
                         curr=curr->right;
                     }
                     else
                     {
                         curr=curr->left;
                     }
                 }
                     if(ptr->val > temp->val)
                     {
                         ptr->left=temp;
                     }
                     else
                     {
                         ptr->right=temp;
                     }
             }
         }
         return roott;
    }
     void preorder(TreeNode* root,vector<int> &bst,int L,int R)
     {
         if(root==NULL)
         {
             return;
         }
         if(root->val>=L && root->val<=R)
         {
             bst.push_back(root->val);
         }
         preorder(root->left,bst,L,R);
         preorder(root->right,bst,L,R);
     }
};
