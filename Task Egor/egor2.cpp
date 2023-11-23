#include <iostream>
#include <regex>
#include <string>


int main(){


    std::string html = "<element>ab<element1>ba<element2>cb</element2></element1></element>";
    regex start_tag_re("<+[a-zA-Z0-9]+>");
    regex end_tag_re('</+[a-zA-Z0-9]+>');
    

    return 0;
}