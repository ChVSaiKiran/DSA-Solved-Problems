// My Code
// Finding the critical point i.e point where left side & right side are sorted
// Now applying the binary search on both halves 
// class Solution {
//     private int f(int[] nums, int low, int high){
//         if(low > high)  return -1;
        
//         int mid = low + (high - low) / 2;
//         if(mid + 1 < nums.length && nums[mid] > nums[mid + 1]){
//             return mid;
//         }

//         int lt = f(nums, low, mid - 1);
//         if(lt != -1)    return lt;

//         int rt = f(nums, mid + 1, high);
//         if(rt != -1)    return rt;

//         return -1;
//     }

//     private int binarySearch(int[] nums, int start, int end, int target){
//         while(start <= end){
//             int mid = start + (end - start)/2;
//             if(nums[mid] == target){
//                 return mid;
//             } else if(nums[mid] > target){
//                 end = mid - 1;
//             } else{
//                 start = mid + 1;
//             }
//         }
//         return -1;
//     }

//     public int search(int[] nums, int target) {
//         int n = nums.length, idx = f(nums, 0, n - 1);
//         if(idx == -1){
//             return binarySearch(nums, 0, n - 1, target);
//         }

//         int lt = binarySearch(nums, 0, idx, target);
//         if(lt != -1)    return lt;
//         return binarySearch(nums, idx + 1, n - 1, target);
//     }
// }


// Optimised approach
class Solution {
    public int search(int[] nums, int target) {
        int low = 0, high = nums.length - 1;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(nums[mid] == target){
                return mid;
            } else if(nums[low] <= nums[mid]){  
                //if control inside this block means Left Half is sorted
                if(nums[low] <= target && target <= nums[mid]){  // Might be present in Left half, so try seraching in left half
                    high = mid - 1;
                } else{
                    low = mid + 1;
                }
            } else{
                //if control inside this block means Rigth Half is sorted
                if(nums[mid] <= target && target <= nums[high]){ // Might be present in right hlaf, so try searching in right half
                    low = mid + 1;
                } else{
                    high = mid - 1;
                }
            }
        }
        return -1;
    }
}