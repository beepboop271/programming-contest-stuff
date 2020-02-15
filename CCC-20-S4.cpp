#include <bits/stdc++.h>

#define st std::string
#define psi std::pair<st, int>
#define q std::queue<psi>
#define maps std::unordered_map<st, int>

maps visited;

bool found(st s) {
  // std::cout<<s<<"\n";
  char start = s.at(0);
  char cur = start;
  int i = 0;
  while (i < s.length() && s[i++] == cur) {}
  if (i >= s.length()) {
    // std::cout<<"wtf\n";
    return false;
  }
  --i;
  // std::cout<<"first ends at "<<i<<"\n";
  // if (s.rfind(cur) >= i) {

  // } else {
  cur = s.at(i);
  while (i < s.length() && s[i++] == cur) {}
  if (i >= s.length()) {
    // std::cout<<"wtf\n";
    return false;
  }
  --i;
  if (s.rfind(cur) >= i) {
    return false;
  } else {
  // std::cout<<"second ends at "<<i<<"\n";
    cur = s.at(i);
    while (i < s.length() && s[i++] == cur) {}
    if (i >= s.length()) {
      return true;
    } else {
        --i;
  // std::cout<<"third ends at "<<i<<"\n";
      if (s.at(i) != start) {
        return false;
      } else {
        while (i < s.length() && s[i++] == start) {}
        if (i >= s.length()) {
          return true;
        } else {
          return false;
        }
      }
    }
  }
  // }
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(NULL);

  st table;
  std::cin>>table;

  if (found(table)) {
    std::cout<<0<<std::endl;
    return 0;
  }

  // std::cout<<(lol(table, 0));

  q bfs;

  bfs.push(psi(table, 0));
  visited.emplace(table, 0);

  psi next;
  st curS;
  int step;
  st temp;
  st nextS;
  while (!bfs.empty()) {
    next = bfs.front();
    curS = next.first;
    step = next.second;
    bfs.pop();
    
    if (found(curS)) {
      std::cout<<step<<std::endl;
      return 0;
    } else {
      for (int i = 0; i < curS.length(); ++i) {
        for (int j = 0; j < curS.length(); ++j) {
          if (i != j) {
            temp = curS.substr(i, 1);
            nextS = st(curS);
            nextS.replace(i, 1, curS.substr(j, 1));
            nextS.replace(j, 1, temp);
            // if (visited.count(nextS) != 0) {
            //   std::cout<<"lol "<<cur<<" "<<visited.at(cur)<<" "<<steps<<"\n";
            // } else {
            //   std::cout<<"not in "<<cur;
            // }
            if (visited.count(nextS) == 0 || visited.at(nextS) >= step+1) {
              // std::cout<<"checking\n";
              visited.emplace(st(nextS), step+1);
              bfs.emplace(st(nextS), step+1);
            }
          }
        }
      }
    }
  }

  return 0;
}
