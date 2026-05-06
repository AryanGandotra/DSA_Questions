class Solution {
  public:
    int func(int number,int times,int m){
        int ans=1;
        for(int i=0;i<times;i++){
            ans*=number;
            if(ans>m)
                return 2;
        }
        if(ans==m) return 1;
        
        return 0;
    }
    int nthRoot(int n, int m) {
        int low = 1, high = m;
        int ans = 0;
        
        if(m==0)
            return 0;

        while (low <= high) {
            int mid = (low + high) / 2;
            int val = func(mid,n,m);
            if (val == 1)
                return mid;
            else if (val == 0) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return -1;
        
    }
};


