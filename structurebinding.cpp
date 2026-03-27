// structurebinding.cpp
// Explained by Kiran on 2026-03-01
// This code demonstrates the use of structured bindings in C++17 to unpack pairs from a vector and to retrieve the top student score using an optional return type.

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
    {"Kiran", 50},
    {"Marc", 80}
};

                   
optional<pair<string, int>> getTopStudentScore()
{

    if (studentScores.empty())
        return std::nullopt;

    cout << "Finding top students...\n";
    
    auto result = std::max_element(
        studentScores.begin(),
        studentScores.end(),
        [](const auto& s1, const auto& s2)
        {
            return s1.second < s2.second;
        }
    );
    
    return *result;
}

int main()
{

    for (const auto& [id, name] : users){
        cout << "User: " << name << " (ID: " << id << ")\n";
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