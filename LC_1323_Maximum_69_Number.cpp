// O(n) solution
class Solution {
public:
    int maximum69Number (int num) 
    {
        // To maximize the number, turn the first 6 into a 9
        string numVal = to_string(num);
        for (auto &ix : numVal)
        {
            if (ix == '6')
            {
                ix = '9';
                return stoi(numVal);
            }
        }
        return num;
    }
};
