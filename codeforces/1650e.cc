#include <bits/stdc++.h>

using namespace std;

int solve(vector<int>& exam, int d) {
  vector<int> interval;
  int last = 1;
  for (int e : exam) {
    interval.push_back(e - last);
    last = e+1;
  }
  interval.push_back(d-last+1);

  auto can_schedule = [&](int u) {
    // cout << "trying: " << u << endl;
    vector<int> temp = interval;
    int m = temp.size();
    bool found_less = false;
    bool found_large = false;
    for (int i = 0; i < m-1; ++i) {
      if (temp[i] < u) {
        temp[i+1] += temp[i]+1;
        if (found_less) return false;
        found_less = true;
      }
      if ((temp[i]-1) / 2 >= u) {
        found_large = true;
      }
      // for (int t : temp) cout << t << ' ';
      // cout << endl;
    }
    // cout << "found less: " << found_less << endl;
    if (!found_less) return true;
    // cout << "found large: " << found_large << endl;
    // cout << "last interval: " << temp.back() << endl;
    if (found_large || temp.back() >= u+1) return true;

    found_less = false;
    temp = interval;
    for (int i = m-2; i >= 0; --i) {
      if (temp[i] < u) {
        if (i-1 >= 0) temp[i-1] += temp[i]+1;
        if (found_less) return false;
        found_less = true;
      }
      if ((temp[i]-1) / 2 >= u) {
        found_large = true;
      }
      // for (int t : temp) cout << t << ' ';
      // cout << endl;
    }
    // cout << "found large: " << found_large << endl;
    return found_large;
  };

  int ans = 0;
  int l = 0, r = d;
  while (l <= r) {
    int m = l + (r-l) / 2;
    if (can_schedule(m)) {
      ans = m;
      l = m+1;
    } else {
      r = m-1;
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
    int n = 0, d = 0;
    cin >> n >> d;
    vector<int> exam(n);
    for (int i = 0; i < n; ++i) cin >> exam[i];
    int ans = solve(exam, d);
    cout << ans << '\n';
  }
  cout << flush;
  return 0;
}
