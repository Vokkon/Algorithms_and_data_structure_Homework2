# Бинарная куча
import heapq

# Минимальная куча
min_heap_list = []
heapq.heappush(min_heap_list, 10)
heapq.heappush(min_heap_list, 3)
heapq.heappush(min_heap_list, 15)
heapq.heappush(min_heap_list, 1)
print("Минимальный элемент:", heapq.heappop(min_heap_list))  # 1

# Максимальная куча (отрицательные числа)
max_heap_list = []
heapq.heappush(max_heap_list, -30)
heapq.heappush(max_heap_list, -12)
heapq.heappush(max_heap_list, -45)
largest = -heapq.heappop(max_heap_list)
print("Максимальный элемент:", largest)  # 45


# Биномиальная куча
class BinomialTree:
    class TreeNode:
        def __init__(self, value):
            self.value = value
            self.order = 0
            self.parent_ref = None
            self.first_child = None
            self.next_tree = None
    
    def __init__(self):
        self.root_node = None

    def add_value(self, value):
        new_tree = BinomialTree()
        new_tree.root_node = self.TreeNode(value)
        self.root_node = self.combine_trees(self.root_node, new_tree.root_node)
    


# Словарь
# Используется встроенный словарь Python
inventory_dict = {}
inventory_dict["laptop"] = 5
inventory_dict["mouse"] = 12
inventory_dict["keyboard"] = 8

print("Количество ноутбуков:", inventory_dict["laptop"])  # 5
print("Есть ли мыши в инвентаре?", "mouse" in inventory_dict)  # True

# Удаление элемента
del inventory_dict["keyboard"]
print("Остатки инвентаря:", inventory_dict)


# Куча Фибоначчи
class FibonacciHeapStructure:
    class FibNode:
        def __init__(self, data):
            self.data = data
            self.rank = 0
            self.is_marked = False
            self.parent_ptr = None
            self.first_child_ptr = None
            self.prev_node = self
            self.next_node = self
    
    def __init__(self):
        self.minimum_ptr = None
        self.total_nodes = 0
    
    def add_node(self, data):
        new_fib_node = self.FibNode(data)
        if self.minimum_ptr is None:
            self.minimum_ptr = new_fib_node
        else:
            self._insert_into_root(new_fib_node)
            if data < self.minimum_ptr.data:
                self.minimum_ptr = new_fib_node
        self.total_nodes += 1
        return new_fib_node
    
    def _insert_into_root(self, fib_node):
        # Добавления узла в корневой список
        if self.minimum_ptr is not None:
            fib_node.next_node = self.minimum_ptr.next_node
            fib_node.prev_node = self.minimum_ptr
            self.minimum_ptr.next_node.prev_node = fib_node
            self.minimum_ptr.next_node = fib_node
    
    def extract_minimum(self):
        # Извлечения минимального элемента
        if self.minimum_ptr is None:
            return None
        
        min_node = self.minimum_ptr
        return min_node.data


# Работа Фибоначчиевой кучи
fib_heap = FibonacciHeapStructure()
fib_heap.add_node(25)
fib_heap.add_node(7)
fib_heap.add_node(18)
print("Минимум в Фибоначчиевой куче:", fib_heap.extract_minimum())  # 7
