/*
 * Main.cpp
 *
 *  Created on: Mar 11, 2018
 *      Author: Caleb Miller
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdio.h>
#include <string.h>
#include <stack>
#include <iomanip>
#include <list>
#include <limits.h>

using namespace std;

class Coord {
public:
Coord(int rr, int cc) : m_r(rr), m_c(cc) {}
int r() const { return m_r; }
int c() const { return m_c; }
private:
int m_r;
int m_c;
};
int minimum(int a[],int size) {
    int small=a[0];
    for(int i=0;i<size;i++)
        if(a[i]<small)
            small=a[i];
    return small;
}

void determineDistances(const char maze[][10], int sr, int sc, int dist[][10]) {
    stack<Coord> coordStack;
    coordStack.push(Coord(sr,sc));
    for(int i=0;i<10;i++)
        for(int j=0;j<10;j++)
        {
            dist[i][j]=99;
        }
        dist[sr][sc]=0;
        int distarr[11];
        int min;
        int currval;
        while (!coordStack.empty()) {
            Coord inuse = coordStack.top();
            coordStack.pop();
            const int row = inuse.r();
            const int col = inuse.c();

            cout<<"row"<<row<<"col"<<col<<endl;
            distarr[0]=dist[row-1][col];    //      Up
            distarr[1]=dist[row+1][col];    //      Down
            distarr[2]=dist[row][col-1];    //      Left
            distarr[3]=dist[row][col+1];    //      Right
            min=minimum(distarr,11);

            if(dist[row][col]>min+1)
            dist[row][col]=min+1;
            currval=dist[row][col];
            if ((maze[row-1][col] == '.')&&(dist[row-1][col]>(currval+1))) {
            	dist[row-1][col]=currval+1;
            	coordStack.push(Coord(row+1,col));
            }
             if (maze[row+1][col] == '.'&&(dist[row+1][col]>(currval+1))) {
            	 coordStack.push(Coord(row+1,col));
             }
            if (maze[row][col+1] == '.'&&(dist[row][col+1]>(currval+1))) {
            	dist[row][col+1]=currval+1;
            	coordStack.push(Coord(row,col+1));
            }
            if (maze[row][col-1] == '.'&&(dist[row][col-1]>(currval+1))) {
            	dist[row][col-1]=dist[row][col]+1;
            	coordStack.push(Coord(row,col-1));
            }
        }
}

class Graph
{
    int V;    // No. of vertices

    // Pointer to an array containing
    // adjacency lists
    list<int> *adj;

    // A recursive function used by DFS
    void DFSUtil(int v, bool visited[]);
public:
    Graph(int V);   // Constructor

    // function to add an edge to graph
    void addEdge(int v, int w);

    // DFS traversal of the vertices
    // reachable from v
    void DFS(int v);
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v�s list.
}

void Graph::DFSUtil(int v, bool visited[])
{
    // Mark the current node as visited and
    // print it
    visited[v] = true;
    cout << v << " ";

    // Recur for all the vertices adjacent
    // to this vertex
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFSUtil(*i, visited);
}

// DFS traversal of the vertices reachable from v.
// It uses recursive DFSUtil()
void Graph::DFS(int v)
{
    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;

    // Call the recursive helper function
    // to print DFS traversal
    DFSUtil(v, visited);
}

int main () {
	string txt[12];
	string line;

	int i=0;
	ifstream file ("MazeProject\src\input_file.txt");
	if (file.is_open()){
		while (!file.eof()){
			getline(file,line);
			txt[i]=line;
			i++;
		}
	}
	file.close();

	Graph g(11);
	g.addEdge(0, 0);
	g.addEdge(3, 10);
	g.addEdge(0, 6);
	g.addEdge(0, 7);
	g.addEdge(0, 9);
	g.addEdge(1, 1);
	g.addEdge(1, 2);
	g.addEdge(1, 4);
	g.addEdge(1, 7);
	g.addEdge(2, 1);
	g.addEdge(2, 7);
	g.addEdge(2, 8);
	g.addEdge(2, 10);
	g.addEdge(3, 1);
	g.addEdge(3, 2);
	g.addEdge(3, 3);
	g.addEdge(3, 4);
	g.addEdge(3, 7);
	g.addEdge(4, 0);
	g.addEdge(4, 6);
	g.addEdge(4, 9);
	g.addEdge(4, 10);
	g.addEdge(5, 2);
	g.addEdge(5, 3);
	g.addEdge(5, 4);
	g.addEdge(5, 5);
	g.addEdge(5, 7);
	g.addEdge(6, 1);
	g.addEdge(6, 8);
	g.addEdge(6, 9);
	g.addEdge(7, 1);
	g.addEdge(7, 2);
	g.addEdge(7, 3);
	g.addEdge(7, 6);
	g.addEdge(8, 1);
	g.addEdge(8, 5);
	g.addEdge(8, 6);
	g.addEdge(8, 8);
	g.addEdge(8, 10);
	g.addEdge(9, 3);
	g.addEdge(9, 7);

	cout << "Following is Depth First Traversal"
	            " (starting from vertex 2) \n";
	    g.DFS(2);

	ofstream myfile;
    myfile.open ("maze_project.txt");

    int height = 11;
    int width = 10;

    string open = "1";
    string start = "S";
    string free = "F";
    string wall = "0";

string blockArray[11][10] = {
		{"S","1","1","1","0","1","1","1","1","1"},
		{"1","0","0","0","1","1","0","0","0","1"},
		{"1","0","1","0","1","0","1","0","1","1"},
		{"1","1","1","0","1","0","1","0","1","0"},
		{"1","0","1","0","1","0","1","1","1","1"},
		{"1","1","1","1","1","0","1","1","0","1"},
		{"0","1","1","1","0","1","1","0","0","1"},
		{"0","0","0","0","1","0","1","1","1","0"},
		{"1","1","0","1","1","1","0","1","0","1"},
		{"0","1","1","1","0","1","0","1","1","1"},
		{"1","1","1","F","0","1","1","1","0","1"},
	};


        for (int i = 0; i < height; i++) {

            // run the first time to create numbers
            if(i == 0){
                myfile << "   ";
                for (int j = 0; j < width ; j++) {
                    myfile << " " << j << " ";
                }
                myfile << endl;
                myfile << "   ";
                for (int j = 0; j < width ; j++) {
                    myfile << "_" << "_" << "_";
                }
                myfile << endl;
            }

            // run 3 times to create 3x3 block
            for (int h = 0; h < 3; h ++) {

                if(h == 1 && i < 10){
                    myfile << i << " |";
                }
                else if (h == 1 && i >= 10){
                    myfile << i << "|";
                }
                else {
                    myfile << "  |";
                }

                for (int j = 0; j < width; j++) {
					for (int k = 0; k < 3; k++) {
						if (k != 1) {
							if (blockArray[i][j] == start) {
								myfile << "1";
							} else if (blockArray[i][j] == free) {
								myfile << "1";
							} else if (blockArray[i][j] == wall) {
								myfile << "0";
							} else if (blockArray[i][j] == open) {
								myfile << "1";
							}
						} else {
							if (blockArray[i][j] == start) {
								if (h == 1){
									myfile << "S";
								} else{
									myfile << "1";
								}
							} else if (blockArray[i][j] == free) {
								if (h == 1){
									myfile << "F";
								} else{
									myfile << "1";
								}
							} else if (blockArray[i][j] == wall) {
								myfile << "0";
							} else if (blockArray[i][j] == open) {
								myfile << "1";
							}
						}
					}

				}
                myfile << endl;
            }

        }
    // write maze to file
    myfile.close();

    //dijkstra(graph, 0);

    return 0;

}
