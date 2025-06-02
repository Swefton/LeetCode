class Solution:
    def reverseWords(self, s: str) -> str:
        result = ""
        index = 0
        start = 0 if s[0] != " " else None
        string_list = list()

        while index != len(s):
            if s[index] == " ":
                if start != None:
                    string_list.append(s[start:index])
                    start = None
                else:
                    pass
            else:
                if start != None:
                    pass
                else:
                    start = index
            index += 1

        string_list.append(s[start:]) if start != None else None
        string_list.reverse()

        for i in range(len(string_list)):
            result += string_list[i] + (" " if i != len(string_list) - 1 else "")
        
        return result
        