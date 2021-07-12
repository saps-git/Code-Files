package sorting;

public class SelectionSort {
    public static void swap(int arr[], int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    public static void main(String[] args) {
        int arr[] =  {13,45,2,6,78,10};
        for(int i=0;i<arr.length-1;i++){
            for(int j=i+1;j<arr.length;j++){
                if(arr[i] > arr[j])
                    swap(arr, i, j);
            }
        }

        for(int i: arr)
            System.out.print(i+" ");
        System.out.println();
    }
}
