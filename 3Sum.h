/*
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:
Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
The solution set must not contain duplicate triplets.
    For example, given array S = {-1 0 1 2 -1 -4},

    A solution set is:
    (-1, 0, 1)
    (-1, -1, 2)
*/

class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int> > res;  
        int N = num.size();
        if (N < 3) return res;

        sort(begin(num), end(num));
        for (int k = 0; k < N-2; k++) {
            if (k > 0 && num[k-1] == num[k]) continue; //remove any duplicates
            int i = k+1, j = N-1;
            while (i < j) {
                int sum = num[k]+num[i]+num[j];
                if (sum < 0) i++;
                else if (sum > 0) j--;
                else {
                    vector<int> sub;
                    sub.push_back(num[k]);
                    sub.push_back(num[i]);
                    sub.push_back(num[j]);
                    res.push_back(sub);
                    do { i++; } while (i < j && num[i-1] == num[i]); //remove any duplicates
                    do { j--; } while (i < j && num[j] == num[j+1]);
                }

            }
        }
        return res;
    }
};