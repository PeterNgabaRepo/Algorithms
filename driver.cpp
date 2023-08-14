
#include "graph.h"
#include "minHeap.h"
#include <fstream>
using namespace std;

const int EXITFAILURE = -1;
const int EXITSUCCESS = 0;

vector<int> MST_Prim(graph G, int r){
	//intializes solution vector that will be returned
	//with index of vertices in the Hamiltonian cycle order
        vector<int> sol;

	//sets root to the vertex chosen by user
	vertex* root = G.getVertices()[r];
	root->setKey(0);

	//initializes minHeap using list of vertex in Graph
	minHeap Q(G.getVertices());

	//runs until heap is empty
	while(Q.heapSize() > 0){
		//extracts vertex with smallest key and adds it index
		//to  solution vector
		vertex* u = Q.extractVertex();

		int j = G.getIndex(u);
		sol.push_back(j);

		//initalizes adjList with G's adjList
		vector<vector<edge*>> adjList = G.getAdjList();

		vertex* v = new vertex();

		int n = adjList[j].size();

		//iterates through adjList[j] which contains edjes
		//corresponding to G.m_vertex[j]
		for(int i = 0; i < n; i++){
			//intializes edge as the current edge
		        edge* edge1 = adjList[j][i];

			//if the vertex is G.m_vertex[j] then
			//the one we are looking for is the other vertex in the pair
		        if(edge1->getVert(1) == u){
			  v = edge1->getVert(2);
			}
			else{
			  v = edge1->getVert(1);
			}

			//if the vertex v that connects to u is still in the heap
			// and the cost of the edge is less then the key then it updates
			// the key and parent
			if(Q.isInHeap(v) == true and edge1->getCost() < v->getKey()){
			        v->setParent(j);
				Q.decreaseKey(v, edge1->getCost());
				int x = 5;
			}
		}
	}
	return sol;
}

void preOrderWalk(graph G, int index, vector<int>& sol){
  int j = index;
  vector<vertex*> vertices = G.getVertices();
  int n = vertices.size();
  
  sol.push_back(j);

  for(int i = 0; i < n; i++){
    if(vertices[i]->getParent() == j){
      preOrderWalk(G, G.getIndex(vertices[i]), sol);
    }
  }
}

int main(){
	string filename;
	vector<vertex*> vertices;
	vector<edge*> edges;
	vertices.reserve(100);
	edges.reserve(100);
	int rootIndex;

	cout << "Enter the file you wish to approximate" << endl;
        cin >> filename;

	//Read in File
	fstream myFile;

        myFile.open(filename);

        if(!myFile.is_open()){
                cerr << "Could not open the file - '" << filename << "'" << endl;
                return EXITFAILURE;
        }

	//read in fileContents
	string fileContent;
	myFile >> fileContent;

	int i = 0;
	int x;
	int y;

	vertex* vert = new vertex();

	//if the fileContent is not at the divider then we are reading in
	//vertices
        while(fileContent != "---"){
		if(i % 2 == 0){
			x = stoi(fileContent);
		}
		else{
			y = stoi(fileContent);
			vert = new vertex(x, y);
			vertices.push_back(vert);
		}

		myFile >> fileContent;
		i++;
        }

	i = 0;

	vertex* vert1 = new vertex();
	vertex* vert2 = new vertex();
	edge* newEdge = new edge();

	//after the divider we are reading in edges until there is nothing to read
	while(myFile >> fileContent){
		if(i % 2 == 0){
                        int vertIndex = stoi(fileContent);
			vert1 = vertices[vertIndex];
                }
                else{
                        int vertIndex2 = stoi(fileContent);
                        vert2 = vertices[vertIndex2];

			newEdge = new edge(vert1, vert2);

			edges.push_back(newEdge);
                }

                i++;
	}

	myFile.close();

	//make graph using list of vertex and list of edges

	graph G(vertices, edges);

	cout << "Choose the root vertex by selecting its corresponding index" << endl;

	cin >> rootIndex;

	//sets H as the indices of the Hamiltonian Cycle
	vector<int> H = MST_Prim(G, rootIndex);

	vector<int> P;

	preOrderWalk(G, rootIndex, P);

	

	

	cout << "Display Indices of the Hamiltonian Cycle" << endl;

	double total = 0;

	int n = P.size();

	//traverses vector and outputs indices and calculates total
	for(int i = 0; i < n; i++){
		cout << P[i] << " ";
		total += G.getVertices()[P[i]]->getKey();
	}

	cout << endl;
	cout << "The total cost of this approximation is: " << total << endl;

	return EXITSUCCESS;
}

