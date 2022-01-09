#include <string>
#include <vector>

using namespace std;

string step1(string id){
    for (auto &ch: id) 
        ch = tolower(ch);
    
    return id;
}

string step2(string id){
    string rtn = "";
    
    for (auto ch: id){
        if (isalnum(ch) || ch == '-' || ch == '_' || ch == '.')
            rtn += ch;
    }
    
    return rtn;
}

string step3(string id){
    string rtn = "";
    
    for (int i = 0; i < id.length(); i++){
        rtn += id[i];
        
        if (id[i] == '.'){
            while (id[++i] == '.'){}
            i--;
        }
    }
    
    return rtn;
}

string step4(string id){
    if (id.front() == '.')
        id = id.substr(1);
    if (id.back() == '.')
        id.pop_back();
    
    return id;
}

string step5(string id){
    if (id.empty())
        return "a";
    else
        return id;
}

string step6(string id){
    if (id.length() > 15)
        return step4(id.substr(0, 15));
    else
        return id;
}

string step7(string id){
    while (id.length() < 3)
        id += id.back();
    
    return id;
}

string solution(string new_id) {
    new_id = step1(new_id);
    new_id = step2(new_id);
    new_id = step3(new_id);
    new_id = step4(new_id);
    new_id = step5(new_id);
    new_id = step6(new_id);
    new_id = step7(new_id);
    
    return new_id;
}