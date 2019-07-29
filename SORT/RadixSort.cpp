#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

void printVector(const vector<int>& array, int i)
{
    cout << i << ": ";
    for (vector<int>::const_iterator it = array.begin(); it != array.end(); it++)
        cout << *it << ", ";
    cout << endl;
}

void RadixSortArray(vector<int>& array)
{
    vector<int>::iterator maxPosition = max_element(array.begin(), array.end());
    int maxNum = *maxPosition;
    cout << maxNum << endl;

    vector<int> nulv;
    vector<vector<int> > vec(10, nulv);
    int i = 1;

    int x = 1;
    int y = 1; 
    do {
        for (int j = 0; j < array.size(); j++){
            vec[array[j] / (int)(pow(10, (i -1))) % 10].push_back(array[j]);
        }

        array.clear();
        vector<vector<int> >::iterator it = vec.begin();
        for (; it != vec.end(); it++)
        {
            array.insert(array.end(), it->begin(), it->end());
            it->clear();
        }

        printVector(array, i);
        i++;
    } while(maxNum = maxNum / 10);
}

int main()
{
    vector<int> array;
    array.push_back(64);
    array.push_back(8);
    array.push_back(216);
    array.push_back(512);
    array.push_back(27);
    array.push_back(729);
    array.push_back(0);
    array.push_back(1);
    array.push_back(343);
    array.push_back(125);
    array.push_back(425);

    RadixSortArray(array);

    printVector(array, 100);

    return 0;
}
