//
// Created by Ahmet Emir Kocaaga on 21.11.2018.
//

#include "Graph.h"
#include <stack>
#include <iostream>




Graph::Graph() {};

vector<int> Graph::findSCC() {

    int n = this->adjList.size();
    int id = 0;
    int sccCount = 0;
    stack<int> s;


    vector<int> ids;
    for(int i = 0; i < n; i++){
        ids.push_back(-1);
    }
    vector<int> low;
    for(int i = 0; i < n; i++){
        low.push_back(0);
    }
    vector<bool> onStack;
    for(int i = 0; i < n; i++){
        onStack.push_back(false);
    }

    for(int i = 0; i < n; i++){
        if(ids[i] == -1){
            dfs(s, id, i, ids, low, onStack, sccCount);
        }

    }

    return low;

}

void Graph::dfs(stack<int> &s, int &id, int at, vector<int> &ids, vector<int> &low, vector<bool> &onS, int &count) {

 //   cout << at << id << endl;
    s.push(at);
    onS[at] = true;
    ids[at] = id;
    low[at] = id;
    id++;

    for(int i = 0; i < this->adjList[at].size(); i++){
        int to = this->adjList[at][i];
        if(ids[to] == -1){
            dfs(s, id, to, ids, low, onS, count);
            low[at] = min(low[at], low[to]);

        }
        if(onS[to]){
            low[at] = min(low[at], ids[to]);
        }

    }

    if(ids[at] == low[at]){

        this->members.push_back(at);
        while(true){

            int temp = s.top();
            s.pop();
            scc[temp] = cc;
            onS[temp] = false;
            if(temp == at){
                break;
            }

        }
        cc++;
        count++;

    }

}

