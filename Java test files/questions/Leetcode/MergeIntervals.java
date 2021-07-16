package questions.Leetcode;
import java.util.*;

public class MergeIntervals {
    public static int[][] merge(int[][] intervals) {
        if(intervals.length <= 1) return intervals;

        Arrays.sort(intervals, (i1, i2) -> Integer.compare(i1[0], i2[0])); //sorting, with comparator and inner class lambda exp

        List<int[]> ans = new ArrayList<>(); //list of arrays, (2D arraylist)
        int[] current_int = intervals[0]; //will hold the current interval that is been checked
        ans.add(current_int); 

        for(int[] interval : intervals){
            if(current_int[1] >= interval[0])
                current_int[1] = Math.max(current_int[1], interval[1]);
            else{
                current_int = interval;
                ans.add(current_int); 
            }
        }

        return ans.toArray(new int[ans.size()][]); //converting list to 2D array
    }
    public static void main(String[] args) {
        int[][] intervals = {{1,3},{2,6},{8,10},{15,18}};
        int[][] ans = merge(intervals);
        for(int i=0;i<ans.length;i++){
            for(int j=0;j<ans[i].length;j++){
                System.out.print(ans[i][j] + " ");
            }
            System.out.println();
        }
    }
}
