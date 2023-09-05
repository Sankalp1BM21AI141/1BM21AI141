#include <iostream>
using namespace std;

const int MAX_ELEMENTS = 100;// Maximum number of elements in the set
class sub{
    public:
    int n;
    int set[MAX_ELEMENTS];
    int targetSum;
    void printSubset(int subset[], int subsetSize);
    void generateSubsets(int set[], int n, int targetSum, int subset[], int subsetSize, int index);
    void findSubsets(int set[], int n, int targetSum);
}sum;
void sub:: printSubset(int subset[], int subsetSize) {
    cout << "Subset: ";
    for (int i = 0; i < subsetSize; ++i) {
        cout << subset[i] << " ";
    }
    cout << endl;
}

void sub:: generateSubsets(int set[], int n, int targetSum, int subset[], int subsetSize, int index) {
    if (targetSum == 0) {
        printSubset(subset, subsetSize);
        return;
    }

    if (index == n || targetSum < 0) {
        return;
    }

    subset[subsetSize] = set[index];

    generateSubsets(set, n, targetSum - set[index], subset, subsetSize + 1, index + 1);
    generateSubsets(set, n, targetSum, subset, subsetSize, index + 1);
}

void sub:: findSubsets(int set[], int n, int targetSum) {
    int subset[MAX_ELEMENTS];
    generateSubsets(set, n, targetSum, subset, 0, 0);
}

int main() {
    
    cout << "Enter the number of elements in the set: ";
    cin >> sum.n;

    
    cout << "Enter the elements: ";
    for (int i = 0; i < sum.n; ++i) {
        cin >> sum.set[i];
    }

    
    cout << "Enter the target sum: ";
    cin >>sum. targetSum;

    sum.findSubsets(sum.set,sum.n, sum.targetSum);

    return 0;
}

