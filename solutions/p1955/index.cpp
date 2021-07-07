#include<bits/stdc++.h>
using namespace std;

const int MAX_NODE_COUNT = 100000;

int parent_node_map[MAX_NODE_COUNT + 5];

void init_trees() {
    for (int node = 0; node < MAX_NODE_COUNT; node++)
        parent_node_map[node] = node;
}

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

    const int EQ = 1, NE = 0;

    bool tree_type;
    for (int ii = 0; ii < cond_count; ii++) {
        int x1, x2, cond_type;
        cin >> x1 >> x2 >> cond_type;

        if (!ii)
            tree_type = cond_type;

        if (cond_type == tree_type) {
            merge_trees(x1, x2);
        } else {
            if (in_same_tree(x1, x2)) {
                cout << "NO" << endl;
                return;
            }
        }
    }

    cout << "YES" << endl;
    return;
}

int main() {
    int group_count;
    cin >> group_count;

    for (int i = 0; i < group_count; i++) {
        init_trees();
        handle_conditions();
    }

    return 0;
}
