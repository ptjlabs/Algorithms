//----------------------------------------------------------------------------------------------------------------------------------
/*
Table of Contents
1. Given an array of integers, every element appears twice except for two. Output both elements. T(n) = O(n), S(n) = O(1)
2. Check if a number is a power of 2, T(n) = O(1), S(n) = O(1)
3. Count first occurence of leading 1 in a variable (Qualcomm interview), T(n) = O(n), S(n) = O(1)
//----------------------------------------------------------------------------------------------------------------------------------
#include <bitset> 

bitset<numberOfBits> b;
b.count(); // number of 'set' bits (bits that are true)
b.size(); // number of bits allocated for bitset
bool is2True = b.test(2); // returns if bit at location '2' from 0th-index is true.
bool isAnyBitSet = b.any(); // returns true if any bit is true
bool isNoBitSet = b.none(); // returns true if all bits are false
bool allBitSet = b.all(); // returns true if all bits are set. 
b[2] = true; // set bit at position 2 to true
b[2] = false; // set bit at position 2 to false
//-------------------------------------------
TODO: 
5. Write function to determine number of bit swap required to convert integer A to integer B
4. Write program to swap odd and even bits in an interger with the fewest instructions (O(1))
// e.g. bit 0 and bit 1 swapped, bit 2 and bit 3 swapped
HARD: 6. SingleNumberII: Given an array of 3n + 1 elements, where n of elements are repeated thrice each, and 1 element is different from the rest. Identify that one element.
7. SingleNumberIII: Given an array of kn + 1 elements, where n of elements are repeated k times each, k > 1, and 1 element is different from the rest. Identify that one element.
    Create an array of 32/64 slots. 
    Add each 1 bit separately in each array slots. 
    Then mod each array slot by k. If remainder is NOT 0, then that bit has to be a 1 in the special element. 
    Then, output that special element from the arrays. 
8. 
The gray code is a binary numeral system where two successive values differ in only one bit.
Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0.
For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:
00 - 0
01 - 1
11 - 3
10 - 2
    hint: Go forwards, then when end, append a 1, and go backwards, all the way, needs some form of recursion. 
    betterHint: BinaryToGrey => (num>>1 ^ num)

10: Implement Swap() function on integers using just bit operators: 
    Hint: XOR 
// */
//----------------------------------------------------------------------------------------------------------------------------------
// 1 Given an array of integers, every element appears twice except for two. Output both elements . T(n) = O(n), S(n) = O(1)
/*
Questions:
    Are the inputs sorted already? No 
    Can the original vector be modified? 
    Is there a limit to the number of integers given? No
    Can the integers be (-) ? Yes
    How large can the integers be? (use counting sort and then can do a pass with O(n) timing.)
        As large as can be represented in memory 
    Can the same number appear 2z times instead of twice? where z is an integer > 0	
        Yes
Test cases: 
    [2, 3, 2, 5, 3, 6] = [5, 6]
    [3,7] = [3, 7]
*/
//---------------------------------
/* //
#include <vector> 
#include <iostream> 
using namespace std;
 
int firstLeadingOne(int value)
{
    if (value == 0) return -1;
    int shift = 0; 
	while (!(value & 0x1))
	{
		value >>= 1; 
		shift++; 
	}
    return shift;
}

vector<int> outputBothUnique(const vector<int>& arr)
{
    int both = 0; 
    for (int value : arr) both ^= value;
    // Here, as long as both numbers are different, it will xor them separately
    int shift = firstLeadingOne(both); 
    int first = 0; 
    int second = 0; 
    int andValue = 1 << shift; 
    for (int value : arr)
    {
        if (value & andValue)
            first ^= value;
        else
            second ^= value;
    }
    vector<int> result = {first, second};
    return result;
}

void printSolution(const vector<int>& arr)
{
    vector<int> result = outputBothUnique(arr);
    cout << result[0] << " " << result[1] << endl;
}

int main(void)
{
    vector<int> onlyTwo = {3,7}; // [3, 7] or [7, 3]
    vector<int> normal = {2, 3, 2, 5, 3, 6}; //  [5, 6] or [6, 5]
    printSolution(onlyTwo);
    printSolution(normal);
    return 0; 
}
// */
//----------------------------------------------------------------------------------------------------------------------------------
// 2 Check if a number is a power of 2
// Time Complexity, T(n) = O(1)
// Space Complexity, S(n) = O(1)
//---------------------------------
/*
Question:
    1. Is the number integer or float? integer, because power of 2 must be integer!
Function Prototype:
    bool powerOfTwo(int num);
TestCases:
    2,8 => True
    7 => False

Algorithm
    ((n&1 == 0) only tells you it is even, use (n&(n-1))to find if it is power of 2 (done in leetcode)
*/
//---------------------------------
/* //
#include <iostream> 
using namespace std; 

bool powerOfTwo(int num)
{
    if (num & (num-1))
        return false;
    return true;
}
int main(void)
{
    int a = 2; 
    if (powerOfTwo(a)) cout << "True" << endl; else cout << "False" << endl;
    a = 8; 
    if (powerOfTwo(a)) cout << "True" << endl; else cout << "False" << endl;
    a = 7;
    if (powerOfTwo(a)) cout << "True" << endl; else cout << "False" << endl;
    return 0; 
}
// */
//----------------------------------------------------------------------------------------------------------------------------------
// 3 Count first occurence of leading 1 in a variable (Qualcomm interview) 
// Time Complexity, T(n) = O(n)
// Space Complexity, S(n) = O(1)
//---------------------------------
/*
Questions
Function Prototype:
    int firstOccurenceLeadOne(int x);
TestCases:
    0 => 0
    1 => 1
    2 => 2
    3 => 1
    4 => 3
*/
//---------------------------------
/* //
#include <iostream> 
using namespace std; 

int firstOccurenceLeadOne(int x)
{
    int count = 0;
    if (!x) return count; // Base Case: x = 0
    count++;
    while (!(x&0x1))
    {
        x = x >> 1; // shift x by 1
        count++;
    }
    return count;
}

int main(void)
{
    cout << firstOccurenceLeadOne(0) << endl; // 0
    cout << firstOccurenceLeadOne(1) << endl; // 1
    cout << firstOccurenceLeadOne(2) << endl; // 2
    cout << firstOccurenceLeadOne(3) << endl; // 1  
    cout << firstOccurenceLeadOne(4) << endl; // 3
    return 0;
}
// */
//----------------------------------------------------------------------------------------------------------------------------------
