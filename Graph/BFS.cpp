#include<iostream>
#include<vector>
#include <queue>

using namespace std;


vector <int> G[100];
queue <int> Q;
int level[100];
bool visited[100];

/*
7 8
1 2
1 5
5 3
2 4
5 2
3 4
3 6
4 7

*/
void bfs(int n);

int main()
{
    int node, edge, i, j, x, y, root;

    cin >> node >> edge;
    for(i=0; i<edge; i++){
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }

    cout << endl;
    for(i=1; i<=node; i++){
        for(j=0; j<G[i].size(); j++)
        cout << G[i][j] << "  ";
        cout << endl;
    }
    cout << endl;

    cout << "Enter Root Node : ";
    cin >> root;
    bfs(root);

    cout << endl << endl;
    for(i=1; i<=node; i++)
        cout << "Level :  " << level[i] << " --> " << i << endl;


    return 0;
}


void bfs(int n)
{
    int i, m;
    level[n] = 0;
    visited[n] = true;
    Q.push(n);

    while(!Q.empty()){
        n = Q.front();
        for(i=0; i<G[n].size(); i++){
            m = G[n][i];

            if(visited[m] == false){
                visited[m] = true;
                level[m] = level[n] + 1;
                Q.push(m);
            }
        }
        cout << Q.front() << "  ";
        Q.pop();
    }
}
