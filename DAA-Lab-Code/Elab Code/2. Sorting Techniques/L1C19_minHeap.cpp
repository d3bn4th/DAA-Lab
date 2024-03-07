#include <iostream>
using namespace std;
// Min Heap
class min_heap { 
    public:
    int arr[100];
    int size;
    min_heap() {
        arr[0] = -1;
        size = 0;
    }

    // Functions
    //  1. Insert new node
    void insert(int val) {
        // add the new node to the end
        // place the new node in its correct position
        size++;
        int index = size;
        arr[index] = val;
        while(index > 1) {
            // compare with  
            int parent = index/2;
            if(arr[parent] > arr[index]){
                //swap
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else{
                break;
            }
        }
    }

    // 2. Delete new node
    int deleteRoot() {
        int root = arr[1];
        // replace the root node with last node of the heap   
        arr[1] = arr[size];
        // remove the last node
        size--;
        // propogate the newly added root node to its correct pos
        int index = 1; // pointer to the root node
        while(index < size){
            int left = 2 * index;
            int right = 2 * index + 1;
            // if both left and right node exists
            if(left <= size && right <= size) {
                int max = (arr[left] <= arr[right] ? left : right);
                //swap with max
                if(arr[max] < arr[index]) {
                    //swap
                    swap(arr[max], arr[index]);
                    index = max;
                }
                else 
                    break;
            }
            // if left node only exists
            else if(left <= size) {
                if(arr[left] < arr[index]) {
                    // swap
                    swap(arr[left], arr[index]);
                    index = left;
                }
                else 
                    break;
            }
            // if right node only exists
            else if(right <= size){
                if(arr[right] < arr[index]) {
                    // swap
                    swap(arr[right], arr[index]);
                    index = right;
                }
                else
                    break;
            }
            // if both left and right node does not exists 
            else {
                break;
            }
        }
        return root;
    }
    
    // 3. To create a heap from an array
    void makeheap(int x[], int n) {
        for(int i = 0; i < n; i++) {
            this->insert(x[i]);
        }
    }

    void print() {
        cout << "Heap: ";
        for(int i = 1; i <=size; i++) {
            cout << arr[i] << " ";
        }cout << endl;
    }
    
};

void heapsort(int x[], int n) {
    // create a heap - O(nlogn)
    min_heap h;
    h.makeheap(x,n);
    h.print();
    while(h.size > 0) {
        x[h.size-1] = h.deleteRoot();
    } 
}
int main(){
    int T; cin >> T;
    while(T--) {
        int n, budget; cin >> n >> budget;
        int a[n];
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        heapsort(a,n);
        // for(int i = 0; i < n; i++){
        //     cout << a[i] << " ";
        // }
        // cout << endl;
        int i = n-1;
        int cnt = 0;
        while(budget-a[i] >= 0) {
            budget -= a[i];
            i--;
            cnt++;
        }
        cout << cnt << endl;
    }
    return 0;
}