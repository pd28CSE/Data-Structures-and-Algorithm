#include<iostream>
#include<vector>
#include<stack>

using namespace std;

#define SIZE 10
bool Is_visited[SIZE];          ///     ekti node theke kon kon node gulate jawa jay tar program

//
//typedef struct
//{
//    int top;
//    int str[SIZE];
//}Stack;
//


//void push(Stack &obj, int data);
//int pop(Stack &obj);
//bool Is_empty(Stack &obj);
void D_F_S(vector <int> Graph[], int root);




int main()
{
    vector <int> Graph[SIZE];
    int x, y;
    int node, edge, i, j, root;


    cout << "Enter Total Node & Edge : ";
    cin >> node >> edge;

    cout << "Enter Node To Node Connection : " << endl;
    for(i=0; i<edge; i++){
        cin >> x >> y;
        Graph[x].push_back(y);
    }
    cout << endl << endl;


    for(i=1; i<node; i++){
        cout << i << endl;
        for(j=0; j<Graph[i].size(); j++){
            cout << Graph[i][j] << "  ";
        }
        if(j>0)
            cout << endl << endl;
    }
    cout << endl << endl;


    cout << "Enter Root : ";
    cin >> root;
    D_F_S(Graph, root);

//
//9 17
//
//1 2
//1 3
//1 6
//2 3
//2 7
//3 6
//6 4
//7 3
//7 5
//5 3
//5 4
//5 8
//4 3
//9 7
//9 5
//8 4
//8 9
// enter root node


    return 0;
}


void D_F_S(vector <int> Graph[], int root)
{
    int child_node, root_node, i;
  //  Stack obj;

    stack <int> q;
    q.push(root);

   // obj.top = 0;
  //  push(obj, root);
    Is_visited[root] = true;

    while(q.empty() != true){
        root_node = q.top();
        q.pop();
        cout << root_node << " ";
        for(i=0; i < Graph[root_node].size(); i++){
            child_node = Graph[root_node][i];
            if(Is_visited[child_node] == false){
                Is_visited[child_node] = true;
               // push(obj, child_node);
                q.push(child_node);
            }
        }
    }

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

*/


//
//void push(Stack &obj, int data)
//{
//    if(obj.top < SIZE)
//        obj.str[obj.top++] = data;
//
//    return ;
//}
//
//
//int pop(Stack &obj)
//{
//    if(Is_empty(obj) == false)
//        return obj.str[--obj.top];
//
//   return -1;
//}
//
//
//bool Is_empty(Stack &obj)
//{
//    if(obj.top == 0)
//        return true;
//
//    return false;
//}
