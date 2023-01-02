#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  bool closeStrings(string word1, string word2) {
    vector<int> count1(26), count2(26), char_set1(26), char_set2(26);
    for (char c : word1) {
      count1[c-'a']++;
      char_set1[c-'a'] = 1;
    }
    for (char c : word2) {
      count2[c-'a']++;
      char_set2[c-'a'] = 1;
    }
    sort(count1.begin(), count1.end());
    sort(count2.begin(), count2.end());
    return count1 == count2 && char_set1 == char_set2;
  }
};


int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  string word1, word2;
  word1 = "abc";
  word2 = "bca";
  bool ans = Solution().closeStrings(word1, word2);
  assert(ans);

  word1 = "aaa";
  word2 = "bbb";
  ans = Solution().closeStrings(word1, word2);
  assert(!ans);

  word1 = "aaa";
  word2 = "aaa";
  ans = Solution().closeStrings(word1, word2);
  assert(ans);

  word1 = "cabbba";
  word2 = "aabbss";
  ans = Solution().closeStrings(word1, word2);
  assert(!ans);

  word1 = "cabbba";
  word2 = "abbccc";
  ans = Solution().closeStrings(word1, word2);
  assert(ans);

  word1 = "a";
  word2 = "aaa";
  ans = Solution().closeStrings(word1, word2);
  assert(!ans);

  word1 = "uau";
  word2 = "ssx";
  ans = Solution().closeStrings(word1, word2);
  assert(!ans);

  return 0;
}
