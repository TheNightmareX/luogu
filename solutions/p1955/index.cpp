#include<bits/stdc++.h>
using namespace std;

map<int, int> parent_node_map;

int get_root_node(int node) {
    int parent_node = parent_node_map[node];
    if (parent_node == node)
        return node;
    else
        return parent_node_map[node] = get_root_node(parent_node);
}

int in_same_tree(int node_a, int node_b) {
    int root_a = get_root_node(node_a);
    int root_b = get_root_node(node_b);
    return root_a == root_b;
}

int merge_trees(int node_a, int node_b) {
    int root_node_a = get_root_node(node_a);
    int root_node_b = get_root_node(node_b);
    parent_node_map[root_node_a] = root_node_b;
    return root_node_b;
}

void handle_conditions() {
    int cond_count;
    cin >> cond_count;

    const int MAX_COND_COUNT = 100000;
    const int EQ = 1, NE = 0;
    
    struct {
        int x1, x2, type;
    } eq_conds[MAX_COND_COUNT + 5];

    for (int i = 0; i < cond_count; i++) {
        int x1, x2, type;
        cin >> x1 >> x2 >> type;
        eq_conds[i] = { x1, x2, type };
        parent_node_map[x1] = x1;
        parent_node_map[x2] = x2;
    }

    for (int i = 0; i < cond_count; i++) {
        if (eq_conds[i].type == NE)
            continue;
        merge_trees(eq_conds[i].x1, eq_conds[i].x2);
    }

    for (int i = 0; i < cond_count; i++) {
        if (eq_conds[i].type == EQ)
            continue;
        if (in_same_tree(eq_conds[i].x1, eq_conds[i].x2)) {
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;
    return;
}

int main() {
    int group_count;
    cin >> group_count;

    for (int i = 0; i < group_count; i++) {
        parent_node_map.clear();
        handle_conditions();
    }

    return 0;
}
