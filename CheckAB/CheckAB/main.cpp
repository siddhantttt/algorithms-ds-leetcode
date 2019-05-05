#include <vector>
#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>

using namespace std;

bool checkABHelper(char input[], int pos, int size){
    if (!*input)
        return true;
    
    
    bool midResult = checkABHelper(input+1, pos+1, size);
    
    bool curr = true;
    
    if (*input == 'a')
        curr = !*(input+1) || (*(input+1) == 'a' || (*(input+1) == 'b' && *(input+2) == 'b'));
    
    
    else if (*input == 'b' && *(input+1) == 'b')
        curr = *(input+2) == 'a' || !*(input+2);
    
    return curr && midResult;
    
}



bool checkAB(char input[]) {
    if (*input != 'a')
        return false;
    
    int size = strlen(input);
    int pos = 0;
    
    return checkABHelper(input, pos, size);
}




int main(){
    
    cout << checkAB("abbb");
    return 0;
}
