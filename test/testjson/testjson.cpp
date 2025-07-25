#include "json.hpp"
using json = nlohmann::json;
#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

//json序列化示例1
string func1()
{
    json js;
    js["msg_type"] = 2;
    js["from"] = "zhang san";
    js["to"] = "li si";
    js["msg"] = "hello, what are you doing now?";

    cout<<js<<endl;

    string sendBuf = js.dump();
    //cout<<sendBuf.c_str()<<endl;

    return sendBuf;
}

//json序列化示例2
string func2()
{
    json js;
    // 添加数组
    js["id"] = {1,2,3,4,5};
    // 添加key-value
    js["name"] = "zhang san";
    // 添加对象
    js["msg"]["zhang san"] = "hello world";
    js["msg"]["liu shuo"] = "hello china";
    // 上面等同于下面这句一次性添加数组对象
    js["msg"] = {{"zhang san", "hello world"}, {"liu shuo", "hello china"}};

    //cout << js << endl;
    return js.dump();
}

//json序列化示例3
void func3()
{
    json js;
    // 直接序列化一个vector容器
    vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(5);
    js["list"] = vec;
    // 直接序列化一个map容器
    map<int, string> m;
    m.insert({1, "黄山"});
    m.insert({2, "华山"});
    m.insert({3, "泰山"});
    js["path"] = m;
    cout<<js<<endl;
}

int main()
{
    string revBuf = func2();
    // 数据的反序列化 json字符串 -> 数据对象(看作容器) 
    json jsBuf = json::parse(revBuf);
    // cout<<jsBuf["msg_type"]<<endl;
    // cout<<jsBuf["from"]<<endl;
    // cout<<jsBuf["to"]<<endl;
    // cout<<jsBuf["msg"]<<endl;

    cout<<jsBuf["id"]<<endl;
    auto arr = jsBuf["id"];
    cout<<arr[2]<<endl;

    auto msgjs = jsBuf["msg"];
    cout<<msgjs["zhang san"]<<endl;
    cout<<msgjs["liu shuo"]<<endl;

    return 0;
}

