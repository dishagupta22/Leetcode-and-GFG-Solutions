// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int K) 
    { 
// O(n2) solution using unordered set   
        // unordered_set<int> us;
        // int maxlen=0, presum=0, e=0;
        // for(int i=0; i<N; i++){   ----------------------O(n)
        //     presum+=A[i];
        //     if(presum==K || us.count(presum-K))
        //     {
        //         e=i;
        //         int s=e, len=0, currsum=0;
        //         while(s>=0)------------------------------O(n) 
        //         {                                 because s-- will go one until s<0
        //             currsum+=A[s];                      |
        //             if(currsum==K)                      |
        //             {                                   |
        //                 len=e-s+1;                      |
        //                 maxlen= max(maxlen, len);       |  here we have not written
        //             }                                   |  else{ s--;} because we need to
        //             s--;             --------------------  have longest length. there may be
        //         }                    a 0 sum subarr in btw so by adding that len will increase                 
        //     }                        so we need to go on decrsing s to encounter same sum again
        //     us.insert(presum);
        // }
        // return maxlen;
        
// O(n) solution using unordered map
        unordered_map<int, int> um;
        int presum=0, maxlen=0;
        for(int i=0; i<N; i++)
        {
            presum+=A[i];
            int len=0;
            if(presum==K)
               len = i+1;
            else if(um.find(presum-K)!=um.end())
               len = i-um[presum-K];
            maxlen = max(maxlen, len);
            if(um.find(presum)==um.end())
                um[presum]=i;
        }
        return maxlen;
    } 

};

// { Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends