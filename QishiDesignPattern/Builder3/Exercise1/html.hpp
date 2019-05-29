//
//  html.hpp
//  QishiPatternDesign
//
//  Created by Qiushi Li on 5/27/19.
//  Copyright © 2019 Qiushi Li. All rights reserved.
//

#ifndef html_hpp
#define html_hpp

#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class htmlBase
{
protected:
    string tag;
    string text;
    vector<htmlBase> element;

public:
    htmlBase() {}
    htmlBase(const string& tag, const string& text);
    string expr(int indenture = 0) const;
};


class htmlBuilder : public htmlBase
{
public:
    htmlBuilder(const string root_tag);
    
    htmlBuilder& add_child(const string child_tag, const string child_text);
    
};

#endif /* html_hpp */
