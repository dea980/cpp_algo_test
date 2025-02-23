#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string n_str){
    return stoi(n_str);
}

int main(){
    string n_str = "123";
    cout << solution(n_str) << endl;

    vector<string> n_str_list;
    n_str_list.push_back("123");
    n_str_list.push_back("456");
    n_str_list.push_back("789");
    vector<int> result = solution(n_str_list);
    for (auto& n : result){
        cout << n << " ";
    }
    cout << endl;

    return 0;
}

vector<int> solution(vector<string> n_str_list){
    vector<int> result;
    for (auto& n_str : n_str_list){
        result.push_back(stoi(n_str));
    }
    sort(result.begin(), result.end());
    return result;

    // For descending order:
    // sort(result.begin(), result.end(), greater<int>());
}


int main(){
    string n_str = "123";
    cout << solution(n_str) << endl;

    vector<string> n_str_list;
    n_str_list.push_back("123");
    n_str_list.push_back("456");
    n_str_list.push_back("789");
    vector<int> result = solution(n_str_list);
    for (auto& n : result){
        cout << n << " ";
    }
    cout << endl;

    return 0;
}

