#include <iostream>
#include <queue>
#include <vector>

int main() {
    // Max-heap (default)
    std::priority_queue<int> max_pq;
    max_pq.push(15);
    max_pq.push(5);
    max_pq.push(30);
    std::cout << "Max top: " << max_pq.top() << "\n"; // 30

    // Min-heap
    std::priority_queue<int, std::vector<int>, std::greater<int>> min_pq;
    min_pq.push(15);
    min_pq.push(5);
    min_pq.push(30);
    std::cout << "Min top: " << min_pq.top() << "\n"; // 5

    return 0;
}
