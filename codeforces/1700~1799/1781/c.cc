#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n = 0;
  cin >> n;
  string s;
  cin >> s;

  vector<int> count(26);
  for (char ch : s) count[ch-'a']++;

  vector<pair<int,char>> all;
  for (int i = 0; i < 26; ++i) {
    all.push_back({count[i], i + 'a'});
  }
  sort(all.rbegin(), all.rend());


  int best_diff = numeric_limits<int>::max();
  string ans;
  for (int k = 26; k >= 1; --k) if (n % k == 0) {
    unordered_map<char, int> available;
    for (int j = 0; j < k; ++j) {
      available[all[j].second] = n / k;
    }

    vector<int> dont_know;
    string t;
    for (int i = 0; i < n; ++i) {
      if (available.count(s[i])) {
        t.push_back(s[i]);
        if (--available[s[i]] == 0) available.erase(s[i]);
      } else {
        t.push_back('?');
        dont_know.push_back(i);
      }
    }

    int diff = dont_know.size();
    if (diff < best_diff) {
      while (dont_know.size() > 0) {
        int index = dont_know.back();
        dont_know.pop_back();
        t[index] = available.begin()->first;
        available.begin()->second--;
        if (available.begin()->second == 0) {
          available.erase(available.begin());
        }
      }

      ans = t;
      best_diff = diff;
    }
  }

  cout << best_diff << endl;
  cout << ans << endl;
}

// hello
// c = 4
// helxo b = 1

// codeforces
// codefofced b = 2

// eevee
// eeeee b = 5

// appall
// appall b = 2

// abcdefghijklmnopqrstvuwxyzz
// aaadddgggjjjmmmpppsssuuuzzz b = 3

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
