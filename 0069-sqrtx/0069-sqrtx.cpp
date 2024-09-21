class Solution {
public:
    int mySqrt(int x) {
        int s=0;
        int e=x;
        long long int mid=s+(e-s)/2;
        int ans = -1;
        while(s<=e) {
            // Happy Case
          long long int product = mid*mid;
          if(product==x) {
            return mid;
          }  
          if(product<x) {
            // may or may not be
            // store and compute
            ans=mid;
            // go to right to find or jyada pass ka answer
            s=mid+1;
          }
          else{
            // product>x -> left me jao
            e=mid-1;
          }
          mid=s+(e-s)/2;
        }
        return ans;
    }
};