#include<iostream>
#include<map>
#include<list>
#include<queue>

using namespace std;

template <typename T=int>
class graph{
	// Q.1 Create a graph, print it
	public:
	map <T,list<pair<T,int>>> adjList;

	void addEdge(T u,T v,int dist=1,bool bidirec=1){
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
	void bfs(T src){
		map<T,bool> visited;
		queue<T> q;
		q.push(src);
		while(!q.empty()){
			T node = q.front();
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
	void dfsHelper(T u,map<T,bool> &visited){
		cout<<u<<"->";
		visited[u] = true;
		for(auto i:adjList[u]){
			if(!visited[i.first])
				dfsHelper(i.first,visited);
		}
	}

	void dfs(T src){
		map<T,bool> visited;
		dfsHelper(src,visited);
	}

	// Q.4 Detect Cycle in Undirected Graph

	//Helper Function
	bool isUnCycleDFS(T node,map<T,bool> &visited,T parent){
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
		map<T,bool> visited; 
		T parent;
		for(auto i:adjList){
			if(!visited[i.first] && isUnCycleDFS(i.first,visited,parent))
				return true;
		}
		return false;
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
	graph<int> g1;
	g1.addEdge(1, 0);
    g1.addEdge(0, 2);
    g1.addEdge(2, 1);
    g1.addEdge(0, 3);
    g1.addEdge(3, 4);
	cout<<g1.undirectedCycleDFS()<<endl;
    return 0;
}