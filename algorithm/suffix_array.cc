#include <bits/stdc++.h>

using namespace std;

#define ALPHABET 256

vector<int> suffix_array(const string& t) {
  const string s = t + "$";
  vector<pair<pair<int,int>, int>> suff;
  int n = s.length();
  for (int i = 0; i < n; ++i) {
    suff.push_back({{s[i], s[i]}, i});
  }
  sort(suff.begin(), suff.end());

  vector<int> equiv(n);

  auto compute_equiv = [&]() {
    for (int i = 1; i < n; ++i) {
      auto [p1, i1] = suff[i-1];
      auto [p2, i2] = suff[i];
      equiv[i2] = equiv[i1] + (p2 > p1);
    }
  };

  compute_equiv();

  for (int len = 1; len < n; len *= 2) {
    for (auto& [p, idx]: suff) {
      p.first = equiv[idx];
      p.second = equiv[(idx + len) % n];
    }
    sort(suff.begin(), suff.end());

    compute_equiv();
  }
  vector<int> sa(n);
  for (int i = 0; i < n; ++i) {
    sa[i] = suff[i].second;
  }
  return sa;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  string s = "abcbcba";
  // string s = "aaba";
  vector<int> p = suffix_array(s);
  for (int idx : p) {
    cout << idx << " ";
  }
  cout << endl;
  return 0;
}
