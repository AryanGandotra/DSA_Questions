class Solution
{
public:
    vector<int> replaceElements(vector<int> &arr)
    {
        int maxElementOnRight = -1;

        for (int i = arr.size() - 1; i >= 0; i--)
        {
            int temp = arr[i];
            arr[i] = maxElementOnRight;
            maxElementOnRight = max(maxElementOnRight, temp);
        }

        return arr;
    }
};

// class Solution {
// public:
//     vector<int> replaceElements(vector<int>& arr) {
// O(N) Time Complexity , O(N) Space complexity
//         int max_number = -1;
//         vector<int> result(arr.size(),0);

//         for(int i=arr.size()-1;i>=0;i--){
//             result[i] = max_number;

//             if(arr[i]>max_number)
//                 max_number = arr[i];
//         }

//         return result;
//     }
// };