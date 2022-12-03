#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;//Definindo um valor infinito para ser a distância até todos vértices no começo
const int N = 6;//Número de vértices

vector<pair<int,int> > adj[N];//Vetor de vector que para cada vértice vai guardar os seus vizinhos com seu respectivo peso na aresta

vector<int> dist;//Vector que vai guardar a distância de cada vértice até o vértice fonte
vector<bool> visi;//Vector que vai guardar os vértices já visitados
vector<int> path(N);

void dijkstra(int inicio) {//Função Dijkstra que vai encontrar o menor caminho do vértice fonte até todos vértices
	dist.assign(N, INF);//Definindo a distância de todos os vértices como infinito
	visi.assign(N, false);//Definindo todos os vértices como não visitados
	dist[inicio] = 0;//Definindo a distância do vértice fonte até o vértice fonte como 0
	path[inicio] = inicio;//Definindo o pai do vértice fonte como ele mesmo
	priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > pq;//Criando a fila de prioridade para vermos os menores caminhos primeiro
	pq.push({0, inicio});//Colocando o vértice fonte na fila de prioridade
	while(!pq.empty()) {//Esquanto a fila de prioridade não estiver vazia
		int u = pq.top().second;//Atribuindo a u o vértice com menor caminho da fila de prioridade
		pq.pop();//Retirando este elemento da fila de prioridade
		if(visi[u])//Se o vértice já foi visitado, então apenas pule para o próximo vértice
			continue;
		visi[u] = true;//Marca o vértice como visitado
		for(auto e : adj[u]) {//Para cada vizinho do vértice u
			int v = e.first, w = e.second;//Armazeno em v o vértice vizinho e em w o peso da aresta que liga o vértice u ao vértice v
			if(dist[u] + w < dist[v]) {//Se a distância do vértice u ao vértice v for menor que a distância atual do vértice v
				dist[v] = dist[u] + w;//Atualiza a distância do vértice fonte até o vértice v
				path[v] = u;//Atualiza o pai do vértice v
				pq.push({dist[v], v});//Coloca na fila de prioridade o vértice que acabamos de atualizar
			}
		}
	}
}

int main(void) {

	//Contruindo o grafo não direcionado com peso nas arestas
	adj[1].push_back({2,2});//O vértice 1 conecta ao vértice 2 com peso 2
	adj[1].push_back({3,9});//O vértice 1 conecta ao vértice 3 com peso 4
	adj[2].push_back({1,2});//...
	adj[2].push_back({4,5});//...
	adj[3].push_back({1,9});//...
	adj[3].push_back({4,1});//...
	adj[3].push_back({5,5});//...
	adj[4].push_back({2,5});//...
	adj[4].push_back({3,1});//...
	adj[4].push_back({5,2});//...
	adj[5].push_back({3,5});//...
	adj[5].push_back({4,2});//...

	dijkstra(1);//executando o dijkstra a partir do vértice 1

	for(int i = 1; i < N; i++) {
		cout << "Menor distancia ate " << i << " eh " << dist[i] << endl;
	}cout << endl;

	for(int i = 1; i < N; i++) {
		cout << "Caminho indo do " << i << " ate o vertice 1: ";
		cout << i << " ";
		int v = i;
		while(path[v] != v) {
			cout << path[v] << " ";
			v = path[v];
		}cout << endl;
	}

	return 0;
}
