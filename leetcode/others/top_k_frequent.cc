#include <bits/stdc++.h>

using namespace std;

class Solution1 {
 public:
  vector<int> TopKFrequent(vector<int>& a, int k) {
    unordered_map<int, int> count;
    for (int n : a) count[n]++;

    vector<pair<int, int>> counts(count.begin(), count.end());
    nth_element(counts.begin(), counts.begin()+k, counts.end(), [](auto p1, auto p2) {
      return p1.second > p2.second;
    });

    vector<int> ans;
    for (int i = 0; i < k; ++i) {
      ans.push_back(counts[i].first);
    }
    return ans;
  }
};

class Solution2 {
 public:
  int partition(vector<pair<int, int>>& counts, int l, int r) {
    pair<int, int> pivot = counts[r];
    int i = l;
    for (int j = l; j < r; ++j) {
      if (counts[j].second > pivot.second) {
        swap(counts[j], counts[i++]);
      }
    }
    swap(counts[i], counts[r]);
    return i;
  }

  void quick_select(vector<pair<int, int>>& counts, int l, int r, int k) {
    if (l < r) {
      int p = partition(counts, l, r);
      if (p == k) {
        return;
      } else if (p < k) {
        quick_select(counts, p+1, r, k);
      } else {
        quick_select(counts, l, p-1, k);
      }
    }
  }

  vector<int> TopKFrequent(vector<int>& a, int k) {
    unordered_map<int, int> count;
    for (int n : a) count[n]++;

    vector<pair<int, int>> counts(count.begin(), count.end());
    quick_select(counts, 0, counts.size()-1, k);

    vector<int> ans;
    for (int i = 0; i < k; ++i) {
      ans.push_back(counts[i].first);
    }
    return ans;
  }
};

int main(void) {
  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    int n = 0, k = 0;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int aa : a) cout << aa << " ";
    cout << endl;

    vector<int> ans = Solution1().TopKFrequent(a, k);
    for (int an : ans) cout << an << " ";
    cout << endl;

    ans = Solution2().TopKFrequent(a, k);
    for (int an : ans) cout << an << " ";
    cout << endl;
  }
  return 0;
}
