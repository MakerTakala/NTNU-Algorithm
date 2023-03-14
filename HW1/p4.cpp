#include <bits/stdc++.h>
#define ll long long int
#define Node pair<ll, ll>
#define x first
#define y second
using namespace std;

bool pair_compare(Node p1, Node p2) {
    if(p1.x == p2.x) return p1.y < p2.y;
    return p1.x < p2.x;
}

ll get_area(Node p1, Node p2, Node p3) {
    ll a1 = p1.x * p2.y + p2.x * p3.y + p3.x * p1.y;
    ll a2 = p1.y * p2.x + p2.y * p3.x + p3.y * p1.x;
    return a1 - a2;
}

ll find_convex(Node leftest_node, Node rightest_node, vector<Node> nodes) {
    if(nodes.empty()) return;

    Node max_node;
    ll max_area = 0;
    for(Node node : nodes) {
        ll area = get_area(leftest_node, rightest_node, node);
        if(area > max_area) {
            max_node = node;
            max_area = area;
        }
    }


    vector<Node> left_nodes, right_nodes;
    for(auto node : nodes) {
        if(get_area(leftest_node, max_node, node) > 0) 
            left_nodes.push_back(node);
        else if(get_area(max_node, rightest_node, node) > 0)
            right_nodes.push_back(node);
    }

    return max_area + find_convex(leftest_node, max_node, left_nodes) + find_convex(max_node, rightest_node, right_nodes);
}

int main() {
    int n;

    cin>>n;
    vector<Node> nodes(n);
    for(Node &node : nodes) {
        cin>>node.x>>node.y;
    }
    sort(nodes.begin(), nodes.end(), pair_compare);

    Node leftest_node = nodes.front(), rightest_node = nodes.back();
    vector<Node> up_nodes, down_nodes;

    for(auto node : nodes) {
        ll area = get_area(leftest_node, rightest_node, node);
        if(area > 0) 
            up_nodes.push_back(node);
        else if(area < 0)
            down_nodes.push_back(node);
    }

    cout<<(find_convex(leftest_node, rightest_node, up_nodes) + find_convex(rightest_node, leftest_node, down_nodes)) / 2.0<<endl;

    return 0;
}