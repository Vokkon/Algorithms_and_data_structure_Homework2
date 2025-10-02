#include <iostream>
#include <queue>
#include <unordered_map>
#include <memory>

using namespace std;

// Бинарная куча
void binaryHeapDemo() {
    // Минимальная куча
    priority_queue<int, vector<int>, greater<int>> minHeap;
    minHeap.push(10);
    minHeap.push(3);
    minHeap.push(15);
    minHeap.push(1);
    cout << "Минимальный элемент: " << minHeap.top() << endl; // 1
    minHeap.pop();

    // Максимальная куча
    priority_queue<int> maxHeap;
    maxHeap.push(30);
    maxHeap.push(12);
    maxHeap.push(45);
    cout << "Максимальный элемент: " << maxHeap.top() << endl; // 45
    maxHeap.pop();
}

// Узел биномиальной кучи
struct BinomialTreeNode {
    int value;
    int order;
    shared_ptr<BinomialTreeNode> parent;
    shared_ptr<BinomialTreeNode> firstChild;
    shared_ptr<BinomialTreeNode> nextTree;

    BinomialTreeNode(int val) : value(val), order(0) {}
};

// Биномиальная куча
class BinomialHeap {
private:
    shared_ptr<BinomialTreeNode> rootNode;

public:
    void addValue(int value) {
        auto newHeap = make_shared<BinomialHeap>();
        newHeap->rootNode = make_shared<BinomialTreeNode>(value);
        rootNode = combineTrees(rootNode, newHeap->rootNode);
    }

private:
    shared_ptr<BinomialTreeNode> combineTrees(shared_ptr<BinomialTreeNode> tree1, 
                                              shared_ptr<BinomialTreeNode> tree2) {
        // Реализация объединения деревьев
        return tree1; // заглушка
    }
};

// Хеш-таблица
void hashTableDemo() {
    unordered_map<string, int> inventory;
    inventory["laptop"] = 5;
    inventory["mouse"] = 12;
    inventory["keyboard"] = 8;

    cout << "Количество ноутбуков: " << inventory["laptop"] << endl; // 5
    cout << "Есть ли мыши в инвентаре? " << (inventory.find("mouse") != inventory.end() ? "true" : "false") << endl;

    inventory.erase("keyboard");
    cout << "Остатки инвентаря: ";
    for (const auto& item : inventory) {
        cout << item.first << ":" << item.second << " ";
    }
    cout << endl;
}

// Узел кучи Фибоначчи
struct FibonacciNode {
    int data;
    int rank;
    bool isMarked;
    shared_ptr<FibonacciNode> parent;
    shared_ptr<FibonacciNode> firstChild;
    shared_ptr<FibonacciNode> prev;
    shared_ptr<FibonacciNode> next;

    FibonacciNode(int val) : data(val), rank(0), isMarked(false) {
        prev = shared_ptr<FibonacciNode>(this);
        next = shared_ptr<FibonacciNode>(this);
    }
};

// Куча Фибоначчи
class FibonacciHeap {
private:
    shared_ptr<FibonacciNode> minNode;
    int totalNodes;

public:
    FibonacciHeap() : minNode(nullptr), totalNodes(0) {}

    shared_ptr<FibonacciNode> addNode(int data) {
        auto newNode = make_shared<FibonacciNode>(data);
        if (!minNode) {
            minNode = newNode;
        } else {
            insertIntoRoot(newNode);
            if (data < minNode->data) {
                minNode = newNode;
            }
        }
        totalNodes++;
        return newNode;
    }

private:
    void insertIntoRoot(shared_ptr<FibonacciNode> node) {
        if (minNode) {
            node->next = minNode->next;
            node->prev = minNode;
            minNode->next->prev = node;
            minNode->next = node;
        }
    }

public:
    int* extractMin() {
        if (!minNode) {
            return nullptr;
        }
        return &minNode->data;
    }
};

int main() {
    cout << "=== Бинарная куча ===" << endl;
    binaryHeapDemo();
    
    cout << "\n=== Хеш-таблица ===" << endl;
    hashTableDemo();
    
    cout << "\n=== Куча Фибоначчи ===" << endl;
    FibonacciHeap fibHeap;
    fibHeap.addNode(25);
    fibHeap.addNode(7);
    fibHeap.addNode(18);
    int* minVal = fibHeap.extractMin();
    if (minVal) {
        cout << "Минимум в Фибоначчиевой куче: " << *minVal << endl; // 7
    }

    return 0;
}
