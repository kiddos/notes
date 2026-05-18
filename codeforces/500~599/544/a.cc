#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int k = 0;
  cin >> k;
  string q;
  cin >> q;
  int n = q.length();
  vector<vector<int>> count(26);
  for (int i = 0; i < n; ++i) {
    int c = q[i]-'a';
    count[c].push_back(i);
  }
  int distinct = 0;
  for (int c = 0; c < 26; ++c) {
    if (count[c].size() > 0) {
      distinct++;
    }
  }
  if (k > distinct) {
    cout << "NO" << endl;
    return;
  }

  int t = k;
  vector<int> choose;
  for (int c = 0; c < 26; ++c) {
    if (count[c].size() && count[c][0] == 0) {
      choose.push_back(count[c][0]);
      count[c].clear();
      t--;
      break;
    }
  }

  for (int c = 0; c < 26 && t > 0; ++c) {
    if (count[c].size()) {
      choose.push_back(count[c][0]);
      t--;
    }
  }

  sort(choose.begin(), choose.end());
  int size = choose.size();
  vector<string> ans;
  for (int i = 0; i < size; ++i) {
    if (i+1 < size) {
      int i1 = choose[i], i2 = choose[i+1];
      ans.push_back(q.substr(i1, i2-i1));
    } else {
      int i1 = choose[i];
      ans.push_back(q.substr(i1));
    }
  }
  cout << "YES" << endl;
  for (string s : ans) {
    cout << s << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
