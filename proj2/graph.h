
#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <iostream>
#include <string>
#include <cmath>
#include <cfloat>
using namespace std;

class vertex{
	//private member variable of vertex class
	int m_x;
	int m_y;
	double m_key;
	int m_parent;

	public:
		//getter fxns for mem variables
		int getX(){
			return m_x;
		}

		int getY(){
			return m_y;
		}

		double getKey(){
			return m_key;
		}

		int getParent(){
			return m_parent;
		}

		//setter fxns for mem variables
		void setX(int x){
			m_x = x;
		}

		void setY(int y){
			m_y = y;
		}

               	void setKey(double key){
                        m_key = key;
                }

		void setParent(int parent){
			m_parent = parent;
		}

		//Overload Operators, not relevant since I changed implementation
		//to pass pointers
		bool operator == (vertex const& obj){
			bool result = false;

			if(obj.m_x == m_x and obj.m_y == m_y and obj.m_key == m_key and obj.m_parent == m_parent){
				result = true;
			}
			return result;
		}

		bool operator < (vertex const& obj){
			bool result = false;

			if(m_key < obj.m_key){
				result = true;
			}
			return result;
		}

		//default constructor for vertex class
		vertex(){
			m_x = 0;
			m_y = 0;
			m_parent = -1;
			m_key = DBL_MAX;
		}

		//constructor with relevant x and y coordinates
  		vertex(int x, int y) : m_x(x), m_y(y), m_key(DBL_MAX), m_parent(-1){
		}
};

class edge{
	//member variables for an edge
	vertex* m_vert1;
	vertex* m_vert2;
	double m_cost;

	public:
		//getters fxns for member variables
		vertex* getVert(int choice){
			if(choice == 1){return m_vert1;}
                        else{return m_vert2;}
                }

		double getCost(){
			return m_cost;
		}

		//setter fxns for member variables
		void setVert(int choice, vertex* vert){
			if(choice == 1){m_vert1 = vert;}
			else{m_vert2 = vert;}
		}

		void setCost(double cost){
			m_cost = cost;
		}

		//calculates weight/cost of an edge
		double cost(vertex* vert1, vertex* vert2){
			int y2  = vert2->getY();
			int y1 = vert1->getY();

			int x2 = vert2->getX();
			int x1 = vert1->getX();

			int delta_y = y2 - y1;
			int delta_x = x2 - x1;

			if(delta_y < 0){
				delta_y *= -1;
			}

			if(delta_x < 0){
				delta_x *= -1;
			}

			double cost = sqrt(pow(delta_y, 2) + pow(delta_x, 2));
			return cost;
		}

		//default constructor for an edge
		edge(){
		        vertex* v = new vertex();
		        m_vert1 = v;
			m_vert2 = v;
			m_cost = 0;
		}

		//constructor with given vectors
		edge(vertex* vert1, vertex* vert2){
		  m_vert1 = vert1;
		  m_vert2 = vert2;
		  m_cost = cost(vert1, vert2);

		}
};

class graph {
	//private mem variables of graph cls
	vector<vertex*> m_vertices;
	vector<edge*> m_edges;
	vector<vector<edge*>> m_adjList;

	public:
		//getter fxns for mem variables
		vector<vector<edge*>> getAdjList(){
			return m_adjList;
		}

		vector<vertex*> getVertices(){
			return m_vertices;
		}

                vertex* getVertex(int i){
                        return m_vertices[i];
                }

		//gets index in m_vertices corresponding with given vertex
		int getIndex(vertex* vert1){
			int n = m_vertices.size();

			for(int i = 0; i < n; i++){
				if(m_vertices[i] == vert1){
					return i;
				}
			}
			return -1;
		}

		//setter fxns for mem variables
		void setVert(vector<vertex*> vertices){
			m_vertices = vertices;
		}

		void setEdges(vector<edge*> edges){
			m_edges = edges;
		}

		void setAdjList(vector<vector<edge*>> adjList){
			m_adjList = adjList;
		}

		//constructor with vertices and edges as parameters to create
		//a corresponding adjacency list which contains edges and the edge cost
		graph(vector<vertex*> vertices, vector<edge*> edges) : m_vertices(vertices), m_edges(edges){
			int m = vertices.size();
			int n = edges.size();

			m_adjList.reserve(100);

			for(int i = 0; i < m; i++){
			        vector<edge*> empty;
			        m_adjList.push_back(empty);
				for(int j = 0; j < n; j++){
					if(vertices[i] == edges[j]->getVert(1) || vertices[i] == edges[j]->getVert(2)){
					        edge* v = edges[j]; 
						m_adjList[i].push_back(v);
					}
				}
			}
		}
};
#endif

