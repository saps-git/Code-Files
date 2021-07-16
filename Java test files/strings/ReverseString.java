package strings;

public class ReverseString{
    private static void reverse(char strArr[], int start, int end) {
        while(start < end){
            char temp = strArr[start];
            strArr[start] = strArr[end];
            strArr[end] = temp;
            start++;
            end--;
        }
    }
    public static void main(String[] args) {
        String str = "the sky is blue";
        char strArr[] = str.toCharArray();

        reverse(strArr, 0, strArr.length-1); // will return as reversed string "eulb si yks eht"
        //now we can just reverse that again, in order to get our o/p

        int start = 0; // var for swapping the char in word
        for(int end=0;end<strArr.length;end++){
            if(strArr[end] == ' '){
                reverse(strArr, start, end-1); // will reverse every word, char by char swapping
                start = end+1; //var set to staring index of next word
            }
        }

        reverse(strArr, start, strArr.length-1); //to reverse the last word, as it won't be done by the last loop

        System.out.println(String.valueOf(strArr)); //convert char array to string
    }
}