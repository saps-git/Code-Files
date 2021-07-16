package questions.Leetcode;
import java.util.*;

public class NonOverlappingIntervals {
    
    public static int eraseOverlapIntervals(int[][] intervals) {
        if(intervals.length <= 1) return 0;

        Arrays.sort(intervals, (a, b) -> Integer.compare(a[1], b[1])); //we're comparing by last element as, we've to find the minimum no of removals in order to make it non overlaping. Lesser the last element, means more tasks we can add.

        int count = 0;
        int end = intervals[0][1];
        for(int i=1;i<intervals.length;i++){
            if(intervals[i][0] < end){
                count++;
            }
            else
                end = intervals[i][1];
        }

        return count;

    }
    public static void main(String[] args) {
        int[][] intervals = {{1,100},{11,22},{1,11},{2,12}};
        System.out.println(eraseOverlapIntervals(intervals));
    }
}
