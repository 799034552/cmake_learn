#pragma once
#include<iostream>
#include<string>
#include<JsonParse/JsonParse.h>
namespace rq {
    using namespace std;
    class Request {
        public:
            Request() = default;
            static int request_times;
            string get();
            jp::JsonParse get_json();
            string post();
            jp::JsonParse post_json();
    };

}