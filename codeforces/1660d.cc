#include <bits/stdc++.h>

using namespace std;

pair<int, int> solve(vector<int>& a) {
  int n = a.size();
  int best_two_count = 0;
  pair<int, int> ans = {n, 0};

  for (int i = 0; i < n; ++i) {
    if (a[i] != 0) {
      int j = i;
      int neg_count = 0;
      int two_count = 0;
      while (j < n && a[j] != 0) {
        if (abs(a[j]) == 2) two_count++;
        if (a[j] < 0) neg_count++;
        j++;
      }

      if (neg_count % 2 == 0) {
        if (two_count > best_two_count) {
          ans = {i, n-j};
          best_two_count = two_count;
        }
      } else {
        int l = i, r = j-1;
        int count1 = two_count, count2 = two_count;
        while (l <= j-1) {
          if (abs(a[l]) == 2) count1--;
          if (a[l++] < 0) break;
        }
        while (r >= i) {
          if (abs(a[r]) == 2) count2--;
          if (a[r--] < 0) break;
        }

        // cout << "left: " << l << " right: " << r << endl;
        // cout << "count1: " << count1 << ", count2: " << count2 << endl;
        if (count1 > best_two_count) {
          ans = {l, n-j};
          best_two_count = count1;
        }
        if (count2 > best_two_count) {
          ans = {i, n-r-1};
          best_two_count = count2;
        }
      }

      i = j;
    }
  }
  return ans;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int t = 0;
  cin >> t;
  while (t-- > 0) {
    int n = 0;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    pair<int, int> ans = solve(a);
    cout << ans.first << ' ' << ans.second << '\n';
  }
  cout.flush();
  return 0;
}
