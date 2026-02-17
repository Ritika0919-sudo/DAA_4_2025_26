class Solution {
  public:
    int minTime(vector<int>& arr, int k) {
        
        long long low = 0, high = 0;
        
        // Minimum time must be at least the largest board
        for (int board : arr) {
            low = max(low, (long long)board);
            high += board;
        }
        
        while (low <= high) {
            
            long long mid = low + (high - low) / 2;
            
            long long currentSum = 0;
            int painters = 1;
            
            for (int board : arr) {
                
                if (currentSum + board <= mid) {
                    currentSum += board;
                } else {
                    painters++;
                    currentSum = board;
                }
            }
            
            if (painters <= k) {
                high = mid - 1;   
            } else {
                low = mid + 1;    
            }
        }
        
        return low;
    }
};
