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





