#include <iostream>
#include <vector>
#include <string>
#include <thread>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::vector<int> answer;
        map <int, int> aHashMap;        // store (nums[i], i)
        map <int, int>::iterator it;

        int size = nums.size();

        for (int i = 0; i<size; i++)
        {
            it = aHashMap.find(target - nums[i]);
            if (it != aHashMap.end())
            {
                answer.push_back(it->second);
                answer.push_back(i);
                //cout << "Found!!" << endl;
                //cout << "value = " << it->second << ", " << i << endl;
                return answer;
            }
            else
            {
                aHashMap.emplace(nums[i], i);
                //cout << "nums[i], i = " << nums[i] << ", " << i << endl;
            }
        }
        return answer;
    }    
};


int main()
{
    vector<int> numbers {2, 7, 11, 3, -3, 15};
    int target = 12;

    //vector<int> numbers {3, 2, 4};  // need to sort first
    //int target = 6;

    vector<int> aResult;

    Solution aSolution;
    aResult = aSolution.twoSum(numbers, target);

    for (int i = 0; i <aResult.size(); i++)
    {
        cout << endl;
        cout << "Result = " << aResult[i] << endl;
    }

    return 0;
}