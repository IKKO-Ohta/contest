#include <iostream>
using  namespace std;

const int MAX = 100000;
const int NIL = -1;

struct Node{
    int parent;
    int left;
    int right;
};

Node T[MAX];
int n,D[MAX],H[MAX],Deg[MAX]; //depth,height,degree


int getSibling(int u){
    if(T[u].parent == NIL ) return NIL;
    if(T[T[u].parent].left != u and T[T[u].parent].left != NIL) return T[T[u].parent].left;
    if(T[T[u].parent].right != u and T[T[u].parent].right != NIL) return T[T[u].parent].right;
    return NIL;
}

int getDegree(int u){
    int deg = 0;
    if(T[u].left != NIL) deg ++;
    if(T[u].right != NIL) deg ++;
    return deg;
}

int getDepth(int u){
    int d = 0;
    while(T[u].parent != NIL){
        u =T[u].parent;
        d++;
    }
    return d;
}

int setHeight(int u){
    int h1 = 0 , h2 = 0;
    if (T[u].left != NIL) h1 = setHeight(T[u].left) + 1;
    if (T[u].right != NIL) h2 = setHeight(T[u].right) + 1;
    return H[u] = max(h1,h2);
}

void print(int u){
    cout << "node " << u << ": ";
    cout << "parent = " << T[u].parent << ", ";
    cout << "sibling = " << getSibling(u) << ", ";
    //getSibling
    cout << "degree = " << Deg[u] << ", ";
    //getDegree
    cout << "depth = " << D[u] << ", ";
    //getDepth
    cout << "height = " << H[u] << ", ";
    //getHeight
    if(T[u].parent == NIL) cout << "root";
    else if (T[u].left == NIL && T[u].right == NIL) cout << "leaf";
    else cout << "internal node";
    cout << endl;
}


int main(){
    int n,num,left,right;
    cin >> n;
    for (int i = 0; i < n ; ++i) {
        T[i].parent = T[i].left = T[i].right = NIL;
    }
    for (int i = 0; i < n; ++i) {
        cin >> num >> left >> right;
        T[num].left = left;
        T[num].right = right;
        if (left != NIL) T[left].parent = num;
        if (right != NIL) T[right].parent =num;
    }

    for (int i = 0; i < n ; ++i) {
        D[i] = getDepth(i);
        H[i] = setHeight(i);
        Deg[i] = getDegree(i);
    }

    for (int i = 0; i < n ; ++i) {
        print(i);
    }
    return 0;
}