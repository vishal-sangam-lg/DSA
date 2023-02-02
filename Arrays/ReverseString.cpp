// https://www.geeksforgeeks.org/write-a-program-to-reverse-an-array-or-string/
// Approach: Traverse LTR till midpoint and swap(str[i], str[n-i-1])
// TC: O(n)
// SC: O(1)

#include<iostream>
using namespace std;

string reverseWord(string str);

int main() {
	string reversed = reverseWord("Hello World");
	cout << reversed << endl;
	return 0;
}

string reverseWord(string str){
    int length = str.length();
    for(int i = 0; i < length/2; i++) {
        swap(str[i], str[length - i - 1]);
    }
    return str;
}