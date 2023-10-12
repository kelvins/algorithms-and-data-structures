# Title: 767. Reorganize String
# Difficulty: Medium
# Problem: https://leetcode.com/problems/reorganize-string/description/

## using dictionary (faster)
from collections import Counter

class Solution:
    def reorganizeString(self, s: str) -> str:
        arr = [''] * len(s)  # Initialize the array to store the reorganized string
        counter = Counter(s)
        counter = dict(sorted(counter.items(), key=lambda x: x[1], reverse=True))
        even, odd = 0, 1
        
        for char in counter:
            # Check if the frequency of the current character is too high to fit in the array
            if counter[char] > (len(s) + 1) // 2:
                return ''
            
            # Place characters in even positions
            while counter[char] > 0 and even < len(arr):
                arr[even] = char
                even += 2
                counter[char] -= 1
            
            # Place remaining characters in odd positions
            while counter[char] > 0 and odd < len(arr):
                arr[odd] = char
                odd += 2
                counter[char] -= 1
        
        return ''.join(arr)

# using heap (Slower)
class Solution:
    def reorganizeString(self, s: str) -> str:
        counter = Counter(s)
        max_heap = [(-freq, char) for char, freq in counter.items()]
        heapq.heapify(max_heap)
        
        result = []
        
        while max_heap:
            freq, char = heapq.heappop(max_heap)
            if not result or char != result[-1]:
                result.append(char)
                if freq + 1 < 0:
                    heapq.heappush(max_heap, (freq + 1, char))
            else:
                if not max_heap:
                    return ""
                freq2, char2 = heapq.heappop(max_heap)
                result.append(char2)
                if freq2 + 1 < 0:
                    heapq.heappush(max_heap, (freq2 + 1, char2))
                heapq.heappush(max_heap, (freq, char))
        
        return ''.join(result)
