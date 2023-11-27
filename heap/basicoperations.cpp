#include <iostream>
#include <vector>

// Helper functions
int parent(int i) { return (i - 1) / 2; }
int leftChild(int i) { return 2 * i + 1; }
int rightChild(int i) { return 2 * i + 2; }

// Heapify a subtree rooted at index i
void heapify(std::vector<int>& heap, int i) {
    int smallest = i;
    int l = leftChild(i);
    int r = rightChild(i);

    if (l < heap.size() && heap[l] < heap[smallest]) {3
        smallest = l;
    }

    if (r < heap.size() && heap[r] < heap[smallest]) {
        smallest = r;
    }

    if (smallest != i) {
        std::swap(heap[i], heap[smallest]);
        heapify(heap, smallest);
    }
}

// Insert an element into the heap
void insert(std::vector<int>& heap, int value) {
    heap.push_back(value);
    int i = heap.size() - 1;

    while (i > 0 && heap[parent(i)] > heap[i]) {
        std::swap(heap[i], heap[parent(i)]);
        i = parent(i);
    }
}

// Extract the minimum element from the heap
int extractMin(std::vector<int>& heap) {
    if (heap.empty()) {
        std::cerr << "Heap is empty.\n";
        return -1; // Return a special value to indicate an empty heap
    }

    int root = heap[0];
    heap[0] = heap.back();
    heap.pop_back();
    heapify(heap, 0);

    return root;
}

// Print the elements of the heap
void printHeap(const std::vector<int>& heap) {
    for (int i : heap) {
        std::cout << i << " ";
    }
    std::cout << "\n";
}

int main() {
    std::vector<int> minHeap;

    insert(minHeap, 3);
    insert(minHeap, 2);
    insert(minHeap, 1);
    insert(minHeap, 4);
    insert(minHeap, 5);

    std::cout << "Min Heap: ";
    printHeap(minHeap);

    std::cout << "Extracting Min: " << extractMin(minHeap) << "\n";

    std::cout << "Min Heap after extraction: ";
    printHeap(minHeap);

    return 0;
}
