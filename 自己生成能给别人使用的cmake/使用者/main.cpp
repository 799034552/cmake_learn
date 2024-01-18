#include<iostream>
#include<string>
#include<JsonParse/JsonParse.h>
using namespace std;

int main() {
    string a = R"({"name":"xiaohong", "age":18})";
    jp::JsonParse my_json(a);
    cout<<my_json.get("name").s<<endl;
}