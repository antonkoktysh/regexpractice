#include <iostream>
#include <string>
#include <regex>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    string code = R"(
        // This is a comment
        int main() {
            cout << "Hello, world!" << endl; // Another comment
            return 0;
        }
        /*
            This is a
            multiline comment
        */
    )";

    cout << "Before deleting: ";
    cout << code << endl;

    // Define regex pattern to match comments
    regex pattern(R"((\/\/[^\n]*|\/\*[\s\S]*?\*\/))");

    // Remove all comments from the code
    string result = regex_replace(code, pattern, "");

    // Print the result
    cout << "After deleting: ";
    cout << result << endl;

    return 0;
}
