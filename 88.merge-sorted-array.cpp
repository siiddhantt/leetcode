/*
 * @lc app=leetcode id=88 lang=cpp
 *
 * [88] Merge Sorted Array
 */

// @lc code=start
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // vector<int>::iterator iter;
        int i = m;
        int curr, k;
        for(int l = 0; l < n; l++){
            nums1[i] = nums2[l];
            i++; 
        }
        //Insertion Sort
        // for(int j = 1; j < nums1.size(); j++){
        //     curr = nums1[j];
        //     k = j-1;
        //     while(k>=0 && nums1[k]>curr){
        //         // Swap
        //         nums1[k+1] = nums1[k];
        //         k = k - 1;
        //     }
        //     nums1[k+1] = curr;
        // }
        sort(nums1.begin(), nums1.end());
    }
};
// @lc code=end
