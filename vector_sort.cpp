#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct Player {
    string name;
    int score;
};
struct com
{
    bool operator()(Player const &a, Player const &b) const {
    if(a.score>b.score)
        return true;
    else if(a.score<b.score)
        return false;
    else
    {
        if(a.name.compare(b.name)<=0)
            return true;
        else
            return false;
    }
    }
};
vector<Player> comparator(vector<Player> players) {
sort(players.begin(),players.end(),com());
    return players;
}

int main() {

    int n;
    cin >> n;
    vector< Player > players;
    string name;
    int score;
    for(int i = 0; i < n; i++){
        cin >> name >> score;
        Player p1;
        p1.name = name, p1.score = score;
        players.push_back(p1);
    }

    vector<Player > answer = comparator(players);
    for(int i = 0; i < answer.size(); i++) {
        cout << answer[i].name << " " << answer[i].score << endl;
    }
    return 0;
}
