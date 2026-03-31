class Solution {
public:
    int myAtoi(string s) {
        int i = 0, n = s.size();
        long long result = 0; // use long long to prevent overflow during calculation
        int sign = 1;

        //Ignore leading whitespaces
        while (i < n && s[i] == ' ')
            i++;

        //Check for sign
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-')
                sign = -1;
            i++;
        }

        //Read digits and convert to integer
        while (i < n && isdigit(s[i])) {
            result = result * 10 + (s[i] - '0');

            //Handle overflow
            if (result * sign <= INT_MIN) return INT_MIN;
            if (result * sign >= INT_MAX) return INT_MAX;

            i++;
        }

        return (int)(result * sign);
    }
};