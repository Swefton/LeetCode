class Solution:
    def sumFourDivisors(self, nums: List[int]) -> int:
        total = 0

        for num in nums:
            divisors = 0
            curr_sum = 0
            for c in range(1, floor(sqrt(num))+1):
                if num % c == 0:
                    if num//c != c:
                        curr_sum += c
                        curr_sum += num//c
                        divisors += 2
                    else:
                        curr_sum += c
                        divisors += 1
            if divisors == 4:
                total += curr_sum    
            
        return total
        