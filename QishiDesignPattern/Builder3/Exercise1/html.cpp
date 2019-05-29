//
//  html.cpp
//  QishiPatternDesign
//
//  Created by Qiushi Li on 5/27/19.
//  Copyright © 2019 Qiushi Li. All rights reserved.
//

#include "html.hpp"

htmlBase :: htmlBase(const string& tag, const string& text) : tag(tag), text(text){}
    
string htmlBase :: expr(int indenture) const
{
    stringstream ss;
    ss << string(indenture, ' ') << '<' << tag << '>' << endl;
    if(text.size() > 0)
        ss << string(indenture+2, ' ') << text << endl;
    for(const auto& e : element)
        ss << e.expr(indenture+2);
    
    ss << string(indenture, ' ') << "</" << tag << '>' << endl;
    return ss.str();
}

htmlBuilder :: htmlBuilder(const string root_tag){tag = root_tag;}

htmlBuilder& htmlBuilder :: add_child(const string child_tag, const string child_text)
{
    htmlBase e{child_tag, child_text};
    element.push_back(e);
    return *this;
}
