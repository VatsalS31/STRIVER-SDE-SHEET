#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    int n = nums.size(); //size of the array
    vector<vector<int>> ans;

    // sort the given array:
    sort(nums.begin(), nums.end());

    //calculating the quadruplets:
    for (int i = 0; i < n; i++) {
        // avoid the duplicates while moving i:
        if (i > 0 && nums[i] == nums[i - 1]) continue;
        for (int j = i + 1; j < n; j++) {
            // avoid the duplicates while moving j:
            if (j > i + 1 && nums[j] == nums[j - 1]) continue;

            // 2 pointers:
            int k = j + 1;
            int l = n - 1;
            while (k < l) {
                long long sum = nums[i];
                sum += nums[j];
                sum += nums[k];
                sum += nums[l];
                if (sum == target) {
                    vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                    ans.push_back(temp);
                    k++; l--;

                    //skip the duplicates:
                    while (k < l && nums[k] == nums[k - 1]) k++;
                    while (k < l && nums[l] == nums[l + 1]) l--;
                }
                else if (sum < target) k++;
                else l--;
            }
        }
    }

    return ans;
}
/*
### Explanation of the 4Sum Approach

The **4Sum problem** requires finding all unique quadruplets \((a, b, c, d)\) in an array such that \(a + b + c + d = \text{target}\). Here's a step-by-step explanation of your approach:

---

### **Step 1: Sort the Array**
- Sorting the array simplifies the process of finding quadruplets and helps in skipping duplicates.
- Example: If the array is \([1, 0, -1, 0, -2, 2]\), sorting it gives \([-2, -1, 0, 0, 1, 2]\).

---

### **Step 2: Fix the First Two Numbers (Outer Loops)**
- Use **two nested loops** to pick the first two numbers of the quadruplet:
  - The first loop (`i`) fixes the first number.
  - The second loop (`j`) fixes the second number after `i`.

- Skip duplicate numbers in both loops to avoid redundant quadruplets.

  Example:
  - For \(i = 0\), \(j = 1\), the fixed numbers are \(-2\) and \(-1\).

---

### **Step 3: Use Two Pointers for the Remaining Two Numbers**
- After fixing the first two numbers, use two pointers (`k` and `l`) to find the remaining two numbers:
  - **`k` starts** just after `j`.
  - **`l` starts** at the end of the array.

- Calculate the sum of the four numbers:  
  \(\text{sum} = \text{nums}[i] + \text{nums}[j] + \text{nums}[k] + \text{nums}[l]\).

  - If \(\text{sum} = \text{target}\), store the quadruplet and adjust pointers:
    - Move `k` to the right, skipping duplicates.
    - Move `l` to the left, skipping duplicates.
  - If \(\text{sum} < \text{target}\), increase `k` to try larger numbers.
  - If \(\text{sum} > \text{target}\), decrease `l` to try smaller numbers.

---

### **Step 4: Skip Duplicates**
- While moving the pointers (`i`, `j`, `k`, `l`), ensure duplicates are skipped:
  - For `i` and `j`, skip if the current number is the same as the previous one.
  - For `k` and `l`, adjust the pointers if they point to duplicate values.

---

### **Step 5: Return the Result**
- Store all unique quadruplets in the `ans` vector and return it.

---

### Example Walkthrough
Array: \([-2, -1, 0, 0, 1, 2]\), Target: \(0\)

1. Fix \(i = 0\), \(\text{nums}[i] = -2\).
   - Fix \(j = 1\), \(\text{nums}[j] = -1\).
     - Start two pointers:
       - \(k = 2\), \(\text{nums}[k] = 0\).
       - \(l = 5\), \(\text{nums}[l] = 2\).
       - Calculate sum: \(-2 + (-1) + 0 + 2 = -1\) (less than target). Move \(k\) to \(3\).
       - Calculate sum: \(-2 + (-1) + 0 + 2 = 0\) (matches target). Store \([-2, -1, 0, 2]\). Adjust \(k\) and \(l\) to avoid duplicates.

   - Continue with the same logic for other combinations.

Result: \([[-2, -1, 0, 2], [-2, 0, 0, 1], [-1, 0, 0, 1]]\)

---

### **Time Complexity**
- Sorting the array: \(O(n \log n)\).
- Outer loops and two-pointer traversal: \(O(n^3)\).

**Overall Complexity**: \(O(n^3)\).

### **Space Complexity**
- Sorting takes \(O(1)\) extra space (in-place).
- Result storage: \(O(k)\), where \(k\) is the number of quadruplets.


*/
