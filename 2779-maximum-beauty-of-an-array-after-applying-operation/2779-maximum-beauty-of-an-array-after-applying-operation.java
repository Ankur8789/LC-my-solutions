class Solution {
    public int maximumBeauty(int[] nums, int k) {
        int val = 100000;
        int[] fre = new int[1000000];
        for(int num : nums) {
            fre[num-k+val]++;
            fre[num+k+val+1]--;
        }
        int sum=0;
        int ans=0;
        for(int i=0;i<fre.length;i++) {
            sum+=fre[i];
            ans=Math.max(ans,sum);
        }
        return ans;
    }
}