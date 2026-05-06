class Solution {
public:
    long long func(vector<int>& piles, int mid) {
        long long ans = 0;
        for (int i = 0; i < piles.size(); i++) {
            ans += ceil((double)piles[i] / mid);
        }
        return ans;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = INT_MIN, ans = -1;

        for (int i = 0; i < piles.size(); i++)
            high = max(high, piles[i]);

        while (low <= high) {
            int mid = (low + high)/ 2;
            long long val = func(piles, mid);
            if (val <= h) {
                ans = mid;
                high = mid - 1;
            } else
                low = mid + 1;
        }
        return ans;
    }
};

// brute force solution

// class Solution {
// public:
//     int minEatingSpeed(vector<int>& piles, int h) {
//         int hours_needed;
//         int ans = 0;
//         int max = INT_MIN;

//         for(int i=0;i<piles.size();i++){
//             if(max<piles[i])
//                 max = piles[i];
//         }
//         for(int k=1;k <= max;k++){
//             hours_needed = 0;
//             for(int i=0;i<piles.size();i++){
//                 if(piles[i]% k == 0)
//                     hours_needed += piles[i]/k;
//                 else{
//                     hours_needed += ((piles[i]/k)+1);
//                 }
//             }

//             // cout<<"speed: "<<k<<"  time needed: "<< hours_needed<<endl;

//             if(hours_needed <= h){
//                 ans = k;
//                 break;
//             }
//         }

//         return ans;
//     }
// };
