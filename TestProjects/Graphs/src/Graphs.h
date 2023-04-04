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

    bool is_connected(Node &node);
    bool is_connected(uint32_t node_id);
    vector<Edge> connected_nodes(void);
    uint32_t num_edges(void);
    uint32_t get_node_id(void);
    void add_edge(Node &node, uint32_t weight);
    uint32_t get_weight(uint32_t id);
    uint32_t get_weight(Node &node);
    void change_weight(Node &node, uint32_t new_weight);
    void remove_edge(Node &node);
    void remove_edge(uint32_t node_id);

private:
    uint32_t node_id;
    vector<Edge> edges;
};

class Graph
{
/**
 * TODO: Create exceptions:
 *          * NODE_NOT_PRESENT
*/
public:
    Graph(void);
    ~Graph(void);

    bool is_empty(void);
    void add_node(uint32_t id);
    bool is_node_present(uint32_t id);
    bool are_node_connected(uint32_t node_id_from, uint32_t node_id_to);
    uint32_t get_node_connection_weight(uint32_t node_id_from, uint32_t node_id_to);
    uint32_t get_num_nodes(void);
    void remove_node(uint32_t id);
    void make_connection(uint32_t node_id_begin, uint32_t node_id_end, uint32_t weigh);
    vector<Node> read_all_nodes(void);

private:
    vector<Node> nodes;
};

#endif /* GRAPHS_H */
