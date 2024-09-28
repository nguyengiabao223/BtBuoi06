#include<iostream>
#include<string>
using namespace std;

class Student {
    private :
    string name;
    int age;
    float gpa;

    public :
    Student(string n, int a, float g ) : name(n), age (a), gpa(g) {} 
    string getName() const {return name; }
    int getAge() const { return age; }
    float getGpa() const { return gpa; } 

    void setName(string n ) {name = n; }
    void setAge(int a) { age = a;}
    void setGpa(float g) { gpa = g; }

    void displayInfo() const {
        cout << "Ten: " << name << endl;
        cout << "Tuoi: " << age << endl;
        cout << "Gpa: " << gpa << endl;
    }
};
int main () {
    Student s1("Nguyen gia bao ", 20, 3.7);
    cout << "Thong tin sinh vien: " << endl;
    s1.displayInfo();
    s1.setGpa(3.7);
    cout << "\nThong tin sau khi cap nhat Gpa: " << endl;
    s1.displayInfo();
    return 0;

}
