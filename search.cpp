#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    // Linear Search
    std::vector<int> unsorted = {10, 20, 30, 40, 50};
    auto it = std::find(unsorted.begin(), unsorted.end(), 30);
    if (it != unsorted.end()) {
        std::cout << "Found 30 at index " << (it - unsorted.begin()) << std::endl;
    }

    // Binary Search (Requires sorted range)
    std::vector<int> sorted = {10, 20, 30, 40, 50};
    if (std::binary_search(sorted.begin(), sorted.end(), 30)) {
        std::cout << "30 exists in sorted vector" << std::endl;
    }
    return 0;
}   
