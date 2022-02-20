//https://www.codingninjas.com/codestudio/problems/target-sum_4127362?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=1
int targetSum(int n, int k, vector<int>& arr) {
    // Write your code here.
    int sum=0;
    for(int x:arr){
        sum+=x;
    }
    int target=(sum-k)/2;
    if(sum-k<0 || (sum-k)%2) return 0; 
    
    vector<int> dp(target+1 ,0);
    dp[0]=1;
    for(int i=0;i<n;i++){
        for(int j=target;j>=0;j--){
            int take=0;
            if(j>=arr[i])
            take=dp[j-arr[i]];
            dp[j]=take+dp[j];
        }
    }
    return dp[target];
}
