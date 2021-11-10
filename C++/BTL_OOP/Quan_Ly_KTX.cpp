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
    cout<<"So CMND: "<<identitycard<<endl;
    cout<<"So phong: "<<room<<endl;
    cout<<"So thang: "<< months<< endl;
    cout<<"Don gia: "<<unitprice<<endl;
    cout<<"So lan vi pham: "<<violations<<endl;
    this->tinhtien();
    cout<<"So tien can dong noi tru: "<< money << endl;
}

void Student::capnhatThongtin(){
    Person::capnhatThongtin();
    cout<<"Nhap so CMND: ";
    getline(cin, identitycard);
	fflush(stdin);
    cout<<"Nhap so phong: ";
    cin>>room;
	fflush(stdin);
    cout << "Nhap so thang: ";
    cin >> months;
    fflush(stdin);
    cout<<"Nhap don gia: ";
    cin>>unitprice;
	fflush(stdin);
    cout<<"Nhap so lan vi pham: ";
    cin>>violations;
	fflush(stdin);
}

void Student::updateInformation(){
    Person::updateInformation();
    cout<<"Enter Identity card number: ";
    getline(cin, identitycard);
	fflush(stdin);
    cout<<"Enter Room number: ";
    cin>>room;
	fflush(stdin);
    cout << "Enter Months number: ";
    cin >> months;
    fflush(stdin);
    cout<<"Enter Unit price: ";
    cin>>unitprice;
	fflush(stdin);
    cout<<"The number of violations: ";
    cin>>violations;
	fflush(stdin);
}

class Manage : public Person{
private:
    	unsigned long int coefficientssalary; //Tiền lương
    	string position; //Chức vụ
	string phone; //CMND
    	int seniority; //thâm niên
public: 
    Manage();
    ~Manage();
    unsigned long int getCoefficientssalary();
    void setCoefficientssalary(unsigned long int coefficientssalary);
    double getSalary();
    void setSalary(double salary);
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
unsigned long int Manage::getCoefficientssalary(){
    return coefficientssalary;
}
void Manage::setCoefficientssalary(unsigned long int coefficientssalary){
    this->coefficientssalary=coefficientssalary;
}
string Manage::getPosition(){
    return position;
}
void Manage::setPosition(string position){
    this->position=position;
}
string Manage::getPhone(){
	return phone;
}
void Manage::setPhone(string phone){
	this->phone=phone;
}

void Manage::Nhap(int &n){
    Person::Nhap(n);
    cout<<"Nhap so dien thoai: ";
    getline(cin, phone);
	fflush(stdin);
    cout<<"Nhap tham nien: ";
    cin>>seniority;
    fflush(stdin);
	cout<<"Nhap he so luong: ";
	cin>>coefficientssalary;
	fflush(stdin);
	cout<<"Nhap chuc vu: ";
	getline(cin,position);
}

void Manage::input(int &n){
    Person::input(n);
    cout<<"Enter your phone number: ";
    getline(cin, phone);
	fflush(stdin);
    cout<<"Enter seniority: ";
    cin>>seniority;
    fflush(stdin);
	cout<<"Enter salary: ";
	cin>>coefficientssalary;
	fflush(stdin);
	cout<<"Enter position: ";
	getline(cin,position);
}

void Manage::Xuat(int &n){
    Person::Xuat(n);
    cout<<"So dien thoai: "<<phone<<endl;
    cout<<"Tham nien: "<< seniority<< endl;
	cout<<"He so luong: "<<coefficientssalary<<endl;
	cout<<"Chuc vu: "<<position<<endl;
    this->tinhtien();
    cout<<"Luong: "<< money<< endl;
}

void Manage::output(int &n){
    Person::output(n);
    cout<<"Phone number: "<<phone<<endl;
    cout<<"Seniority: "<< seniority<< endl;
	cout<<"Salary: "<<coefficientssalary<<endl;
	cout<<"Position: "<<position<<endl;
    this->tinhtien();
    cout<<"Salary: "<< money<< endl;
}

void Manage::capnhatThongtin(){
    Person::capnhatThongtin();
    cout<<"Nhap so dien thoai: ";
    getline(cin, phone);
	fflush(stdin);
    cout<<"Nhap tham nien: ";
    cin>>seniority;
    fflush(stdin);
	cout<<"Nhap he so luong: ";
	cin>>coefficientssalary;
	fflush(stdin);
	cout<<"Nhap chuc vu: ";
	getline(cin,position);
}

void Manage::updateInformation(){
    Person::updateInformation();
    cout<<"Enter your phone number: ";
    getline(cin, phone);
	fflush(stdin);
    cout<<"Enter seniority: ";
    cin>>seniority;
    fflush(stdin);
	cout<<"Enter salary: ";
	cin>>coefficientssalary;
	fflush(stdin);
	cout<<"Enter position: ";
	getline(cin,position);
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
    void sapxepName();
    void SortName();
    void capnhatThongtin();
    void updateInformation();
    void capnhatID();
    void updateID();
    void timkiemAddress();
    void findAddress();
    void timkiemID();
    void findID();
    void xoaID();
    void deleteID();
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

void Dormitory::Xuat(){   
    system("cls");
	// inkhung();
    for (int i = 0; i < list_person.size(); i++){
    	
        if (list_person[i]->selection() == true)
            list_person[i]->Xuat(i);
        
    }
    for (int i = 0; i < list_person.size(); i++){
        
		
		if (list_person[i]->selection() == false)
            list_person[i]->Xuat(i);
    }
}

void Dormitory::output(){   
    system("cls");
	// inkhung();
    for (int i = 0; i < list_person.size(); i++){
    	
        if (list_person[i]->selection() == true)
            list_person[i]->output(i);
        
    }
    for (int i = 0; i < list_person.size(); i++){
        
		
		if (list_person[i]->selection() == false)
            list_person[i]->output(i);
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
	
