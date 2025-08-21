#include <iostream>
#include <algorithm>
using namespace std;

struct Team
{
    string name;
    int likes;
    int comments;
    int shares;

    int scores()
    {
        return likes + comments * 2 + shares * 3;
    }
};

void ranking(Team team[], int numOfTeams) 
{
    for (int i = 0; i < numOfTeams - 1; ++i) {
        for (int j = i + 1; j < numOfTeams; ++j) {
            if (team[j].scores() > team[i].scores()) {
                swap(team[i], team[j]);
            }
        }
    }

    for (int i = 0; i < 3; ++i) {
        cout << team[i].name << endl;
    }
}

int main()
{
    int n = 0;
    Team team[100];

    while (true) {
        cin >> team[n].name;
        if (team[n].name == "000") break;
        cin >> team[n].likes;
        cin >> team[n].comments;
        cin >> team[n].shares;
        n++;
    }

    ranking(team, n);

    return 0;
}