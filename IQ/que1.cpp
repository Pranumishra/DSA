// 1.	Tag Identification Number
// You're given a string containing a list of digits. 
// You must make as many IDs of the format 8xxxxxxxxxx (an 8 followed by 10 digits) as possible.
//  Return the number of IDs you can make. The IDs do not have to be unique, and you may rearrange the digits, but you may only use each digit once.

#include <iostream>
#include <string>
using namespace std;

int numOfIds(const string &pool) {
    int len = pool.size();
    int max_ids_by_length = len / 11;
    int count_of_eights = 0;

    // Count occurrences of '8' in the string
    for (char ch : pool) {
        if (ch == '8') {
            count_of_eights++;
        }
    }

    // Return the minimum of the count of '8's and complete 11-digit groups possible
    return min(count_of_eights, max_ids_by_length);
}

int main() {
    string pool;
    cout << "Enter the pool of digits: ";
    cin >> pool;

    int result = numOfIds(pool);
    cout << "Number of possible IDs: " << result << endl;
    return 0;
}