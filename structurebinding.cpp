// structurebinding.cpp

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <optional>

using namespace std;

vector<pair<int, string>> users {
    {1, "Kiran"},
    {2, "Michel"}
};

vector<pair<string, int>> studentScores {
    {"Michel", 5},
    {"Kiran", 10}
};

                   
optional<pair<string, int>> getTopStudentScore()
{
    auto begin = std::begin(studentScores);
    auto end   = std::end(studentScores);

    if (begin == end)
        return std::nullopt;

    auto result = std::max_element(begin, end,
        [](const pair<string, int>& s1, const pair<string, int>& s2)
        {
            return s1.second < s2.second;
        });

    return *result;
}

int main()
{
    for (const auto& [id, name] : users){
        cout << id << " " << name << endl;
    }    

    if (auto topStudent = getTopStudentScore(); topStudent.has_value()) {
        auto [name, score] = *topStudent;
        cout << "Top student: "
             << name
             << " Score: "
             << score
             << endl;
    } else {
        cout << "No students found." << endl;
    }
    return 0;
}