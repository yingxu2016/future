class Solution {
  public int[] twoSum(int[] nums, int target) {
    Map<Integer, Integer> idxMap = new HashMap<>();
    for (int i = 0; i< nums.length; i++) {
      int complement = target - nums[i];
      if (idxMap.containsKey(complement)) {
        return new int[]{i, idxMap.get(complement)};
      }
      idxMap.put(nums[i], i);
    }
    return null;
  }
}
