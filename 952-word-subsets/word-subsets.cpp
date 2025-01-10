#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        unordered_map<char, int> max_letter_count;

        for (const auto& word : words2)
        {
            unordered_map<char, int> temp_count;
            for (char character : word)
            {
                temp_count[character]++;
            }
            for (const auto& [character, count] : temp_count)
            {
                max_letter_count[character] = max(max_letter_count[character], count);
            }
        }

        vector<string> result;
        for (const auto& word : words1)
        {
            unordered_map<char, int> letter_count;
            for (char character : word)
            {
                letter_count[character]++;
            }

            bool is_universal = true;
            for (const auto& [character, required_count] : max_letter_count)
            {
                if (letter_count[character] < required_count)
                {
                    is_universal = false;
                    break;
                }
            }

            if (is_universal)
            {
                result.push_back(word);
            }
        }

        return result;
    }
};
