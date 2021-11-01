#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool isLoggedIn()
{
    string username, password, usernameCheck, passwordCheck;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    ifstream read("data\\" + username + ".txt");
    getline(read, usernameCheck);
    getline(read, passwordCheck);

    if(username == usernameCheck && password == passwordCheck)
    {
        return true;
    }
    else
    {
        return false;
    }

}
bool isRegistered(){
    //TODO
}
int main()
{

    int choice;
    int counter = 0;


    while(true)
    {
        while(true){
            cout << "1 - Register\n2 - Login\nPlease enter your choice: ";
            cin >> choice;
            if(choice == 1 || choice == 2)
            {
                break;
            }
            else
            {
                cout << "\n\nWrong input!\n\n";
                continue;
            }
        }
        if(counter < 3)
        {
            if(choice == 1)
            {
                string username, password;
                cout << "Type username: ";
                cin >> username;
                cout << "Type password: ";
                cin >> password;

                ofstream file;
                file.open("data\\" + username + ".txt");

                file << username << endl << password;
                file.close();
                counter = 0;
                continue;
            }
            else if(choice == 2)
            {
                bool status = isLoggedIn();
                if(!status)
                {
                    cout << "False Login" <<endl;
                    counter++;
                    cout << counter;
                    system("PAUSE");
                    continue;
                }

                else
                {
                    cout << "Successfully logged in!" << endl;
                    system("PAUSE");
                    break;
                }
            }

        }
        else
        {
            cout << "Too many tries. Try again later.";
            break;
        }
    }
    return 0;
}
