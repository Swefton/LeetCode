class Solution:
    def fullJustify(self, words: List[str], maxWidth: int) -> List[str]:
        result = list()
        buffer = list()
        curr_len = 0

        for word in words:
            if curr_len + len(word) + len(buffer) <= maxWidth:
                buffer.append(word)
                curr_len += len(word)
            else:
                total_chars = sum(len(w) for w in buffer)
                num_spaces = maxWidth - total_chars

                if len(buffer) == 1:
                    line = buffer[0] + ' ' * (maxWidth - len(buffer[0]))
                else:
                    num_gaps = len(buffer) - 1
                    space_per_gap = num_spaces // num_gaps
                    extra_spaces = num_spaces % num_gaps

                    line = ''
                    for i in range(num_gaps):
                        line += buffer[i]
                        line += ' ' * (space_per_gap + (1 if i < extra_spaces else 0))
                    line += buffer[-1]

                result.append(line)
                buffer = [word]
                curr_len = len(word)

        last_line = ' '.join(buffer)
        last_line += ' ' * (maxWidth - len(last_line))
        result.append(last_line)

        return result
