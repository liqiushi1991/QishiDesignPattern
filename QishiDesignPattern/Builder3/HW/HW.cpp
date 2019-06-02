//
//  main.cpp
//  Builder
//
//  Created by Qiushi Li on 6/2/19.
//  Copyright © 2019 Qiushi Li. All rights reserved.
//
#include <string>
#include <ostream>
#include <vector>
#include <iostream>
using namespace std;


class CodeBuilder
{
    string className;
    vector<pair<string, string>> elements;
    
public:
    CodeBuilder(const string& class_name)
    {
        className = class_name;
    }
    
    CodeBuilder& add_field(const string& name, const string& type)
    {
        elements.emplace_back(make_pair(type, name));
        return *this;
    }
    
    friend ostream& operator<<(ostream& os, const CodeBuilder& obj)
    {
        os << "class " << obj.className << endl
        << "{" << endl;
        for(const auto& e : obj.elements)
        {
            os << "  " << e.first << " " << e.second << ";" << endl;
        }
        os << "};" ;
        return os;
    }
};


int main()
{
    auto cb = CodeBuilder{"Person"}.add_field("name", "string").add_field("age", "int");
    cout << cb;
}
