#include <iostream>
#include <algorithm> // Add the missing header
using namespace std;

class heap {
    public:
    int arr[100];
    int size;
    heap() {
        arr[0] = -1;
        size = 0;
    }

    void insert(int x){
        // inserting at the end
        size = size + 1;
        int index = size;
        arr[index] = x;
    
        //comparisions
        while(index > 1) {
            int parent = index/2;
            // max heap condition
            if(arr[parent] < arr[index]) {
                // swapping
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else {
                break;
            }
        }
    }
    // delete the root node
    void deleteNode() {
        if(size == 0) {
            cout << "heap is empty" << endl;
            return;
        }
        // step 1 : put the last node at root
        arr[1] = arr[size]; 
        // step 2 : delete the last node
        size = size - 1; 

        // step 3 :  propogate the root node to its correct position
        int index = 1;
        while(index < size) {
            int left_child = 2*index;
            int right_child = 2*index + 1;
            if(left_child < size && arr[index] < arr[left_child]) {
                swap(arr[index], arr[left_child]);
                index = left_child;
            }
            else if(right_child < size && arr[index] < arr[right_child]) {
                swap(arr[index], arr[right_child]);
                index = right_child;
            }
            else {
                return;
            }
        }
    }
    void print() {
        for(int i = 0; i <= size; i++) {
            cout << arr[i] << " "; 
        }cout << endl;
    }
};

int main(){
    heap h;
    h.insert(60);
    h.insert(50);
    h.insert(40);
    h.insert(30);
    h.insert(20);
    h.insert(55);
    h.print();
 
    h.deleteNode();
    h.print();
    return 0;
}