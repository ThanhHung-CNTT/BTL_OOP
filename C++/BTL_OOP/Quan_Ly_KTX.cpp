#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>
#include <cstdlib>
#include <ctime>
#include <math.h>
#include "setcolor.h"
#include <conio.h>
#include <cstdlib>

using namespace std;

void SetColor(int backgound_color, int text_color)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

    int color_code = backgound_color * 16 + text_color;
    SetConsoleTextAttribute(hStdout, color_code);
}
void SET_COLOR(int color)
{
	WORD wColor;
     

     HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
     CONSOLE_SCREEN_BUFFER_INFO csbi;
     if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
     {
          wColor = (csbi.wAttributes & 0xF0) + (color & 0x0F);
          SetConsoleTextAttribute(hStdOut, wColor);
     }
}
void gotoXY (int column, int line)
{
	COORD coord;
	coord.X = column;
	coord.Y = line;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

int numberStudent(int &n){
	cin >> n;
    return n;
}
int numberManage(int &n){
	cin >> n;
    return n;
}

int SoluongSinhvien(int &n){
	cin >> n;
    return n;
}
int SoluongQuanly(int &n){
	cin >> n;
    return n;
}

class Person{
    private:
        string name;
        int age;
        string address;
	string id;
	double money;
        bool check;
    public:
	Person();
        ~Person();
	void setId(string id);
	string getId();
        string getName();
        void setName(string name);
        int getAge();
        void setAge(int age);
        string getAddress();
        void setAddress(string address);
	int numberStudent(int &n);
        int numberManage(int &n);
        int SoluongSinhvien(int &n);
        int SoluongQuanly(int &n);
        virtual void Nhap(int &);
        virtual void Xuat(int &);
        virtual void capnhatThongtin();
        virtual void tinhtien() = 0;
        double getMoney(){
            return money;
        }
        bool selection();
        void selection(bool check);
};
Person::Person(){
    name = "";
    age = 0;
    address = "";
    money = 0;
}
Person::~Person(){
}
bool Person::selection(){
    return this->check;
}
void Person::selection(bool check){
    this->check = check;
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
double Student::getId() {
	return id;
}
void Student::setId(double id) {
	this->id = id;
}

void Person::Nhap(int &n){
    fflush(stdin);
    gotoXY(35, 4+n);
    getline(cin, name);
    fflush(stdin);
    gotoXY(60, 4+n);
    cin >> age;
    fflush(stdin);
    gotoXY(70,4+n);
    getline(cin, address);
    gotoXY(85,4+n);
    getline(cin, id);
	fflush(stdin);
}

void Person::Xuat(int &n){
    gotoXY(35, 4+n);
    cout << name;
    gotoXY(60, 4+n);
    cout << age;
    gotoXY(70,4+n);
    cout << address;
    gotoXY(85,4+n);
    cout<< id;
}

void Person::capnhatThongtin(){
    fflush(stdin);
    gotoXY(35, 4);
    getline(cin, name);
    fflush(stdin);
    gotoXY(60, 4);
    cin >> age;
    fflush(stdin);
    gotoXY(70,4);
    getline(cin, address);
}

class Student : public Person {
private:
	string identitycard; //số CMND
	int room; // số phòng ở
	double unitprice; //dơn gia
	int violations; //số lần vi phạm
        double months; //số tháng ở
public:
	Student();
        ~Student();
	void setIdentitycard(string identitycar);
	string getIdentitycardnumber();
	void setRoom(int room);
	int getRoom();
	void setUnitprice (double unitprice);
	double getUnitprice();
	void setViolations(int violations);
	int getViolations();
	double getMonths();
        void setMonths(double months);
        void Nhap(int &n);
        void Xuat(int &n);
        void tinhtien(){
            this->money = this->months*this->unitprice;
        }
        void capnhatThongtin();
};
//Khai báo phương thức bên ngoài lớp

Student::Student(){
    id="";
    identitycard="";
    room = 0;
    unitprice = 0;
    violations = 0;
    months = 0;
}
Student::~Student(){
}
string Student::getIdentitycardnumber() {
	return identitycard;
}
void Student::setIdentitycard(string identitycard) {
	this->identitycard = identitycard;
}
int Student::getRoom() {
	return room;
}
void Student::setRoom(int room) {
	this->room = room;
}
double Student::getMonths(){
    return months;
}
void Student::setMonths(double months){
    this->months = months;
}
double Student::getUnitprice() {
	return unitprice;
}
void Student::setUnitprice(unsigned long int unitprice) {
	this->unitprice = unitprice;
}
int Student::getViolations() {
	return violations;
}
void Student::setViolations(int violations) {
	this->violations = violations;
}

void Student::Nhap(int &n){
    Person::Nhap(n);
    gotoXY(100,4+n);
    getline(cin, identitycard);
	fflush(stdin);
    gotoXY(115,4+n);
    cin>>room;
	fflush(stdin);
    gotoXY(125,4+n);
    cin >> months;
    fflush(stdin);
    gotoXY(135,4+n);
    cin>>unitprice;
	fflush(stdin);
    gotoXY(148,4+n);
    cin>>violations;
	fflush(stdin);
}

void Student::Xuat(int &n){
    Person::Xuat(n);
    Person::Xuat(n);
    gotoXY(100,4+n);
    cout << identitycard;
    gotoXY(115,4+n);
    cout << room ;
    gotoXY(125,4+n);
    cout << months;
    gotoXY(135,4+n);
    cout << unitprice;
    gotoXY(148,4+n);
    cout << violations;
    gotoXY(162,4+n);
    this->tinhtien();
    cout << money ;
    cout<<"\n\n\n";
}

void Student::capnhatThongtin(){
    Person::capnhatThongtin();
    gotoXY(100,4);
    getline(cin, identitycard);
    fflush(stdin);
    gotoXY(115,4);
    cin >> room;
    fflush(stdin);
    gotoXY(125,4);
    cin >> months;
    fflush(stdin);
    gotoXY(135,4);
    cin >> unitprice;
    fflush(stdin);
    gotoXY(148,4);
    cin >> violations;
    fflush(stdin);
}

class Manage : public Person{
private:
    	double coefficientssalary; //He so lương
    	string position; //Chức vụ
	string phone; //CMND
    	double seniority; //thâm niên
public: 
    Manage();
    ~Manage();
    double getCoefficientssalary();
    void setCoefficientssalary(double coefficientssalary);
    double getSeniority();
    void setSeniority(double seniority);
    string getPosition();
    void setPosition(string position);
    string getPhone();
	void setPhone(string phone);
    void tinhtien(){
        money = coefficientssalary*1600 + seniority*500;
    }
    void Nhap(int &n);
    void Xuat(int &n);
    void input(int &n);
    void output(int &n);
    void capnhatThongtin();
    void updateInformation();
};
Manage::Manage(){
    seniority = 0;
    position = "";
    phone = "";
    coefficientssalary = 0;
}
Manage::~Manage(){

}
double Manage::getCoefficientssalary(){
    return coefficientssalary;
}
void Manage::setCoefficientssalary(double coefficientssalary){
    this->coefficientssalary=coefficientssalary;
}
string Manage::getPosition(){
    return position;
}
void Manage::setPosition(string position){
    this->position=position;
}
double Manage::getSeniority(){
    return seniority;
}
void Manage::setSeniority(double seniority){
    this->seniority = seniority;
}
string Manage::getPhone(){
	return phone;
}
void Manage::setPhone(string phone){
	this->phone=phone;
}

void Manage::Nhap(int &n){
    Person::Nhap(n);
    gotoXY(100,4+n);
    getline(cin, phone);
    fflush(stdin);
    gotoXY(115,4+n);
    cin >> seniority;
    fflush(stdin);
    gotoXY(130,4+n);
    cin >> coefficientssalary;
    fflush(stdin);
    gotoXY(145,4+n);
    getline(cin, position);
}

void Manage::Xuat(int &n){
    Person::Xuat(n);
    gotoXY(100,4+n);
    cout << phone << endl;
    gotoXY(115,4+n);
    cout << seniority << endl;
    gotoXY(130,4+n);
    cout << coefficientssalary << endl;
    gotoXY(145,4+n);
    cout << position << endl;
    gotoXY(160,4+n);
    this->tinhtien();
    cout << money << endl;
}

void Manage::capnhatThongtin(){
    Person::capnhatThongtin();
    gotoXY(100,4);
    getline(cin, phone);
    fflush(stdin);
    gotoXY(115,4);
    cin >> seniority;
    fflush(stdin);
    gotoXY(130,4);
    cin >> coefficientssalary;
    fflush(stdin);
    gotoXY(145,4);
    getline(cin, position);
}

void inmenu1(){
	for(int i=0; i <5; i++){
		gotoXY(1,i);
		putchar(219);
	}
	
	for(int i=0; i <5; i++){
		gotoXY(30,i);
		putchar(219);
	}
	for(int i=2; i <30; i++){
		gotoXY(i,0);
		putchar(223);
	}
	for(int i=2; i <30; i++){
		gotoXY(i,4);
		putchar(220);
	}
	gotoXY(2,1);
        cout << "1. Nhap sinh vien";
        gotoXY(2,2);
        cout << "2. Nhap ban quan ly";
        gotoXY(2,3);
        cout << "3. Thoat ";
}

void inmenu2(){
	for(int i=0; i <5; i++){
		gotoXY(1,i);
		putchar(219);
	}
	
	for(int i=0; i <5; i++){
		gotoXY(30,i);
		putchar(219);
	}
	for(int i=2; i <30; i++){
		gotoXY(i,0);
		putchar(223);
	}
	for(int i=2; i <30; i++){
		gotoXY(i,4);
		putchar(220);
	}
		
	gotoXY(2,1);
        cout << "1. Enter student";
        gotoXY(2,2);
        cout << "2. Enter manage";
        gotoXY(2,3);
        cout << "3. Exit ";
}

void inmenu3(){
	for(int i=0; i <5; i++){
		gotoXY(1,i);
		putchar(219);
	}
	
	for(int i=0; i <5; i++){
		gotoXY(30,i);
		putchar(219);
	}
	for(int i=2; i <30; i++){
		gotoXY(i,0);
		putchar(223);
	}
	for(int i=2; i <30; i++){
		gotoXY(i,4);
		putchar(220);
	}
	gotoXY(2,1);
        cout << "1. Sinh vien";
        gotoXY(2,2);
        cout << "2. Ban quan ly";
        gotoXY(2,3);
        cout << "3. Thoat ";
}

void inmenu4(){
	for(int i=0; i <5; i++){
		gotoXY(1,i);
		putchar(219);
	}
	
	for(int i=0; i <5; i++){
		gotoXY(30,i);
		putchar(219);
	}
	for(int i=2; i <30; i++){
		gotoXY(i,0);
		putchar(223);
	}
	for(int i=2; i <30; i++){
		gotoXY(i,4);
		putchar(220);
	}
		gotoXY(2,1);
        cout << "1. Student";
        gotoXY(2,2);
        cout << "2. Manage";
        gotoXY(2,3);
        cout << "3. Exit ";
}

void inkhung(){
//in bien doc
    for(int i=1; i <25; i++){
		gotoXY(34,i);
		putchar(219);
		gotoXY(59,i);
		putchar(219);
		gotoXY(69,i);
		putchar(219);
		gotoXY(84,i);
		putchar(219);
		gotoXY(99,i);
		putchar(219);
		gotoXY(114,i);
		putchar(219);
        gotoXY(124,i);
		putchar(219);
		gotoXY(134,i);
		putchar(219);
        gotoXY(144,i);
		putchar(219);
        gotoXY(161,i);
		putchar(219);
        gotoXY(177,i);
        putchar(219);
	}

    // in bien ngang
    for(int i=35; i <177; i++){
		gotoXY(i,1);
		putchar(223);
		gotoXY(i,24);
		putchar(220);
		gotoXY(i,3);
		putchar(220);
	}
	// in cac tieu de
	gotoXY(35,2);
	cout<<" Ho va ten";
	gotoXY(60,2);
	cout<<" Tuoi";
	gotoXY(70,2);
	cout<<" Dia chi";
	gotoXY(85,2);
	cout<<" Ma ID";
	gotoXY(100,2);
	cout<<" CMND/CCCD";
	gotoXY(115,2);
	cout<<" Phong";
	gotoXY(125,2);
	cout<<" Thang";
    gotoXY(135,2);
    cout <<" Don gia";
    gotoXY(145,2);
    cout<<" So lan vi pham";
    gotoXY(162,2);
    cout<<" Tien can dong";
}

void inkhung1(){
//in bien doc
    for(int i=1; i <25; i++){
		gotoXY(34,i);
		putchar(219);
		gotoXY(59,i);
		putchar(219);
		gotoXY(69,i);
		putchar(219);
		gotoXY(84,i);
		putchar(219);
		gotoXY(99,i);
		putchar(219);
		gotoXY(114,i);
		putchar(219);
        gotoXY(129,i);
		putchar(219);
		gotoXY(144,i);
		putchar(219);
        gotoXY(159,i);
		putchar(219);
        gotoXY(175,i);
		putchar(219);
	}

    // in bien ngang
    for(int i=35; i <175; i++){
		gotoXY(i,1);
		putchar(223);
		gotoXY(i,24);
		putchar(220);
		gotoXY(i,3);
		putchar(220);
	}
	// in cac tieu de
	gotoXY(35,2);
	cout<<" Ho va ten";
	gotoXY(60,2);
	cout<<" Tuoi";
	gotoXY(70,2);
	cout<<" Dia chi";
	gotoXY(85,2);
	cout<<" Ma ID";
	gotoXY(100,2);
	cout<<" So DT";
	gotoXY(115,2);
	cout<<" Tham nien";
	gotoXY(130,2);
	cout<<" He so luong";
    gotoXY(145,2);
    cout <<" Chuc vu";
    gotoXY(160,2);
    cout<<" Tien luong";
}

void inkhung3(){
//in bien doc
    for(int i=1; i <25; i++){
		gotoXY(34,i);
		putchar(219);
		gotoXY(59,i);
		putchar(219);
		gotoXY(69,i);
		putchar(219);
		gotoXY(84,i);
		putchar(219);
		gotoXY(99,i);
		putchar(219);
		gotoXY(114,i);
		putchar(219);
        gotoXY(124,i);
		putchar(219);
		gotoXY(134,i);
		putchar(219);
        gotoXY(147,i);
		putchar(219);
        gotoXY(161,i);
		putchar(219);
        gotoXY(177,i);
        putchar(219);
	}

    // in bien ngang
    for(int i=35; i <177; i++){
		gotoXY(i,1);
		putchar(223);
		gotoXY(i,24);
		putchar(220);
		gotoXY(i,3);
		putchar(220);
	}
	// in cac tieu de
	gotoXY(35,2);
	cout<<" First and last name";
	gotoXY(60,2);
	cout<<" Age";
	gotoXY(70,2);
	cout<<" Address";
	gotoXY(85,2);
	cout<<" ID code";
	gotoXY(100,2);
	cout<<" Identity card";
	gotoXY(115,2);
	cout<<" Room";
	gotoXY(125,2);
	cout<<" Months";
    gotoXY(135,2);
    cout <<" Unit price";
    gotoXY(148,2);
    cout<<" Violations";
    gotoXY(162,2);
    cout<<"Money to pay";
}

void inkhung4(){
//in bien doc
    for(int i=1; i <25; i++){
		gotoXY(34,i);
		putchar(219);
		gotoXY(59,i);
		putchar(219);
		gotoXY(69,i);
		putchar(219);
		gotoXY(84,i);
		putchar(219);
		gotoXY(99,i);
		putchar(219);
		gotoXY(114,i);
		putchar(219);
        gotoXY(129,i);
		putchar(219);
		gotoXY(144,i);
		putchar(219);
        gotoXY(159,i);
		putchar(219);
        gotoXY(175,i);
		putchar(219);
	}

    // in bien ngang
    for(int i=35; i <175; i++){
		gotoXY(i,1);
		putchar(223);
		gotoXY(i,24);
		putchar(220);
		gotoXY(i,3);
		putchar(220);
	}
	// in cac tieu de
	gotoXY(35,2);
	cout<<"First and last name";
	gotoXY(60,2);
	cout<<"Age";
	gotoXY(70,2);
	cout<<"Address";
	gotoXY(85,2);
	cout<<"ID code";
	gotoXY(100,2);
	cout<<"Phone";
	gotoXY(115,2);
	cout<<"Seniority";
	gotoXY(130,2);
	cout<<"Salary";
    gotoXY(145,2);
    cout <<"Position";
    gotoXY(160,2);
    cout<<"Money to pay";
}

void giaodien()
{
    system("cls");
    srand(time(NULL));
    SetColor(0, 1 + rand() % 15);
    gotoXY(45,1);
    cout << "      ********     *    *     *       **      *       *     *      *        *     *  ********  *       *      " << endl;
    gotoXY(45,2);
    cout << "     *        *    *    *    *  *     *  *    *       *       *   *         *   *       *        *   *        " << endl;
    gotoXY(45,3);
    cout << "    *       *  *   *    *   *    *    *    *  *       *         *           * *         *          *          " << endl;
    gotoXY(45,4);
    cout << "     *        *    *    *  ********   *      **       *         *           *   *       *        *   *        " << endl;
    gotoXY(45,5);
    cout << "      ********  *  ****** *        *  *       *       *******   *           *     *     *      *       *      " << endl;

    SetColor(0, 2);
    gotoXY(73,8);
        for(int i=0;i<=38;i++){
            putchar(219);
        }
        for(int i=0;i<=10;i++){
            cout<<endl;
            gotoXY(73,8+i);
            putchar(219);
        }
        for(int i=0;i<=36;i++){
            putchar(219);
        }
        for(int i=0;i<=10;i++){
            cout<<endl;
            gotoXY(111,8+i);
            putchar(219);
        }
    gotoXY(80, 11);
    cout << "1. Ngon ngu Tieng Viet" << endl;
    gotoXY(80, 12);
    cout << "2. Language English" << endl;
    gotoXY(80, 13);
    cout << "3. Thoat" << endl;
}

void giaodien2()
{
    for(int i=0; i <13; i++){
		gotoXY(64,i);
		putchar(219);
	}
	
	for(int i=0; i <13; i++){
		gotoXY(120,i);
		putchar(219);
	}
	for(int i=65; i <120; i++){
		gotoXY(i,0);
		putchar(223);
	}
	for(int i=65; i <120; i++){
		gotoXY(i,12);
		putchar(220);
	}

    SetColor(0, 2);
    gotoXY(70,1);
    cout << "Ban da chon ngon ngu Tieng Viet" << endl;
    gotoXY(70,2);
    cout << "1. Nhap thong tin";
    gotoXY(70,3);
    cout << "2. Hien thi thong tin";
    gotoXY(70,4);
    cout << "3. Sap xep theo ten";
    gotoXY(70,5);
    cout << "4. Tim kiem theo tinh";
    gotoXY(70,6);
    cout << "5. Cap nhat thong tin theo ID";
    gotoXY(70,7);
    cout << "6. Xoa theo ID";
    gotoXY(70,8);
    cout << "7. Tim kiem theo ID";
    gotoXY(70,9);
    cout << "8. Tinh tong tien";
    gotoXY(70,10);
    cout << "9. Thoat ";
    gotoXY(70,15);
    cout << " Nhap lua chon: ";
}

void giaodien3()
{
    for(int i=0; i <13; i++){
		gotoXY(64,i);
		putchar(219);
	}
	
	for(int i=0; i <13; i++){
		gotoXY(120,i);
		putchar(219);
	}
	for(int i=65; i <120; i++){
		gotoXY(i,0);
		putchar(223);
	}
	for(int i=65; i <120; i++){
		gotoXY(i,12);
		putchar(220);
	}

    SetColor(0, 2);
    gotoXY(70,1);
    cout << "You have selected the English language" << endl;
    gotoXY(70,2);
    cout << "1. Enter information";
    gotoXY(70,3);
    cout << "2. Display information";
    gotoXY(70,4);
    cout << "3. Sort by name";
    gotoXY(70,5);
    cout << "4. Search by address";
    gotoXY(70,6);
    cout << "5. Update by ID";
    gotoXY(70,7);
    cout << "6. Delete by ID";
    gotoXY(70,8);
    cout << "7. Search by ID";
    gotoXY(70,9);
    cout << "8. Total Money";
    gotoXY(70,10);
    cout << "9. Exit ";
    gotoXY(70,15);
    cout <<  "Enter Choose: ";
}


class Dormitory{
private:
    vector<Person *> list_person;

public:
    Dormitory();
    ~Dormitory();
    void Nhap();
    void Xuat();
    void input();
    void output();
    friend void inkhung();
    friend void inmenu1();
	friend void inkhung1();
    friend void inmenu2();
    friend void inkhung3();
    friend void inmenu3();
    friend void inkhung4();
    friend void inmenu4();
    void sapxepName();
    void SortName();
    void capnhatThongtin();
    void capnhatID();
    void updateID();
    void timkiemAddress();
    void findAddress();
    void timkiemID();
    void findID();
    void xoaID();
    void deleteID();
    void TongTien();
    void TotalMoney();
};

Dormitory::Dormitory(){
}

Dormitory::~Dormitory(){
}
void Dormitory::Nhap(){
    int i=1, Luachon, n;
        inmenu1();
         while (i)
    {
        cout << "\n \n   Nhap lua chon: ";
        cin >> Luachon;
        Person *p;
        switch (Luachon)
        {
        case 1:  
		  {
            system("cls");
        	inmenu1();
            int a = SoluongSinhvien(n);
            for(int i=0; i<a; i++){
            p = new Student[n];
            p->Nhap(i);
            p->selection(true);
            list_person.push_back(p);
            }
            break;
        }
        case 2:
        {   
            system("cls");
            inmenu1();
            int b= SoluongQuanly(n);
            for(int i=0; i<b; i++){
            p = new Manage[n];
            p->Nhap(i);
            p->selection(false);
            list_person.push_back(p);
            }
			break;
            
        }
        case 3:
        {
            i--;
            break;
        }
        default:
        {
            cout << "Lua chon khong hop le!!!" << endl;
            break;
        }
        }
    }
}

void Dormitory::input(){
    int i=1, Selection , n;
        inmenu2();
         while (i)
    {
        cout << "\n \n  Enter selection: ";
        cin >> Selection;
        Person *p;
        switch (Selection)
        {
        case 1:  
		  {
            system("cls");
        	inmenu2();
            int a = numberStudent(n);
            for(int i=0; i<a; i++){
            p = new Student[n];
            p->input(i);
            p->selection(true);
            list_person.push_back(p);
            }
            
            break;
        }
        case 2:
        {   
            system("cls");
            inmenu2();
            int b= numberManage(n);
            for(int i=0; i<b; i++){
            p = new Manage[n];
            p->input(i);
            p->selection(false);
            list_person.push_back(p);
            }
			break;
            
        }
        case 3:
        {
            i--;
            break;
        }
        default:
        {
            cout << "Invalid selection!!!" << endl;
            break;
        }
        }
    }
}

void Dormitory::Xuat()
{
    int i = 1, Luachon, n;
    inmenu3();
    while (i)
    {
        cout << "\n \n  Nhap lua chon: ";
        cin >> Luachon;
        switch (Luachon)
        {
        case 1:
        {
            system("cls");
            inmenu3();
            for (int i = 0; i < list_person.size(); i++)
            {   
                if(list_person[i]->selection()==true){
                    inkhung();
                    list_person[i]->Xuat(i);
                }
            }

            break;
        }
        case 2:
        {
            system("cls");
            inmenu3();
            for (int i = 0; i < list_person.size(); i++)
            {
                    if(list_person[i]->selection()==false){
                    inkhung1();
                    list_person[i]->Xuat(i);
                }
            }
            break;
        }
        case 3:
        {
            i--;
            break;
        }
        default:
        {
            cout << "  Lua chon khong hop le!!!" << endl;
            break;
        }
        }
    }
}

void Dormitory::output()
{
    int i = 1, Selection, n;
    inmenu4();
    while (i)
    {
        cout << "\n \n  Enter selection: ";
        cin >> Selection;
        switch (Selection)
        {
        case 1:
        {
            system("cls");
            inmenu4();
            for (int i = 0; i < list_person.size(); i++)
            {   
                if(list_person[i]->selection()==true){
                    inkhung4();
                    list_person[i]->Xuat(i);
                }
            }

            break;
        }
        case 2:
        {
            system("cls");
            inmenu4();
            for (int i = 0; i < list_person.size(); i++)
            {
                    if(list_person[i]->selection()==false){
                    inkhung4();
                    list_person[i]->Xuat(i);
                }
            }
            break;
        }
        case 3:
        {
            i--;
            break;
        }
        default:
        {
            cout << "  Invalid selection!!!" << endl;
            break;
        }
        }
    }
}

void Dormitory::sapxepName(){
    for(int i=0;  i<list_person.size()-1  ;  i++){
        for(int j= list_person.size()-1  ;  j>i ;  j--){
            //Táº¡o biáº¿n lÆ°u tĂªn dÆ°á»›i dáº¡ng máº£ng kĂ­ tá»±
            char* name1= new char[list_person[j]->getName().length()];
            strcpy(name1,list_person[j]->getName().c_str());
            char* name2= new char[list_person[j-1]->getName().length()];
            strcpy(name2,list_person[j-1]->getName().c_str());
            //sắp xếp tăng dần theo tên
            if(strcmp(name1,name2)<0){
                Person * mtp;
                mtp = list_person[j];
                list_person[j]=list_person[j-1];
                list_person[j-1] = mtp;
            }
        }
    }
    for (int i = 0; i < list_person.size(); i++){
    	
        if (list_person[i]->selection() == true)
            list_person[i]->Xuat(i);
        
    }
    for (int i = 0; i < list_person.size(); i++){
        
		
		if (list_person[i]->selection() == false)
            list_person[i]->Xuat(i);
        
    }
}
void Dormitory::SortName(){
    for(int i=0;  i<list_person.size()-1  ;  i++){
        for(int j= list_person.size()-1  ;  j>i ;  j--){
            //Táº¡o biáº¿n lÆ°u tĂªn dÆ°á»›i dáº¡ng máº£ng kĂ­ tá»±
            char* name1= new char[list_person[j]->getName().length()];
            strcpy(name1,list_person[j]->getName().c_str());
            char* name2= new char[list_person[j-1]->getName().length()];
            strcpy(name2,list_person[j-1]->getName().c_str());
             //sắp xếp tăng dần theo tên
            if(strcmp(name1,name2)<0){
                Person * mtp;
                mtp = list_person[j];
                list_person[j]=list_person[j-1];
                list_person[j-1] = mtp;
            }
        }
    }
    for (int i = 0; i < list_person.size(); i++){
    	
        if (list_person[i]->selection() == true)
            list_person[i]->output(i);
        
    }
    for (int i = 0; i < list_person.size(); i++){
        
		
		if (list_person[i]->selection() == false)
            list_person[i]->output(i);
        
    }
}
void Dormitory::timkiemAddress(){
    int dem = 0;
    string timkiem;
    cout << "Nhap dia chi day du de tim: " << endl;
    cin.ignore();
    getline(cin, timkiem);
    for (int i = 0; i < list_person.size(); i++)
    {
        if (timkiem == list_person[i]->getAddress())
        {
            dem++;
            if (list_person[i]->selection())
                cout << "Sinh vien!\n\n " << endl;
            else
                cout << "Ban quan ly!\n\n " << endl;
            // inkhung();
            list_person[i]->Xuat(i);
        }
    }
    if (dem == 0)
        cout << "\nKhong tim duoc theo yeu cau!!!\n\n" << endl;
}

void Dormitory::findAddress(){
    int dem = 0;
    string timkiem;
    cout << "Enter the full address to search: " << endl;
    cin.ignore();
    getline(cin, timkiem);
    for (int i = 0; i < list_person.size(); i++)
    {
        if (timkiem == list_person[i]->getAddress())
        {
            dem++;
            if (list_person[i]->selection())
                cout << "Student!\n\n " << endl;
            else
                cout << "Manage!\n\n " << endl;
            // inkhung();
            list_person[i]->output(i);
        }
    }
    if (dem == 0)
        cout << "\nThe request could not be found!!!\n\n" << endl;
}

void Dormitory::timkiemID(){
    int dem = 0;
    string timkiem;
    cout << "Nhap dia chi day du de tim: " << endl;
    cin.ignore();
    getline(cin, timkiem);
    for (int i = 0; i < list_person.size(); i++)
    {
        if (timkiem == list_person[i]->getId())
        {
            dem++;
            if (list_person[i]->selection())
                cout << "\nSinh vien!\n " << endl;
            else
                cout << "\nBan quan ly!\n " << endl;
            // inkhung();
            list_person[i]->Xuat(i);
        }
    }
    if (dem == 0)
        cout << "\nKhong tim duoc theo yeu cau!!!\n\n" << endl;
}

void Dormitory::findID(){
    int dem = 0;
    string timkiem;
    cout << "Enter the full ID to search: " << endl;
    cin.ignore();
    getline(cin, timkiem);
    for (int i = 0; i < list_person.size(); i++)
    {
        if (timkiem == list_person[i]->getId())
        {
            dem++;
            if (list_person[i]->selection())
                cout << "\nStudent!\n " << endl;
            else
                cout << "\nManage!\n " << endl;
            // inkhung();
            list_person[i]->output(i);
        }
    }
    if (dem == 0)
        cout << "\nThe request could not be found!!!\n\n" << endl;
}

void Dormitory::capnhatThongtin(){
    int i;
        if(list_person[i]->selection()==true){
            list_person[i]->capnhatThongtin();
        }
        else if ((list_person[i]->selection()==false)){
            list_person[i]->capnhatThongtin();
        }
}

void Dormitory::updateInformation(){
    int i;
        if(list_person[i]->selection()==true){
            list_person[i]->updateInformation();
        }
        else if ((list_person[i]->selection()==false)){
            list_person[i]->updateInformation();
        }
}

void Dormitory::capnhatID(){
    int found=0;
    string timkiem;
    cout << "Nhap ID day du de cap nhat: ";
    fflush(stdin);
    getline(cin, timkiem);
    for(int i=0;i<=list_person.size()-1;i++){
        if(timkiem==list_person[i]->getId()){
            found = 1;
            cout << "Cap nhat thong tin co ID: " << timkiem << endl;
            capnhatThongtin();
            break;
        }
    }
    if(found == 0){
        cout << "Khong ton tai!"<< endl;
    }
}

void Dormitory::updateID(){
    int found=0;
    string find;
    cout << "Enter the full ID to update: ";
    fflush(stdin);
    getline(cin, find);
    for(int i=0;i<=list_person.size()-1;i++){
        if(find==list_person[i]->getId()){
            found = 1;
            cout << "Update information with ID " << find << endl;
            updateInformation();
            break;
        }
    }
    if(found == 0){
        cout << "ID does not exist!"<< endl;
    }
}

void Dormitory::xoaID(){
    int found = 0;
    string xoa;
    cout << "Nhap ID day du de xoa: ";
    cin.ignore();
    getline(cin, xoa);
    for (int i = 0; i <= list_person.size()-1; i++){
        if (xoa == list_person[i]->getId()){
            found = 1;
            list_person.erase(list_person.begin()+i);
            cout << "\nDa xoa ID " << xoa << " ra khoi he thong!!!"<< endl;
            break;
        }
    }
    if(found == 0){
        cout << "ID khong ton tai!!!"<< endl;
    }
}

void Dormitory::deleteID(){
    int found = 0;
    string xoa;
    cout << "Enter the full ID to delete: ";
    cin.ignore();
    getline(cin, xoa);
    for (int i = 0; i <= list_person.size()-1; i++){
        if (xoa == list_person[i]->getId()){
            found = 1;
            list_person.erase(list_person.begin()+i);
            cout << "\nRemoved ID " << xoa << " from the system!!!"<< endl;
            break;
        }
    }
    if(found == 0){
        cout << "ID does not exist!!!"<< endl;
    }
}

void Dormitory::TongTien(){
    unsigned long int Tongluong=0;
    unsigned long int Tongphi=0;
    for (int i = 0; i < list_person.size(); i++){
    	
        if (list_person[i]->selection() == true){
            //list_person[i]->Xuat(i);
            list_person[i]->tinhtien();
            Tongphi=Tongphi+list_person[i]->getMoney();
        }else{
            list_person[i]->tinhtien();
            Tongluong=Tongluong+list_person[i]->getMoney();
        }
    }
    cout<<"Tong tien luong quan ly la: "<<Tongluong<<endl;
    cout<<"Tong tien phi ktx la: "<<Tongphi;
}
void Dormitory::TotalMoney(){
    unsigned long int Tongluong=0;
    unsigned long int Tongphi=0;
    for (int i = 0; i < list_person.size(); i++){
    	
        if (list_person[i]->selection() == true){
            //list_person[i]->Xuat(i);
            list_person[i]->tinhtien();
            Tongphi=Tongphi+list_person[i]->getMoney();
        }
        else{
            list_person[i]->tinhtien();
            Tongluong=Tongluong+list_person[i]->getMoney();
        }    
    }
    cout<<"Manager's total salary: "<<Tongluong<<endl;
    cout<<"Total dormitory rent: "<<Tongphi;
}

void menu(){
    giaodien();
    int chon;
    cout << "Nhap lua chon: ";
    cin >> chon;

}
	
