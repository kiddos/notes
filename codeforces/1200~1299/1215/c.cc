#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

// ab
// ba
// 1 1
// bb
// aa
// 1 2
// ba
// ba
//
// aa
// bb
// 1 2
//
// baaaaa
// abbbbb
// aaaaaa
// bbbbbb

void solve() {
  int n = 0;
  cin >> n;
  string s, t;
  cin >> s >> t;
  vector<int> count(2);
  for (int i = 0; i < n; ++i) {
    count[s[i]-'a']++;
    count[t[i]-'a']++;
  }

  if (count[0] % 2 != 0 || count[1] % 2 != 0) {
    cout << "-1" << endl;
    return;
  }

  vector<set<int>> s_indices(2);
  vector<set<int>> t_indices(2);
  for (int i = 0; i < n; ++i) {
    if (s[i] != t[i]) {
      s_indices[s[i]-'a'].insert(i);
      t_indices[t[i]-'a'].insert(i);
    }
  }

  vector<pair<int,int>> ans;

  auto swap1 = [&](set<int>& indices1, set<int>& indices2, set<int>& indices3, set<int>& indices4) {
    while (indices1.size() >= 2 && indices2.size() >= 2) {
      vector<int> i1, i2;
      for (int t = 0; t < 2; ++t) {
        int idx1 = *indices1.begin();
        i1.push_back(idx1);
        indices1.erase(idx1);
        indices4.erase(idx1);

        int idx2 = *indices2.begin();
        i2.push_back(idx2);
        indices2.erase(idx2);
        indices3.erase(idx2);
      }
      if (i1[0] != i2[0]) {
        ans.push_back({i1[0], i2[0]});
      } else {
        ans.push_back({i1[0], i2[1]});
      }
    }
  };

  swap1(s_indices[0], t_indices[1], s_indices[1], t_indices[0]);
  swap1(s_indices[1], t_indices[0], s_indices[0], t_indices[1]);

  auto swap2 = [&](set<int>& indices1, set<int>& indices2, set<int>& indices3, set<int>& indices4) {
    if (!indices1.empty() && !indices2.empty() && !indices3.empty() && !indices4.empty()) {
      int i1 = *indices1.begin();
      int i2 = *indices2.begin();
      // int i3 = *indices3.begin();
      int i4 = *indices4.begin();
      ans.push_back({i1, i2});
      ans.push_back({i1, i4});
    }
  };

  swap2(s_indices[0], t_indices[1], s_indices[1], t_indices[0]);

  cout << ans.size() << endl;
  for (auto [i1, i2]: ans) {
    cout << i1+1 << " " << i2+1 << endl;
    // swap(s[i1], t[i2]);
  }

  // cout << s << endl;
  // cout << t << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
