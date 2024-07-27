#include <bits/stdc++.h>

using namespace std;


class Solution {
 public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    if (nums1.size() > nums2.size()) {
      return findMedianSortedArrays(nums2, nums1);
    }

    int a = nums1.size();
    int b = nums2.size();
    bool odd = (a + b) % 2 == 1;
    int l = 0, r = a;
    while (l <= r) {
      int m1 = l + (r-l) / 2;
      int m2 = (a + b + 1) / 2 - m1;
      int a1 = m1 == 0 ? numeric_limits<int>::min() : nums1[m1-1];
      int a2 = m1 == a ? numeric_limits<int>::max() : nums1[m1];
      int b1 = m2 == 0 ? numeric_limits<int>::min() : nums2[m2-1];
      int b2 = m2 == 0 ? numeric_limits<int>::max() : nums2[m2];
      if (a1 <= b2 && b1 <= a2) {
        if (odd) return max(a1, b1);
        else return (max(a1, b1) + min(a2, b2)) / 2.0;
      }

      if (a1 > b2) {
        r = m1 - 1;
      } else {
        l = m1 + 1;
      }
    }
    return 0;
  }
};


int main(void) {
  mt19937 gen(chrono::system_clock::now().time_since_epoch().count());

  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    int n1 = 0, n2 = 0;
    cin >> n1 >> n2;
    vector<int> nums1(n1);
    vector<int> nums2(n2);

    uniform_int_distribution<int> dist(0, max(n1, n2) * 2);
    for (int i = 0; i < n1; ++i) nums1[i] = dist(gen);
    for (int i = 0; i < n2; ++i) nums2[i] = dist(gen);

    double median = Solution().findMedianSortedArrays(nums1, nums2);
    cout << "median : " << median << endl;
  }
  return 0;
}
