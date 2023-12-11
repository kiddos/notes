#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  string s;
  cin >> s;

  if (n % 2 == 1) {
    cout << "-1" << endl;
    return;
  }

  vector<int> ans;
  deque<char> d(s.begin(), s.end());
  int l = 0, r = n;
  for (int i = 0; i < n && !d.empty(); ++i) {
    while (!d.empty() && d.front() != d.back()) {
      d.pop_front();
      d.pop_back();
      l++;
      r--;
    }

    if (d.empty()) {
      break;
    }

    if (d.front() == '1') {
      d.push_front('1');
      d.push_front('0');
      ans.push_back(l);
      r += 2;
    } else if (d.front() == '0') {
      d.push_back('0');
      d.push_back('1');
      ans.push_back(r);
      r += 2;
    }
  }

  if (!d.empty()) {
    cout << "-1" << endl;
  } else {
    cout << ans.size() << endl;
    if (!ans.empty()) {
      for (int idx : ans) cout << idx << " ";
      cout << endl;
    }
  }
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
