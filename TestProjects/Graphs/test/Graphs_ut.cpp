#include <Graphs.h>
#include <gtest/gtest.h>

#include <cstdlib>
#include <iostream>

#define MAX_ID 0xFFFFFFFF

//###############################################################################//
//#                                Node Class UT                                #//
//###############################################################################//
TEST(NodeClass, Constructor)
{
    uint32_t node_id = rand() % MAX_ID;
    Node node = Node(node_id);
    EXPECT_EQ(node.get_node_id(), node_id);
}

TEST(NodeClass, is_connected_1)
{
    Node node_1(0), node_2(1), node_3(2);

    uint32_t edge_weight = (rand() % 10) + 1;
    node_1.add_edge(node_2, edge_weight);

    EXPECT_TRUE(node_1.is_connected(node_2));
    EXPECT_FALSE(node_1.is_connected(node_3));
}

TEST(NodeClass, is_connected_2)
{
    Node node_1(0), node_2(1), node_3(2);

    uint32_t edge_weight = (rand() % 10) + 1;
    node_1.add_edge(node_2, edge_weight);

    EXPECT_TRUE(node_1.is_connected(node_2.get_node_id()));
    EXPECT_FALSE(node_1.is_connected(node_3.get_node_id()));
}

TEST(NodeClass, num_edges)
{
    const uint32_t num_nodes = 65;
    Node *nodes[num_nodes];

    for (uint32_t i = 0; i < num_nodes; i++)
    {
        nodes[i] = new Node(i);
    }

    for (uint32_t i = 0; i < num_nodes - 1; i++)
    {
        nodes[0]->add_edge(*nodes[i + 1], (rand() % 20) + 1);
    }

    EXPECT_EQ(nodes[0]->num_edges(), num_nodes - 1);
}

TEST(NodeClass, add_edge_1)
{
    const uint32_t num_nodes = 65;
    Node *nodes[num_nodes];
    vector<Edge> edge_ref;

    for (uint32_t i = 0; i < num_nodes; i++)
    {
        nodes[i] = new Node(i);
    }

    for (uint32_t i = 0; i < num_nodes - 1; i++)
    {
        Edge temp_edge;
        temp_edge.node = nodes[i + 1];
        temp_edge.weight = (rand() % 10) + 1;
        edge_ref.insert(edge_ref.end(), temp_edge);
        nodes[0]->add_edge(*nodes[i + 1], edge_ref[i].weight);
    }

    vector<Edge> edge_test = nodes[0]->connected_nodes();

    for (uint32_t i = 0; i < num_nodes - 1; i++)
    {
        EXPECT_EQ(edge_test[i].node, edge_ref[i].node);
        EXPECT_EQ(edge_test[i].weight, edge_ref[i].weight);
    }
}

TEST(NodeClass, add_edge_2)
{
    Node node_1(0), node_2(1);
    vector<Edge> edge_ref;
    uint32_t edge_weight;

    edge_ref = node_1.connected_nodes();
    EXPECT_EQ(edge_ref.size(), 0);

    edge_weight = 10;
    node_1.add_edge(node_2, edge_weight);
    edge_ref = node_1.connected_nodes();
    EXPECT_EQ(edge_ref.size(), 1);
    EXPECT_EQ(edge_ref[0].node->get_node_id(), node_2.get_node_id());
    EXPECT_EQ(edge_ref[0].weight, edge_weight);

    edge_weight = 20;
    node_1.add_edge(node_2, edge_weight);
    edge_ref = node_1.connected_nodes();
    EXPECT_EQ(edge_ref.size(), 1);
    EXPECT_EQ(edge_ref[0].node->get_node_id(), node_2.get_node_id());
    EXPECT_EQ(edge_ref[0].weight, edge_weight);
}

TEST(NodeClass, add_edge_3)
{
    Node node_1(0), node_2(1);
    node_1.add_edge(node_2, 0);
    vector<Edge> edge_ref = node_1.connected_nodes();

    EXPECT_EQ(edge_ref.size(), 0);
}

TEST(NodeClass, get_weight)
{
    Node node_1(0), node_2(1), node_3(2);

    uint32_t edge_weight = (rand() % 10) + 1;
    node_1.add_edge(node_2, edge_weight);
    EXPECT_EQ(node_1.get_weight(node_2.get_node_id()), edge_weight);

    edge_weight = (rand() % 10) + 1;
    node_2.add_edge(node_3, edge_weight);
    EXPECT_EQ(node_2.get_weight(node_3), edge_weight);
}

TEST(NodeClass, change_weight_1)
{
    Node node_1(0), node_2(1);

    uint32_t edge_weight = (rand() % 10) + 1;
    node_1.add_edge(node_2, edge_weight);

    uint32_t new_edge_weight = edge_weight + 1;
    node_1.change_weight(node_2, new_edge_weight);

    EXPECT_EQ(node_1.get_weight(node_2), new_edge_weight);
}

TEST(NodeClass, change_weight_2)
{
    Node node_1(0), node_2(1);

    uint32_t old_edge_weight = (rand() % 10) + 1;
    node_1.add_edge(node_2, old_edge_weight);

    uint32_t new_edge_weight = 0;
    node_1.change_weight(node_2, new_edge_weight);

    EXPECT_EQ(node_1.get_weight(node_2), old_edge_weight);
}

TEST(NodeClass, change_weight_3)
{
    Node node_1(0), node_2(1);

    uint32_t edge_weight = (rand() % 10) + 1;
    node_1.change_weight(node_2, edge_weight);

    EXPECT_EQ(node_1.get_weight(node_2), 0);
}

TEST(NodeClass, remove_edge_1)
{
    Node node_1(0), node_2(1);

    uint32_t edge_weight = (rand() % 10) + 1;
    node_1.add_edge(node_2, edge_weight);

    node_1.remove_edge(node_2);
    EXPECT_FALSE(node_1.is_connected(node_2));
}

TEST(NodeClass, remove_edge_2)
{
    Node node_1(0), node_2(1);

    EXPECT_FALSE(node_1.is_connected(node_2));
    node_1.remove_edge(node_2);
    EXPECT_FALSE(node_1.is_connected(node_2));
}

TEST(GraphClass, is_empty_1)
{
    Graph g1;
    EXPECT_TRUE(g1.is_empty());
}

TEST(GraphClass, is_empty_2)
{
    Graph g1;
    const uint32_t id = 10;
    g1.add_node(id);
    EXPECT_FALSE(g1.is_empty());
}

TEST(GraphClass, add_node_1)
{
    Graph g1;
    const uint32_t id = 10;
    EXPECT_TRUE(g1.is_empty());
    g1.add_node(id);
    EXPECT_FALSE(g1.is_empty());
    EXPECT_TRUE(g1.is_node_present(id));
}

TEST(GraphClass, add_node_2)
{
    Graph g1;
    const uint32_t id = 10;
    g1.add_node(id);
    EXPECT_EQ(g1.get_num_nodes(), 1);
}

TEST(GraphClass, add_node_3)
{
    Graph g1;
    const uint32_t id_1 = 10;
    const uint32_t id_2 = 20;
    g1.add_node(id_1);
    g1.add_node(id_1);
    EXPECT_EQ(g1.get_num_nodes(), 1);
    g1.add_node(id_2);
    EXPECT_EQ(g1.get_num_nodes(), 2);
}

int main(int argc, char **argv)
{
    srand((unsigned)time(NULL));
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
