#ifndef SEARCHINGALGORITHM_H
#define SEARCHINGALGORITHM_H

#include <iostream>
#include <vector>

class SearchingAlgorithm {
protected:
    int numberComparisons;

public:
    static int totalComparisons;
    static int totalSearch;
    static double averageComparisons;

    SearchingAlgorithm();
    virtual ~SearchingAlgorithm();

    virtual int search(const std::vector<int>& tableau, int target) = 0;

    void displaySearchResults(
        std::ostream& sortie, int results, int target
    );
};

class LinearSearch : public SearchingAlgorithm {
public:
    int search(const std::vector<int>& tableau, int target) override;
};

class JumpSearch : public SearchingAlgorithm {
public:
    int search(const std::vector<int>& tableau, int target) override;
};

class BinarySearch : public SearchingAlgorithm {
public:
    int search(const std::vector<int>& tableau, int target) override;
};

#endif