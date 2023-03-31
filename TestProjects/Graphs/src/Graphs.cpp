#include "Graphs.h"

//********************************************************************
//********************************************************************
//*                      N o d e s    C l a s s                      *
//********************************************************************
//********************************************************************

typedef struct
{
    bool is_connected;
    uint32_t array_index;
} CheckEdgeConnection;

static inline CheckEdgeConnection is_connected_to(Node &node, uint32_t node_id)
{
    CheckEdgeConnection check = {.is_connected = false, .array_index = 0};
    vector<Edge> edges = node.connected_nodes();

    for (uint32_t i = 0; i < edges.size(); i++)
    {
        if (edges[i].node->get_node_id() == node_id)
        {
            check.is_connected = true;
            check.array_index = i;
            break;
        }
    }

    return check;
}

Node::Node(uint32_t node_id)
{
    this->node_id = node_id;
}

Node::~Node(void)
{
}

vector<Edge> Node::connected_nodes(void)
{
    return this->edges;
}

uint32_t Node::num_edges(void)
{
    return this->edges.size();
}

uint32_t Node::get_node_id(void)
{
    return this->node_id;
}

void Node::add_edge(Node &node, uint32_t weight)
{
    CheckEdgeConnection check = is_connected_to(*this, node.node_id);

    if (check.is_connected)
    {
        this->edges[check.array_index].weight = weight;
    }
    else
    {
        Edge new_edge = {.node = &node, .weight = weight};
        this->edges.insert(edges.end(), new_edge);
    }
}

void Node::change_weight(Node &node, uint32_t new_weight)
{
    CheckEdgeConnection check = is_connected_to(*this, node.node_id);

    if (!check.is_connected)
    {
        return;
    }

    this->edges[check.array_index].weight = new_weight;
}

void Node::remove_edge(Node &node)
{
    this->remove_edge(node.node_id);
}

void Node::remove_edge(uint32_t node_id)
{
    CheckEdgeConnection check = is_connected_to(*this, node_id);

    if (!check.is_connected)
    {
        return;
    }

    this->edges.erase(this->edges.begin() + check.array_index);
}

//********************************************************************
//********************************************************************
//*                      G r a p h    C l a s s                      *
//********************************************************************
//********************************************************************

typedef struct
{
    bool is_present;
    uint32_t array_index;
} CheckIfNodesIsPresent;

static inline CheckIfNodesIsPresent is_this_node_already_present(Graph &graph, uint32_t node_id)
{
    vector<Node> nodes = graph.read_all_nodes();
    CheckIfNodesIsPresent check = {.is_present = false};

    for (uint32_t i = 0; i < nodes.size(); i++)
    {
        if (nodes[i].get_node_id() == node_id)
        {
            check.is_present = true;
            check.array_index = i;
            break;
        }
    }

    return check;
}

Graph::Graph(void)
{
}

Graph::~Graph(void)
{
}

void Graph::add_node(uint32_t id)
{
    CheckIfNodesIsPresent check = is_this_node_already_present(*this, id);

    if (check.is_present)
    {
        return;
    }

    Node node(id);
    this->nodes.insert(nodes.end(), node);
}

void Graph::remove_node(uint32_t id)
{
    CheckIfNodesIsPresent check = is_this_node_already_present(*this, id);

    if (!check.is_present)
    {
        return;
    }

    this->nodes.erase(this->nodes.begin() + check.array_index);
}

void Graph::make_connection(uint32_t node_id_begin, uint32_t node_id_end, uint32_t weigh)
{
    CheckIfNodesIsPresent check_node_begin = is_this_node_already_present(*this, node_id_begin);
    CheckIfNodesIsPresent check_node_end = is_this_node_already_present(*this, node_id_end);

    if (!check_node_begin.is_present || !check_node_end.is_present)
    {
        return;
    }

    this->nodes[check_node_begin.array_index].add_edge(this->nodes[check_node_end.array_index], weigh);
}

vector<Node> Graph::read_all_nodes(void)
{
    return this->nodes;
}