#include<iostream>
#include<vector>

using namespace std;

#define SIZE 100
bool is_visited[SIZE];
int level[SIZE];
int parent_node[SIZE];

typedef struct
{
    int ara[SIZE];
    int frontt, rear;
}Queue;


void push(Queue &obj, int data);
int pop(Queue &obj);
bool is_Empty(Queue &obj);
bool Breadth_First_Search(vector <int> Graph[], int n, int destination);


int main()
{
    vector <int> Graph[SIZE];
    int *path;
    int i, j, k, node, edge, x, y, root, destination;
    bool check;

    cout << "Enter Total Edge : ";
    cin >> node >> edge;
    cout << "Enter Root Node and Destination Node : ";
    cin >> root >> destination;

    for(i=0; i<edge; i++){
        cin >> x >> y;
        Graph[x].push_back(y);
        Graph[y].push_back(x);
    }
    cout << endl << endl;



    for(i=1; i<=node; i++){
        cout << i << " ==>> ";
        for(j=0;j<Graph[i].size(); j++)
            cout << Graph[i][j] << "  ";
        cout << endl;
    }

    check = Breadth_First_Search(Graph, root, destination); //

    cout << endl << endl << "Shortest Path : " << endl;
    if(check == true){
        path = new int[SIZE];
        path[0] = destination;
        for(i=destination,j=1; i != root; i=parent_node[i],j++)
            path[j] = parent_node[i];
        for(k=0, i=j-1; i >= k; k++,i--){
            x = path[k];
            path[k] = path[i];
            path[i] = x;
        }
        for(i=0; i<j; i++)
            cout << path[i] << "  ";
    }
    else
        cout << "Not Found";
    cout << endl;



    return 0;
}


void push(Queue &obj, int data)
{
    if(obj.rear == SIZE){
        cout << "Queue Is Full" << endl;
        return ;
    }
    obj.ara[obj.rear++] = data;
}

int pop(Queue &obj)
{
   if(is_Empty(obj) != true)
        return obj.ara[obj.frontt++];
   cout << "Queue Is Empty" << endl;
   return -1;
}

bool is_Empty(Queue &obj)
{
    if(obj.rear == obj.frontt)
        return true;
    return false;

}


bool Breadth_First_Search(vector <int> Graph[], int n, int destination)
{
    Queue obj;
    int i;

    obj.frontt = obj.rear = 0;
    level[n] = 0;
    is_visited[n] = true;
    push(obj, n);

    while(is_Empty(obj) != true){
        n = pop(obj);
        for(i=0; i<Graph[n].size(); i++){
            if(is_visited[Graph[n][i]] == false){
                is_visited[Graph[n][i]] = true;
                parent_node[Graph[n][i]] = n;
                level[Graph[n][i]] = level[n] + 1;
                push(obj, Graph[n][i]);
                if(destination == n){
                    return true;
                }
            }
            if(destination == n)
                return true;
        }
    }

    return false;
}


