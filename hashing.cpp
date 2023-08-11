#include <iostream>
#include <vector>
#include <list>

class HashTable {
private:
    int size; 
    std::vector<std::list<std::pair<int, int>>> table; 

    
    int hash(int key) {
        return key % size;
    }

public:
    HashTable(int s) : size(s), table(s) {}

    void insert(int key, int value) {
        int index = hash(key);
        table[index].emplace_back(key, value);
    }

    int get(int key) {
        int index = hash(key);

        for (const auto& entry : table[index]) {
            if (entry.first == key) {
                return entry.second;
            }
        }

        return -1; 
    }

    void remove(int key) {
        int index = hash(key);

        auto& entries = table[index];
        for (auto it = entries.begin(); it != entries.end(); ++it) {
            if (it->first == key) {
                entries.erase(it);
                break;
            }
        }
    }
};

int main() {
    HashTable hashTable(10);

    hashTable.insert(3, 42);
    hashTable.insert(15, 101);
    hashTable.insert(23, 7);

    std::cout << "Value for key 15: " << hashTable.get(15) << std::endl;

    hashTable.remove(15);

    std::cout << "Value for key 15 after removal: " << hashTable.get(15) << std::endl;

    return 0;
}
