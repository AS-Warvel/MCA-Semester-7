#pragma once
#include "stack&queses/stack.h"
#include "stack&queses/circularQueue.h"
#include <iostream>
#define MAX 20
using namespace std;

class Graph
{
	char vertices[MAX];
	int no_of_vertices;
	int adjancyMtx[MAX][MAX];

	int getVtxIndex(char v)
	{
		for (int i = 0; i < no_of_vertices; i++)
			if (v == vertices[i])
				return i;
		return -1;
	}
public:
	Graph()
	{
		no_of_vertices = 0;
		for (int i = 0; i < MAX; i++)
			for (int j = 0; j < MAX; j++)
				adjancyMtx[i][j] = 0;
	}

	void addVertex(char c)
	{
		vertices[no_of_vertices++] = c;
	}

	void addEdge(char v1, char v2, int weight = 1)
	{
		int i1 = getVtxIndex(v1);
		int i2 = getVtxIndex(v2);

		adjancyMtx[i2][i1] = weight;
	}

	void displayAdjMtx()
	{
		cout << '\t';
		for (int i = 0; i < no_of_vertices; i++)
			cout << vertices[i] << '\t';
		cout << endl;

		for (int i = 0; i < no_of_vertices; i++)
		{
			cout << vertices[i] << '\t';
			for (int j = 0; j < no_of_vertices; j++)
			{
				cout << adjancyMtx[i][j] << '\t';
			}
			cout << endl;
		}
	}

	void DFS_trav()
	{
		Stack<int> stk;
		char status[100];
		for (int i = 0; i < no_of_vertices; i++)
			status[i] = 'N';

		status[0] = 'W';
		stk.push(0);
		int index;
		while (!stk.isEmpty())
		{
			index = stk.pop();
			cout << vertices[index] << "\t";
			status[index] = 'V';
			for (int i = no_of_vertices - 1; i >= 0; i--)
			{
				if (adjancyMtx[i][index] != 0 && status[i] == 'N')
				{
					status[i] = 'W';
					stk.push(i);
				}
			}
		}
		cout << endl;
	}

	void BFS_trav()
	{
		CircularQueue<int> q;
		char status[100];
		for (int i = 0; i < no_of_vertices; i++)
			status[i] = 'N';

		status[0] = 'W';
		q.insert(0);
		int index;
		while (!q.isEmpty())
		{
			index = q.remove();
			cout << vertices[index] << "\t";
			status[index] = 'V';
			for (int i = 0; i < no_of_vertices; i++)
			{
				if (adjancyMtx[i][index] != 0 && status[i] == 'N')
				{
					status[i] = 'W';
					q.insert(i);
				}
			}
		}
		cout << endl;
	}

	void dijk_alg(char v, char destination)
	{
		int v0 = getVtxIndex(v);
		bool visited[MAX];
		int dis[MAX];
		char parnt[MAX];
		for (int i = 0; i < no_of_vertices; i++)
		{
			visited[i] = false;
			dis[i] = INT32_MAX;
			parnt[i] = 'n';
		}

		int total_visited = 0;

		dis[v0] = 0;
		parnt[v0] = vertices[v0];

		int curr_vertex;
		int distance = 0;
		int count = 0;
		while (total_visited < no_of_vertices)
		{
			int i;
			for (i = 0; i < no_of_vertices; i++)
			{

				if (visited[i] == false)
				{
					curr_vertex = i;
					break;
				}
			}

			for (i; i < no_of_vertices; i++)
				if (dis[i] < dis[curr_vertex] && visited[i] == false)
					curr_vertex = i;

			cout << vertices[curr_vertex] << endl;
			for (int i = 0; i < no_of_vertices; i++)
			{
				if (adjancyMtx[i][curr_vertex] != 0)
				{
					distance = dis[curr_vertex] + adjancyMtx[i][curr_vertex];
					if (distance < dis[i])
					{
						dis[i] = distance;
						parnt[i] = vertices[curr_vertex];
					}
				}
			}
			visited[curr_vertex] = true;
			total_visited++;
		}
		for (int i = 0; i < no_of_vertices; i++)
		{
			cout << parnt[i] << '\t';
		}
		cout << endl;
		for (int i = 0; i < no_of_vertices; i++)
		{
			cout << dis[i] << '\t';
		}
		cout << endl;

		int curr_Vertex_idx = getVtxIndex(destination);
		cout << "Shortest Distance: " << dis[curr_Vertex_idx] << endl;
		while (vertices[curr_Vertex_idx] != v)
		{
			cout << vertices[curr_Vertex_idx] << " <-- ";
			curr_Vertex_idx = getVtxIndex(parnt[curr_Vertex_idx]);
		}
		cout << v << endl;

	}
};