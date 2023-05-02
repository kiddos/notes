#include <bits/stdc++.h>
 
using namespace std;
 
void solve(vector<vector<int>>& arr) {
  if (arr.size() == 1) {
    cout << "NO" << endl;
    return;
  }
  int num_bits = 0;
  for (vector<int>& a : arr) {
    num_bits = max(num_bits, *max_element(a.begin(), a.end()));
  }
  vector<int> bits(num_bits+1);
  for (vector<int>& a : arr) {
    for (int b : a) {
      bits[b]++;
    }
  }
 
  for (vector<int>& a : arr) {
    bool can_remove = true;
    for (int b : a) {
      if (bits[b] == 1) {
        can_remove = false;
        break;
      }
    }
 
    if (can_remove) {
      cout << "YES" << endl;
      return;
    }
  }
  cout << "NO" << endl;
}
 
int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
 
  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    int n = 0;
    cin >> n;
    vector<vector<int>> arr;
    for (int i = 0; i < n; ++i) {
      int k = 0;
      cin >> k;
      vector<int> a(k);
      for (int j = 0; j < k; ++j) cin >> a[j];
      arr.push_back(a);
    }
 
    solve(arr);
  }
  return 0;
}
