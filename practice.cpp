// ConsoleApplication3.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <deque>
#include <string>
#include <stdio.h>
using namespace std;

/* proproblem: 
1. De quy.
2. Thao tac tren list, stack, deque, queue.
3. Cac giai thuat tim kiem.
4. Xay dung cac ham va thao tac tren list. 
5. Luyen ++ lai.
6. Solve problem. 
*/


/*
int main()
{
	cout << "Hello! My name is LE ANH TUAN. \t \n" << endl; 
	char string1[200], string2[100]; 
	char ch[1];

	cout << "\n Enter string 1: "; 
	cin.getline(string1,200);
	cout << "\n Enter string 2: "; 
	cin.getline(string2, 200);
	cout << "String 1: " << string1 << ". String 2: " << string2; 

	cin.get(ch);
	cout << ch;

	cout << "enter a phrase: ";
	while (!ch.empty())
	{
		if (ch == '!')
			cin.putback('$');
		else
			cout << ch; 
		while (cin.peek() == '#')
			cin.ignore(1, '#');

		char one[] = "One if by land!";
		int x = strlen(one); 
		cout.write(one, x-4);


		cout << "start";
		cout.width(25); 
		cout.width('*');
		cout << "good!";

		printf("%s", "hello world \n"); 
		char *phase = "hello again!"; 
		printf("%s", phrase); 

		int x = 5; 
		printf("%d\n", x);  // %d, %s, %10.5f




	}


	return 0;
}
*/


/* I. Review basic command in C++
- Inline to get data from keyboard: 
getline (cin,films[n].title);

1. Week 1
* Day 1: Nothing 
* Day 2:
- ep kieu due lieu can hien thi sau tinh toan --> (float) 5/8
- new line: endl or "\n"
- using function: int Sum( int first, int second)
* Day 3: Working with Variables and Constants
	• How to declare and define variables and constants
	• How to assign values to variables and manipulate those values
	• How to write the value of a variable to the screen
- Cac kieu bien: int, short, double, long, char, bool, float. 4-2-8-4-1-1-4 bytes; 
- Others: unsigned short int, short int, unsigned long int, long int, bool, unsigned int, int, char, float, double. 
- Create an alieses with typedef. i.e. typedef unsigned short int USHORT; 
- Usign enum: 
	# include<iostream>
	# int main()
	{
	enum Days{Sunday, Monday, Tuesday, Wednessday, Thurday, Friday, Saturday};
	Days today; 
	today = Monday; 
	if (todday == Sunday)|| (today == Saturday) 
		cout << "Gotta' love the weekends! \n";
	else
		cout << "\n Back to work.! \n";
	return 0; 
	}
	-------------------------------------------------------------------------------------------------------------------------------------------
* Day 4: Creating Expressions and Statements 
- If: 
	if (expression1)
	{
	if (expression2)
	statement1;
	else
	{
	if (expression3)
	statement2;
	else
	statement3;
	}
	}
	else
	statement4;
- Module: Finding the remender of a division. 
- Local Variables Within Block. i.e., x= 8{ int x = 9} x. O day x ra ngoai block {} se mang gia tri khac trong {}
- Default parameters: i.e., long myFunction(int x = 50); Khi goi ham defaul thi chi can goi ham khong co tham so ben trong: myFunction(); 
  Voi ham nhieu tham so thi goi ham can chu y la nhung tham so nao defaul thi se viet sau. de goi ra se bo bot tham so phia sau di. 
- Overload function: Cho phep tao nhieu hon 1 ham voi cung ten. 
	int Double(int);
	long Double(long);
	float Double(float);
	double Double(double);
	-------------------------------------------------------------------------------------------------------------------------------------------
* Day 6: Understanding Object Oriented Programming 
- Declaring a Class: 
	class Cat 
	{
		unsigned int itsAge; 
		unsigned int itsWeight' 
		void Meow();
	}
- Accessing class  Members
	Cat Frisky; 
	Frisky.itsWeight = 50; 
	Frisky.Meo(); 

- Private Versus Public Access: The keyword public applies to all members in the declaration until the keyword private is encountered—and vice versa. This lets you easily declare
sections of your class as public or private.

	class Cat
	{
	public:
	unsigned int itsAge;
	unsigned int itsWeight;
	void Meow();
	};

- Making Member Data Private: 
// Cat class declaration
// Data members are private, public accessor methods
// mediate setting and getting the values of the private data

	Class Cat
	{
	public: 
		// public accessors
		unsinged int GetAge(); 
		void SetAge(unsigned int Age);
		unsigned int GetWeight();
		void SetWeight(unsigned int Weight);

		// public member functions
		void Meow();
	private: 
		unsigned int itsAge;
		unsigned int itsWeight; 

	}
	void Cat::SetAge(int age)
	{
		int itsAge = age; 
	}
	void Cat::GetAge()
	{
		return itsAge; 
	}

	void Cat::SetWeight(int weight)
	{
	int itsWeight = weight;
	}
	void Cat::GetWeight()
	{
	return itsWeight;
	}

	void Cat::Meow()
	{
		cout << "Say meo";
	}

	// main
	# int main()
	{
		Cat Tom;
		Tom.SetAge(2);
		Tom.GetAge();
		Tom.Meow();
	}

- USing Constructors and Destructors: 
	+ putting  ~Cat() and Cat(int initialAge) in public class;
	+ Then, takes no action to ~Cat() function. 

- Including const Member Functions: If you declare a class method const, you are promising that the method won’t change the value of any of the members of the class.
	void SomeFunction() const; i.e., int Cat::GetAge() const {return (itsAge++} --> violatates const!

- Khai bao class trong mot ham rieng: 

	#include "Cat.hpp"

	+ Declaring a Complete Class: 

	# include <isotream>
	using namespace std; 
	
	class Point {
		public: 
			void SetX(int x) {itsX = x;}
			void SetY(int y) {itsY = y;}
			void GetX() {return itsX;}
			void GetY() {return itsY;}
		private: 
			int itsX; 
			int itsY;
	};
	classs Rectangle{
		public: 
			Rectangle (int top, int left, int bottom, int right); 
			~Rectanle() {}

			int GetTop() const {return itsTop;}
			int GetLeft() const {return itsLeft;}
			int GetBottom() const {return itsBottom;}
			int GetRight() const {return itsRight;}

			Point GetUpperLeft() const { return itsUpperLeft; }
			Point GetLowerLeft() const { return itsLowerLeft; }
			Point GetUpperRight() const { return itsUpperRight; }
			Point GetLowerRight() const { return itsLowerRight; }

			void SetUpperLeft(Point Location) {itsUpperLeft = Location;}
			void SetLowerLeft(Point Location) {itsLowerLeft = Location;}
			void SetUpperRight(Point Location) {itsUpperRight = Location;}
			void SetLowerRight(Point Location) {itsLowerRight = Location;}

			void SetTop(int top) { itsTop = top; }
			void SetLeft (int left) { itsLeft = left; }
			void SetBottom (int bottom) { itsBottom = bottom; }
			void SetRight (int right) { itsRight = right; }

			int GetArea() const;
		
		private: 

			Point itsUpperLeft;
			Point itsUpperRight;
			Point itsLowerLeft;
			Point itsLowerRight;
			int itsTop;
			int itsLeft;
			int itsBottom;
			int itsRight;
	};



	Rectangle::Rectangle(int top, int left, int bottom, int right)
	{
		itsTop = top; 
		itsLeft = left;
		itsBottom = bottom; 
		itsRight = right;	

		itsUpperLeft.SetX(left);
		itsUpperLeft.SetY(top);
	
		itsUpperRight.SetX(right);
		itsUpperRight.SetY(top);
	
		itsLowerLeft.SetX(left);
		itsLowerLeft.SetY(bottom);
	
		itsLowerRight.SetX(right);
		itsLowerRight.SetY(bottom);
	}
	
	
	// compute area of the rectangle by finding sides,
	// establish width and height and then multiply
	int Rectangle::GetArea() const
	{
		int Width = itsRight-itsLeft;
		int Height = itsTop - itsBottom;
		return (Width * Height);
	}
	
	int main()
	{
		//initialize a local Rectangle variable
		Rectangle MyRectangle (100, 20, 50, 80 );
	
		int Area = MyRectangle.GetArea();
	
		std::cout << “Area: “ << Area << “\n”;
		std::cout << “Upper Left X Coordinate: “;
		std::cout << MyRectangle.GetUpperLeft().GetX();
		return 0;
	}
-------------------------------------------------------------------------------------------------------------------------------------
* Day 7: More on Program Flow: 
// Looping with goto: 

int main()
{
loop: 
	counter ++;
	if (counter<5) 
		go to loop; 
	cout << "Complete. 
	goto end

end: 
	cout << "done";

}


// while loop: 
	while (counter <5) 
	{
	counter++; 
	cout << "couter: << counter << endl";
	}
// switch (expression) 
{
	case valueOne: 
				statement; 
				break;
	default:   
				statement; 
				break; 

}
-------------------------------------------------------------------------------------------------------------------------------------
-------------------------------------------------------------------------------------------------------------------------------------
-------------------------------------------------------------------------------------------------------------------------------------

* Week 2
* Day 8: Understanding Pointers

• What pointers are
• How to declare and use pointers
• What the free store is and how to manipulate memory
int main(0
{
	unsigned short shortVar=5;
	cout << "shortVar = " << shortVar;
	cout << "\t Address of shortVar: \t" << &shortVar << endl; 
}

- Storing a Variable's Address in a Pointer: thay doi gia tri cua pointer va bien se cung thay doi gia tri cua nhau. 

+ declares pAge to be a pointer to an int. 
int howOld; 
int *pAge = 0; // make a pointer 
pAge = &howOld; // put howOld's address in pAge; 
or 
typedef unsigned short int USHORT;
USHORT myAGe; 
USHORT * pAge = 0; 
myAge = 5; 
pAGe = &myAge; 

- delete pointer: delete pAge; 
- We can create pointer to any data type including classes: Cat *pCat =  new Cat; DUng nhu binh thuong trong class. 

Khi truy cap thi dung (*pCat).setAge() hoac pCat->setAge(); 

? Dat Poiter ben trong bien cua class de lam gi? 

this->itsLength = length;

-------------------------------------------------------------------------------------------------------------------------------------
* Day 9: Exploiting References 
• What references are
• How references differ from pointers
• How to create references and use them
• What the limitations of references are
• How to pass values and objects into and out of functions by reference

- Cach khai bao: 
	int intOne;
	int &rSomeRef = intOne; ca hai gia tri se giong nhau khi thay doi 1 trong hai( Cung dia chi, cung gia tri nhu con tro)  
- Khi da gan dau tien vao dia chinao thi no se giu dia chi do. Khi ca no cung da an dinh den bien khac. 
- Truoc khi khoi tao refer thi phai tao bien tham chieu ( data), sau do refer den gia tri khoi tao. Vi du: 

int howBig = 200;
int & rCatRef = Cat; // wrong
int & reCatRef = howBig

- ? Lam the nao de tra null pointer and null references 
Day 12: Su ke thua trong lop. 
- Khai bao lop dau tien
- Khai bao lop thu 2 ke thua lop dau tien
class Mammal: 

class Dog: public Mamal

-------------------------------------------------------------------------------------------------------------------------------------
Day 13: Array

Khoi tao mang: 
int IArray[5] = {1,2,3,4,5};


Using consts and enums in Arrays: 

int main()
enum = {sun, mon, tue, wed, thur, fri, sat, daysinweek}
int ArrayWeek[daysinweek] = {1,2,3,4,5,6,7}
cout << ArrayWeek[tue]; // 3

- Using array of objective: 

Cat Tom[5]; 
- Multidimention: 

int SomeArray[2][5] = {{0,1,2,3,4},{0,2,3,4,5}};


- Building arrays of pointers. 

Cat * Family[500];
int i; 
Cat * pCat; 
for (int i = 0; i< 500; i++) 
{
pCat = new Cat; // pointer 
pCat->SetAge(2*i+1);
Family[i] = pCat; 
}

for (i=0; i<500; i++)
{
	cout << Family[i]->GetAge() << endl; 
}


The advantage of using Family in this way is that you can use pointer arithmetic to
access each member of Family. For example, you can write
Cat *Family = new Cat[500];
Cat *pCat = Family; //pCat points to Family[0]
pCat->SetAge(10); // set Family[0] to 10
pCat++; // advance to Family[1]
pCat->SetAge(20); // set Family[1]


---------------------------------------------------------------------------------------
Day 13:

- create a buffer: 
char buffer[80]; 
cin.get(buffer, 79); // get up to 79 of newline. 



- Using strcpy(0 and strncpy() methods: 

- printf based on C function: 

		//17.15 Printing with printf()
		1: #include <stdio.h>
		2:
		3: int main()
		4: {
		5: printf(“%s”,”hello world\n”);
		6:
		7: char *phrase = “Hello again!\n”;
		8: printf(“%s”,phrase);
		9:
		10: int x = 5;
		11: printf(“%d\n”,x);
		12:
		13: char *phraseTwo = “Here’s some values: “;
		14: char *phraseThree = “ and also these: “;
		15: int y = 7, z = 35;
		16: long longVar = 98456;
		17: float floatVar = 8.8f;
		18:
		19: printf(“%s %d %d”, phraseTwo, y, z);
		20: printf(“%s %ld %f\n”,phraseThree,longVar,floatVar);
		21:
		22: char *phraseFour = “Formatted: “;
		23: printf(“%s %5d %10d %10.5f\n”,phraseFour,y,z,floatVar);
		24:
		25: return 0;
		26: }




--------------------------------------------------------------------------------------------------------------------------
Day 17: Using the ofstream;

Opening files for input and output: 

ofstream fout("myfile.cpp"); 
ifstream fin("myfile.cpp"); 


For example: 

#include<fstream>

using namespace std;
int main()
{
char fileName[80];
char buffer[255];
cout << "File name: ";
cin >> fileName;

ofstream fout(fileName); // open for writing
fout << "This line writeen dirrenctly to the file ... \n ";
cout << "Enter text for the file: ";
cin.ignore(1, '\n');
cin.getline(buffer, 255);
fout << buffer << "\n";
fout.close();

ifstream fin(fileName);
cout << "Here's the contens of the line: \n";

char ch;
while (fin.get(ch))
{
cout << ch;

}
cout << "\n End of file contents.";
fin.close();
return 0;
}

*/



/*Ham friend trong C++ 

Hàm friend trong C++ của một lớp được định nghĩa bên ngoài phạm vi lớp đó, nhưng nó có quyền truy cập tất cả thành viên private và protected của lớp đó.

Một friend có thể là một hàm, một mẫu hàm, hoặc hàm thành viên, hoặc một lớp hoặc một mẫu lớp, trong trường hợp này, toàn bộ lớp và tất cả thành viên của nó là friend.

For example: 

class Box{
	double chieurong;
	public: 
		friend void InChieruRong(Box box); 
		void SetChieuRong(double rong); 
		};

void InChieuRong(Box box)
{
cout << box.chieurong;
}
void SetChieuRong(double rong)
{
	chieurong = rong;
}
int main()
{
	Box box; 
	SetChieuRong(20.5); 
	InChieuRong(box); 

}



*/


/*
Lop ke thua: 

class lop_ke_thua: access_modifier lop_co_so

class Hinh{
		protected: 
			int ChieuRong;
			int ChieuCao; 
		public:
			SetChieuRong(int rong) {ChieuRong = rong;}
			SetChieuCao(int cao) {ChieuCao = cao;} 

// day la lop ke thua: 

class HinhChuNhat: public Hinh{
	puplic: 
		int tinhDientich()
		{
		return chieurong * chieucao; 
		}
	
};


// ham main

int main()
{
Hinh *hinh; 
HinhChuNhat HCN; 
HCN.SetChieuRong(10); 
HCM.SetChieuCao(20.5);


hinh = &HCN;
hinh.tinhDientic();


hinh.dientich(); 



}


-------------------------------------
Nạp chồng hàm trong C++
Bạn có thể có nhiều định nghĩa cho cùng tên hàm trong cùng phạm vi

---------------------------------------
Nap chong toan tu + de cong hai doi tuong nhu sau:
Box3 = Box1 + Box2;

Tinh da hinh: co nhieu hinh thai khac nhau. Tieu bieu la khi xuat hien khi co mot cau truc cap bac cua lop va chung lien quan den nhau boi tinh ke thua. 
Vi du trong xet tai lop hinh: 
	int dientich()
      {
         cout << "Dien tich cua lop cha:" <<endl;
         return 0;
      }
	  ---------------------------------------

	  Câu lệnh struct định nghĩa một kiểu dữ liệu mới, với hơn một thành viên trong chương trình của bạn. Dạng tổng quát của câu lệnh struct như sau đây:

	  struct [ten cau truc]
	  {
	  phan dinh nghia thanh vien;
	  phan dinh nghia thanh vien;
	  ...
	  phan dinh nghia thanh vien;
	  } [mot hoac nhieu bien cau truc];

	  Để truy cập bất kỳ thành viên nào của cấu trúc, bạn sử dụng toán tử truy cập phần tử (.). Toán tử truy cập thành viên cấu trúc được mã hóa là dấu chấm giữa tên biến cấu trúc và thành viên cấu trúc mà bạn muốn truy cập.
	  ---------------------------------------

	  Standard Log Stream (clog) trong C++
	  cout, cerr và clog

	  ----------------------------------------
	  Con trỏ là gì?
	  Một con trỏ là một biến mà trong đó giá trị của nó là địa chỉ của biến khác. Ví dụ như địa chỉ của vùng nhớ
	  ----------------------------------------
	  cap phat dong:

	  double* contro  = NULL; // con tro duoc khoi tao voi gia tri null
	  contro  = new double;   // yeu cau bo nho cho bien


	  Để xóa mảng mà chúng ta vừa tạo, cú pháp trong C/C++ là:

	  delete [] contro;        // xoa mang da duoc tro boi contro



	  // noi hai chuoi: chuoi1 va chuoi2 
	  #include<cstring>
	  strcat( chuoi1, chuoi2); //strlen, strcpy, strncpy; 
	  chuoi3.string();

*/

/*

Ke thua tu nhieu lop, tinh da hinh. 

#include <iostream>
using namespace std; 

// Khai bao cac lop

class Hinh {
public: 
	void setChieuRong(int a); 
	void setChieuDai(int b); 
protected:
	int chieurong; 
	int chieudai; 
};

class ChiPhi {
public:
	void setCost(int c = 0); 

	void TinhChiPhi(int dt = 0)
	{
		cout << "\n Chi Phi la: " << dt *cost << " $." << endl; 
	}
private: 
	int cost; 
};

class HinhChuNhat :public Hinh, public ChiPhi
{
public:
	int tinhdientich()
	{	
		int dt = chieudai * chieurong;
		cout << "\n Dientinh la:" << dt << " m2." << endl;

		return dt;
	}
};

// Khai bao cac ham thanh vien
void ChiPhi::setCost(int c)
{
	cost = c; 
	cout << "\n Chi phi tren 1 m2 la: " << cost << " $." << endl; 
}

void Hinh::setChieuDai(int a)
{
	chieudai = a; 
}

void Hinh::setChieuRong(int b)
{
	chieurong = b;
}

int main()
{
	HinhChuNhat HCN; 
	HCN.setChieuDai(20); 
	HCN.setChieuRong(10); 
	int dientich = HCN.tinhdientich(); 

	HCN.setCost(4); 
	HCN.TinhChiPhi(dientich);

	return 0;
}
*/



/*
// Chu y: Protected thường được dùng khi bạn biết chắc là có lớp khác sẽ kế thừa lớp này và những phương
thức, thuộc tính đó chỉ được dùng trong lớp kế thừa nó.

// Giả sử bạn khai báo lớp Động Vật, trong đó có hàm lưu dữ liệu động vật vào database, hàm này dùng chung
cho tất cả các lớp con kế thừa lớp Động Vật.Và để bảo mật nên tôi không muốn ở bên ngoài lớp có thể sử
dụng được, vì vậy tôi khai báo là protected.
*/






/*
- Struct: 
struct product {
int weigt;
double price;
} banana, orange, apple,  films [3]; 
// Note: if we use files [x], we create an array of the product. 
*/
// example of struct bai toan quan ly sinh vien: 


/* 
I. Phan tich yeu cau bai toan: 

1. Doc va luu tru du lieu cua hoc sinh tu mot text file. 
2. Thong tin cua hoc sinh bao gom ten, lop, dia chi, va dien so 3 mon: Toan, Van, Anh. 
3. Cho phep liet ke tat ca hoc sinh, hoac loc hoc sinh theo ten, lop, dia chi hoac diem so. 

II. Phan tich yeu cau output khi chay: 
  Moi ban lua chon: 
  1. Mo file cu 	
  2. Ta0 file moi
  3. Exit 

  1-2.1 In ra toan bo hoc sinh
  1-2.2. Loc lay mot so hoc sinh
  1-2.3. Them hoc sinh 
  1-2.4. Chinh sua
  1-2.5. Xoa thong tin hoc sinh 
  1-2.6. Ket thuc va dong file. 

  1-2.2.1. Loc duoc thong tin theo dang chu co so thong tin trung voi gia tri nhap vao. 
  1-2.2.1. Loc duoc thong tin theo dang so co so, ta co the lua chon lay cac gia tri bang, lon hon, nho hon, ... 

III. Problem solve: 
1. Dung cau truc struct de viet chuong trinh loi. 



2. Luu tru file 
3. Doc file. 
4. Loc file. 
5. Tim kiem. 

6. Cac ham se dung: switch, for, if, ... 
*/



/*
// Mở file
ifstream input;
isEditing
number
mathScore, literatureScore, englishScore; // diem so 3 mon
currentFile 
searchStudentByString
searchStudentByScore
decode(string s); encode
strcpy_s
ifstream input;
input.open(currentFile);
input.close();
inputStudentInfo(int id);
addStudent()
string temp; getline(cin, temp);
deleteStudent();
string data; getline(cin, data); getline(cin, data);
searchStudentByString(byWhat, data);
strcmp(currentFile, "") != 0
output.close();
*/

// Khai bao cac ham thu vien 
#include<iostream>
#include<fstream>
#include<string>

// fstream, string, ifstream, ofstream = output. output.open(namefile), 

using namespace std; 
int main()
{

	string s = "toi la ai";
	string t = " "; 
	char s1[] = "adf"; 
	char s2[] = "bcd";

	cout << s+t << strcat(s1,t2); 


		return 0; 

}
/*

// globle variable
bool isEditingFile = true;
char currentFile[200]=""; 
int numberOfStudent = 0; 

// student date in struct: 

struct Student { 
	int id; 
	double math, literature, english;
	string fullname, classID, address, sex, birthday; 
};
Student allStudentList[10000]; // struct of all student list. 


// function initialization: 
int getInRange(int a, int b); 
void openFile();
string decode(string s);
string encode(string s);
void newFile();
void saveFile();
void printStudentInfo(int student_id);
void printStudentList(); 



// functions:
int getInRange(int a, int b) // check input number belong to the range from a to b for selecting actions. 
{	
	bool check = false; 
	int input1;
	while (check == false)
	{
		cout << "\n Enter a value: \n";
		cin >> input1; 
		if (input1 < a || input1 > b)
		{
			cout << "Please try again. Range selection is (" << a << ", " << b << ")";
		}
		else
			check = true;
	}
	return input1; 
}

string decode(string s)
{
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '$')
		{
			s[i] = ' '; 
		}
	}
	return s; 
}

string encode(string s)
{
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == ' ')
		{
			s[i] = '$';
		}
	}
	return s;
}

void openFile()
{
	cout << "Enter the file name to open"; 
	cin >> currentFile; 
	ifstream input; 
	input.open(currentFile); // open file
	input >> numberOfStudent; // read number of students
	for (int i = 1; i <= numberOfStudent; i++) // read each line
	{
		input >> allStudentList[i].id;  // update to id

		input >> allStudentList[i].fullname; // update to name
		allStudentList[i].fullname = decode(allStudentList[i].fullname); // decode data
		
		input >> allStudentList[i].classID; // update to class id
		allStudentList[i].classID = decode(allStudentList[i].classID);
		
		input >> allStudentList[i].sex; // update to sex 
		allStudentList[i].sex = decode(allStudentList[i].sex);

		input >> allStudentList[i].birthday; // update to birthay		
		allStudentList[i].birthday = decode(allStudentList[i].birthday);

		input >> allStudentList[i].address;  // update to address; 		
		allStudentList[i].address = decode(allStudentList[i].address);
		
		input >> allStudentList[i].math;  // update to math; 
		input >> allStudentList[i].literature; // update to liturature; 
		input >> allStudentList[i].english; // update to english; 
	}

	input.close(); // close file. 
	isEditingFile = true;  // confirm the file is opening and editing. 
	return; 

}

void newFile()
{
	cout << "Initialized list and file";
	numberOfStudent = 0; // number of student 
	strcpy_s(currentFile, ""); // set to empty to current file. 
	isEditingFile = true; 
}

void exitFile()
{
	cout << "\n Do you want to save file? " << endl; 
	cout << "\n 1: yes, 0 : no. Please select an action."; 
	int input = getInRange(0, 1); 
	ofstream output; 
	output.open(currentFile); 

	if (input == 1)
	{
		saveFile();
	}
	output.close();
	isEditingFile = 0; // ??? do we need this 
}

void saveFile()
{
	// compare two string 
	if (strcmp(currentFile, " ") != 0)
	{
		cout << "\n Do you want to save to a new file or old file?";
		cout << "\n 1. Save to a old file";
		cout << "\n 2. Save to an new file";
		int input = getInRange(1, 2);
		if (input == 2)
		{
			cout << "\n Enter new file name: ";
			cin >> currentFile;
		}
	}
	else
		{
			cout << "\n Enter old file name: ";
			cin >> currentFile; 
		}
	// open file 
	ofstream output; 
	output.open(currentFile); 
		
	// write to the file:  // not delete all information before writing. How? 
	output << numberOfStudent; // update the number of student. 
	if (numberOfStudent>=1)
		{
		for (int i = 1; i <= numberOfStudent; i++) 
			{
			output << allStudentList[i].id;  // update to id
			
			allStudentList[i].fullname = encode(allStudentList[i].fullname); // decode data
			output << allStudentList[i].fullname; // update to name
			
			allStudentList[i].classID = encode(allStudentList[i].classID);
			output << allStudentList[i].classID; // update to class id
			
			allStudentList[i].sex = encode(allStudentList[i].sex);
			output << allStudentList[i].sex; // update to sex 
			
			allStudentList[i].birthday = encode(allStudentList[i].birthday);
			output << allStudentList[i].birthday; // update to birthay
			
			allStudentList[i].address = encode(allStudentList[i].address);
			output << allStudentList[i].address;  // update to address; 			
			
			output << allStudentList[i].math;  // update to math; 
			output << allStudentList[i].literature; // update to liturature; 
			output << allStudentList[i].english; // update to english; 
			}
		}
	output.close();	
}


void printStudentInfo(int student_id)
{
	cout << "\n Student id: " << allStudentList[student_id].id << endl;  // update to id
	cout << "\n Student name: " << allStudentList[student_id].fullname << endl;  // update to id
	cout << "\n Student classID: " << allStudentList[student_id].classID << endl;  // update to id
	cout << "\n Student sex: " << allStudentList[student_id].sex << endl;  // update to id
	cout << "\n Student birthday: " << allStudentList[student_id].birthday << endl;  // update to id
	cout << "\n Student address: " << allStudentList[student_id].address << endl;  // update to id
	cout << "\n Student math score: " << allStudentList[student_id].math << endl;  // update to id
	cout << "\n Student literature score: " << allStudentList[student_id].literature << endl;  // update to id
	cout << "\n Student english score: " << allStudentList[student_id].english << endl;  // update to id
}

void printStudentList()
{
	if (numberOfStudent != 0)
	{
		for (int i = 1; i <= numberOfStudent; i++)
		{   
			cout << "\n Student 1 information: " << endl;
			printStudentInfo(i); 
		}
	}
	else
	{
		cout << "\n Number of student equals to zero. Empty list. " << endl; 
	}
}

void updateStudentInfo(int student_id);

void updateStudentInfo(int student_id)
{
	cout << "\n Update information to student id: " << student_id; allStudentList[student_id].id = student_id; cout << endl;  // update to id
	cout << "\n Enter student name: "; cin >> allStudentList[student_id].fullname; cout << endl;  // update to id
	cout << "\n Enter student classID: "; cin >> allStudentList[student_id].classID; cout << endl;  // update to id
	cout << "\n Enter student sex: "; cin >> allStudentList[student_id].sex; cout << endl;  // update to id
	cout << "\n Enter student birthday: "; cin >> allStudentList[student_id].birthday; cout << endl;  // update to id
	cout << "\n Enter student address: "; cin >> allStudentList[student_id].address; cout << endl;  // update to id
	cout << "\n Enter student math score: "; cin >> allStudentList[student_id].math; cout << endl;  // update to id
	cout << "\n Enter student literature score: "; cin >> allStudentList[student_id].literature; cout << endl;  // update to id
	cout << "\n Enter student english score: "; cin >> allStudentList[student_id].english; cout << endl;  // update to id	
}

void editStudent();
void editStudent()
{   
	cout << "\n Enter a student ID number: " << endl; 
	int student_id; 
	student_id = getInRange(1,numberOfStudent);
	updateStudentInfo(student_id);
}

void addStudent();
void addStudent()
{
	numberOfStudent++;
	updateStudentInfo(numberOfStudent);
}

void deleteStudent();
void deleteStudent()
{
	cout << "\n Enter a student ID number to delete: " << endl; 
	int student_id = getInRange(1, numberOfStudent);
	for (int i = student_id; i <= numberOfStudent; i++)
	{
		allStudentList[student_id - 1] = allStudentList[student_id];
	}
	numberOfStudent--; // reduce one student; 
}


void filter_student(int input);
void filter_student(int input)
{

}

void filterStudent();
void filterStudent()
{
	string input1, input3, input4,input5, input6, input7;
	string input2;
	int input0; 
	int couter = 0;
	cout << "\n Enter student information to put into filter." << endl; 
	cout << "\n 1. Follows student id" << endl
		<< "\n 2. Follows student classID " << endl
		<< "\n 3. Follows student name " << endl
		<< "\n 4. Follows student sex " << endl
		<< "\n 5. Follows student address " << endl
		<< "\n 6. Follows student birthday " << endl
		<< "\n 7. Follows student score " << endl;
	int input = getInRange(1, 7); 	
	switch (input)
	{
	case 1:
		cout << "\n Enter student_id: "; 
		input0 = getInRange(1, numberOfStudent); 
		for (int i = 1; i <= numberOfStudent; i++)
		{
			if (input0 == i)
			{
				printStudentInfo(i);
				couter++;
			}
		}
		break; 
	case 2: 
		cout << "\n Enter class_id: ";
		cin >> input2; 
		cout << "\n Students in the class_id " << input2 << " are: " << endl;
		for (int i = 1; i <= numberOfStudent; i++)
		{
			if (allStudentList[i].classID == input2)
			{
				printStudentInfo(i);
				couter++;
			}
		}
		break; 
	case 3:
		cout << "\n Enter name: ";
		cin >> input3;
		cout << "\n Students name: " << input3 << " are: " << endl;
		for (int i = 1; i <= numberOfStudent; i++)
		{
			if (allStudentList[i].fullname == input3)
			{
				printStudentInfo(i);
				couter++;
			}
		}		
		break; 
	case 4: 
		cout << "\n Enter sex: ";
		cin >> input4;
		cout << "\n Students sex: " << input4 << " are: " << endl;
		
		for (int i = 1; i <= numberOfStudent; i++)
		{
			if (allStudentList[i].sex == input4)
			{
				printStudentInfo(i);
				couter++;
			}
		}		
		break;
	case 5:	
		cout << "\n Enter province name: ";
		cin >> input5;
		cout << "\n Students address at " << input5 << " are: " << endl;

		for (int i = 1; i <= numberOfStudent; i++)
		{
			if (allStudentList[i].address == input5)
			{
				printStudentInfo(i);
				couter++;
			}
		}
		break;
	case 6:
		cout << "\n Enter birthday: ";
		cin >> input6;
		cout << "\n Students with birthday of " << input6 << " are: " << endl;

		for (int i = 1; i <= numberOfStudent; i++)
		{
			if (allStudentList[i].birthday == input6)
			{
				printStudentInfo(i);
				couter++;
			}
		}
		break;
	case 7:
		cout << "\n Enter subject: ";
		cin >> input7;
		if (input2 == "math")
		{

		}
		else if (input7 == "literature")
		{

		}
		else if (input7 == "english")
		{

		}

		break;
	default:		
		break; 
	}

	cout << "Found " << couter << "students";

}


////////////////////////////////// main /////////////////////////////
int main()
{
	// cout << !isEditingFile;  // return 0; 
	while (true) // checking the file is open or not. 
	{
		if (!isEditingFile)
		{
			cout << "\n Hello, please kindly select an action in range (1-3): \n";
			cout << "\n 1. Open old file \n";
			cout << "\n 2. Create a new file \n";
			cout << "\n 3. Exit \n";			
			int input = getInRange(1, 3);
			switch (input)
			{
			case 1:
				openFile(); // open an old file
				break;
			case 2:
				newFile(); // create a new file;
				break;
			case 3:
				exitFile(); // exit programe 
				break;
			default:
				cout << "/n try again"; 
				break;
			}
		}
		else
		{
			cout << "\n Choose an action number (1-8)\n "	<< endl;
			cout << "\n 1. printStudentList"				<< endl; 
			cout << "\n 2. filterStudent"					<< endl;
			cout << "\n 3. addStudent "						<< endl;
			cout << "\n 4. editStudent "					<< endl; 
			cout << "\n 5. deleteStudent "					<< endl; 
			cout << "\n 6. saveFile"						<< endl; 
			cout << "\n 7. closeFile"						<< endl;
			cout << "\n 8. exitFile"						<< endl;
			int input = getInRange(1, 8);
			switch (input)
			{
			case 1: 
				printStudentList(); 
				break;
			case 2:
				filterStudent();
				break;
			case 3:
				addStudent(); 
				break;
			case 4:
				editStudent(); 
				break;
			case 5:
				deleteStudent();
				break;
			case 6:
				saveFile(); 
			case 7:
				exitFile();
			case 8:				
				break;
			}

		}		

	}
}
*/


/* 2. Review problems in Cau Truc Du Lieu va Giai Thuat (list, ..., searching alrithm) in C++
- Ky thuat tim kiem searching: 
typede




*/

/* 3. Thuc hanh tao cac cau truc du lieu va giai thuat


#include <iostream>
using namespace std; 
struct Date
{
	int month; 
	int day; 
	int year; 
}; 
Date dueDate = { 12,31,2018 };
*/


/* 4. Lam de and problem solving. 

*/

