class Solution {
    public boolean isPalindrome(int x) {
        int revers = 0;
        int temp =  x;
        while (x > 0) {
            int digit = x % 10;


           revers = revers*10 + digit;


            x /= 10;


        }

        if(revers==temp){
            return true;
        }
        
        return false;
        
    }
}
