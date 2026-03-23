#include <iostream>
#include <ctime>
#include <string>

using namespace std;
int main() {
    time_t now = time(nullptr);
    string time_str = ctime(&now);
    time_str.pop_back(); // remove newline
    cout << "Hello, World! Current time: " << time_str << " ,have fun!" << endl;
    return 0;
}