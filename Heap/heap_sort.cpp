#include <iostream>
using namespace std;

// Max Heap
class max_heap { 
    public:
    int arr[100];
    int size;
    max_heap() {
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
            if(arr[parent] < arr[index]){
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
                int max = (arr[left] >= arr[right] ? left : right);
                //swap with max
                if(arr[max] > arr[index]) {
                    //swap
                    swap(arr[max], arr[index]);
                    index = max;
                }
                else 
                    break;
            }
            // if left node only exists
            else if(left <= size) {
                if(left <= arr[left] > arr[index]) {
                    // swap
                    swap(arr[left], arr[index]);
                    index = left;
                }
                else 
                    break;
            }
            // if right node only exists
            else if(right <= size){
                if(right <= size && arr[right] > arr[index]) {
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
    void create_heap(int arr[], int n) {
        for(int i = 0; i < n; i++) {
            this->insert(arr[i]);
        }
    }

    void print() {
        cout << "Heap: ";
        for(int i = 1; i <=size; i++) {
            cout << arr[i] << " ";
        }cout << endl;
    }
    
};

void heap_sort(int *arr, int n) {
    // create a heap - O(nlogn)
    max_heap h;
    h.create_heap(arr,n);
    h.print();
    while(h.size > 0) {
        arr[h.size-1] = h.deleteRoot();
        // h.print();
    } 
}
void printArr(int arr[], int n) {
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }cout << endl;
}

int main(){
    int arr[] = {2, 1, 4, 3, 6, 5};   
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Original Array : ";
    printArr(arr,n);
    cout << "\nApplying  heap_sort... " << endl;

    heap_sort(arr,n);
    cout << "\nSorted Array : ";
    printArr(arr,n);
    return 0;
}