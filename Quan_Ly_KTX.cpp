#include <iostream>
#include <string>
using namespace std;

class Person{
    private:
        string name;
        int age;
        string address;
    public:
        Person(string name, int age, string address);
        string getName();
        void setName(string name);
        int getAge();
        void setAge(int age);
        string getAddress();
        void setAddress(string address);
};
Person::Person(string name, int age, string address){
    this->name=name;
    this->age=age;
    this->address=address;
}
string Person::getName(){
    return name;
}
void Person::setName(string name){
    this->name = name;
}
int Person::getAge(){
    return age;
}
void Person::setAge(int age){
    this->age = age;
}
string Person::getAddress(){
    return address;
}
void Person::setAddress(string address){
    this->address = address;
}

// class Student : public Person{
//     private:
//         string msv;
//         double phinoitru;
//         double cmnd;
//         int sophong;
//         int solanvipham;
//     public:
        
// };
class Student : public Person {
private:
	double id; //mã sinh viên
	double identitycard; //số CMND
	int room; // số phòng ở
	double boardingfee; //phí nội trú
	int violations; //số lần vi phạm
public:
	Student(string name, int age, string address, double id,  double identitycar, int roomnumber, double boardingfee, int violations) : Person(name, age, address){
        this->id = id;
        this->identitycard = identitycar;
        this->room = room;
        this->boardingfee = boardingfee;
        this->violations = violations;
    }
	void setId(double id);
	double getId();
	void setIdentitycard(double identitycar);
	double getIdentitycardnumber();
	void setRoom(int room);
	int getRoom();
	void setBoardingfee(double boardingfee);
	double getBoardingfee();
	void setViolations(int violations);
	int getViolations();
	// void Nhap();
	// void Xuat();
};
//Khai báo phương thức bên ngoài lớp

// Student::Student(double id,  double identitycar, int room, double boardingfee, int violations) : Person(name, age, address){
// 	this->id = id;
// 	this->identitycard = identitycar;
// 	this->room = room;
// 	this->boardingfee = boardingfee;
// 	this->violations = violations;
// }
double Student::getId() {
	return id;
}
void Student::setId(double id) {
	this->id = id;
}
double Student::getIdentitycardnumber() {
	return identitycard;
}
void Student::setIdentitycard(double identitycard) {
	this->identitycard = identitycard;
}
int Student::getRoom() {
	return room;
}
void Student::setRoom(int room) {
	this->room = room;
}
double Student::getBoardingfee() {
	return boardingfee;
}
void Student::setBoardingfee(double boardingfee) {
	this->boardingfee = boardingfee;
}
int Student::getViolations() {
	return violations;
}
void Student::setViolations(int violations) {
	this->violations = violations;
}

class Manage : public Person{
private:
    double salary;
    string position;
public: 
    Manage(string name, int age, string address, double salary, string position):Person(name, age, address){
        this->salary=salary;
        this->position=position;
    }
    double getSalary();
    void setSalary(double salary);
    string getPosition();
    void setPosition(string position);
};
double Manage::getSalary(){
    return salary;
}
void Manage::setSalary(double salary){
    this->salary=salary;
}
string Manage::getPosition(){
    return position;
}
void Manage::setPosition(string position){
    this->position=position;
}