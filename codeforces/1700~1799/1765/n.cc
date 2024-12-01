#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  string x;
  int k = 0;
  cin >> x;
  cin >> k;

  int n = x.length();
  vector<int> next_smaller(n, n);
  vector<int> st;
  for (int i = 0; i < n; ++i) {
    while (!st.empty() && x[st.back()] > x[i]) {
      next_smaller[st.back()] = i;
      st.pop_back();
    }
    st.push_back(i);
  }

  // for (int i = 0; i < n; ++i) {
  //   cout << next_smaller[i] << " ";
  // }
  // cout << endl;

  string ans;
  int i = 0;
  for (char ch = '1'; ch <= '9'; ++ch) {
    auto result = x.find(ch);
    if (result != string::npos && (int)result <= k) {
      ans.push_back(ch);
      i = result+1;
      k -= result;
      break;
    }
  }

  while (i < n) {
    int idx = next_smaller[i];
    if (idx < n) {
      int to_remove = idx - i;
      if (to_remove <= k) {
        k -= to_remove;
        i = idx;
      } else {
        ans.push_back(x[i++]);
      }
    } else {
      ans.push_back(x[i++]);
    }
  }

  // cout << ans << endl;
  while (!ans.empty() && k > 0) {
    ans.pop_back();
    k--;
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    solve();
  }
  return 0;
}
