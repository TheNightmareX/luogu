#include<bits/stdc++.h>
using namespace std;

const int MAX_TEAM_COUNT = 1000;
const int MAX_MEMBER_COUNT = 1000;

void execute(int team_count) {
    queue<int> team_orders;
    queue<int> team_member_orders[MAX_TEAM_COUNT + 5];
    int member_id_to_team_id[MAX_TEAM_COUNT * MAX_MEMBER_COUNT + 5];
    for (int team_id = 1; team_id <= team_count; team_id++) {
        int member_count;
        cin >> member_count;

        for (int i = 0; i < member_count; i++) {
            int member_id;
            cin >> member_id;
            member_id_to_team_id[member_id] = team_id;
        }
    }

    while (true) {
        string operation;
        cin >> operation;

        if (operation == "STOP")
            break;
        
        if (operation == "ENQUEUE") {
            int member_id;
            cin >> member_id;

            int team_id = member_id_to_team_id[member_id];
            team_member_orders[team_id].push(member_id);
            if (team_orders.empty() || (team_orders.back() != team_id && (int)team_orders.size() <= team_count))
                team_orders.push(team_id);

            continue;
        }

        if (operation == "DEQUEUE") {
            int team_id = team_orders.front();
            int member_id = team_member_orders[team_id].front();
            cout << member_id << endl;
            team_member_orders[team_id].pop();
            if (team_member_orders[team_id].empty())
                team_orders.pop();

            continue;
        } 
    }
}

int main() {
    int case_index = 0;
    while (true) {
        int team_count;
        cin >> team_count;

        if (!team_count)
            break;

        cout << "Scenario #" << ++case_index << endl;
        execute(team_count);
        cout << endl;
    }
    
    return 0;
}
