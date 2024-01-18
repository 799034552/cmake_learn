#include<Request/Request.h>

namespace rq
{
    int Request::request_times = 1;
    string Request::get() {
        return R"({"name":"xiaohong", "age":18})";
    }
    jp::JsonParse Request::get_json() {
        return R"({"name":"xiaohong", "age":18})"; 
    }
    string Request::post(){
        return R"({"name":"xiaogang", "age":20})";
    }
    jp::JsonParse Request::post_json(){
        return R"({"name":"xiaogang", "age":20})";
    }
}
