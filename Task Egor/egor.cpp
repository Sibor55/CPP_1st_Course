#include <iostream>
#include <string>

template <typename T, class... Args>
void print(const T& x, Args... args) {
    std::cout << x;
    ((std::cout << args), ...);
    std::cout << std::endl;
}
std::string func(std::string html){
    std::size_t fsttagnum = html.find('<');
    std::size_t taglen;
    std::string tagname;
    
    if (fsttagnum != std::string::npos) {
        for (size_t i = fsttagnum + 1; i < html.size(); i++) {
            if (html[i] == '>') {
                taglen = i - fsttagnum;
                tagname = html.substr(fsttagnum + 1, taglen - 1);
                break;
            }
        }
        
        std::size_t sctagnum = html.find("</" + tagname + ">");
        std::string funcstart = tagname + "(";
        html.replace(fsttagnum, tagname.size() + 2, funcstart);
        html.replace(sctagnum - 1, tagname.size() + 3, ")");
    }
    
    return html;
}
int main() {
    
    std::string html = "<element>ab<element1>ba<element2>cb</element2></element1></element>";

    while (html.find('<')!= std::string::npos)
    {
        html = func(html);
    }
    
    print(html);
    return 0;
}