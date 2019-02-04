//
// Created by Ahmet Emir Kocaaga on 21.11.2018.
//

#ifndef PROJECT3_GRAPH_H
#define PROJECT3_GRAPH_H
#include <vector>
#include <stack>
#include <iostream>

using namespace std;


class Graph {

public:

    vector<vector<int>> adjList;
    int scc[1000005];
    int cc = 0;
    Graph();
    vector<int> members;

    vector<int> findSCC();

    void dfs(stack<int> &s, int &id, int at, vector<int> &ids, vector<int> &low, vector<bool> &onS, int &count);





};


#endif //PROJECT3_GRAPH_H
