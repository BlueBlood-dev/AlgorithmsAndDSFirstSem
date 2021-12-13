#include <fstream>
#include  <vector>

using namespace std;


int getHash(const string& key){
    long long h = 0;
    int k = 32;
    long long mod =  1e9+7;
    for (char c : key) {
        int x = (int) (c - 'a' + 1);
        h = (h * k + x) % mod;
    }
    return  h;
}


int main(){
    ifstream in("map.in");
    ofstream out("map.out");
    string command;
    bool exists;
    int indexFound;
    string key,value;
    vector<vector<pair<string,string>>> hashTable;
    hashTable.resize(1009);
    while(in>>command){
        in >> key;
        exists = false;
        int temp = getHash(key) % 1009;
        if(temp < 0 )temp*=(-1);
        for(int i = 0; i <hashTable[temp].size(); ++i){
            if(hashTable[temp][i].first == key){
                exists = true;
                indexFound = i;
                break;
            }
        }

        if(command == "put"){
            in >> value;
            if(exists)
                hashTable[temp][indexFound].second = value;
            else
                hashTable[temp].push_back(make_pair(key,value));
        } else if(command == "delete" && exists)
            hashTable[temp].erase(hashTable[temp].begin() + indexFound);
        else if(command == "get"){
            if(exists)
                out << hashTable[temp][indexFound].second << endl;
            else
                out << "none\n";
        }
    }
}