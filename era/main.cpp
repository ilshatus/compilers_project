#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define pb push_back

enum TYPE{STRING,REGISTER_VALUE,EQUAL,STAR,COLON, SEMICOLON, QUESTION, PLUS,MINUS,AND};

class Operator{
    TYPE find_type(){
        TYPE res;
        if (value.length() == 0) {
            cerr <<"error 0 length operator "<<endl;
            exit(0);
        }
        else if (value.length() == 1) {
            switch ( value[0] ) {
                case ';' : res =  SEMICOLON;
                    break;
                case ':' : res =  COLON;
                    break;
                case '*' : res =  STAR;
                    break;
                case '?' : res = QUESTION;
                    break;
                case '+' : res =  PLUS;
                    break;
                case '-' : res =  MINUS;
                    break;
                case '&' : res =  AND;
                    break;
                case '=' : res =  EQUAL;
                    break;
                default: cerr <<"Error couldn't recognize operator " + value<<endl;
                exit(0);
            }
        } else {
            if ( value[0]=='R' ) {
                int number = 0;
                for(int i=1;i<value.length();++i){
                    if(value[i] <'0' || value[i]>'9'){
                        cerr<<value<<" " << "not digit in register operator "<<endl;
                        exit(0);
                    }
                    number = number * 10 + ( value[i] - '0');

                }
                if (number <0 || number >= 32 ){
                    cerr<<"register value not in range 0 31"<<endl;
                    exit(0);
                }

                res = TYPE :: REGISTER_VALUE;
                value = to_string(number);
            } else {

                cerr <<"Error couldn't recognize operator " + value<<endl;
                exit(0);
            }

        }
        return res;
    }
    TYPE type;
    string value;
public:

    Operator(string value){

        this->value = value;
        this->type = find_type();
    }

    TYPE get_type(){
        return type;
    }
    string get_value(){
        return value;
    }




};
class Instruction{

public:
    virtual bool is_this(string line){
        return true;
    }

    virtual string process(string line){
        return "Base Instruction " + line;
    }

protected:
    vector<Operator> parse(string line){
        vector<Operator> res;

        string cur = "";
        for(int i=0;i<line.size();++i){
            char ch = line[i];
            if(ch==' '){
                if(cur!="")
                    res.push_back(Operator(cur));
                cur="";
            } else if(ch=='*' || ch=='=' || ch==':' || ch==';' || ch=='?' || ch=='&' || ch=='+' || ch=='-'){
                if(cur!="")
                    res.push_back(Operator(cur));
                res.push_back(Operator(string(1,ch)));
                cur="";
            } else{
                cur.push_back(ch);
            }
        }
        if( cur.size() > 0){
            res.pb(Operator(cur));
        }

        return res;
    }


};

inline string to_binary(string value, int len){
    int val = stoi(value);
    string res = "";
    while(val > 0){
        res.pb(val%2 + '0');
        val = val / 2;
    }
    while(res.size() < len){
        res.pb('0');
    }
    return res;


}

class LDInstruction : public Instruction{

public:
    LDInstruction(){

    }
    bool is_this(string line){
        vector<Operator> vals = parse(line);
        bool flag = vals.size() == 6;

        if (flag){
            flag = flag && vals[0].get_type() == REGISTER_VALUE;
            flag = flag && vals[1].get_type() == COLON;
            flag = flag && vals[2].get_type() == EQUAL;
            flag = flag && vals[3].get_type() == STAR;
            flag = flag && vals[4].get_type() == REGISTER_VALUE;
            flag = flag && vals[5].get_type() == SEMICOLON;
        }
        return flag;

    }

    string process(string line) {
        assert(is_this(line));
        vector<Operator> vals = parse(line);
        string res = "110001";
        res = res + to_binary(vals[4].get_value(),5);
        res = res + to_binary(vals[0].get_value(),5);
        return res;

    }

};

class DefaultInstruction : public Instruction{

public:
    DefaultInstruction(){

    }

    bool is_this(string line){
        return true;
    }

    string process(string line) {
        return "Default Instruction " + line;
    }

};
void process_assemble_code(){
    vector<Instruction*> instructions;
    instructions.push_back(new LDInstruction());
    instructions.push_back(new DefaultInstruction());

    string line;
    while(getline(cin,line)){
        for(Instruction* cur : instructions){
            if( cur->is_this(line)){
                string res = cur->process(line);

                cout << res<<endl;
                break;
            }
        }
    }

}

int main() {
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);

    process_assemble_code();

    return 0;
}