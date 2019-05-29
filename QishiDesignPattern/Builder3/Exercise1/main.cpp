//
//  main.cpp
//  QishiPatternDesign
//
//  Created by Qiushi Li on 5/27/19.
//  Copyright © 2019 Qiushi Li. All rights reserved.
//

#include <stdio.h>
#include "html.hpp"

int main()
{
    string text = "hello";
    string tag = "p";
    
    htmlBase h = htmlBase(tag, text);
    cout << h.expr() << endl;
    
    htmlBuilder h1{"ul"};
    h1.add_child("li", "12").add_child("li", "32");
    cout << h1.expr() << endl;
    
    return 0;
}
