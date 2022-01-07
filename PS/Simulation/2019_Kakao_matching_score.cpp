#include <string>
#include <vector>
#include <map>

using namespace std;

string parse(string page, string s_target, string e_target, size_t start = 0){
    size_t s_pos = page.find(s_target, start);
    s_pos += s_target.length();
    size_t e_pos = page.find(e_target, s_pos);
    
    return page.substr(s_pos, e_pos - s_pos);
}

vector<string> parse_links(string body){
    vector<string> rtn;
    
    string s_target = "<a href=\"https://";
    string e_target = "\"";
    
    size_t before = 0;
    while (true){
        size_t s_pos = body.find(s_target, before);
        if (s_pos == string::npos)
            break;
        
        s_pos += s_target.length();
        size_t e_pos = body.find(e_target, s_pos);
        before = e_pos;
        
        rtn.emplace_back(body.substr(s_pos, e_pos - s_pos));
    }
    
    return rtn;
}

string parse_text(string body){
    string rtn = "";
    
    size_t before = 0;
    while (true){
        size_t found = body.find("<a", before);
        if (found == string::npos){
            rtn += body.substr(before);
            break;
        }
        
        rtn += body.substr(before, found - before);
        before = body.find("</a>", found);
    }
    
    return rtn;
}

int base_score(string word, string body, bool no_link = false){
    int rtn = 0;
    
    string text;
    if (no_link)    text = body;
    else            text = parse_text(body);
    
    for (char &ch: text) ch = tolower(ch);
    for (char &ch: word) ch = tolower(ch);
    
    size_t before = 0;
    while (true){
        size_t pos = text.find(word, before);
        if (pos == string::npos) break;
        
        if (!isalpha(text[pos + word.length()]) && !isalpha(text[pos - 1]))
            rtn++;
        
        before = pos + 1;
    }
    
    return rtn;
}

int solution(string word, vector<string> pages) {
    int answer = 0;
    
    vector<string> list; // list of URLs
    map<string, int> link_count; // url: #out-going links
    map<string, vector<string>> link_map; // url: [links toward url ...]
    map<string, int> b_score; // url: base score
    
    for (int i = 0; i < pages.size(); i++){
        string page = pages[i];
        
        string id = parse(page, "https://", "\"", page.find("<meta property=\"og:url\""));
        string body = parse(page, "<body>", "</body>");
        vector<string> links = parse_links(body);
        
        list.emplace_back(id);
        link_count[id] = links.size();
        for (auto l: links) link_map[l].emplace_back(id);
        b_score[id] = base_score(word, body, links.empty());
    }
    
    double max = 0.0;
    for (int i = 0; i < list.size(); i++){
        string id = list[i];
        
        double tot = b_score[id];
        for (auto neighbor: link_map[id])
            tot += (double) b_score[neighbor] / (double)link_count[neighbor];
        
        if (max < tot){
            max = tot;
            answer = i;
        }
    }
    
    return answer;
}