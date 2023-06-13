class Solution {
  public:
    void dfs(int node,int vis[],vector<int> arr[]){
        vis[node]=1;
        for(auto it:arr[node]){
            if(vis[it]==0){
                dfs(it,vis,arr);
            }
        }
    }
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        vector<int> arr[V];
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(adj[i][j]==1 && i!=j){
                    arr[i].push_back(j);
                    arr[j].push_back(i);
                }
            }
        }
        int vis[V]={0};
        int c=0;
        for(int i=0;i<V;i++){
            if(vis[i]!=1){
                c++;
                dfs(i,vis,arr);
            }
        }
        return c;
    }
};
