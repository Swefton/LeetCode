class Solution:
    def readBinaryWatch(self, turnedOn: int) -> List[str]:
        res = list()
        hours = [2**i for i in range(3,-1,-1)]
        minutes = [2**i for i in range(5,-1,-1)]

        for i in range(turnedOn + 1):
            j = turnedOn - i
        
            if i > 3 or j > 5:
                continue
            
            for h_bits in combinations(hours, i):
                h_sum = sum(h_bits)
                if h_sum >= 12:
                    continue
                
                for m_bits in combinations(minutes, j):
                    m_sum = sum(m_bits)
                    if m_sum >= 60:
                        continue
                    
                    res.append(f"{h_sum}:{m_sum:02d}")
        
        return res