#include <iostream>
#include <queue>
#include <vector>
#include <sstream>
#include <fstream>
#include<iterator>
#include "Graph.h"

using namespace std;

template <class Container>
void split1(const string& str, Container& cont)
{
    istringstream iss(str);
    copy(istream_iterator<string>(iss),
         istream_iterator<string>(),
         back_inserter(cont));
}

float findAmount(const vector<string> words)
{
    float return_value = 0;
    for(int i=0; i< words.size(); i++){
        if (words[i][0] == '$') {
            const char *cstr = (words[i].substr(1)).c_str();
            return_value = strtof(cstr, NULL);
            //        cout << "return_value: " << return_value << endl;
            break;
        }
    }
    return return_value;
}

int main(int argc, char* argv[]) {


    ifstream infile(argv[1]);
    string line;
    vector<string> input;
    // process first line
    getline(infile, line);
//    cout << line << endl;
    vector<string> words;
    split1(line,words);
    int N = stoi(words[0]);
//    cout << "number of input lines: " << N << endl;

    Graph myGraph;
    vector<vector<int>> nodes;

    for (int i=0; i<N; i++) {

        getline(infile, line);
        //       cout << "line: " << line << endl;
        vector<int> list;
        myGraph.adjList.push_back(list);
        vector<string> words1;
        split1(line,words1);
        int numOfKeys = stoi(words1[0]);
        if(numOfKeys != 0) {
            for (int j = 1; j <= numOfKeys; j++) {

                myGraph.adjList.back().push_back(stoi(words1[j])-1);

            }
        }

    }

//    for(int i = 0; i < N; i++){
//
//        cout << i << "-->";
//        for(int v : myGraph.adjList[i]){
//            cout << v << " ";
//        }
//        cout << endl;
//    }

//    cout << "scc list:";

    vector<int> temp = myGraph.findSCC();
 //   for(int i = 0; i < N; i++){
//        cout << myGraph.scc[i] << " ";
//    }
//    cout << endl;
//    cout << myGraph.cc << endl;

    int marker[myGraph.cc];

    for(int i = 0; i < myGraph.cc; i++){
        marker[i] = 0;
   }

//    cout<< "members list:";
//    for(int i = 0; i< myGraph.members.size(); i++){
//        cout << myGraph.members[i] << " ";
//    }

//    cout << endl;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < myGraph.adjList[i].size(); j++){
            if(myGraph.scc[myGraph.adjList[i][j]]!=myGraph.scc[i]){
                marker[myGraph.scc[myGraph.adjList[i][j]]] = 1;
            }
        }
    }
//    cout<< "marker list:";
//    for(int i = 0; i< myGraph.cc; i++){
//        cout<< marker[i] << " ";
//    }
//    cout<<endl;
    int count = 0;
    for(int i = 0; i < myGraph.cc; i++){

        if(marker[i] == 0){
            count++;
         //   cout << myGraph.members[i] + 1 << " ";
        }

    }
//    cout<<endl;
//    cout<<count;
     ofstream myfile;
     myfile.open (argv[2]);
     myfile<<count;
    for(int i = 0; i < myGraph.cc; i++){

        if(marker[i] == 0){
            count++;
            myfile << " " << myGraph.members[i] + 1;
        }

    }

    return 0;
}