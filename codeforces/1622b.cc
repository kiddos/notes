#include <bits/stdc++.h>

using namespace std;

struct Song {
  int index;
  int like;
  int p;
};

vector<int> solve(vector<int>& p, string q) {
  int n = p.size();
  vector<Song> songs;
  for (int i = 0; i < n; ++i) {
    songs.push_back(Song{i, q[i] == '1', p[i]});
  }
  sort(songs.begin(), songs.end(), [&](auto& s1, auto& s2) {
    if (s1.like == s2.like) {
      return s1.p < s2.p;
    }
    return s1.like < s2.like;
  });

  vector<int> ans(n);
  for (int i = 0; i < n; ++i) {
    ans[songs[i].index] = i+1;
  }
  return ans;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    int n = 0;
    cin >> n;
    vector<int> p(n);
    string q;
    for (int i = 0; i < n; ++i) cin >> p[i];
    cin >> q;
    vector<int> ans = solve(p, q);
    for (int a : ans) cout << a << ' ';
    cout << '\n';
  }
  cout << flush;
  return 0;
}
