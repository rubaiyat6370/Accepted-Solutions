/**
Given a string, find the length of the longest substring in it with no more than K distinct characters.
Input: String="araaci", K=2
Output: 4
Explanation: The longest substring with no more than '2' distinct characters is "araa".

Input: String="araaci", K=1
Output: 2
Explanation: The longest substring with no more than '1' distinct characters is "aa".

Input: String="cbbebi", K=3
Output: 5
Explanation: The longest substrings with no more than '3' distinct characters are "cbbeb" & "bbebi".
**/

import java.util.*;

class LongestSubstringKDistinct {
  public static int findLength(String str, int k) {
    int arr[] = new int[26];
    int count = 0, start = 0, end = 0, maxLen = 0;

    for(end = 0; end< str.length(); end++){
        int pos = str.charAt(end) - 'a';
        if (arr[pos] == 0 ){
           count++;
        }
        arr[pos]++;
        while (count > k) {
           pos = str.charAt(start) - 'a';
           arr[pos]--;
           if (arr[pos] == 0 ) count--;
           start++;
        }
        if(end - start + 1 > maxLen) {
          maxLen = end - start + 1;
        }
    }

    return maxLen;
  }
}
