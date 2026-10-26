#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<string, int> phoneBook;

bool isPrefix(const string& phoneNumber)
{
    string prefix = "";
    for (char digit : phoneNumber)
    {
        prefix += digit;
        if (phoneBook.find(prefix) != phoneBook.end() && prefix != phoneNumber)
        {
            return true;
        }
    }
    
    return false;
}

bool solution(vector<string> phone_book) {
    for (const string& phoneNumber : phone_book)
    {
        phoneBook[phoneNumber] = 1;
    }
    
    for (const string& phoneNumber : phone_book)
    {
        if (isPrefix(phoneNumber))
        {
            return false;
        }
    }
    
    return true;
}