class Solution:
    def intToRoman(self, num: int) -> str:
        numeral = ""
        romans = {
            1000: 'M',
            500: 'D',
            100: 'C',
            50: 'L',
            10: 'X',
            5: 'V',
            1: 'I'
        }
        num_str = str(num)
        place = len(num_str) - 1

        for i in num_str:
            i = int(i)
            
            if i == 4:
                numeral += romans[10**place] + romans[5*10**place]
            
            elif i == 9:
                numeral += romans[10**place] + romans[10**(place+1)]
            
            else:
                if i >= 5:
                    numeral += romans[5 * 10**place] + (i-5)*romans[10**place]
                else:
                    numeral += i * romans[10**place]
                           
            place -= 1



        return numeral
        