#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//Student Class
class Student
{
public:
    int rollNo;
    string name;
    float marks;

    Student(int r, string n, float m)
    {
        rollNo = r;
        name = n;
        marks = m;
    }
};

template <class T>
class StudentManager
{
private:
    vector<T> students;

public:
    //Insert Student
    void insertStudent(T s)
    {
        students.push_back(s);
        cout << "\nStudents Record Inserted Successfully.\n";
    }

    //Display Students
    void displayStudents()
    {
        if(students.empty())
        {
            cout << "\nNo Students Record Found.\n";
            return;
        }
        cout << "\n--------------------\n";
        cout << "Roll No\tName\t\tMarks\n";
        cout << "--------------------\n";
        for(int i = 0; i < students.size(); i++)
        {
            cout << students[i].rollNo << "\t";
            cout << students[i].name << "\t\t";
            cout << students[i].marks << endl;
        }
    }

    // search student
    void searchStudent(int roll)
    {
        for(int i = 0; i < students.size(); i++)
        {
            if(students[i].rollNo == roll)
            {
                cout << "\n Students Found\n";
                cout << "roll no:" << students[i].rollNo << endl;
                cout << "name:" << students[i].name << endl;
                cout << "marks:" << students[i].marks << endl;
                return;
            }
        }
        cout << "\nStudents Not Found.\n";
    }

    //Delete Student
    void deleteStudent(int roll)
    {
        typename vector<T>::iterator it;
        for(it = students.begin(); it != students.end(); it++)
        {
            if(it->rollNo == roll)
            {
                students.erase(it);
                cout << "\nStudents Record Deleted Successfully.\n";
                return;
            }
        }
        cout << "\nStudents Not Found.\n";
    }

    //Sort Students
    void sortStudents()
    {
        sort(students.begin(),
             students.end(),
             [](T a, T b)
             {
                 return a.rollNo < b.rollNo;
             });
        cout << "\nStudents Record Sorted Successfully.\n";
    }
};

int main()
{
    StudentManager<Student> manager;
    int choice;
    int roll;
    string name;
    float marks;

    do
    {
        cout << "\n-------Student Management System-------\n";
        cout << "1.Insert Student\n";
        cout << "2.Delete Student\n";
        cout << "3.Search Student\n";
        cout << "4.Sort Student\n";
        cout << "5.Display Student\n";
        cout << "6.Exit\n";

        cout << "Enter Choice:";
        cin >> choice;

        switch(choice)
        {
            case 1:
                cout << "enter roll no:";
                cin >> roll;

                cout << "enter name:";
                cin >> name;

                cout << "enter marks:";
                cin >> marks;

                manager.insertStudent(Student(roll, name, marks));
                break;

            case 2:
                cout << "enter roll no to delete:";
                cin >> roll;
                manager.deleteStudent(roll);
                break;

            case 3:
                cout << "enter roll no to search:";
                cin >> roll;
                manager.searchStudent(roll);
                break;

            case 4:
                manager.sortStudents();
                break;

            case 5:
                manager.displayStudents();
                break;

            case 6:
                cout << "\nProgram Terminated.\n";
                break;

            default:
                cout << "\nInvalid Choice.\n";
        }
    } while(choice != 6);

    return 0;
}
