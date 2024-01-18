#pragma once
#include<string>
#include<unordered_map>
namespace jp {
    using std::string;
    using std::unordered_map;
    // 定义返回的类型
    struct TargetVal {
        float i;
        string s;
    };
    // 定义解释器类
    class JsonParse {
        private:
            string raw_str;
            unordered_map<string, TargetVal> string_map;
        public:
            JsonParse() = default;
            JsonParse(const string &s){ parse(s); };
            bool parse(const string &s);
            
            TargetVal get(const string &s);
   };
}