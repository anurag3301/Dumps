#include <curlpp/cURLpp.hpp>
#include <curlpp/Options.hpp>
#include <sstream>
#include <iostream>
using std::cout, std::endl;


curlpp::Cleanup myCleanup;

int main(){
    std::ostringstream os;
    os << curlpp::options::Url(std::string("http://example.com"));

    std::string asAskedInQuestion = os.str();
    cout << asAskedInQuestion << endl; 
}
