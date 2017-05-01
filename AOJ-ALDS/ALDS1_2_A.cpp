#include <iostream>

using namespace std;

int bubble_sort(int a[],int n){
    int c=0;
    for(int i=0;i<n;i++){
        for(int j=1;j<n-i;j++){
            if(a[j-1]>a[j]){
                c++;
                swap(a[j-1],a[j]);
            }
        }
    }
    return c;
}

int main(){
    int n,a[100];
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    int change = bubble_sort(a,n);
    for(int i=0;i<n-1;i++){
        cout << a[i] << ' ';
    }
    cout << a[n-1] << endl;
    cout << change << endl;
}