#include <bits/stdc++.h>
using namespace std;

int main() {

    vector<string> log_lines = {"1641060000, judy, 138.174.23.121, CreateResource, /isospondylous/fecundity/unsweetness/achkan, 308", 
 "1641060001, judy, 138.174.23.121, SwitchUser, /user/wendy, 200", 
 "1641060001, carol, 149.82.23.194, GetResource, /admin/another/thing, 300", 
 "1641060002, victor, 234.40.180.202, DecryptResource, /bewrayers/kieselgur/fascinatress, 302", 
 "1641060003, trudy, 191.134.32.174, UpdateResource, /admin/sensitive, 301", 
 "1641060004, michael, 156.38.249.189, SwitchUser, /user/michael, 200"};

    vector<string> people;
    for(int i = 0; i < log_lines.size(); i++){
        int result = stoi(log_lines[i].substr(log_lines[i].size()-3,3));
        string name = "";
        int j = 0;
        int finded = 0;
        cout << log_lines[i].find("admin") << endl;
        
        if(log_lines[i].find("admin") < log_lines.size() &&  result < 400 && result >= 200){
            while(true){
                if(log_lines[i][j] == ','){
                    finded++;
                    j+=2;
                    //people.pop_back();
                }
                if(finded > 0 && finded < 2){
                    name = name + log_lines[i][j];
                }
                if(finded == 2){
                    people.push_back(name);
                    finded = 0;
                    j = 0;
                    name = "";
                    break;
                    }
                
                j++;
            }
            
        }
    }

}