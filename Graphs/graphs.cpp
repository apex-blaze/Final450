#include<iostream>
#include<map>
#include<list>
#include<queue>

using namespace std;

class graph{
	// Q.1 Create a graph, print it
	public:
	map <int,list<pair<int,int>>> adjList;

	void addEdge(int u,int v,int dist=1,bool bidirec=1){
		adjList[u].push_back(make_pair(v,dist));
		if(bidirec){
			adjList[v].push_back(make_pair(u,dist));
		}
	}

	void printGraph(){
		for(auto i:adjList){
			cout<<i.first<<" : ";
			for(auto j:i.second){
				cout<<"("<<j.first<<","<<j.second<<") ";
			}
			cout<<endl;
		}
	}
	// Q.2 BFS Algo
	void bfs(int src){
		map<int,bool> visited;
		queue<int> q;
		q.push(src);
		while(!q.empty()){
			int node = q.front();
			q.pop();
			if(!visited[node]){
				cout<<node<<"->";
				visited[node]=true;
			}
			for(auto i: adjList[node]){
				if(!visited[i.first])
					q.push(i.first);
			}
			// push nulls here if u want levels
		}
	}

	// Q.3 DFS Algo
	void dfsHelper(int u,map<int,bool> &visited){
		cout<<u<<"->";
		visited[u] = true;
		for(auto i:adjList[u]){
			if(!visited[i.first])
				dfsHelper(i.first,visited);
		}
	}

	void dfs(int src){
		map<int,bool> visited;
		dfsHelper(src,visited);
	}
	// Q.4 Detect cycle in directed graph
	/****************** Using DFS ********************/
	bool isDirCycleDFS(int src,map<int,bool>&visited,map<int,bool>recStack){
		visited[src] = true;
		recStack[src] = true;
		for(auto i:adjList[src]){
			if(!visited[i.first]){
				return isDirCycleDFS(i.first,visited,recStack);
			}else if(recStack[i.first]){
				return true;
			}
		}
		recStack[src] = false;
		return false;
	}

	bool directedCycleDFS(){
		map<int,bool> visited;
		map<int,bool> recStack;
		for(auto i:adjList){
			if(!visited[i.first] && isDirCycleDFS(i.first,visited,recStack)){
				return true;
			}
		}
		return false;
	}

	/***************** Using BFS ********************/
	bool directedCycleBFS(){
		map<int,int> indeg;
		queue<int>q;
		for(auto i:adjList){
			for(auto j:i.second){
				indeg[j.first]++;
			}
		}
		for(auto x:indeg){
			if(x.second==0){
				q.push(x.first);
			}
		}
		vector<int> topologicalOrder;
		int cnt=0;
		while(!q.empty()){
			int node = q.front();
			q.pop();
			topologicalOrder.push_back(node);
			for(auto i:adjList[node]){
				if(--indeg[i.first]==0){
					q.push(i.first);
				}
			}
			cnt++;
		}
		if(cnt!=adjList.size()) return true;
		else return false;
	}
	

	// Q.5 Detect Cycle in Undirected Graph
	/****************** Using DFS*********************/
	//Helper Function
	bool isUnCycleDFS(int node,map<int,bool> &visited,int parent){
		visited[node] = true;
		for(auto i:adjList[node]){
			if(i.first != parent){
				if(!visited[i.first]){
					return isUnCycleDFS(i.first,visited,node);
				}
				return true;
			}
		}
		return false;
	}
	// Driver Function
	bool undirectedCycleDFS(){
		map<int,bool> visited; 
		int parent=int(-1);
		// cout<<parent<<endl;
		for(auto i:adjList){
			if(!visited[i.first] && isUnCycleDFS(i.first,visited,parent))
				return true;
		}
		return false;
	}

		/****************** Using BFS*********************/
	bool isUnCycleBFS(int src,map<int,bool>&visited){
		map<int,int> parent;
		parent[src] = -1;
		queue<int> q;
		visited[src] = true;
		q.push(src);

		while(!q.empty()){
			int node = q.front();
			q.pop();
			for(auto i :adjList[node]){
				if(!visited[i.first]){
					visited[i.first] = true;
					q.push(i.first);
					parent[i.first] = node;
				}else if(parent[node] != i.first){
					return true;
				}
			}
		}
		return false;
	}

	// Driver Function
	bool undirectedCycleBFS(){
		map<int,bool> visited;
		for(auto i:adjList){
			if(!visited[i.first] && isUnCycleBFS(i.first,visited))
				return true;
		}
		return false;
	}
	// Q.13 Topological Sort
	vector<int> topologicalSort(){
		map<int,int> indeg;
		queue<int>q;
		vector<int> topologicalOrder;
		for(auto i:adjList){
			for(auto j:i.second){
				indeg[j.first]++;
			}
		}
		for(auto x:indeg){
			if(x.second==0){
				q.push(x.first);
			}
		}
		int cnt=0;
		while(!q.empty()){
			int node = q.front();
			q.pop();
			topologicalOrder.push_back(node);
			for(auto i:adjList[node]){
				if(--indeg[i.first]==0){
					q.push(i.first);
				}
			}
			cnt++;
		}
		return topologicalOrder;
	}

};


int main(){
	// graph<char> g;
	// g.addEdge('0', '1',4, 0);
	// g.addEdge('0', '7',8, 0);
	// g.addEdge('1', '7',11, 0);
	// g.addEdge('1', '2',8, 0);
	// g.addEdge('7', '8',7, 0);
	// g.addEdge('2', '8',2, 0);
	// g.addEdge('8', '6',6, 0);
	// g.addEdge('2', '5',4, 0);
	// g.addEdge('6', '5',2, 0);
	// g.addEdge('2', '3',7, 0);
	// g.addEdge('3', '3',14, 0);
	// g.addEdge('3', '4',9, 0);
	// g.addEdge('5', '4',10, 0);
	// g.addEdge('7', '6',1, 0);
	// g.printGraph();

	// auto i = g.adjList.begin()->first;
	// g.bfs(i);

	// auto x = g.adjList.begin()->first;
	// g.dfs(x);
	// graph g1;
	// g1.addEdge(1, 0);
    // g1.addEdge(0, 2);
    // g1.addEdge(2, 1);
    // g1.addEdge(0, 3);
    // g1.addEdge(3, 4);
	// cout<<g1.undirectedCycleBFS()<<endl; // 1

	// graph g2;
    // g2.addEdge(0, 1);
    // g2.addEdge(1, 2);
	// cout<<g2.undirectedCycleBFS()<<endl; // 0

	// graph g1;
	// g1.addEdge(1, 0);
	// g1.addEdge(4, 1);
	// g1.addEdge(2, 0);
	// g1.addEdge(4, 2);
	// cout<<g1.undirectedCycleBFS()<<endl; // 1

	// graph g;
    // g.addEdge(0, 1,0,0);
    // g.addEdge(0, 2,0,0);
    // g.addEdge(1, 2,0,0);
    // g.addEdge(2, 0,0,0);
    // g.addEdge(2, 3,0,0);
    // g.addEdge(3, 3,0,0);
	// cout<<g.directedCycleDFS()<<endl; // 1

	// graph g;
    // g.addEdge(0, 1,0,0);
    // g.addEdge(0, 2,0,0);
    // g.addEdge(1, 2,0,0);
	// cout<<g.directedCycleDFS()<<endl; // 0
	// graph g;
    // g.addEdge(0, 1,1,0);
    // g.addEdge(1, 2,1,0);
    // g.addEdge(2, 0,1,0);
    // g.addEdge(3, 4,1,0);
    // g.addEdge(4, 5,1,0);
	// cout<<g.directedCycleBFS()<<endl; // 1

    return 0;
}