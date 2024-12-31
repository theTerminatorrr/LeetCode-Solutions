class Solution:
    def firstBadVersion(self, n: int) -> int:
        left = 0
        right = n - 1

        while left <= right:
            mid = (left + right) // 2
            if isBadVersion(mid) == False:
                left = mid + 1
            else:
                right = mid - 1
        return left