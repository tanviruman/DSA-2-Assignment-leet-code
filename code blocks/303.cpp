#include <iostream>
#include <vector>
using namespace std;

class NumArray {
private:

    vector<int> prefixSumArray;

public:

    NumArray(const vector<int>& inputNumbers)
    {
        int totalNumbers = inputNumbers.size();
        prefixSumArray.resize(totalNumbers + 1, 0);

        for (int index = 0; index < totalNumbers; ++index)

            {
            prefixSumArray[index + 1] = prefixSumArray[index] + inputNumbers[index];
        }
    }


    int sumRange(int leftIndex, int rightIndex)

     {
        return prefixSumArray[rightIndex + 1] - prefixSumArray[leftIndex];
    }
};


int main()

{
    int totalNumbers;
    cout << "Enter number of elements: ";
    cin >> totalNumbers;

    vector<int> inputNumbers(totalNumbers);
    cout << "Enter the numbers: ";

    for (int i = 0; i < totalNumbers; ++i)

        {
        cin >> inputNumbers[i];
    }

    NumArray rangeSumCalculator(inputNumbers);

    int leftIndex, rightIndex;

    cout << "Enter range (leftIndex rightIndex): ";
    cin >> leftIndex >> rightIndex;

    cout << "Sum of range [" << leftIndex << ", " << rightIndex << "] = "
         << rangeSumCalculator.sumRange(leftIndex, rightIndex) << endl;

    return 0;
}
