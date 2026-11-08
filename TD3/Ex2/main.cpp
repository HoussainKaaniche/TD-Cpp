#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> twoSumBruteForce(const vector<int>& nums, int target) {
    vector<int> indicesBruteForce;

    for (int i = 0; nums.size(); i++)
    {
        for (int j =  i + 1; nums.size(); j++)
        {
            if (nums[i] + nums[j] == target)
            {
                indicesBruteForce.push_back(i);
                indicesBruteForce.push_back(j);

                return indicesBruteForce;
            }
        }
    }

    return indicesBruteForce;
}

vector<int> twoSumOptimal(const vector<int>& nums, int target){
    unordered_map<int, int> dejaVus;
    vector<int> indicesOptimal;

    for (int i = 0; i < nums.size(); i++){
        int complement = target - nums[i];

        if(dejaVus.find(complement) != dejaVus.end())
        {
            indicesOptimal.push_back(dejaVus[complement]);
            indicesOptimal.push_back(i);

            return indicesOptimal;
        }

        dejaVus[nums[i]] = i;
    }

    return indicesOptimal;

}

int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    vector<int> indicesBruteForce = twoSumBruteForce(nums, target);
    cout << "Brute Force Solution : ["
         << indicesBruteForce[0]
         << ", "
         << indicesBruteForce[1]
         << "]"
         << endl;
    vector<int> indicesOptimal = twoSumOptimal(nums, target);
    cout << "Optimal Solution : ["
         << indicesOptimal[0]
         << ", "
         << indicesOptimal[1]
         << "]"
         << endl;

    return 0;

}