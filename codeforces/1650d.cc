#include <bits/stdc++.h>

using namespace std;

vector<int> solve(vector<int>& a) {
  deque<int> d(a.begin(), a.end());
  int n = a.size();
  vector<int> ans(n);
  for (int i = n; i >= 1; --i) {
    if (d.back() != i) {
      int k = 0;
      for (; k < i && d.back() != i; ++k) {
        int last = d.back();
        d.pop_back();
        d.push_front(last);
      }
      ans[i-1] = i-k;
    }
    d.pop_back();
  }
  return ans;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int t = 0;
  cin >> t;
  while (t -- > 0) {
    int n = 0;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    vector<int> ans = solve(a);
    for (int a : ans) cout << a << ' ';
    cout << '\n';
  }
  cout << flush;
  return 0;
}
