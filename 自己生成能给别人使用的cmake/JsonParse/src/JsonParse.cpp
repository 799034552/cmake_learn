#include<JsonParse/JsonParse.h>
#include<sstream>
#include<iostream>
#include<assert.h>
#include <stdexcept>
namespace jp
{
    using std::runtime_error;
    bool JsonParse::parse(const string &s) {
        string back_s = "", key = "", str_val = "";
        std::istringstream json_stream(s);
        char c;
        float float_val;
        while(json_stream >> c) {
            if (c == '\"'){
                std::getline(json_stream, key, '\"');
                json_stream >> c; // Skip ':'
                json_stream >> c;

                if (c == '\"') {
                    std::getline(json_stream, str_val, '\"');
                    string_map[key] = {0, str_val};
                } else {
                    json_stream.putback(c);
                    json_stream >> float_val;
                    string_map[key] = {float_val, ""};
                }
            }
        }
        return true;
    }

    TargetVal JsonParse::get(const string &s) {
        if (string_map.count(s) != 0)
            return string_map[s];
        throw runtime_error("can't found key");
    }
}
