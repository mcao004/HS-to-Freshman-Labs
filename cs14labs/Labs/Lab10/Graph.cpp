// Marvin Cao
//Andy Truong
#include <iostream>
#include <fstream>
#include <list>
#include <map>
#include <utility>
#include <climits>
#include <queue>
#include "Vertex.h"
#include "Graph.h"

using namespace std;

Graph::Graph() {}

Graph::Graph(ifstream& inFS) { //Reads the graph input file and instantiates a graph object.
    
    //// cout << "constructor called"<< endl;
    int N; // number of nodes
    int M; // number of edges
    int i;
    int k;
    Vertex currVertex;
    string currLabel;
    int currCost;
    pair<int, int> currPair;
    
    inFS >> N;
    inFS >> M;
    
    // first N lines are node labels(vertices)
    for (i = 0; i < N; i++) {
        inFS >> currLabel;
        vertices.push_back(Vertex());
        vertices.at(i).label = currLabel;
    }
    
    // next M lines are edges e = (u, v, c)
    for (int j = 0; j < M; j++) {
        inFS >> currLabel;
        // find currLabel in vertices
        for (i = 0; i < N; i++) {
            if (currLabel.compare(vertices.at(i).label) == 0) {
                break;
            }
        } // now i is the index of the source vertex
        
        inFS >> currLabel; // now the label of the sink vertex
        for (k = 0; k < N; k++) {
            if (currLabel.compare(vertices.at(k).label) == 0) {
                break;
            }
        } // now i is the index of the sink vertex
        
        inFS >> currCost;
        
        currPair = pair<int, int>(k,currCost);
        vertices[i].neighbors.push_back(currPair);
    }
    //// cout << "End Constructor" << endl;
}

Graph::~Graph() {
}

void Graph::output_graph(const string & outputFile) {
    // cout << "Start output" << endl;
    
    ofstream outFS(outputFile.c_str());
    if (!outFS.is_open()) {
        cout << "Error opening" << outputFile << endl;
        return;
    }
    outFS << "digraph G {" << endl;
    
    // for each vertex
    for (unsigned i = 0; i < vertices.size(); i++) {
        outFS << "\t" << vertices.at(i).label << "["
            << "color = " << "Magenta" << ", style = filled, label = "
            << "\"" << vertices.at(i).label << ", " << vertices.at(i).distance << "\""
            << "];" << "\n";
    }
    //cout << "Is it a pair? " << endl;
    // now for the edges
    std::list<pair<int, int> >::iterator it;
    for (unsigned i = 0; i < vertices.size(); i++) {
         it = vertices.at(i).neighbors.begin();
         
         //cout << "Working on : " << vertices.at(i).neighbors.front().first << endl;
         
         while (it != vertices.at(i).neighbors.end()) {
             outFS << "\t" << vertices.at(i).label << "->" << vertices.at(it->first).label 
             /*<< "[label= " << it->second << "]"*/<< ";\n";
             it++;
         }
    }
    //cout << "practically Done" << endl;
    
    outFS << "}";
    outFS.close();// cout << "We Good?" << endl;
    string jpgFilename = outputFile.substr(0,outputFile.size()-4)+".jpg";
    string command = "dot -Tjpg " + outputFile + " -o " + jpgFilename;
    system(command.c_str());
    
    //cout << "End output" << endl;
}

/*
for each vertex u in V[G] - [s] do
color[u] = WHITE (White means undiscovered)
d[u] = Infinity (distance from s)
pr[u] = NIL (previous vertex)
color[s] = GRAY, d[s] = 0, pr[s] = NIL, Q = {}
ENQUEUE(Q,s)
while Q ≠ {} do
u = DEQUEUE(Q)
for each v in Adjacent[u] do
if color[v] == WHITE then
color[v] = GRAY (Gray means discovered, but not expanded)
d[v] = d[u] + 1
pr[v] = u
ENQUEUE(Q, v)
color[u] = BLACK (Black means expanded)
*/
void Graph::bfs() {
    
    //cout << "Start bfs" << endl;
    queue<Vertex> q;
    Vertex u, v;
    std::list<pair<int, int> >::iterator it;
    
    // initialization
    for (unsigned i = 0; i < vertices.size(); i++) {
        vertices.at(i).color = "WHITE";
        vertices.at(i).distance = INT_MAX;
        vertices.at(i).prev = 0;
    }
    
    // starting vertex
    vertices.at(0).color = "GRAY";
    vertices.at(0).distance = 0;
    vertices.at(0).prev = 0;
    
    q.push(vertices[0]);
    while(!q.empty()) {
        u = q.front();
        q.pop();
        it = u.neighbors.begin();
       // cout << "into neighbors" << endl;
        while(it != u.neighbors.end()) {
         //   cout << "current: " << vertices.at(it->first).label << ", color: " << vertices.at(it->first).color << endl;
            if (vertices.at(it->first).color == "WHITE") {
                vertices.at(it->first).color = "GRAY";
                vertices.at(it->first).distance = u.distance + it->second;
                vertices.at(it->first).prev = &u;
                q.push(vertices.at(it->first));
            }
            it++;
        }
        unsigned i;
        for(i = 0; i < vertices.size(); i++) {
            if (u.label == vertices.at(i).label)
                break;
        }
        vertices.at(i).color = "BLACK";
    }
    //cout << "End bfs" << endl;
}


void Graph::dfs() {
    //cout << "dfs called" << endl;
    for (unsigned i = 0; i < vertices.size(); i++) {
        vertices.at(i).color = "WHITE";
        vertices.at(i).prev = 0;
    } // initalize everything
    
    for (unsigned i = 0; i < vertices.size(); i++) {
        if (vertices.at(i).color == "WHITE") {
            dfs_visit(vertices.at(i));
        }
    }
    
}

void Graph::dfs_visit(Vertex & v) {
    //cout << "dfs_visit called" << endl;
    cout << v.label << endl;
    v.color = "GRAY"; // discovered
    std::list<pair<int, int> >::iterator it;
    
    // for each neighbor of v
    it = v.neighbors.begin();
    
    while(it != v.neighbors.end()) {
        if (vertices.at(it->first).color == "WHITE") {
            //cout << it->first << endl;
            vertices.at(it->first).prev = &v;
            dfs_visit(vertices.at(it->first));
        }
        it++;
    }
    v.color = "BLACK";
    
}