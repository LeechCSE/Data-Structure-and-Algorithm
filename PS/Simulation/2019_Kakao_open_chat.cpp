#include <string>
#include <vector>
#include <map>

using namespace std;

struct Message{
    string op, id, nn;
};

Message split(string r){
    Message msg;
    size_t op_pos = r.find(' ');
    msg.op = r.substr(0, op_pos);
    size_t id_pos = r.find(' ', op_pos + 1);
    msg.id = r.substr(op_pos + 1, id_pos - op_pos - 1);
    msg.nn = r.substr(id_pos + 1);
    
    return msg;
}

vector<string> solution(vector<string> record) {
    vector<string> answer;
    map<string, string> nickname;
    vector<Message> message;
    
    for (auto r: record){
        Message msg = split(r);
        message.emplace_back(msg);
        if (msg.op != "Leave")
            nickname[msg.id] = msg.nn;
    }
    
    for (auto msg: message){
        if (msg.op == "Enter")      
			  answer.emplace_back(nickname[msg.id] + "님이 들어왔습니다.");
        else if (msg.op == "Leave") 
			  answer.emplace_back(nickname[msg.id] + "님이 나갔습니다.");
    }
    
    return answer;
}