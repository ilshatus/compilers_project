//
// Created by kolya on 04.12.18.
//
#include <string>
#include <algorithm>
#include <sstream>
#include <cassert>
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
        string input= "R1 >>= R2 format 8;";

        std::stringstream ss{input};
        auto processed = process_assembly_code(ss);

        string ccc = "";
        for(char c:processed) {
            ccc += convert_to_binary(c);
        }
        cout<<"now it is"<<ccc<<endl;
        string coc = "00000000"
                     "00000000"
            +string(32,'0')+
            "00"+"01110001000001"
            +string(16,'0');
        cout<<"expected "<<coc<<endl;
        assert(coc==ccc);
    }

}