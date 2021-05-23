#include<iostream>
#include<vector>
#include<stack>

using namespace std;

#define SIZE 100
bool is_visited[100];
int level[100];
int path[100];

bool D_F_S(vector <int> Graph[], int root, int destination);

int main()
{
    int node, edge, i, j, x, y, root, destination;
    vector <int> Graph[SIZE];
    int ara[SIZE];

    cout << "Enter Node & Edge : ";
    cin >> node >> edge;

    for(i=0; i<edge; i++){
        cin >> x >> y;
        Graph[x].push_back(y);
       // Graph[y].push_back(x);
    }

    for(i=1; i<=node; i++){
        cout << "Node : " << i << "   ";
        for(j=0; j<Graph[i].size(); j++)
            cout << Graph[i][j] << "   ";
        cout << endl;
    }

    cout << endl << "Enter Root Node & Destination : ";
    cin >> root >> destination;
    cout << endl << endl;



    cout << "All nodes connected to : " << root << endl << endl;
    if(D_F_S(Graph, root, destination) == true){
        for(i=destination, j=0; i != root; i=path[i], j++)
            ara[j] = i;
        ara[j] = i;
        y = j;
        for(i=0,j; i<j; i++, j--){
            x = ara[i];
            ara[i] = ara[j];
            ara[j] = x;
        }
        cout << endl << endl << "Shortest Path is : ";
        for(i=0; i<=y; i++)
            cout << ara[i] << "  ";

    }

    cout << endl << endl;

    for(i=1; i<=node; i++)
        cout << "Node : " << i << "   Level : " << level[i] << endl;



    return 0;
}

bool D_F_S(vector <int> Graph[], int root, int destionation)
{
    stack <int> q;
    int i, n, m;


    q.push(root);
    is_visited[root] = true;
    level[root] = 0;

    while(q.empty() != true){
        n = q.top();
        q.pop();
       // cout << n << "  ";                 //  <<=== ekta node er satge kon kon node connected
        for(i=0; i<Graph[n].size(); i++){
            m = Graph[n][i];
            if(is_visited[m] == false){
                is_visited[m] = true;
                q.push(m);
                level[m] = level[n] + 1;
                path[m] = n;
            }
//            if(m == destionation){  //  <<===     if shortest path check , before uncomment,
//                return true;
//            }
        }
        cout << n << "   ";
    }

    return false;
}


/*
8 11
1 2
1 3
1 4
2 3
2 5
3 6
4 7
7 3
7 8
5 8
6 8



8 12
1 2
1 3
1 4
2 3
2 5
3 6
4 7
7 3
7 8
5 8
6 8
8 1

*/

