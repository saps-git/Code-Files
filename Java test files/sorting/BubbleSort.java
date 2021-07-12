package sorting;

public class BubbleSort {
    public static void swap(int arr[], int i, int j){
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    public static void main(String[] args) {
        int arr[] = {13,45,2,6,78,10};
        for(int i=0;i<arr.length;i++){
            for(int j=1;j<arr.length-i;j++){
                if(arr[j] < arr[j-1])
                    swap(arr, j, j-1);
            }
        }

        for(int i: arr){
            System.out.print(i+" ");
        }
        System.out.println();
    }
    
}
