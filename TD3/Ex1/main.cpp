#include <iostream>
#include <vector>
#include <map>

using namespace std;

void countFrequencyBruteForce(const vector<int>& numbers) {
    for(int i = 0; i < numbers.size(); i++)
    {
        int compteur = 0;
        
        for(int j = 0; j < numbers.size(); j++)
        {
            if(numbers[i] == numbers[j])
            compteur++;
        }

        cout << numbers[i] << " : " << compteur << " fois" << endl;
    }
}

map<int, int> countFrequencyOptimal(const vector<int>& numbers) {
    map<int, int> frequences;

    for(int i=0; i < numbers.size(); i++)
    {
        frequences[numbers[i]]++;
    }
    return frequences;
}

int main() {
    vector<int> numbers = {1, 2, 3, 2, 4, 1, 5, 5, 6};

    cout << "Frequency(Brute-Force) : " << endl;
    countFrequencyBruteForce(numbers);

    cout << "Frequency(Optimal) : " << endl;
    map<int, int> frequencyMapOptimal = countFrequencyOptimal(numbers);
    for(const  auto& entry : frequencyMapOptimal)
    {
        cout << entry.first << " : " << entry.second << " fois" << endl;
    }

    return 0;
}