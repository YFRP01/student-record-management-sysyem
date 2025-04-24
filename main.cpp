#include <iostream>
#include<vector>
#include<time.h>
#include<string>
#include<cstdlib>
#include<ctime>


using namespace std;

class student{
private:
    string name;
    string sex;
    string email;
    string contact;
    string matricule;
    string course[7] = {"Object Oriented Programming","Algorithm and Data Structure II","Linear Algebra", "Real Analysis II","Discrete Mathematics","Introduction to Networking","African Leadership"};
    string score[7];

public:
    void add(int index){
        cout<<"\tStudent ("<<index+1<<"):"<<endl;
        cout<<"\t\tThe student's name:\t";
        cin>>name;
        cout<<"\t\tThe student's sex (m/f):\t";
        cin>>sex;

        cout<<"\t\tThe student's phone number (+237):\t";
        cin>>contact;

        int randomNumber = rand()%9000+1000;
        matricule = name + to_string(randomNumber);
        cout<<"\t\tThe student's matricule: "<<matricule<<endl;

        string path = ".student@ictuniversity.edu.cm";
        email = name + path;
        cout<<"\t\tThe student's email adress: "<<email<<endl;
        int i=0;
        cout<<"\t\tEnter the different scores of the student:"<<endl;
        while(i<7){
            cout<<"\t\t\t";
            cout<<course[i]<<" :\t";
            cin>>score[i];
            i++;
        }
        cout<<"\n*********** Student's record successfully created. ***********"<<endl;
        //cout<<"**********************************************************"<<endl;
    }

    void display(int index){
        if(index<0){
            cout<<"\n\t\t\t****** No match found! ******"<<endl;
        }
        else{
            cout<<"\tStudent ("<<index+1<<"):"<<endl;
            cout<<"\t\tThe student's name:\t"<<name<<endl;
            cout<<"\t\tThe student's sex:\t"<<sex<<endl;
            cout<<"\t\tThe student's matricule: "<<matricule<<endl;
            int i=0;
            string gender;
            if(sex == "m" || sex == "male") gender = "his"; else if(sex == "f" || sex == "female") gender = "her"; else gender = "his/her";
            cout<<"\t\tHere are "<<gender<<" scores:"<<endl;
            while(i<7){
                cout<<"\t\t\t";
                cout<<course[i]<<" :\t";
                cout<<score[i]<<endl;;
                i++;
            }
        }

        //cout<<"**********************************************************"<<endl;
    }

    bool get_search_key(string search_key){
        if(search_key == matricule || search_key == name || search_key == contact || search_key == email || search_key == sex) return true; else return false;
    }
    void edit(int index){
        bool isAccepted = false;
        cout<<"\tStudent ("<<index+1<<"):"<<endl;
        int selection;
            cout<<"\t***Do you want to edit the student's name?\t\t(1) Yes continue\t(2) No exit:\t\t";
            cin>>selection;
            switch(selection){
            case 1:
                isAccepted = true;
                cout<<"\t\tThe new student's name:\t";
                cin>>name;
                break;
            case 2:
                cout<<"Exit operation successful!"<<endl;
                break;
            default:
                cout<<"\n\t\t***** Invalid input! *****"<<endl;
                cout<<"Function exited successfully!"<<endl;

            }
            cout<<"\t***Do you want to edit the student's sex?\t\t(1) Yes continue\t(2) No exit:\t\t";
            cin>>selection;
            switch(selection){
            case 1:
                isAccepted = true;
                cout<<"\t\tThe new student's sex:\t";
                cin>>sex;
                break;
            case 2:
                cout<<"Exit operation successful!"<<endl;
                break;
            default:
                cout<<"\t\t***** Invalid input! *****"<<endl;
                cout<<"Function exited successfully!"<<endl;

            }
            int i=0;
            cout<<"\t***Do you want to edit the student's course scores?\t\t(1) Yes continue\t(2) No exit:\t\t";
            cin>>selection;
            switch(selection){
            case 1:
                isAccepted = true;
                cout<<"\t\tMake your choices:"<<endl;
                while(i<7){
                    cout<<"\t\t\t";
                    cout<<"Edit the "<<course[i]<<" score?\t\t(1) Yes continue\t(2) No exit:\t\t";
                    cin>>selection;
                        switch(selection){
                        case 1:
                            cout<<"\t\tEnter the new student's score:\t"<<endl;
                            cin>>score[i];
                            break;
                        case 2:
                            break;
                        default:
                            cout<<"\n\t\t***** Invalid input! *****"<<endl;
                            cout<<"Function exited successfully!"<<endl;

                        }
                    i++;
                }
                break;
            case 2:
                cout<<"Exit operation successful!"<<endl;
                break;
            default:
                cout<<"\n\t\t***** Invalid input! *****"<<endl;
                cout<<"Function exited successfully!"<<endl;

            }
        if(isAccepted){
            cout<<"*********** Student's record successfully updated! "<<endl;
        }
        else{
            cout<<"*********** The student's record is not updated "<<endl;
        }
        //cout<<"**********************************************************"<<endl;
    }
};


int search_student(vector<student>&studentsDB, string search_key_entity){
    int i=0,res = -10;
    while(i<studentsDB.size()){
        if (studentsDB[i].get_search_key(search_key_entity)) res = i;
        i++;
    }
    return res;
}
void delete_stud(vector<student>&studentsDB, string search_key,int studIndex){
    if(studIndex >= 0 && studIndex<studentsDB.size()){
        studentsDB.erase(studentsDB.begin()+studIndex);
        cout<<"Delete Operation successful!"<<endl;
    }
    else{
        cout<<"\n\t\t\t****** No match found! ******"<<endl;
    }
}

void updateFunc(int studentIndex, vector<student>&studentsDB){
    if(studentIndex == -10) cout<<"\n\t\t\t****** No match found and no update is made! ******"<<endl;
    else studentsDB[studentIndex].edit(studentIndex);
}


int main()
{
    srand(time(0));

    int count = 0,size = 0,selection,i=0,j=0;
    string search_key;

    bool toOperate = true,state = true;
    vector<student>studentsDB;
    student hold;

    cout<<"***************************************************************"<<endl;
    cout<<"You are requested to insert at least a student with his record in the database."<<endl;
        hold.add(count);
        studentsDB.push_back(hold);
        count++;
        while(state){
            cout<<"***Do you want to continue adding?\t\t(1) Yes continue\t(2) No exit:\t\t";
            cin>>selection;
                switch(selection){
                    case 1:
                        hold.add(count);
                        studentsDB.push_back(hold);
                        count++;
                        break;
                    case 2:
                        state = false;
                        cout<<"Exit operation successful!"<<endl;
                        break;
                    default:

                        cout<<"************** Invalid input! **************"<<endl;
                        cout<<"*************Function reloaded**************"<<endl;
                }
        }

    int choice;

    while(toOperate){
        cout<<"\n***************************************************************"<<endl;
        cout<<"Welcome to the Home page! /*What is your request?*/"<<endl;
        cout<<"(1) Add student\t(2) Display students info\t(3) Search student\t(4) Update student information\t(5) Delete student records\t(6) Exit"<<endl;
        cout<<"***************************************************************\nEnter your choice here:\t";
        cin>>choice;

        switch(choice){
            case 1:
                hold.add(count);
                studentsDB.push_back(hold);
                count++;
                state = true;
                while(state){
                    cout<<"***Do you want to continue adding?\t\t(1) Yes continue\t(2) No exit:\t\t";
                    cin>>selection;
                        switch(selection){
                            case 1:
                                hold.add(count);
                                studentsDB.push_back(hold);
                                count++;
                                break;
                            case 2:
                                state = false;
                                cout<<"Exit operation successful!"<<endl;
                                break;
                            default:
                                cout<<"\n************** Invalid input! **************"<<endl;
                                cout<<"**************Function reloaded**************"<<endl;
                        }
                }
                break;

            case 2:
                if(studentsDB.size() == 0) cout<<"The database is empty!";
                else{
                    i=0;
                    while(i<studentsDB.size()){
                        studentsDB[i].display(i);
                        i++;
                    }
                }

                break;
            case 3:
                if(studentsDB.size() == 0) cout<<"The database is empty!"<<endl;
                else{
                    cout<<"Enter either the student's name, email or matricule for a searching operation: \t";
                    cin>>search_key;
                    studentsDB[search_student(studentsDB,search_key)].display(search_student(studentsDB,search_key));
                }
                break;
            case 4:
                if(studentsDB.size() == 0) cout<<"The database is empty!"<<endl;
                else{
                    cout<<"Enter either the student's name, email or matricule for a searching operation: \t";
                    cin>>search_key;
                    updateFunc(search_student(studentsDB, search_key), studentsDB);
                }
                break;
            case 5:
                if(studentsDB.size() == 0) cout<<"The database is empty!"<<endl;
                else{
                    cout<<"Enter either the student's name, email or matricule for a searching operation: \t";
                    cin>>search_key;
                    delete_stud(studentsDB,search_key,search_student(studentsDB,search_key));
                    }
                    break;
            case 6:
                toOperate = false;
                cout<<"Exit operation successful!"<<endl;
                break;
            default:
                cout<<"\n************** Invalid input! **************"<<endl;
                cout<<"You will be sent to the Home page."<<endl;
        }

    }
    return 0;
}
