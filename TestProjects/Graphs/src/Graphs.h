#ifndef GRAPHS_H
#define GRAPHS_H

#include <cstdint>
#include <vector>

using namespace std;

class Node;

typedef struct
{
    Node *node;
    uint32_t weight;
} Edge;

class Node
{
public:
    Node(uint32_t node_id);
    ~Node(void);

    vector<Edge> connected_nodes(void);
    uint32_t num_edges(void);
    uint32_t get_node_id(void);
    void add_edge(Node &node, uint32_t weight);
    void change_weight(Node &node, uint32_t new_weight);
    void remove_edge(Node &node);
    void remove_edge(uint32_t node_id);

private:
    uint32_t node_id;
    vector<Edge> edges;
};

class Graph
{
public:
    Graph(void);
    ~Graph(void);

    void add_node(uint32_t id);
    void remove_node(uint32_t id);
    void make_connection(uint32_t node_id_begin, uint32_t node_id_end, uint32_t weigh);
    vector<Node> read_all_nodes(void);

private:
    vector<Node> nodes;
};

#endif /* GRAPHS_H */
