class Solution {
    func findMedianSortedArrays(_ nums1: [Int], _ nums2: [Int]) -> Double {
        var combinedArray = [Int]()
        var count1 = nums1.count, count2 = nums2.count
        var i = 0, j = 0, c = 0

        while(i<count1 || j<count2){
            if(i<count1 && j<count2 && nums1[i] < nums2[j]){
                combinedArray.append(nums1[i])
                i+=1
            } else if i<count1 && j<count2 && nums1[i] > nums2[j] {
                combinedArray.append(nums2[j])
                j+=1
            } else if i<count1 {
                combinedArray.append(nums1[i])
                i+=1
            } else if j<count2 {
                combinedArray.append(nums2[j])
                j+=1
            }

            if(combinedArray.count > (count1+count2)/2) {
                break
            }

        }

        if (count1+count2)%2 == 0 {
            return Double((Double(combinedArray[combinedArray.count-1]) + Double(combinedArray[combinedArray.count-2]))/2.0)
        } else {
            return Double(combinedArray[combinedArray.count-1])
        }
    }
}
