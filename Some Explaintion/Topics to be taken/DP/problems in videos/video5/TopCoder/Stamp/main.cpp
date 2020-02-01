#include <bits/stdc++.h>
using namespace std;
const int INF=1e9;
class Stamp{

public:
     int getMinimumCost(string desiredColor, int stampCost, int pushCost)
     {

    int n = (desiredColor.size());
    vector<int> msks(n);
    for (int i = 0; i < n; i++) {
      switch (desiredColor[i]) {
      case 'R': msks[i] = 1; break;
      case 'G': msks[i] = 2; break;
      case 'B': msks[i] = 4; break;
      case '*': msks[i] = 7; break;
      }
    }

    int ans = INF;
    for (int len = 1; len <= n; len++) {
      vector<int> dyn(n + 1, INF);
      dyn[0] = 0;
      for (int i = 0; i < n; i++) {
        int ccol = 7;
        for (int ne = i; ne < n; ne++) {
          ccol = ccol & msks[ne];
          if (!ccol) break;

          int clen = (ne - i + 1);
          if (clen < len) continue;

          int cops = (clen + len - 1) / len;
          dyn[ne + 1] = min(dyn[ne + 1], dyn[i] + cops * pushCost);
        }
      }

      ans = min(ans, dyn[n] + len * stampCost);
    }
    return ans;
  }
};


