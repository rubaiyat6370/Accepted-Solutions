import static java.util.stream.Collectors.*;
import static java.util.Map.Entry.*;


public class Solution {

    // Complete the jimOrders function below.
    static int[] jimOrders(int[][] orders) {
        HashMap<Integer, Integer> map  = new HashMap<>();
        int len = orders.length;

        for(int i=0;i<len;i++){
            map.put(i+1,orders[i][0] + orders[i][1]);
        }
        Map<Integer, Integer> sorted = map
        .entrySet()
        .stream()
        .sorted(comparingByValue())
        .collect(
            toMap(e -> e.getKey(), e -> e.getValue(), (e1, e2) -> e2,
                LinkedHashMap::new));
        int [] customerOrders = new int[len];
        int i = 0;
        for (Map.Entry<Integer,Integer> entry : sorted.entrySet())  {
            //System.out.println("Key = " + entry.getKey() + ", Value = " + entry.getValue());
            customerOrders[i++] = entry.getKey();
        }
            
        return customerOrders;
    }
