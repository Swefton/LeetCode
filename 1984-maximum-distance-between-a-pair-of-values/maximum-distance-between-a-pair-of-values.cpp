class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int maxDist = 0;
        int i = 0, j = 0;
        int n1 = nums1.size(), n2 = nums2.size();

        while (i < n1 && j < n2) {
            if (nums1[i] <= nums2[j]) {
                maxDist = max(maxDist, j - i);
                j++;
            } else {
                i++;
            }
        }

        return maxDist;
    }
};