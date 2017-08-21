//
//  Header.h
//  advanced C++
//
//  Created by beckswu on 8/19/17.
//  Copyright © 2017 beckswu. All rights reserved.
//

#ifndef Header_h
#define Header_h


#endif /* Header_h */



//Binary search tree;
/***************** find the tree 的最大深度  104****************/
// recurssion
int maxDepth(TreeNode* root) {
    if (!root) return 0;
    if ((!root->left) && (!root->right)) return 1;
    return 1+max(maxDepth(root->left),maxDepth(root->right) );
}
//iteration

int maxDepth(TreeNode* root) {
    if(!root) return 0;
    int maxlevel = 0;
    queue<TreeNode *>q;
    q.push(root);
    while (q.size()){
        maxlevel += 1;
        int temp_size = q.size();
        for(int i=0; i<temp_size; i++){
            if(q.front()->left) q.push(q.front()->left);
            if(q.front()->right) q.push(q.front()->right);
            q.pop();
        }
    }
    return maxlevel;
}

/***************** average value of the nodes  找每层node的平均值 637 ****************/

class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode *> q;
        vector<double> res;
        q.push(root);
        while(q.size()){
            int size = q.size();
            double temp = 0;
            for(int i = 0; i<size; i++){
                temp += q.front()->val;
                if(q.front()->left) q.push(q.front()->left);
                if(q.front()->right) q.push(q.front()->right);
                q.pop();
            }
            res.push_back(temp/size);
        }
        return res;
    }
};



/***************** invert binary tree 左面到右面，右面的node到左面 ****************/
//recurssion
TreeNode* invertTree(TreeNode* root) {
    if(root){
        std::swap(root->left, root->right);
        invertTree(root->left);
        invertTree(root->right);
    }
    return root;
    
    
}




//iteration
TreeNode* invertTree(TreeNode* root) {
    if(!root) return root;
    if( !root->left && !root->right ) return root;
    queue<TreeNode *>q;
    q.push(root);
    while(q.size())
    {
        int temp_size = q.size();
        for(int i=0; i<temp_size; i++){
            swap(q.front()->left,q.front()->right);
            if(q.front()->left) q.push(q.front()->left);
            if(q.front()->right) q.push(q.front()->right);
            q.pop();
        }
    }
    return root;
    
}



/****************merge two binary tree*******/
//recurssion
TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
    if ( t1 && t2 ) {
        TreeNode * root = new TreeNode(t1->val + t2->val);
        root->left = mergeTrees(t1->left, t2->left);
        root->right = mergeTrees(t1->right, t2->right);
        return root;
    } else {
        return t1 ? t1 : t2;
    }
}


//iteration
TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
    if(!t1) return t2;
    else if(!t2) return t1;
    queue<TreeNode *>q1,q2;
    q1.push(t1);
    q2.push(t2);
    while(q1.size()){
        for(int i=0; i<q1.size(); i++){
            q1.front()->val += q2.front()->val;
            if(q1.front()->left && q2.front()->left) {
                q1.push(q1.front()->left);
                q2.push(q2.front()->left);
            }
            else if((!q1.front()->left) && q2.front()->left)
                q1.front()->left = q2.front()->left;
            if(q1.front()->right && q2.front()->right) {
                q1.push(q1.front()->right);
                q2.push(q2.front()->right);
            }
            else if((!q1.front()->right) && q2.front()->right)
                q1.front()->right = q2.front()->right;
            q1.pop();
            q2.pop();
        }
    }
    return t1;
}



/**************606 Construct string from binary tree ****************/
//recurssion
string tree2str(TreeNode* t) {
    if (!t) return "";
    string s = to_string(t->val);
    if(t->left) s += "("+tree2str(t->left)+")";
    else if(t->right) s+= "()";
    if(t->right) s += "("+tree2str(t->right)+")";
    return s;
}









