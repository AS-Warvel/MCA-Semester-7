#include "headers/assignImplFxns.h"
#include "headers/graph.h"

void graphImpl()
{
	system("cls");
	Graph g;
	int selection;
	int weight;
	int n;
	char ver;
	char ver2;
	
	while (true)
	{
		system("cls");
		cout << "      ***** Assignment - Graphs *****\n\n";

		cout << "Select an option:-\n";
		cout << "1) Insert a Vertex\n";
		cout << "2) Add an Edge\n";
		cout << "3) Add an Edge with weight\n";
		cout << "4) DFS traversal\n";
		cout << "5) BFS traversal\n";
		cout << "6) Djikstra Algorithm\n";
		cout << "7) End Program\n";

		cout << "Enter: ";
		cin >> selection;

		if (selection == 1)
		{
			cout << "Enter no of Vertices to Add: ";
			cin >> n;
			for (int i = 0; i < n; i++)
			{
				cout << "Enter Vertex: ";
				cin >> ver;
				g.addVertex(ver);
			}
			system("pause");
		}
		if (selection == 2)
		{
			cout << "Enter no. of edges to add: ";
			cin >> n;
			for (int i = 0; i < n; i++)
			{
				cout << "Enter Vertices: ";
				cin >> ver >> ver2;
				g.addEdge(ver, ver2);
			}
			system("pause");
		}
		else if (selection == 3)
		{
			cout << "Enter no. of edges to add: ";
			cin >> n;
			for (int i = 0; i < n; i++)
			{
				cout << "Enter Vertices: ";
				cin >> ver >> ver2;
				cout << "Enter Weight: ";
				cin >> weight;
				g.addEdge(ver, ver2, weight);
			}
			system("pause");
		}
		else if (selection == 4)
		{
			cout << "DFS traversal:- \n";
			g.DFS_trav();
			system("pause");
		}
		else if (selection == 5)
		{
			cout << "BFS traversal:- \n";
			g.BFS_trav();
			system("pause");
		}
		else if (selection == 6)
		{
			cout << "Enter Starting Point and Destination: ";
			cin >> ver >> ver2;
			g.dijk_alg(ver, ver2);
			system("pause");
		}
		else if (selection == 7)
			return;
	}

	system("pause");
}