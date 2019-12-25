import java.math.BigInteger;
class Solution {
    public int reverse(int x) {
        StringBuilder sb = new StringBuilder();
        int input = x;
        if(x<0) 
            x = x*(-1);
        if(x<=0) 
            return 0;
        while(x>0){
            int rem = x%10;
            if(rem == 0 && sb.toString().length()==0) {
                x = x/10;
                continue;
            }
            sb.append(rem);
            x = x/10;
        }
        String s = sb.toString();
        BigInteger maxInt = BigInteger.valueOf(Integer.MAX_VALUE);
        BigInteger value = new BigInteger(s);

        if (value.compareTo(maxInt) > 0)
        {
            return 0;
        }
        if(input<0) return value.intValue()*(-1);
        else return value.intValue();
    }
}
