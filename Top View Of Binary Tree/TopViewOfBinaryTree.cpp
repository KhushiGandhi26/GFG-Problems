class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        queue <pair<Node*,int>> q;
        map <int,int> m;
        q.push({root,0});
        while(q.size()!=0){
            auto a=q.front();
            q.pop();
            Node* temp=a.first;
            int vertical=a.second;
            m.insert({vertical,temp->data});
            if(temp->left!=NULL){
                q.push({temp->left,vertical-1});
            }
            if(temp->right!=NULL){
                q.push({temp->right,vertical+1});
            }
        }
        vector<int> ans;
        for(auto i:m){
            ans.push_back(i.second);
        }
        return ans;
        //Your code here
    }

};
