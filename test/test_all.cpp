//
// Created by kolya on 05.12.18.
//

#include <iostream>
#include "../src/process.h"
using namespace std;
#include <algorithm>
#include <sstream>
#include <cassert>
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

void process_add(){

    {
        string input= "R1 += R2 format 16;";

        std::stringstream ss{input};
        auto processed = process_assembly_code(ss);

        string ccc = "";
        for(char c:processed){
            ccc += convert_to_binary(c);
        }
        cout<<"now it is"<<ccc<<endl;
        string coc = "00000000"
                     "00000000"
            +string(32,'0')+
            "0101010001000001"
            +string(16,'0');
        cout<<"expected "<<coc<<endl;
        assert(coc==ccc);
    }

}

void process_and(){

    {
        string input= "R1 &= R2 format 16;";

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
            "01"+"10100001000001"
            +string(16,'0');
        cout<<"expected "<<coc<<endl;
        assert(coc==ccc);
    }

}
void process_asl(){

    {
        string input= "R1 <<= R2 format 8;";

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
            "00"+"10000001000001"
            +string(16,'0');
        cout<<"expected "<<coc<<endl;
        assert(coc==ccc);
    }

}
void process_asr(){

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
void process_cbr(){

    {
        string input= "if R1 goto R2;";

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
            "1111110000100010"
            +string(16,'0');
        cout<<"expected "<<coc<<endl;
        assert(coc==ccc);
    }

}
void process_cnd(){

    {
        string input= "R1 ?= R2 format 8;";

        std::stringstream ss{input};
        auto processed = process_assembly_code(ss);

        string ccc = "";
        for(char c : processed) {
            ccc += convert_to_binary(c);
        }
        cout<<"now it is"<<ccc<<endl;
        string coc = "00000000"
                     "00000000"
            +string(32,'0')+
            "00"+"11100001000001"
            +string(16,'0');
        cout<<"expected "<<coc<<endl;
        assert(coc==ccc);
    }

}
void process_label(){

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
                     "00"  "00100001000010"  "00000000000000000000000000000010"
            +string(16,'0');
        cout<<"expected "<<coc<<endl;
        assert(coc==ccc);
    }

}
void process_ld(){

    {
        string input= "R1 := *R2;";

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
            "11" + "00010001000001"
            +string(16,'0');
        cout<<"expected "<<coc<<endl;
        assert(coc==ccc);
    }

}
void process_lda(){

    {
        string input= "R1 := R2 + -5;";

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
            "00" + "00100001000001" + "11111111111111111111111111111011"
            +string(16,'0');
        cout<<"expected "<<coc<<endl;
        assert(coc==ccc);
    }

}
void process_ldc(){

    {
        string input= "R1 := 31;";

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
            "11" + "00101111100001"
            +string(16,'0');
        cout<<"expected "<<coc<<endl;
        assert(coc==ccc);
    }

}
void process_lsl(){

    {
        string input= "R1 <= R2 format 8;";

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
            "00"+"11000001000001"
            +string(16,'0');
        cout<<"expected "<<coc<<endl;
        assert(coc==ccc);
    }

}
void process_lsr(){

    {
        string input= "R1 >= R2 format 32;";

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
            "11"+"11010001000001"
            +string(16,'0');
        cout<<"expected "<<coc<<endl;
        assert(coc==ccc);
    }

}
void process_mov(){

    {
        string input= "R1 := R2 format 16;";

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
            "01" + "01000001000001"
            +string(16,'0');
        cout<<"expected "<<coc<<endl;
        assert(coc==ccc);
    }

}
void process_or(){

    {
        string input= "R1 |= R2 format 16;";

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
            "01"+"10010001000001"
            +string(16,'0');
        cout<<"expected "<<coc<<endl;
        assert(coc==ccc);
    }

}void process_st(){

    {
        string input= "*R1 := R2;";

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
            "11" + "00110001000001"
            +string(16,'0');
        cout<<"expected "<<coc<<endl;
        assert(coc==ccc);
    }

}
void process_sub(){

    {
        string input= "R1 -= R2 format 16;";

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
            "01" + "01100001000001"
            +string(16,'0');
        cout<<"expected "<<coc<<endl;
        assert(coc==ccc);
    }

}
void process_xor(){

    {
        string input= "R1 ^= R2 format 8;";

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
            "00"+"10110001000001"
            +string(16,'0');
        cout<<"expected "<<coc<<endl;
        assert(coc==ccc);
    }

}

int main(){
    process_add();
    process_and();
    process_asl();
    process_asr();
    process_cbr();
    process_cnd();
    process_label();
    process_ld();
    process_lda();
    process_ldc();
    process_lsl();
    process_lsr();
    process_mov();
    process_or();
    process_st();
    process_sub();
    process_xor();
    return 0;
}