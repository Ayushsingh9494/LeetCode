class Solution {
    public int maxProfit(int[] prices) {
        int n = prices.length;
        int[][][] dp = new int[n+1][2][3];
        
        //base case
        // for cap=0 , index and buy can be anything
        for(int i=0;i<=n;i++){
            for(int buy=0;buy<=1;buy++){
                dp[i][buy][0] = 0;
            }
        }
        // for ind=n , cap and buy can be anything
        for(int buy=0;buy<=1;buy++){
            for(int cap=0;cap<=2;cap++){
                dp[n][buy][cap] = 0;
            }
        }

        //iteration
        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<=1;buy++){
                for(int cap=1;cap<=2;cap++){
                    if(buy==1){
                        dp[i][buy][cap] = Math.max(-prices[i] + dp[i+1][0][cap], dp[i+1][1][cap]);
                    }
                    else{
                        dp[i][buy][cap] = Math.max(prices[i] + dp[i+1][1][cap-1], dp[i+1][0][cap]);
                    }
                }
            }
        }

        return dp[0][1][2];
    }
}