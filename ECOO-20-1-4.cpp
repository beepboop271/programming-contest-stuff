#include <bits/stdc++.h>
#define ll long long
#define byte unsigned char
#define MOD 1000000007

using namespace std;

int execute(int x, vector<pair<string, int>> fun, unordered_map<string, vector<pair<string, int>>> funs) {
  // cout << "WTF " << fun.size() << endl;
  string instruction;
  int operand;
  for (int i = 0; i < fun.size(); ++i) {
    instruction = fun[i].first;
    operand = fun[i].second;
    // cout << "execute " << instruction << " " << operand << endl;
    switch (instruction[0]) {
      case 'a':
        x = (x+operand)%MOD;
        break;
      case 's':
        x = (x-operand)%MOD;
        break;
      case 'm':
        x = (x*operand)%MOD;
        break;
      default:
        x = execute(x, funs.at(instruction), funs);
        break;
    }
    // cout << "x now " << x << endl;
  }
  return x;
}

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);

  int t, n;
  cin >> t;
  for (int test = 0; test < t; ++test) {
    cin >> n;
    unordered_map<string, vector<pair<string, int>>> funs {};
    stack<vector<pair<string, int>>> funstack {};

    vector<pair<string, int>> main {};

    funs.emplace("main_asdfasdfadf", main);
    funstack.push(main);

    // vector<pair<string, int>> &currFun = main;

    // currFun = main;
    string line;
    char c;
    for (int lineasdfasdf = 0; lineasdfasdf < n; ++lineasdfasdf) {
      cin >> line;
      c = line[0];
      if (c == 'F') {
        vector<pair<string, int>> newFun {};
        funstack.push(newFun);
        // currFun = newFun;
        cin >> line;
        funs.emplace(line, funstack.top());
      } else if (c == 'E') {
        funstack.pop();
      } else {
        cin >> line;
        if (c == 'C') {
          funstack.top().emplace_back(line, 0);
        } else {
          // cout << "before " << funstack.top().size();
          funstack.top().emplace_back(string(1, (char)(tolower(c))), stoi(line));
          // cout << " after " << funstack.top().size() << endl;
        }
      }
    }

    cout << execute(0, funstack.top(), funs) << endl;
  }

  return 0;
}
