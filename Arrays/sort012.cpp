void sortArray(vector<int>& arr, int n) {

    int low = 0, mid = 0, high = n - 1; // 3 pointers

    while (mid <= high) {
        if (arr[mid] == 0) {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if (arr[mid] == 1) {
            mid++;
        }
        else {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}
// TC O(N)
// ALSO CALLED AS NATIONAL DUTCH ALGORITHM AND IT IS LIKE JUST TAKE THE POINTER FOR ZERO,ONE,TWO AND WHERE EVER WE ENCOUNTERED 0,1,2 SO SWAP WITH CORRESPONDING ELEMENT AND MOVE 
