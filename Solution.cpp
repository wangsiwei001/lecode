//
// Created by 10593 on 2022/10/8.
//

#include "Solution.h"
/*
 * 724.寻找数组的中心下标
 */
int Solution::pivotIndex(vector<int> &nums) {
    int sum = accumulate(nums.begin(), nums.end(),0);
    int a = 0;
    for (int i = 0; i < nums.size(); ++i) {
        if (2 * a +nums[i] == sum){
            return i;
        }
        a += nums[i];
    }
    return -1;
}
/*
 * 121. 买卖股票的最佳时机
 */
int Solution::maxProfit(vector<int> &prices) {
    //暴力法超时
//    int maxProfit = 0;
//    for (int i = 0; i < prices.size(); ++i) {
//        for (int j = i+1; j < prices.size(); ++j) {
//            maxProfit = max(maxProfit,prices[j] - prices[i]);
//        }
//    }
//    return maxProfit;

    int inf = 1e9;
    int minV = inf,maxV = 0;
    for (const auto &item : prices){
        maxV = max(item - minV,maxV);
        minV = min(minV,item);
    }
    return maxV;
}
