#include <iostream>
#include <string>
#include "List.h"
using namespace std;

int main(){
    List bimar;
    Patient *par = new Patient("1234567895");
    Patient *pat = new Patient("4234567895");
    Patient *pay = new Patient("3234567895");
    bimar.insert(*par);
    bimar.insert(*pat);
    bimar.insert(*pay);
    bimar.printList();

    return 0;
}