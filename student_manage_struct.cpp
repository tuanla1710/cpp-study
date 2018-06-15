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

// Khai bao cac ham thu vien 
#include<iostream>
#include<string> 
#include<fstream>
using namespace std; 
bool isEditing = false; // global variable
char currentFile[100];
int number = 0;

// Data struct: 
struct Student
{
	string name, inClass, address; 	
	unsigned short int id; // Chi co dang so thoi. 
	double mathScore, literatureScore, englishScore; // diem so 3 mon
};

Student allStudent[10000]; // tao record or array size for all student. 


// functions:

// de dam bao gia tri chon vao nam trong 1 dai, ta phai gioi han so nhap vao. 
int getInRange(int low, int high); 

void searchStudentByString(int byWhat, string value);
void searchStudentByScore(int byWhat, double value, int compare);

// detail function

int getInRange(int low =0, int high =2)
{
	int e = 0;
	int value;
	while (e != 1)
	{
		cin >> value; 
		if (value < low || value > high)
			cout << "Please enter the number in range (" << low << " , " << high << "). Try again!";
		else
			cout << "OK. Let's continue!"; 
			e = 1; 
	}
	return value; 	
}



// Doc du lieu tu file: 

/* Do dữ liệu trong file mã hóa các dấu cách, nên ta cần phải giải mã chúng khi đọc file.
Ta sẽ viết hai hàm decode() và encode() để giải mã và mã hóa string - chỉ cần duyệt qua toàn bộ string, và thay các kí tự $ bằng dấu cách.
*/
string decode(string s);
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

string encode(string s);
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


// Ok, có mã hóa và giải mã rồi, giờ ta sẽ bắt tay vào viết hàm void openFile().

void newFile();
void newFile()
{
	// chua co hoc sinh nao trong danhsach 
	number = 0; // global variable;
	// File chua dc luu, do do khong co ten file. 
	strcpy_s(currentFile, ""); // empty
	isEditing = true;
}


void openFile();
void openFile()
{
	// Luu ten file lai de dung ve sau: 
	cout << "Enter fileName to create: ";
	cin >> currentFile; 

	// Mo file: 
	ifstream input; 
	input.open(currentFile);

	// Đọc dữ liệu tung hang
	input >> number;
	for (int i = 1; i <= number; i++)
	{
		input >> allStudent[i].id;
		
		input >> allStudent[i].name;
		allStudent[i].name = decode(allStudent[i].name);
		input >> allStudent[i].inClass;
		allStudent[i].inClass = decode(allStudent[i].inClass);
		input >> allStudent[i].address;
		allStudent[i].address = decode(allStudent[i].address);

		input >> allStudent[i].mathScore;
		input >> allStudent[i].literatureScore;
		input >> allStudent[i].englishScore;
	}

	// Close file
	input.close(); 

	// Thong bao da co file dang dc chinh sua. 
	isEditing = true; 
}

void inputStudentInfo(int id);
void inputStudentInfo(int id)
	{
		string temp; getline(cin, temp);
		cout << "Ten cua hoc sinh?\n";
		getline(cin, allStudent[id].name);
		cout << "Lop?\n";
		getline(cin, allStudent[id].inClass);
		cout << "Dia chi?\n";
		getline(cin, allStudent[id].address);
		cout << "Diem mon Toan?\n"; cin >> allStudent[id].mathScore;
		cout << "Diem mon Van?\n"; cin >> allStudent[id].literatureScore;
		cout << "Diem mon Anh?\n"; cin >> allStudent[id].englishScore;
	}
// sau day viet ham sau: 

void addStudent();
void addStudent()
{
	number++; 
	inputStudentInfo(number); 
}

void editStudent();
void editStudent()
{
	int id;
	cout << "Hay nhap ma so hoc sinh: ";
	cin >> id;
	if (id < 1 || id > number)
	{
		cout << "Ma so hoc sinh khong hop le!\n";
		return;
	}
	inputStudentInfo(id);
}

// Xoa tohng tin hoc sinh: 
void deleteStudent();

void deleteStudent()
{
	int id;
	cout << "Hay nhap ma so hoc sinh: ";
	cin >> id;
	if (id < 1 || id > number)
	{
		cout << "Ma so hoc sinh khong hop le!\n";
		return;
	}
	// Đẩy các học sinh phía sau về đúng chỗ
	for (int i = id + 1; i <= number; i++)
		allStudent[i - 1] = allStudent[i];
	number--; // Bớt đi một học sinh
}

void printStudentInfo(int id)
{
	cout
		<< "Ma so hoc sinh: " << id << '\n'
		<< allStudent[id].name << ", hoc sinh lop " << allStudent[id].inClass << ", song tai " << allStudent[id].address
		<< '\n'
		<< "Diem mon Toan: " << allStudent[id].mathScore
		<< '\n'
		<< "Diem mon Van: " << allStudent[id].literatureScore
		<< '\n'
		<< "Diem mon Anh: " << allStudent[id].englishScore
		<< '\n';
}

void printAllStudent()
{
	for (int i = 1; i <= number; i++)
		printStudentInfo(i);
}


void searchStudent()
{
	cout << "Ban muon tim kiem hoc sinh theo thong tin nao?\n";
	cout << "1: Ten\n";
	cout << "2: Lop\n";
	cout << "3: Dia chi\n";
	cout << "4: Diem Toan\n";
	cout << "5: Diem Van\n";
	cout << "6: Diem Anh\n";
	int byWhat = getInRange(1, 6);
	if (byWhat <= 3) // Ba thông tin kiểu string
	{
		cout << "Nhap gia tri can tim: ";
		string data; getline(cin, data); getline(cin, data);
		searchStudentByString(byWhat, data);
	}
	else // Ba thông tin kiểu số
	{
		cout << "Nhap gia tri can tim: ";
		double data; cin >> data;

		cout << "Ban muon so sanh nhu the nao?\n";
		cout << "1: =\n";
		cout << "2: >\n";
		cout << "3: <\n";
		cout << "4: >=\n";
		cout << "5: <=\n";
		int compare = getInRange(1, 5);

		searchStudentByScore(byWhat, data, compare);
	}
}


void searchStudentByString(int byWhat, string value)
{
	for (int i = 1; i <= number; i++)
	{
		// Lấy dữ liệu phù hợp
		string data;
		switch (byWhat)
		{
		case 1: // Tìm theo tên
			data = allStudent[i].name;
			break;
		case 2: // Tìm theo lớp
			data = allStudent[i].inClass;
			break;
		case 3: // Tìm theo địa chỉ
			data = allStudent[i].address;
			break;
		}

		// So sánh với yêu cầu
		if (data == value)
			printStudentInfo(i);
	}
}

void searchStudentByScore(int byWhat, double value, int compare)
{
	for (int i = 1; i <= number; i++)
	{
		// Lấy dữ liệu phù hợp
		double data;
		switch (byWhat)
		{
		case 4: // Tìm theo điểm môn Toán
			data = allStudent[i].mathScore;
			break;
		case 5: // Tìm theo điểm môn Văn
			data = allStudent[i].literatureScore;
			break;
		case 6: // Tìm theo điểm môn Anh
			data = allStudent[i].englishScore;
			break;
		}

		bool check;

		// So sánh phù hợp với phép toán
		switch (compare)
		{
		case 1: // =
			check = (data == value);
			break;
		case 2: // >
			check = (data > value);
			break;
		case 3: // <
			check = (data < value);
			break;
		case 4: // >=
			check = (data >= value);
			break;
		case 5: // <=
			check = (data <= value);
			break;
		}

		// Kiểm tra kết quả
		if (check)
			printStudentInfo(i);
	}
}


void saveFile()
{
	if (strcmp(currentFile, "") != 0) // Nếu như có file hiện tại đang được mở
	{
		cout << "Ban muon luu vao file cu, hay tao file moi?\n";
		cout << "1: File cu\n";
		cout << "2: File moi\n";
		int input = getInRange(1, 2);
		if (input == 2)
		{
			cout << "Hay nhap ten file ban muon tao moi: ";
			cin >> currentFile;
		}
	}
	else
	{
		cout << "Hay nhap ten file ban muon tao moi: ";
		cin >> currentFile;
	}
	// Mở file
	ofstream output;
	output.open(currentFile);

	// Viết ra file phù hợp với tiêu chuẩn
	output << number << '\n';

	for (int i = 1; i <= number; i++)
	{
		output << encode(allStudent[i].name) << '\n';
		output << encode(allStudent[i].inClass) << '\n';
		output << encode(allStudent[i].address) << '\n';
		output << allStudent[i].mathScore << '\n';
		output << allStudent[i].literatureScore << '\n';
		output << allStudent[i].englishScore << '\n';
	}

	// Đóng file
	output.close();
}

void exitFile()
{
	cout << "Ban co muon luu file hien tai?\n";
	cout << "1: Yes\n";
	cout << "0: No\n";
	ofstream output;
	output.open(currentFile);
	int input = getInRange(0, 1);
	if (input == 1)
		saveFile();
	// Đóng file
	output.close();
}
// Main 

int main()
{
	
	int s0;	
	while (true)
		if (!isEditing)  // Nếu như chưa có file nào được mở
		{
			cout << "\n In current time, file has not opened yet. What do you want to do? Please choose an action in bellow: " << endl;
			cout << "\n 0. Creating a new file." << endl;
			cout << "\n 1. Openning an old file." << endl;
			cout << "\n 2. Exit." << endl;
			// request to choose one of values = {0,1,3}

			s0 = getInRange(0, 2);

			switch (s0)
			{
			case 0:
				cout << "\n 0. Creating a new file..." << endl;
				newFile();
				break;
			case 1:
				cout << "\n 1. Openning an old file..." << endl;
				openFile();
				break;
			case 2:
				cout << "\n 2. Exit now!" << endl;
				return 0; 
			}
		}
		else
		{
			cout << "\n What do you want to do? Choose a number in range(0,7): \n ";

			cout << "\n 0. Print all students \n ";
			cout << "\n 1. Filtering student following information \n ";
			cout << "\n 2. Add student \n ";
			cout << "\n 3. Edit student \n ";
			cout << "\n 4. Delete student \n ";
			cout << "\n 5. Save file \n ";
			cout << "\n 6. Close file. \n ";
			cout << "\n 7. Exit. \n ";

			int s0 = getInRange(0, 6);
			switch (s0)
			{
			case 0:
				cout << "\n 0. Goto Print all students \n ";
				printAllStudent();
				break;

			case 1:
				cout << "\n 1. Goto Filtering student \n ";
				searchStudent();
				break;
			case 2:
				cout << "\n 2. Goto Add student \n ";
				addStudent();
				break;
			case 3:
				cout << "\n 3. Goto Edit student \n ";
				editStudent();
				break;
			case 4:
				cout << "\n 4. Goto Delete student \n ";
				deleteStudent();
				break;
			case 5:
				cout << "\n 5. Save file. \n ";
				saveFile();
				break;
			case 6:
				cout << "\n 6. Close file and exit. \n ";
				exitFile();
				break;
			case 7:
				cout << "\n 7. Exit. \n ";
				return 0;
			}
		}
	return 0; 
}

