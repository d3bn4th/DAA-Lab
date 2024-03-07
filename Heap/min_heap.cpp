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
    }
    void print() {
        for(int i = 1; i <=size; i++) {
            cout << arr[i] << " ";
        }cout << endl;
    }
};

int main(){
    min_heap h;
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