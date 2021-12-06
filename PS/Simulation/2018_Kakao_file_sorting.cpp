#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

vector<string> split(string file){
    vector<string> tokens(3, "");
    auto number_start_it = find_if(file.begin(), file.end(), 
                                   [](char ch){ return isdigit(ch); });
    auto number_end_it = find_if(number_start_it, file.end(), 
                                 [](char ch){ return !isdigit(ch); });
    int num_start_pos = distance(file.begin(), number_start_it);
    int num_end_pos = distance(file.begin(), number_end_it);
    auto non_zero_start_it = find_if(number_start_it, number_end_it, 
                                     [](char ch){ return ch != '0'; });
    int non_zero_start_pos = non_zero_start_it == number_end_it ? 
        num_end_pos : distance(file.begin(), non_zero_start_it);
    
    for (int i = 0; i < num_start_pos; i++) // head
        tokens[0] += tolower(file[i]);
    for (int i = non_zero_start_pos; i < num_end_pos; i++) // number
        tokens[1] += file[i];
    if (tokens[1].size() == 0) tokens[1] += '0';
    for (int i = num_end_pos; i < file.length(); i++) // tail
        tokens[2] += file[i];
    
    return tokens;
}

vector<string> solution(vector<string> files) {
    stable_sort(files.begin(), files.end(), [](string f1, string f2){
        vector<string> tokens1 = split(f1); // tokens: HEAD, NUMBER, TAIL
        vector<string> tokens2 = split(f2);
        
        if (tokens1[0] == tokens2[0]){
            string num1 = tokens1[1];
            string num2 = tokens2[1];
            
            if (num1.length() == num2.length()) return num1 < num2;
            return num1.length() < num2.length();
        }
        
        return tokens1[0] < tokens2[0];
    });
    
    return files;
}