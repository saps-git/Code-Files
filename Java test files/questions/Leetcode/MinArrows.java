package questions.Leetcode;

import java.util.Arrays;

public class MinArrows {
    public static int findMinArrowShots(int[][] points) {
        if(points.length == 0) return 0;

        Arrays.sort(points, (a, b) -> Integer.compare(a[1], b[1]));

        int arrow = 1;
        int end = points[0][1];
        for(int i=1;i<points.length;i++){
            if(points[i][0] > end){
                arrow++;
                end = points[i][1];
            }
        }
        return arrow;
    }
    public static void main(String[] args) {
        int[][] points = {{-2147483646,-2147483645},{2147483646,2147483647}};
        System.out.println(findMinArrowShots(points));
    }
    
}
