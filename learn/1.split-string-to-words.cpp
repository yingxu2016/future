#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <iterator>
//#include <boost/algorithm/string.hpp>

using namespace std;

vector<string> split(const string& s, char delimiter)
{
    vector<string> tokens;
    string token;
    istringstream tokenStream(s);
    while (getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

int main(int args, char **argv) {

    /*
     * Using iterator to split string into words
     */
    string text = " Let me   split this    into   words!";
    istringstream iss1(text);
    vector<string> results(istream_iterator<string> {iss1},
                           istream_iterator<string>());
    for(auto i : results) {
        cout << i << " ";
    }
    cout << endl;

    /*
     * Using istringstream to split string into words
     */
    vector<string> vs;
    istringstream iss2;
    text = "     Hello      world!   This   is Ziqi    ";
    iss2.str(text);
    string tmp;
    while(iss2 >> tmp) {
        vs.push_back(tmp);
    }
    for(auto i : vs) {
        cout << i << " ";
    }
    cout << endl;

    /*
     * Using getline to split string into words
     * and the delimiter can be other things than whitespace
     * Note: the split can only deal with specific whitespace.
     *       If there are variadic whitespaces between each words, split cannot work
     */
    text = "Let,me,split,this,into,words,AGAIN!";
    vector<string> vs1 = split(text, ',');
    for(auto i : vs1) {
        cout << i << " ";
    }
    cout << endl;

    /*
     * Using boost to split string into words
     * Note: <boost/algorithm/string.hpp> must be accessible
     */
    /*
    string text = "Let me split this into words";
    vector<std::string> results;
    boost::split(results, text, [](char c){return c == ' ';});
    */

    return 0;
}

