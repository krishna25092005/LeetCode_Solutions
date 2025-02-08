class NumberContainers {
    unordered_map<int, int> indexToNumber;
    map<int, set<int>> numberToIndices;

public:
    NumberContainers() {}
    
    void change(int index, int number) {
        if (indexToNumber.count(index)) {
            int oldNumber = indexToNumber[index];
            numberToIndices[oldNumber].erase(index);
            if (numberToIndices[oldNumber].empty()) {
                numberToIndices.erase(oldNumber);
            }
        }
        indexToNumber[index] = number;
        numberToIndices[number].insert(index);
    }
    
    int find(int number) {
        return numberToIndices.count(number) ? *numberToIndices[number].begin() : -1;
    }
};