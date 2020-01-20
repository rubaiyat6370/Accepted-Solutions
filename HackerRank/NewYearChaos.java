public class Solution {

    // Complete the minimumBribes function below.
    static void minimumBribes(int[] q) {
        int tcount = 0, count = 0, maxC = 0;
        int n = q.length;
        for(int i = n-1;i>=0;i--){
            int j = i;
            while(j+1<n && q[j+1]<q[j]) {
                int temp = q[j+1];
                q[j+1] = q[j];
                q[j] = temp;
                count++;
                tcount++;
                if(count > 2) {
                    System.out.println("Too chaotic");
                    return;
                }
                j++;
            }
            count = 0;
        }
        System.out.println(tcount);
    }
}
