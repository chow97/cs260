#include <iostream>
#include "unistd.h"

using namespace std;

int specialSauce(char* str)
{
    int val = 0;
    int i=0;
    while(str[i] != 0) {
	val = (val * i) + str[i];
	i++;
    }
    return(val);
}


int main()
{
    const int MAXUSERNAME = 100;

    char* username = new char[MAXUSERNAME];

    getlogin_r(username,MAXUSERNAME);
    cout << "Username: " << username << endl;
    cout << "Class ID: " << specialSauce(username) << endl;
}
