import java.util.*;

public class HeapStructures {
    
    // Бинарная куча
    public static void binaryHeapDemo() {
        // Минимальная куча
        PriorityQueue<Integer> minHeap = new PriorityQueue<>();
        minHeap.add(10);
        minHeap.add(3);
        minHeap.add(15);
        minHeap.add(1);
        System.out.println("Минимальный элемент: " + minHeap.poll()); // 1

        // Максимальная куча
        PriorityQueue<Integer> maxHeap = new PriorityQueue<>(Collections.reverseOrder());
        maxHeap.add(30);
        maxHeap.add(12);
        maxHeap.add(45);
        System.out.println("Максимальный элемент: " + maxHeap.poll()); // 45
    }

    // Узел биномиальной кучи
    static class BinomialTreeNode {
        int value;
        int order;
        BinomialTreeNode parent;
        BinomialTreeNode firstChild;
        BinomialTreeNode nextTree;

        public BinomialTreeNode(int value) {
            this.value = value;
            this.order = 0;
        }
    }

    // Биномиальная куча
    static class BinomialHeap {
        private BinomialTreeNode rootNode;

        public void addValue(int value) {
            BinomialHeap newHeap = new BinomialHeap();
            newHeap.rootNode = new BinomialTreeNode(value);
            this.rootNode = combineTrees(this.rootNode, newHeap.rootNode);
        }

        private BinomialTreeNode combineTrees(BinomialTreeNode tree1, BinomialTreeNode tree2) {
            // Реализация объединения деревьев
            return tree1; // заглушка
        }
    }

    // Хеш-таблица
    public static void hashTableDemo() {
        HashMap<String, Integer> inventory = new HashMap<>();
        inventory.put("laptop", 5);
        inventory.put("mouse", 12);
        inventory.put("keyboard", 8);

        System.out.println("Количество ноутбуков: " + inventory.get("laptop")); // 5
        System.out.println("Есть ли мыши в инвентаре? " + inventory.containsKey("mouse")); // true

        inventory.remove("keyboard");
        System.out.println("Остатки инвентаря: " + inventory);
    }

    // Узел кучи Фибоначчи
    static class FibonacciNode {
        int data;
        int rank;
        boolean isMarked;
        FibonacciNode parent;
        FibonacciNode firstChild;
        FibonacciNode prev;
        FibonacciNode next;

        public FibonacciNode(int data) {
            this.data = data;
            this.prev = this;
            this.next = this;
        }
    }

    // Куча Фибоначчи
    static class FibonacciHeap {
        private FibonacciNode minNode;
        private int totalNodes;

        public FibonacciHeap() {
            this.minNode = null;
            this.totalNodes = 0;
        }

        public FibonacciNode addNode(int data) {
            FibonacciNode newNode = new FibonacciNode(data);
            if (minNode == null) {
                minNode = newNode;
            } else {
                insertIntoRoot(newNode);
                if (data < minNode.data) {
                    minNode = newNode;
                }
            }
            totalNodes++;
            return newNode;
        }

        private void insertIntoRoot(FibonacciNode node) {
            if (minNode != null) {
                node.next = minNode.next;
                node.prev = minNode;
                minNode.next.prev = node;
                minNode.next = node;
            }
        }

        public Integer extractMin() {
            if (minNode == null) {
                return null;
            }
            return minNode.data;
        }
    }

    public static void main(String[] args) {
        System.out.println("=== Бинарная куча ===");
        binaryHeapDemo();
        
        System.out.println("\n=== Хеш-таблица ===");
        hashTableDemo();
        
        System.out.println("\n=== Куча Фибоначчи ===");
        FibonacciHeap fibHeap = new FibonacciHeap();
        fibHeap.addNode(25);
        fibHeap.addNode(7);
        fibHeap.addNode(18);
        System.out.println("Минимум в Фибоначчиевой куче: " + fibHeap.extractMin()); // 7
    }
}
