//
// Created by kolya on 04.12.18.
//

#include <bits/stdc++.h>
#include "../src/process.h"
using namespace std;
string convert_to_binary(unsigned char c){
    string res;
    for(int i=0; i<8;++i){
        if (c&(1<<i)){
            res+='1';
        }
        else{
            res+='0';
        }
    }
    reverse(res.begin(),res.end());
    return res;
}

int main(){

    {
        string input = "R1 += R2 format 16;";
        std::stringstream ss{input};
        auto processed = process_assembly_code(ss);
        auto ccc=  convert_to_binary(processed[0]);
        cout<<ccc;
        assert( ccc== "010000100010");
    }
}
