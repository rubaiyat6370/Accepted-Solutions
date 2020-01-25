class Solution {
    int[] visited = {
        0,
        0,
        0,
        0
    };
    int[] answer = {-1,
        -1,
        -1,
        -1
    };
    int max = 0;
    public String largestTimeFromDigits(int[] A) {
        int[] time = {
            0,
            0,
            0,
            0
        };
        permutation(0, A, time, 0);

        StringBuilder sb = new StringBuilder();
        if (answer[0] == -1) return "";
        for (int i = 0; i < 2; i++) {
            sb.append(answer[i]);
        }
        sb.append(":");
        for (int i = 2; i < 4; i++) {
            sb.append(answer[i]);
        }
        return sb.toString();
    }

    void permutation(int level, int[] A, int[] time, int sum) {
        if (level == 4) {
            int min = 0;
            for (int j = 2; j < 4; j++) {
                min = min * 10 + time[j];
            }

            if (min > 59 || sum > 2359) return;
            if (sum >= max) {

                max = sum;
                for (int j = 0; j < 4; j++)
                    answer[j] = time[j];
            }
            return;
        } else if (level == 2) {
            if (sum > 23)
                return;
        }

        int i;
        for (i = 0; i < A.length; i++) {
            if (visited[i] == 0) {
                time[level] = A[i];
                sum = sum * 10 + A[i];
                visited[i] = 1;
                permutation(level + 1, A, time, sum);
                visited[i] = 0;
                sum = sum / 10;
            }
        }
    }
}
/*
Sample Input: [2,0,6,6]
Sample Output: 06:26
*/
