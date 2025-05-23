

class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        ransom_letters = {}
        magazine_letters = {}
        for letter in ransomNote:
            if letter in ransom_letters:
                ransom_letters[letter] += 1
            else:
                ransom_letters[letter] = 1

        for letter in magazine:
            if letter in magazine_letters:
                magazine_letters[letter] += 1
            else:
                magazine_letters[letter] = 1

        for letter in ransom_letters:
            if letter in magazine_letters and magazine_letters[letter] >= ransom_letters[letter]:
                continue
            else:
                return False

        return True
        