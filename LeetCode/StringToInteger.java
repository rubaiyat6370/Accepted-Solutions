class Solution {
    public int myAtoi(String str) {
        int number = 0;
        int start = 0;
        int sign = 0;
        int min = -2147483648;
        int max = 2147483647;
        int size = str.length();
        for(int i = 0; i< size; i++) {
            int ascii = str.charAt(i) - '0';

            if(ascii == -16 && start == 0) continue;

            if((ascii == -3 || ascii == -5 ) && start == 0 && i+1 < size){
                start = 1;
                sign  = ascii;
                int next = (str.charAt(i+1) - '0');
                if(next >= 0 && next <=9) {
                    if (ascii == -3) number = next*(-1);
                    else number = next;
                    i++;
                } else break;
            } else if(ascii>=0 && ascii<=9){
                start = 1;
                if(number < min/10 || ( number == min/10 && ascii > 8)) {
                    return min;
                } else if(number > max/10 || (number == max/10 && ascii > 7)) {
                    return max;
                } else if(number < 0) {
                    number = number*10 - ascii;
                } else {
                    number = number*10 + ascii;
                }  
            } else break;
        }
        if (sign == -3 && number > 0) number = number*(-1);
        return number;
    }
}
