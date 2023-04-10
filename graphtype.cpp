#include "graphtype.h"
using namespace std;
const int NULL_EDGE = 0;

template<class VertexType>
GraphType<VertexType>::GraphType(){
numVertices = 0;
maxVertices = 50;
vertices = new VertexType[50];
edges = new int*[50];

for(int i=0;i<50;i++)
edges[i] = new int [50];
marks = new bool[50];
}

template<class VertexType>
GraphType<VertexType>::GraphType(int maxV){
numVertices = 0;
maxVertices = maxV;
vertices = new VertexType[maxV];
edges = new int*[maxV];

for(int i=0;i<maxV;i++)
edges[i] = new int [maxV];
marks = new bool[maxV];
}

template<class VertexType>
GraphType<VertexType>::~GraphType()
{
delete [] vertices;
delete [] marks;
for(int i=0;i<maxVertices;i++)
delete [] edges[i];
delete [] edges;
}

template<class VertexType>
void GraphType<VertexType>::MakeEmpty(){
numVertices = 0;
}

template<class VertexType>
bool GraphType<VertexType>::IsEmpty(){
return (numVertices == 0);
}

template<class VertexType>
bool GraphType<VertexType>::IsFull(){
return (numVertices == maxVertices);
}

template<class VertexType>
void GraphType<VertexType> :: AddVertex(VertexType vertex){
vertices[numVertices] = vertex;

for (int index=0; index<numVertices; index++){
    edges[numVertices][index] = NULL_EDGE;
    edges[index][numVertices] = NULL_EDGE;}
numVertices++;
}

template<class VertexType>
int IndexIs(VertexType* vertices, VertexType vertex){
int index = 0;
while (!(vertex == vertices[index]))
    index++;
return index;}

template<class VertexType>
void GraphType<VertexType>::ClearMarks(){
for(int i=0; i<maxVertices; i++)
marks[i] = false;
}

template<class VertexType>
void GraphType<VertexType>::MarkVertex(VertexType vertex){
int index = IndexIs(vertices, vertex);
marks[index] = true;
}

template<class VertexType>
bool GraphType<VertexType>::IsMarked(VertexType vertex){
int index = IndexIs(vertices, vertex);
return marks[index];
}

template<class VertexType>
void GraphType<VertexType>::AddEdge(VertexType fromVertex, VertexType toVertex, int weight)
{
int row = IndexIs(vertices, fromVertex);
int col= IndexIs(vertices, toVertex);
edges[row][col] = weight;
}

template<class VertexType>
int GraphType<VertexType>::WeightIs(VertexType fromVertex, VertexType toVertex)
{
int row = IndexIs(vertices, fromVertex);
int col= IndexIs(vertices, toVertex);
#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Vertex;

class Edge
{
public:
    Edge(Vertex *org, Vertex *dest, int dist)
    {
        origin = org;
        destination = dest;
        distance = dist;
    }

    Vertex* getOrigin() {return origin;}
    Vertex* getDestination() {return destination;}
    int getDistance() {return distance;}
private:
    Vertex* origin;
    Vertex* destination;
    int distance;
};


class Vertex
{
public:
    Vertex(string id)
    {
        name = id;
    }

    void addEdge(Vertex *v, int dist)
    {
        Edge newEdge(this, v, dist);
        edges.push_back(newEdge);
    }

    void printEdges()
    {
        cout << name << ":" << endl;
        for (int i = 0; i < edges.size(); i++)
        {
        Edge e = edges[i];
        cout << e.getDestination()->getName() <<
            " - " << e.getDistance() << endl;
        }
        cout << endl;
    }

    string getName() {return name;}
    vector<Edge> getEdges() {return edges;}

private:
    string name;
    vector<Edge> edges;
};


class Graph
{
public:
    Graph() {}

    void insert(Vertex *v)
    {
        vertices.push_back(v);
    }

    void printGraph()
    {
        for (int i = 0; i < vertices.size(); i++)
            vertices[i]->printEdges();
    }

private:
    vector<Vertex*> vertices;
};

int main()
{
Graph g;

Vertex v1 = Vertex("Seattle");
Vertex v2 = Vertex("Portland");
Vertex v3 = Vertex("Everett");
Vertex v4 = Vertex("Lynnwood");
Vertex v5 = Vertex("Northgate");
Vertex v6 = Vertex("Bellevue");
Vertex v7 = Vertex("Arlington");
Vertex v8 = Vertex("Bellingham");


Vertex *vp1 = &v1;
Vertex *vp2 = &v2;
Vertex *vp3 = &v3;
Vertex *vp4 = &v4;
Vertex *vp5 = &v5;
Vertex *vp6 = &v6;
Vertex *vp7 = &v7;
Vertex *vp8 = &v8;


v1.addEdge(vp2, 100);
v1.addEdge(vp6, 20);
v2.addEdge(vp1, 100);
v3.addEdge(vp1, 30);
v3.addEdge(vp4, 10);
v3.addEdge(vp7, 20);
v4.addEdge(vp5, 15);
v5.addEdge(vp1, 10);
v6.addEdge(vp1, 20);
v8.addEdge(vp7, 45);#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Vertex;

class Edge
{
public:
    Edge(Vertex *org, Vertex *dest, int dist)
    {
        origin = org;
        destination = dest;
        distance = dist;
    }

    Vertex* getOrigin() {return origin;}
    Vertex* getDestination() {return destination;}
    int getDistance() {return distance;}
private:
    Vertex* origin;
    Vertex* destination;
    int distance;
};


class Vertex
{
public:
    Vertex(string id)
    {
        name = id;
    }

    void addEdge(Vertex *v, int dist)
    {
        Edge newEdge(this, v, dist);
        edges.push_back(newEdge);
    }

    void printEdges()
    {
        cout << name << ":" << endl;
        for (int i = 0; i < edges.size(); i++)
        {
        Edge e = edges[i];
        cout << e.getDestination()->getName() <<
            " - " << e.getDistance() << endl;
        }
        cout << endl;
    }

    string getName() {return name;}
    vector<Edge> getEdges() {return edges;}

private:
    string name;
    vector<Edge> edges;
};


class Graph
{
public:
    Graph() {}

    void insert(Vertex *v)
    {
        vertices.push_back(v);
    }

    void printGraph()
    {
        for (int i = 0; i < vertices.size(); i++)
            vertices[i]->printEdges();
    }

private:
    vector<Vertex*> vertices;
};

int main()
{
Graph g;

Vertex v1 = Vertex("Seattle");
Vertex v2 = Vertex("Portland");
Vertex v3 = Vertex("Everett");
Vertex v4 = Vertex("Lynnwood");
Vertex v5 = Vertex("Northgate");
Vertex v6 = Vertex("Bellevue");
Vertex v7 = Vertex("Arlington");
Vertex v8 = Vertex("Bellingham");


Vertex *vp1 = &v1;
Vertex *vp2 = &v2;
Vertex *vp3 = &v3;
Vertex *vp4 = &v4;
Vertex *vp5 = &v5;
Vertex *vp6 = &v6;
Vertex *vp7 = &v7;
Vertex *vp8 = &v8;


v1.addEdge(vp2, 100);
v1.addEdge(vp6, 20);
v2.addEdge(vp1, 100);
v3.addEdge(vp1, 30);
v3.addEdge(vp4, 10);
v3.addEdge(vp7, 20);
v4.addEdge(vp5, 15);
v5.addEdge(vp1, 10);
v6.addEdge(vp1, 20);
v8.addEdge(vp7, 45);


g.insert(vp1);
g.insert(vp2);
g.insert(vp3);
g.insert(vp4);
g.insert(vp5);
g.insert(vp6);
g.insert(vp7);
g.insert(vp8);


g.printGraph();

system("PAUSE");

return 1;
}


g.insert(vp1);
g.insert(vp2);
g.insert(vp3);
g.insert(vp4);
g.insert(vp5);
g.insert(vp6);
g.insert(vp7);
g.insert(vp8);


g.printGraph();

system("PAUSE");

return 1;
}
return edges[row][col];
}

template<class VertexType>
void GraphType<VertexType>::GetToVertices(VertexType vertex, QueType<VertexType>& adjVertices)
{
int fromIndex, toIndex;
fromIndex = IndexIs(vertices, vertex);
for (toIndex = 0; toIndex < numVertices; toIndex++)
if (edges[fromIndex][toIndex] != NULL_EDGE)
adjVertices.Enqueue(vertices[toIndex]);
}

template<class VertexType>
void GraphType<VertexType>::DepthFirstSearch(VertexType startVertex, VertexType endVertex)
{
StackType<VertexType> stack;
QueType<VertexType> vertexQ;
bool found = false;
VertexType vertex, item;
ClearMarks();
stack.Push(startVertex);
do
{
vertex = stack.Top();
stack.Pop();
if (vertex == endVertex)
{
cout << vertex << " ";
found = true;
}
else
{
if (!IsMarked(vertex)){
MarkVertex(vertex);
cout << vertex << " ";
GetToVertices(vertex,vertexQ);
while (!vertexQ.IsEmpty())
{
vertexQ.Dequeue(item);
if (!IsMarked(item))
stack.Push(item);
}
}
}
} while (!stack.IsEmpty() && !found);
cout << endl;
if (!found)
cout << "Path not found." << endl;
}

template<class VertexType>
void GraphType<VertexType>::BreadthFirstSearch(VertexType startVertex, VertexType endVertex)
{
QueType<VertexType> queue;
QueType<VertexType> vertexQ;
bool found = false;
VertexType vertex, item;
ClearMarks();
queue.Enqueue(startVertex);
do
{
queue.Dequeue(vertex);
if (vertex == endVertex)
{
cout << vertex << " ";
found = true;
}
else
{
if (!IsMarked(vertex))
{
MarkVertex(vertex);
cout << vertex << " ";
GetToVertices(vertex, vertexQ);
while (!vertexQ.IsEmpty())
{
vertexQ.Dequeue(item);
if (!IsMarked(item))
queue.Enqueue(item);
}
}
}
} while (!queue.IsEmpty() && !found);
cout << endl;
if (!found)
cout << "Path not found." << endl;
}
