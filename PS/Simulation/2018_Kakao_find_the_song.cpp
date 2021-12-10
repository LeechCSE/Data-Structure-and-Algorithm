#include <string>
#include <vector>

using namespace std;

struct Info{
    int play_time;
    string title, note;
};

int to_time(string s){ return stoi(s.substr(0, 2)) * 60 + stoi(s.substr(3, 2)); }
int get_play_time(string start, string end){ return to_time(end) - to_time(start); }
int get_play_time(string note){
    int play_time = 0;
    for (auto it = note.begin(); it != note.end(); it++){
        if (*next(it) == '#') it++;
        play_time++;
    }
    
    return play_time;
}

Info split(string m){
    Info rtn;
    // play time
    rtn.play_time = get_play_time(m.substr(0, 5), m.substr(6, 5));
    // title
    size_t pos = m.find(',', 12);
    rtn.title = m.substr(12, pos - 12);
    // all played notes for play time
    int play_time = rtn.play_time;
    string score = m.substr(pos + 1);
    int cur = 0;
    while (play_time != 0){
        if (cur >= score.length())
            cur = 0;
        
        rtn.note += score[cur];
        if (!(score[cur] == 'E' || score[cur] == 'B')){
            if (score[cur + 1] == '#'){
                rtn.note += score[cur + 1];
                cur++;
            }
        }
        cur++;
        play_time--;    
    }
    
    return rtn;
}

string solution(string m, vector<string> musicinfos) {
    string answer = "(None)";
    int longest = 0;
    int play_time = get_play_time(m);
    
    for (auto music: musicinfos){
        Info info = split(music);

        if (play_time > info.play_time)
            continue;
        
        size_t found = info.note.find(m);
        while (found != string::npos){
            if (info.note[found + m.length()] != '#'){
                if (longest < info.play_time){
                    answer = info.title;
                    longest = info.play_time;
                }
                break;
            }
            else
                found = info.note.find(m, found + 1);
        }
    }
    
    return answer;
}