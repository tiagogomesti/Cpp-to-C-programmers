#include "Graphs.h"

//********************************************************************
//********************************************************************
//*                      N o d e s    C l a s s                      *
//********************************************************************
//********************************************************************

CheckEdgeConnection Node::is_there_edge_to_this_node(uint32_t node_id)
{
    CheckEdgeConnection check = {.is_connected = false, .array_index = 0};

    for (uint32_t i = 0; i < this->edges.size(); i++)
    {
        if (this->edges[i].node->node_id == node_id)
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

void Node::add_edge(Node &node, uint32_t weight)
{
    CheckEdgeConnection check = this->is_there_edge_to_this_node(node.node_id);

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
    CheckEdgeConnection check = this->is_there_edge_to_this_node(node.node_id);

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
    CheckEdgeConnection check = this->is_there_edge_to_this_node(node_id);

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
