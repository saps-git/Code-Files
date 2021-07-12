package strings;

public class Anagram {
    public static boolean isAnagram(String s1, String s2) {
        if(s1.length() != s2.length())
            return false;

        int char_count[] = new int[26]; //taking arr of size 26 as an buffer array
        for(int i=0;i<s1.length();i++){
            char_count[s1.charAt(i) - 'a']++; //incrementing the value of the char in the vector as eg. 'n'-'a' = 13
            char_count[s2.charAt(i) - 'a']--; //decrementing the value of the char in the vector as eg. 'n'-'a' = 13
        }
        //hence if an anagram, all the cells should return to 0, after all the incr and decr

        for(int i: char_count){
            if(i != 0)
                return false;
        }

        return true;
    }
    public static void main(String[] args) {
        String s1 = "anagram";
        String s2 = "nagaram";

        System.out.println(isAnagram(s1, s2) ? "Anagram" : "Not Anagram");
    }
}
