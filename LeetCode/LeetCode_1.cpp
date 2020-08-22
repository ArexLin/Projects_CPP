#include <iostream>
#include <vector>
#include <string>
#include <thread>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::vector<int> answer;
        int Left = 0, Right = nums.size()-1;
        cout << "Left = " << Left << ", Right = " << Right << endl;

        int sum = 0;

        do
        {
            sum = nums[Left] + nums[Right];
            cout << "Left = " << Left << ", Right = " << Right << endl;
            cout << "value = " << nums[Left] << ", " << nums[Right] << endl;
            cout << "sum = " << sum << endl;

            if (sum < target)
            {
                Left++;
            }
            else if (sum > target)
            {
                Right--;
            }
            else    //(sum == target)
            {
                cout << "Found!!" << endl;

                answer.push_back(Left);
                answer.push_back(Right);
                return answer;
            }
        }while (Left < Right);
        return answer;            
    }
};


int main()
{
    //vector<int> numbers {2, 7, 11, 15};
    //int target = 9;

    vector<int> numbers {3, 2, 4};  // need to sort first

    int target = 6;

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