//You will be given a list of integers,arr , and a single integer k. You must create an array of length k
from elements of arr such that its unfairness is minimized. Call that array . Unfairness of an array is calculated as
max(subarr) - min (subarr)

public class Solution {

    // Complete the maxMin function below.
    static int maxMin(int k, int[] arr) {
        Arrays.sort(arr);
        int min = 99999999;
        for(int i=k-1;i<arr.length;i++){
            if(arr[i] - arr[i-k+1] < min ){
                min = arr[i] - arr[i-k+1];
                if(min==0) return min;
            }
        }
        return min;
    }
}
