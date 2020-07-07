#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<set>
#include<unordered_map>
#include<algorithm>
#include<string>
#include<unordered_set>
#include<map>

using namespace std;

class Solution
{
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
    {
        if (n == 0) return;
        int prev = 0;
        int current = 0;
        int pos = 0;
        int last = m;
        for (int i = 0; i < m; )
        {
            current = BinarySerch(nums2, nums1[pos]) - 1;
            if (current == n - 2 && nums1[pos] >= nums2[n - 1])
                current = current + 1;
            if (current < prev)
            {
                prev = current + 1;
                i++;
                pos++;
                continue;
            }
            else
            {
                int quanlity = current - prev + 1;
                last = last + quanlity;
                for (int j = m - 1; j >= i; j--)
                {
                    nums1[pos + j - i + quanlity] = nums1[pos + j - i];

                }
                for (int j = 0; j < quanlity; j++)
                {
                    nums1[pos + j] = nums2[prev + j];
                }
                i++;
                pos = pos + quanlity + 1;
                prev = current + 1;
            }
        }
        if (prev < n)
        {
            int quanlity = n - prev;
            for (int j = 0; j < quanlity; j++)
            {
                nums1[last + j] = nums2[prev + j];
            }
        }

    }
    int BinarySerch(vector<int>& nums2, int target)
    {
        int low = 0, high = nums2.size() - 1;
        while (low < high)
        {
            int mid = low + (high - low) / 2;
            if (nums2[mid] > target) high = mid;
            else low = mid + 1;
        }
        return high;
    }
};