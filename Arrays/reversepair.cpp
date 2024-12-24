// BRUTE FORCE  TC O(N^2)
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int n=nums.size();
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(nums[i]>2*nums[j])
                {
                    cnt++;
                }
            }
        }
        return cnt;
        
    }
};

//OPTIMAL APPROACH
//int cnt=0;//global variable
class Solution {
    public:
    void merge(vector<int> &arr, int low, int mid, int high) {
    vector<int> temp; // temporary array
    int left = low;      // starting index of left half of arr
    int right = mid + 1;   // starting index of right half of arr

    //storing elements in the temporary array in a sorted manner//

    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        }
        else {
            temp.push_back(arr[right]);
            right++;
        }
    }

    // if elements on the left half are still left //

    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    //  if elements on the right half are still left //
    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    // transfering all elements from temporary to arr //
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
}
int countpair(vector<int> &arr,int low, int mid, int high){
    int right=mid+1;
    int cnt=0;
    for(int i=low;i<=mid;i++)
    {
      while (right <= high && (long long)arr[i] > 2LL * arr[right])

        {
            right++;
            
        }
        cnt=cnt+(right-(mid+1));
    }
    return cnt;

}
int  mergeSort(vector<int> &arr, int low, int high) {
     int cnt=0;
    if (low >= high) return cnt;
   
    int mid = (low + high) / 2 ;
    cnt+=mergeSort(arr, low, mid);  // left half
    cnt+=mergeSort(arr, mid + 1, high); // right half
    cnt+=countpair(arr,low,mid,high);
    merge(arr, low, mid, high);  // merging sorted halves
    return cnt;
}
public:
    int reversePairs(vector<int>& nums) {
        int n=nums.size();
       return mergeSort(nums,0,n-1);
        //return ans;

    }
};

// APPROACH IS SAME LIKE COUNT INVERSION LIKE DONG MERGE SORT AND ATE EVRY ITERATION CHECKING FOR THE CONDITION AND ADDING TO RESULT AND 
// LIKE WISE KEEP MERGING THE ARRAY
// TC O(2N*LOGN)
// SC O(N) WE ARE MERGING THE ARRAY THAT IS DISTORITNG BEFORE MERGING ,IF YOU HAVE PROBLEM I CAN TAKE A COPY OF THAT AND SOLVE IT 

