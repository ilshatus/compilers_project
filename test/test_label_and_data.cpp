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
        string input= "<SIZE>\n"
                      "DATA 3;\n"
                      "R2 := ARRAY;\n"
                      "<ARRAY>\n"
                      "DATA 1, 2;";

        std::stringstream ss{input};
        auto processed = process_assembly_code(ss);

        string ccc = "";
        for(char c:processed) {
            ccc += convert_to_binary(c);
        }
        cout<<"now it is"<<ccc<<endl;
        string coc = "00000000"  "00000000" "00000000000000000000000000000110"
                     "00000000000000000000000000000011"
                     "00000000000000000000000000000001"
                     "00000000000000000000000000000010"
                     "11"  "00100000000010"
                     "00"  "00100001000010"  "00000000000000000000000000000001"
                     +string(16,'0');
        cout<<"expected "<<coc<<endl;
        assert(coc==ccc);
    }

}