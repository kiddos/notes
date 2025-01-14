#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

string filter(const string& s, char c) {
  string ans;
  for (char ch : s) {
    if (ch != c) {
      ans.push_back(ch);
    }
  }
  return ans;
}

bool verify(const string& start, const string& remove, const string& t) {
  string t_prime = start;
  string s = start;
  for (char c : remove) {
    string s2 = filter(s, c);
    t_prime += s2;
    s = std::move(s2);
  }
  return t_prime == t;
}

void solve() {
  string t;
  cin >> t;

  int n = t.length();
  vector<int> char_count(26);
  for (int i = 0; i < n; ++i) {
    int c = t[i] -'a';
    char_count[c]++;
  }
  int unique_count = 0;
  for (int c = 0; c < 26; ++c) {
    if (char_count[c] > 0) {
      unique_count++;
    }
  }

  vector<vector<int>> prev_index(n+1, vector<int>(26, -1));
  for (int i = 0; i < n; ++i) {
    int c = t[i]-'a';
    prev_index[i][c] = i;
    for (int c2 = 0; c2 < 26; ++c2) {
      prev_index[i+1][c2] = prev_index[i][c2];
    }
  }

  vector<bool> found(26);
  auto find_new_char = [&](int index) -> int {
    int best = -1;
    int ans = -1;
    for (int c = 0; c < 26; ++c) {
      if (!found[c]) {
        int idx = prev_index[index][c];
        if (idx > best) {
          best = idx;
          ans = c;
        }
      }
    }
    return ans;
  };

  vector<int> read_count(26);

  string ans1, ans2;
  int idx = n-1;
  while (idx >= 0) {
    int new_char = find_new_char(idx);
    if (new_char < 0) {
      cout << "-1" << endl;
      return;
    }
    found[new_char] = true;

    int char_total = char_count[new_char];
    if (char_total % unique_count != 0) {
      cout << "-1" << endl;
      return;
    }
    read_count[new_char] = char_total / unique_count;
    ans2.push_back(new_char + 'a');
    int total_read = accumulate(read_count.begin(), read_count.end(), 0);
    unique_count--;

    if (unique_count == 0) {
      // cout << "idx=" << idx << endl;
      ans1 = t.substr(0, idx+1);
    }

    idx -= total_read;
    // cout << "new_char=" << new_char << endl;
  }
  if (unique_count != 0) {
    cout << "-1" << endl;
    return;
  }

  reverse(ans2.begin(), ans2.end());
  if (verify(ans1, ans2, t)) {
    cout << ans1 << " " << ans2 << endl;
  } else {
    cout << "-1" << endl;
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
