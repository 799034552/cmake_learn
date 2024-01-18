#include<iostream>
#include<Request/Request.h>
#include<string>
#include<math.h>
using namespace std;
int main() {
    auto req = rq::Request();
    cout<< req.get()<<endl;
    cout<<sin(10);
}