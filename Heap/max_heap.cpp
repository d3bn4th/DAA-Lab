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
    void deleteRoot() {
        // replace the root node with last node of the heap   
        arr[1] = arr[size];
        // remove the last node
        size--;
        // propogate the newly added root node to its correct pos
        int index = 1; // pointer to the root node
        while(index < size){
            int left = 2 * index;
            int right = 2 * index + 1;
            if(left <= size && arr[left] > arr[index]) {
                // swap
                swap(arr[left], arr[index]);
                index = left;
            }
            else if(right <= size && arr[right] > arr[index]) {
                // swap
                swap(arr[right], arr[index]);
                index = right;
            }
            else {
                break;
            }
        }
    }
    void print() {
        for(int i = 1; i <=size; i++) {
            cout << arr[i] << " ";
        }cout << endl;
    }
};

int main(){
    max_heap h;
    h.insert(54);
    h.insert(53);
    h.insert(52);
    h.insert(51);
    h.insert(50);
    h.print();
    h.deleteRoot();
    h.print();


    return 0;
}