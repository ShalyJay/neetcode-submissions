#import <algorithm>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //dp
        //start from the end, go backwards to see max profit
        //max profit on day x  is max profit on day [x + 1] + difference between x and x+1
        //dp[x] = max(prices[x+1] - prices[x] + dp[x+1], dp[x+1])

        //the state is max profit, and price difference

        // int n = prices.size();

        // int profits[n];
        // profits[n - 1] = 0; //max profit on last day is 0 since you cant sell if you buy then

        // int maxIndex = n-1; //this is the point at which the profit is maxed
        // //we want this to signal where we should add max profit from. This is also where the price differnce will be based from

        // //the dp part is when we try multple maxIndexes
        // //so we do maxProfit[prices[0,n-1]] to get max profit of 

        // //profits can be calculated using i+1, but the prices have to be using maxIndex

        // //if i do 2d array, then i can encode maxprofit between 

        // for(int i = n - 2; i >= 0; i--){
        //     if(prices[maxIndex] > prices[i]){
        //         profits[i] = prices[maxIndex] - prices[i] + profits[maxIndex];
        //         maxIndex = i;
        //     }
        //     else{
        //         profits[i] = profits[maxIndex];
        //         maxIndex = i;
        //     }
            
        //     cout << profits[i] << endl;
        // }

        // return profits[0];

        //------WORKING--------

        // int max = 0;
        // for(int i = prices.size() - 1; i >= 0; i--){ //goes through the entire array once
        //     for(int j = i; j < prices.size(); j++){ //goes through everything in front of the current price
        //         max = max < prices[j] - prices[i] ? prices[j] - prices[i] : max; //checks which price difference based on the current day
        //     }
        // }

        //----------------------

        // we want max number found so far. 
        //so for [7,1,5,3,6,4] the resulting array would be [7,6,6,6,6,4]
        //then you just go through again and do arr1[i] - arr2[i] = profit
        //both done in O(n) time

        int n = prices.size();
        int max[n];

        max[n - 1] = prices[n - 1];
        int maxProfit = 0;
        for(int i = n-2; i >= 0; i--){
            max[i] = max[i+1] > prices[i] ? max[i + 1] : prices[i];
            maxProfit = maxProfit > max[i] - prices[i] ? maxProfit : max[i] - prices[i];
        }

        return maxProfit;
    }
};