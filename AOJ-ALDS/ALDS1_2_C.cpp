#include <iostream>
#include <string>
using namespace std;

struct Trump{
    string suit;
    string num;
};


void BubbleSort(Trump trump[], int n){
    for (int i = 0; i < n-1 ; i++){
        for (int j = n - 1; j >= i ; j--){
            if (trump[j].num < trump[j - 1].num){
                swap(trump[j], trump[j - 1]);
            }
        }
    }
}

void SelectionSort(Trump trump[], int n) {
    for (int i = 0; i < n; i++) {
        int minj;
        minj = i;
        for (int j = i; j < n  ; j++) {
            if (trump[j].num < trump[minj].num) {
                minj = j;
            }
        }
        swap(trump[i], trump[minj]);
    }
}


int main (){
    int n;
    Trump a[36],b[36];
    string c;
    cin >> n;

    //cin
    for (int i = 0; i < n ; ++i) {
        cin >> c;
        a[i].suit = c[0];
        a[i].num  = c[1];
    }
    for (int j = 0; j < n ; ++j) {
        b[j] = a[j];
    }

    //sort
    BubbleSort(a,n);
    SelectionSort(b,n);

    //cout
    for (int i = 0; i < n-1 ; ++i) {
        cout << a[i].suit << a[i].num << " ";
    }
    cout << a[n].suit << a[n].num << endl;
    cout << "Stable" << endl;

    for (int i = 0; i < n ; ++i) {
        cout << b[i].suit << b[i].num << " ";
    }
    cout << b[n].suit << b[n].num << endl;

    //check "is stable"
    int check;
    for (int i = 0; i < n ; ++i) {
        if (a[i].num != b[i].num and a[i].suit != b[i].suit)
            check ++;
    }
    if (check == 0){
        cout << "Stable" << endl;
    }else{
        cout << "Not stable" << endl;
    }

    return 0;
}