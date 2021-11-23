#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <cmath>

using namespace std;

int solution(string dartResult) {
    int answer = 0;
    
    vector<double> operand(3);
    vector<double> power(3);
    vector<int> mul(3);
    int id = 2;
    
    for (auto it = dartResult.rbegin(); it != dartResult.rend(); it++){
        if (isdigit(*it)){ // operand
            if (isdigit(*next(it))){ // 10
                operand[id] = 10;
                advance(it, 1);
            }
            else // 0 ~ 9
                operand[id] = *it - '0';
            
            id--;
        }
        else if (isalpha(*it)){ // power
            if (*it == 'S')         power[id] = 1;
            else if (*it == 'D')    power[id] = 2;
            else if (*it == 'T')    power[id] = 3;
        }
        else{ // multiplier
            if (*it == '*'){
                int id_cp = id;
                while (id_cp >= 0 && id - id_cp <= 1){
                    mul[id_cp] += 2;
                    id_cp--;
                }
            }
            else if (*it == '#'){
                if (mul[id] == 0)
                    mul[id] = -1;
                else
                    mul[id] *= -1;
            }
        }
    }
    
    for (int i = 0; i < 3; i++){
        mul[i] = mul[i] == 0 ? 1 : mul[i];
        answer += pow(operand[i], power[i]) * mul[i];
    }
    
    return answer;
}