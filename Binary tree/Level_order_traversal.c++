// There are two method two approach to solve
//1.) By using null to separate the level
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==NULL) return ans;
        queue<TreeNode*>q;
        q.push(root);
        while(q.empty()==false){
            int n=q.size();
            vector<int>level;
            for(int i=0;i<n;i++){
                TreeNode *temp=q.front();
                q.pop();
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
                level.push_back(temp->val);
            }
            ans.push_back(level);
        }

        return ans;
    }
};

//2.) without using null as separator of level

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        vector<vector<int>>v;
        while(q.front()!=NULL)
        {
            vector<int>v1;
            while(q.front()!=NULL)
            {
                v1.push_back(q.front()->val);
                if(q.front()->left)
                {
                    q.push(q.front()->left);
                }
                if(q.front()->right)
                {
                    q.push(q.front()->right);
                }
                q.pop();
            }
            v.push_back(v1);
            q.pop();
            q.push(NULL);
        }

        return v;

    }
};
