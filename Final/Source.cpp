#include <iostream>
#include<conio.h>
#include<string>
#include<fstream>
#include<Windows.h>
#include <stdlib.h>

using namespace std;

struct User
{
	int num;
	string name;
	string family;
	int StNumber;
	string password;
	string role;
	int money;
};
struct Foods{
	string day;
	int BreakfastCode;
	string breakfast;
	int BreakfastValue;
	int LunchCode;
	string lunch;
	int LunchValue;
	int DinnerCode;
	string dinner;
	int DinnerValue;
};
struct Reserveinfo{
	int id;
	int codes[21];
};

User people[35];
User student;
Foods food[7];
fstream file;
void import();
Reserveinfo reserve[35];

void welcome(){
	system("color 0c");
	cout << "  In";
	Sleep(200);
	system("cls");
	cout << "  In The";
	Sleep(200);
	system("cls");
	cout << "  In The Name";
	Sleep(200);
	system("cls");
	cout << "  In The Name Of";
	Sleep(200);
	system("cls");
	cout << "  In The Name Of God";
	Sleep(200);
	system("cls");
	cout << "  In The Name Of God .";
	Sleep(200);
	system("cls");
	cout << "  In The Name Of God . .";
	Sleep(200);
	system("cls");
	cout << "  In The Name Of God . . .";
	Sleep(200);
	system("cls");
	cout << "  In The Name Of God . . .                     Erfan";
	Sleep(200);
	system("cls");
	cout << "  In The Name Of God . . .                     Erfan Zekri";
	Sleep(200);
	system("cls");
	cout << "  In The Name Of God . . .                     Erfan Zekri Esfahani";
	Sleep(200);
	system("cls");
	cout << "  In The Name Of God . . .                    {Erfan Zekri Esfahani}";
	Sleep(200);
	system("cls");
	cout << "  In The Name Of God . . .                    {Erfan Zekri Esfaha}";
	Sleep(200);
	system("cls");
	cout << "  In The Name Of God . . .                    {Erfan Zekri Esfa}";
	Sleep(200);
	system("cls");
	cout << "  In The Name Of God . . .                    {Erfan Zekri Es}";
	Sleep(200);
	system("cls");
	cout << "  In The Name Of God . . .                    {Erfan ZekriE}";
	Sleep(200);
	system("cls");
	cout << "  In The Name Of God . . .                    {Erfan ZekE}";
	Sleep(200);
	system("cls");
	cout << "  In The Name Of God . . .                    {Erfan ZE}";
	Sleep(200);
	system("cls");
	cout << "  In The Name Of God . . .                    {ErfazE}";
	Sleep(200);
	system("cls");
	cout << "  In The Name Of God . . .                    {ErzE}";
	Sleep(200); 
	system("cls");
	system("color 0e");
	cout << "                                              {EzE}";
	Sleep(1000);
}
void ClassList(){
	system("cls");
	for (int i = 0; i < 35; i++)
		cout << people[i].num << " " << people[i].name << " " << people[i].family << endl;
	system("pause");
}
void Lessons(){
	system("cls");
	cout << "1. Fizik 1\n2. Farsi Omumi\n3. Riazi 1\n4. Mabani Computer\n5. Andishe 1\n";
	system("pause");
}
void OpenUsers(){
	file.open("StudentsInfo.txt", ios::in);
	int i = 0;
	while (!file.eof()){
		file >> people[i].num >> people[i].name >> people[i].family >> people[i].StNumber >> people[i].password >> people[i].role >> people[i].money;
		i++;
	}
	file.close();
}
void OpenReserved(){
	file.open("Reserve.txt", ios::in);
	int k = 0;
	while (!file.eof()){
		file >> reserve[k].id;
		for (int j = 0; j < 21; j++){
			file >> reserve[k].codes[j];
		}
		k++;
	}
	file.close();
}
void OpenFoods(){
	file.open("Foods.txt", ios::in);
	int j = 0;
	while (!file.eof()){
		file >> food[j].day >> food[j].BreakfastCode >> food[j].breakfast >> food[j].BreakfastValue >> food[j].LunchCode >> food[j].lunch
			>> food[j].LunchValue >> food[j].DinnerCode >> food[j].dinner >> food[j].DinnerValue;
		j++;
	}
	file.close();
}
void SaveUsers(){
	file.open("StudentsInfo.txt", ios::out);
	for (int i = 0; i < 35; i++){
		file << people[i].num << " " << people[i].name << " " << people[i].family << " " << people[i].StNumber << " "
			<< people[i].password << " " << people[i].role << " " << people[i].money << endl;
	}
	file.close();
}
void SaveReserved(){
	file.open("Reserve.txt", ios::out);
	for (int i = 0; i < 35; i++){
		file << reserve[i].id << " ";
		for (int j = 0; j < 21; j++){
			file << reserve[i].codes[j] << " ";
		}
		file << endl;
	}
	file.close();
}
void SaveFood(){
	file.open("Foods.txt", ios::out);
	for (int i = 0; i < 7; i++){
		file << food[i].day << " " << food[i].BreakfastCode << " " << food[i].breakfast << " " << food[i].BreakfastValue << " " << food[i].LunchCode
			<< " " << food[i].lunch << " " << food[i].LunchValue << " " << food[i].DinnerCode << " " << food[i].dinner << " " << food[i].DinnerValue << endl;
	}
	file.close();
}
void ChangePass(string Oldpass,int i){
	int num=0;
	string pass,pass1;
	do{
	    system("cls");
	    cout << "Please Enter Your Current Password : ";
	    cin >> pass;
		if (pass == Oldpass){
			do{
				system("cls");
				cout << "Please Enter Your Current Password : "<<Oldpass<<endl;
		     	cout << "Please Enter Your New Password : ";
			    cin >> pass;
			    cout << "Please ReEnter Your New Password : ";
			    cin >> pass1;
				if (pass == pass1){
					people[i].password = pass;
					student.password = pass;
					SaveUsers();
					cout << "Your Password Changed Succesfully :)\n";
					num = 2;
					_getch();
					break;
				}
				else{
					cout << "The Passwords You Entered Don't Match\nTry Again?\n1.Yes\t2.No\n";
					cin >> num;
				}
			} while (pass != pass1 && num!=2);
		}
		else{
			cout << "The Password You Enter Is Incorrect!\n1.continue\t2.back\n";
			cin >> num;
		}
	} while (num==1);
}
void AddMember(){
	system("cls");
	bool EmptyFound = false;
	for (int i = 0; i < 35 && !EmptyFound; i++){
		if (people[i].name == "." && people[i].family == "." && people[i].password=="." && people[i].StNumber==0){
			int num;
			cout << "Please Enter New Member's Name : ";
			cin >> people[i].name;
			cout << "Please Enter New Member's Family : ";
			cin >> people[i].family;
			cout << "Please Enter New Member's Login Password : ";
			cin>>people[i].password;
			cout << "Please Select The Role Of New Member :\n1.Admin\tOther.Student\nReply : ";
			cin >> num;
			people[i].role = num == 1 ? "Admin" : "Student";
			for (int k = 941402101; k <= 941402135; k++){
				bool EmptyNumFound = true;
				for (int j = 0; j < 35 && EmptyNumFound==true; j++){
					if (people[j].StNumber==k){
						EmptyNumFound = false;
					}
				}
				if (EmptyNumFound)
					people[i].StNumber = k;
			}
			SaveUsers();
			EmptyFound = true;
		}
	}
	if (!EmptyFound){
		cout << "The Class Is Full & It's Impossible To Add A New Member! ";
		_getch();
	}
}
void DeleteMember(){
	int num;
	ClassList();
	OpenReserved();
	cout << "Enter The Number Of The Student You Want To Delete : ";
	cin >> num;
	for (int i = num; i < 35; i++){
		people[i - 1].name = people[i].name;
		people[i - 1].family = people[i].family;
		people[i - 1].StNumber = people[i].StNumber;
		people[i - 1].password = people[i].password;
		people[i - 1].role = people[i].role;
		people[i - 1].money = people[i].money;
		for (int j = 0; j < 21; j++){
			reserve[i - 1].codes[j] = reserve[i].codes[j];
		}
	}
	for (int j = 0; j< 21; j++){
		reserve[34].codes[j] = 0;
	}
	people[34].name = ".";
	people[34].family = ".";
	people[34].StNumber = 0;
	people[34].password = ".";
	people[34].role = ".";
	people[34].money = 0;
	SaveUsers();
	SaveReserved();
}
void ChangeMemInfo(){
	int num,n;
	ClassList();
	cout << "Enter The Number Of Student That You Want To Change His(Her) Information : ";
	cin >> num;
	num--;
	cout << "Please Enter New Name Instead " << people[num].name<<" : ";
	cin >> people[num].name;
	cout << "Please Enter New Family Instead " << people[num].family << " : ";
	cin >> people[num].family;
	cout << "Please Enter New Password Instead " << people[num].password << " : ";
	cin >> people[num].password;
	cout << "The Role Is " << people[num].role << "\nDo You Want To Change It ?\n1.Yes\t2.No\nReply : ";
	cin >> n;
	if (n == 1){
		if (people[num].role == "Student")
			people[num].role = "Admin";
		else if (people[num].role == "Admin")
			people[num].role = "Student";
	}
	cout << "Do You Want To Change The Wallet Money That Have " << people[num].money << "(rls) ?\n";
	cout << "1.Yes\t2.No\nReply : ";
	cin >> n;
	if (n == 1){
		cout << "Please Enter New Money For The Wallet (rls) : ";
		cin >> people[num].money;
	}
	SaveUsers();
}
void ChangeInfo(){
	int num;
	do{
		ClassList();
		cout << "1.Add Member\n2.Delete Member\n3.Change Member Info\n4.Back\nReply : ";
		cin >> num;
		switch (num){
		case 1:
			AddMember();
			break;
		case 2:
			DeleteMember();
			break;
		case 3:
			ChangeMemInfo();
			break;
		case 4:
			break;
		default:
			system("cls");
			cout << "Error!\a\n";
			system("pause");
		}
	} while (num != 4);
}
void ShowNumberOfReserved(){
	system("cls");
	OpenReserved();
	OpenFoods();
	for (int i = 0; i < 7; i++){
		int count = 0, money = 0;;
		for (int j = 0; j < 35; j++){
			for (int k = 0; k < 21; k++){
				if (reserve[j].codes[k] == food[i].BreakfastCode)
					count++;
			}
		}
		money = count*food[i].BreakfastValue;
		cout << food[i].day << "==> Brf : " << count << "x" << food[i].breakfast << "(" << food[i].BreakfastValue << ")rls = " << money<<"rls";
		money, count = 0;
		for (int j = 0; j < 35; j++){
			for (int k = 0; k < 21; k++){
				if (reserve[j].codes[k] == food[i].LunchCode)
					count++;
			}
		}
		money = count*food[i].LunchValue;
		cout <<"  Lch : " << count << "x" << food[i].lunch << "(" << food[i].LunchValue << ")rls = " << money<<"rls";
		money, count = 0;
		for (int j = 0; j < 35; j++){
			for (int k = 0; k < 21; k++){
				if (reserve[j].codes[k] == food[i].DinnerCode)
					count++;
			}
		}
		money = count*food[i].DinnerValue;
		cout << "  Dnr : " << count << "x" << food[i].dinner << "(" << food[i].DinnerValue << ")rls = " << money<<"rls";
		cout << endl;
	}
	system("pause");
}
void ShowFoods(){
	OpenFoods();
	for (int j = 0; j < 7; j++){
		cout << food[j].day << "==> Brf : " << food[j].breakfast << "(" << food[j].BreakfastValue << ")rls  Lch : " << food[j].lunch << "(" << food[j].LunchValue
			<< ")rls  Dnr : " << food[j].dinner << "(" << food[j].DinnerValue << ")rls" << endl;
	}
	system("pause");
}
void Charge(int i){
	int Money,usr;
	string pass;
	system("cls");
	cout << "Enter The Money That Want To Charge (rls): ";
	cin >> Money;
	cout << "Please Enter Your Username : ";
	cin >> usr;
	cout << "please Enter Your Password : ";
	cin >> pass;
	if (usr==student.StNumber && pass == student.password){
		student.money += Money;
		people[i].money += Money;
		SaveUsers();
		cout << "Your Wallet Charge Succesfully :)";
		_getch();
	}
	else{
		cout << "The Username & Password You Entered Is Incorrect !";
		_getch();
	}
}
void ShowOneDayReservedFoods(int i,int j){
	cout << food[j].day << "==> Brf : " << food[j].breakfast << "(" << food[j].BreakfastValue << ")rls";
	bool isFound = false;
	for (int k = 0; k < 21 && !isFound; k++){
		if (reserve[i].codes[k] == food[j].BreakfastCode){
			cout << "[" << (char)251 << "]";
			isFound = true;
		}
	}
	if (!isFound)
		cout << "[" << (char)88 << "]";
	cout << "  Lch : " << food[j].lunch << "(" << food[j].LunchValue << ")rls";
	isFound = false;
	for (int k = 0; k < 21 && !isFound; k++){
		if (reserve[i].codes[k] == food[j].LunchCode){
			cout << "[" << (char)251 << "]";
			isFound = true;
		}
	}
	if (!isFound)
		cout << "[" << (char)88 << "]";
	cout << "  Dnr : " << food[j].dinner << "(" << food[j].DinnerValue << ")rls";
	isFound = false;
	for (int k = 0; k < 21 && !isFound; k++){
		if (reserve[i].codes[k] == food[j].DinnerCode){
			cout << "[" << (char)251 << "]";
			isFound = true;
		}
	}
	if (!isFound)
		cout << "[" << (char)88 << "]";
	cout << endl;
}
void ShowReservedFoods(int i){
	OpenFoods();
	for (int j = 0; j < 7; j++){
		ShowOneDayReservedFoods(i, j);
	}
	cout << endl;
}
void DeleteFood(int i){
	int num,n,num1,num2=1;
	do{
		do{
	    	system("cls");
	    	cout << "Select The Day :\n";
	    	cout << "1.Saturday\t2.Sunday\t3.Monday\n4.Tuesday\t5.Wednesday\t6.Thursday\n\t\t7.Friday\n\t\t8.Back\nReply : ";
	    	cin >> num;
    		if (num > 8){
				system("cls");
				cout << "Error!\a\n";
				system("pause");
			}
	   	} while (num > 8);
		if (num == 8)
			break;
		num--;
		system("cls");
		ShowOneDayReservedFoods(i, num);
		cout << "Select The Food You Want to Delete Its Reserve :\n";
		cout << "1.Breakfast\n2.Lunch\n3.Dinner\nReply : ";
		cin >> n;
		switch (n){
		case 1:
			for (int j = 0; j < 21; j++){
				if (reserve[i].codes[j] == food[num].BreakfastCode){
					cout << "Do You Want To Delete Reserved " << food[num].breakfast << " ?\n";
					cout << "1.Yes\t2.No\nReply : ";
					cin >> num1;
					if (num1 == 1){
						for (j; j < 20; j++){
							reserve[i].codes[j] = reserve[i].codes[j + 1];
						}
						reserve[i].codes[20] = 0;
						student.money += food[num].BreakfastValue;
						people[i].money += food[num].BreakfastValue;
						SaveUsers();
						SaveReserved();
						system("cls");
						cout << "The Reserved " << food[num].breakfast << " Delete Succesfully :(\n";
						cout << "Do You Want To Delete More ?\n1.Yes\t2.No\nReply : ";
						cin >> num2;
						break;
					}
					break;
				}
				else if (reserve[i].codes[j] == 0){
					cout << "The " << food[num].breakfast << " Could Not Be Deleted Because Of It Didn't Be Reserved! ";
					_getch();
					break;
				}
			}
			break;
		case 2:
			for (int j = 0; j < 21; j++){
				if (reserve[i].codes[j] == food[num].LunchCode){
					cout << "Do You Want To Delete Reserved " << food[num].lunch << " ?\n";
					cout << "1.Yes\t2.No\nReply : ";
					cin >> num1;
					if (num1 == 1){
						for (j; j < 20; j++){
							reserve[i].codes[j] = reserve[i].codes[j + 1];
						}
						reserve[i].codes[20] = 0;
						student.money += food[num].LunchValue;
						people[i].money += food[num].LunchValue;
						SaveUsers();
						SaveReserved();
						system("cls");
						cout << "The Reserved " << food[num].lunch << " Delete Succesfully :(\n";
						cout << "Do You Want To Delete More ?\n1.Yes\t2.No\nReply : ";
						cin >> num2;
						break;
					}
					break;
				}
				else if (reserve[i].codes[j] == 0){
					cout << "The " << food[num].lunch << " Could Not Be Deleted Because Of It Didn't Be Reserved! ";
					_getch();
					break;
				}
			}
			break;
		case 3:
			for (int j = 0; j < 21; j++){
				if (reserve[i].codes[j] == food[num].DinnerCode){
					cout << "Do You Want To Delete Reserved " << food[num].dinner << " ?\n";
					cout << "1.Yes\t2.No\nReply : ";
					cin >> num1;
					if (num1 == 1){
						for (j; j < 20; j++){
							reserve[i].codes[j] = reserve[i].codes[j + 1];
						}
						reserve[i].codes[20] = 0;
						student.money += food[num].DinnerValue;
						people[i].money += food[num].DinnerValue;
						SaveUsers();
						SaveReserved();
						system("cls");
						cout << "The Reserved " << food[num].dinner << " Delete Succesfully :(\n";
						cout << "Do You Want To Delete More ?\n1.Yes\t2.No\nReply : ";
						cin >> num2;
						break;
					}
					break;
				}
				else if (reserve[i].codes[j] == 0){
					cout << "The " << food[num].dinner << " Could Not Be Deleted Because Of It Didn't Be Reserved! ";
					_getch();
					break;
				}
			}
			break;
		default:
			cout << "Error!\a\n";
			system("pause");
		}
	} while (num2 == 1);
}
void Reserve(int i){
	int num,n,num2=1;
	OpenReserved();
	do{
		system("cls");
		cout << "Avalable Foods Is Here ...\n";
		ShowReservedFoods(i);
		cout << "Avalable Money : " << student.money<<"(rls)"<<endl;
		cout << "1.Reserve\n2.Delete Reserved Food\n3.Charge\n4.back\nReply : ";
		cin >> num;
		if (num == 1){
			do{
				do{
					system("cls");
					cout << "Select The Day :\n";
					cout << "1.Saturday\t2.Sunday\t3.Monday\n4.Tuesday\t5.Wednesday\t6.Thursday\n\t\t7.Friday\n\t\t8.Back\nReply : ";
					cin >> num;
					if (num > 8){
				        system("cls");
			        	cout << "Error!\a\n";
				        system("pause");
	        		}
	        	} while (num > 8);
	        	if (num == 8)
		        	break;
				num--;
				system("cls");
				ShowOneDayReservedFoods(i, num);
				cout << "Select The Food You Want to Reserve :\n";
				cout << "1.Breakfast\n2.Lunch\n3.Dinner\nReply : ";
				cin >> n;
				int num1;
				switch (n){
					int YN;
				case 1:
					if (food[num].breakfast != "---"){
						for (int j = 0; j < 21; j++){
							if (reserve[i].codes[j] == 0){
								if (student.money >= food[num].BreakfastValue){
									reserve[i].codes[j] = food[num].BreakfastCode;
									student.money -= food[num].BreakfastValue;
									people[i].money -= food[num].BreakfastValue;
									SaveUsers();
									SaveReserved();
									cout << "The " << food[num].breakfast << " Reserved For You Succesfully :)\n";
									cout << "Do You Want To Reserve More ?\n";
									cout << "1.Yes\t2.No\nReply : ";
									cin >> num2;
									break;
								}
								else{
									cout << "You Don't Have Enough Money ! :(\n";
									cout << "Do You Want To Charge Your Money ?\n1.Yes\t2.No\nReply : ";
									cin >> YN;
									if (YN == 1)
										Charge(i);
									break;
								}
							}
							else if (reserve[i].codes[j] == food[num].BreakfastCode){
								cout << "This Food Is Reserved !\nDo You Want To Delete It ?\n";
								cout << "1.Yes\t2.No\nReply : ";
								cin >> num1;
								if (num1 == 1){
									for (j; j < 20; j++){
										reserve[i].codes[j] = reserve[i].codes[j + 1];
									}
									reserve[i].codes[20] = 0;
									student.money += food[num].BreakfastValue;
									people[i].money += food[num].BreakfastValue;
									SaveUsers();
									SaveReserved();
									cout << "The Reserved " << food[num].breakfast << " Delete Succesfully :(";
									_getch();
									break;
								}
								break;
							}
						}
					}
					else{
						system("cls");
						cout << "There Isn't Any Food In This Section !\n";
						system("pause");
					}
					break;
				case 2:
					if (food[num].lunch != "---"){
						for (int j = 0; j < 21; j++){
							if (reserve[i].codes[j] == 0){
								if (student.money >= food[num].LunchValue){
									reserve[i].codes[j] = food[num].LunchCode;
									student.money -= food[num].LunchValue;
									people[i].money -= food[num].LunchValue;
									SaveUsers();
									SaveReserved();
									cout << "The " << food[num].lunch << " Reserved For You Succesfully :)\n";
									cout << "Do You Want To Reserve More ?\n";
									cout << "1.Yes\t2.No\nReply : ";
									cin >> num2;
									break;
								}
								else{
									cout << "You Don't Have Enough Money ! :(\n";
									cout << "Do You Want To Charge Your Money ?\n1.Yes\t2.No\nReply : ";
									cin >> YN;
									if (YN == 1)
										Charge(i);
									break;
								}
							}
							else if (reserve[i].codes[j] == food[num].LunchCode){
								cout << "This Food Is Reserved !\nDo You Want To Delete It ?\n";
								cout << "1.Yes\t2.No\nReply : ";
								cin >> num1;
								if (num1 == 1){
									for (j; j < 20; j++){
										reserve[i].codes[j] = reserve[i].codes[j + 1];
									}
									reserve[i].codes[20] = 0;
									student.money += food[num].LunchValue;
									people[i].money += food[num].LunchValue;
									SaveUsers();
									SaveReserved();
									cout << "The Reserved " << food[num].lunch << " Delete Succesfully :(";
									_getch();
									break;
								}
								break;
							}
						}
					}
					else{
						system("cls");
						cout << "There Isn't Any Food In This Section !\n";
						system("pause");
					}
					break;
				case 3:
					if (food[num].dinner != "---"){
						for (int j = 0; j < 21; j++){
							if (reserve[i].codes[j] == 0){
								if (student.money >= food[num].DinnerValue){
									reserve[i].codes[j] = food[num].DinnerCode;
									student.money -= food[num].DinnerValue;
									people[i].money -= food[num].DinnerValue;
									SaveUsers();
									SaveReserved();
									cout << "The " << food[num].dinner << " Reserved For You Succesfully :)\n";
									cout << "Do You Want To Reserve More ?\n";
									cout << "1.Yes\t2.No\nReply : ";
									cin >> num2;
									break;
								}
								else{
									cout << "You Don't Have Enough Money ! :(\n";
									cout << "Do You Want To Charge Your Money ?\n1.Yes\t2.No\nReply : ";
									cin >> YN;
									if (YN == 1)
										Charge(i);
									break;
								}
							}
							else if (reserve[i].codes[j] == food[num].DinnerCode){
								cout << "This Food Is Reserved !\nDo You Want To Delete It ?\n";
								cout << "1.Yes\t2.No\nReply : ";
								cin >> num1;
								if (num1 == 1){
									for (j; j < 20; j++){
										reserve[i].codes[j] = reserve[i].codes[j + 1];
									}
									reserve[i].codes[20] = 0;
									student.money += food[num].DinnerValue;
									people[i].money += food[num].DinnerValue;
									SaveUsers();
									SaveReserved();
									cout << "The Reserved " << food[num].dinner << " Delete Succesfully :(";
									_getch();
									break;
								}
								break;
							}
						}
					}
					else {
						system("cls");
						cout << "There Isn't Any Food In This Section !\n";
						system("pause");
					}
					break;
				default:
					cout << "Error!\a\n";
					system("pause");
				}
			} while (num2 == 1 && num!=7);
		}
		else if (num == 2){
			DeleteFood(i);
		}
		else if (num == 3){
			Charge(i);
		}
	} while (num != 4);
}
void Change(int i, int type, string Food,int Value){
	switch (type){
	case 1:
		food[i].breakfast = Food;
		food[i].BreakfastValue = Value;
		SaveFood();
		break;
	case 2:
		food[i].lunch = Food;
		food[i].LunchValue = Value;
		SaveFood();
		break;
	case 3:
		food[i].dinner = Food;
		food[i].DinnerValue = Value;
		SaveFood();
		break;
	}
}
void YesFood(){
	int num,n,num1=1;
	string Food;
	int value;
	do{
    	do{
	        system("cls");
        	cout << "Select The Day :\n";
        	cout << "1.Saturday\t2.Sunday\t3.Monday\n4.Tuesday\t5.Wednesday\t6.Thursday\n\t\t7.Friday\n\t\t8.Back\nReply : ";
    	    cin >> num;
    	    if (num > 8){
	        	system("cls");
			    cout << "Error!\a\n";
		    	system("pause");
	    	}
    	} while (num > 8);
    	if (num == 8)
	    	break;
    	num--;
    	system("cls");
    	cout << "Avalable Foods Of " << food[num].day << " :\n";
    	cout << " Brf : " << food[num].breakfast << "(" << food[num].BreakfastValue << ")rls  Lch : " << food[num].lunch << "(" << food[num].LunchValue
	    	<< ")rls  Dnr : " << food[num].dinner << "(" << food[num].DinnerValue << ")rls" << endl;
    	cout << "Select The Food To Change :\n";
    	cout << "1.Breakfast\n2.Lunch\n3.Dinner\nReply : ";
	    cin >> n;
	    system("cls");
    	cout << "Enter Your Input Food For " << food[num].day << "...\nReply : ";
	    cin >> Food;
    	cout << "Enter The Value Of The " << Food << "...(rls)\nReply : ";
	    cin >> value;
    	Change(num, n, Food,value);
    	system("cls");
    	cout << "Your Food Changed Succesfully :)\nFoods List : \n";
    	ShowFoods();
    	cout<<"Do You Want To Change More ?\n1.Yes\t2.No\nReply : ";
    	cin>>num1;
	}while(num1==1 && num!=7);
}
void YesValue(){
	int num, n,num1=1;
	string Food;
	int value;
	do{
    	do{
    	    system("cls");
        	cout << "Select The Day :\n";
	        cout << "1.Saturday\t2.Sunday\t3.Monday\n4.Tuesday\t5.Wednesday\t6.Thursday\n\t\t7.Friday\n\t\t8.Back\nReply : ";
        	cin >> num;
        	if (num > 8){
		    	system("cls");
			    cout << "Error!\a\n";
		    	system("pause");
		    }
		} while (num > 8);
		if (num == 8)
			break;
    	num--;
	    system("cls");
	    cout << "Avalable Foods Of " << food[num].day << " :\n";
	    cout <<" Brf : " << food[num].breakfast << "(" << food[num].BreakfastValue << ")rls  Lch : " << food[num].lunch << "(" << food[num].LunchValue
		    << ")rls  Dnr : " << food[num].dinner << "(" << food[num].DinnerValue << ")rls" << endl;
    	cout << "Select The Food To Change Its Value :\n";
    	cout << "1.breakfast\n2.lunch\n3.dinner\nReply : ";
    	cin >> n;
    	system("cls");
    	if (n == 1)Food = food[num].breakfast;
	    if (n == 2)Food = food[num].lunch;
	    if (n == 3)Food = food[num].dinner;
	    cout << "Enter The Value Of The " << Food << "...(rls)\nReply : ";
	    cin >> value;
	    Change(num, n, Food, value);
	    system("cls");
	    cout << "Your Value Changed Succesfully :)\nFoods List : \n";
    	ShowFoods();
    	cout<<"Do You Want To Change More ?\n1.Yes\t2.No\nReply : ";
    	cin>>num1;
	}while(num1==1 && num!=7);
}
void ChangeFoods(){
	int num;
	system("cls");
	cout << "Avalable Foods Is Here ...\n";
	ShowFoods();
	cout << "Do You Want To Change ?\n1.Yes Change Food\t2.Yes Change Just Value\n3.No\nReply : ";
	cin >> num;
	if (num == 1)
		YesFood();
	else if (num == 2)
		YesValue();
}
int SignOut(){
	int num;
	system("cls");
	cout << "Do You Want To Sign Out From Your Profile ?\n1.Yes\t2.No\nReply : ";
	cin >> num;
	return num == 1 ? 1 : 0;
}
int Exit(){
	int num;
	system("cls");
	cout << "Do Want To Exit Program :( ?\n1.Yes\t2.No\nReply : ";
	cin >> num;
	if (num == 1){
		system("cls");
		system("color 0c");
		cout << "\n  G";
		Sleep(200);
		system("cls");
		cout << "\n  Go";
		Sleep(200);
		system("cls");
		cout << "\n  Goo";
		Sleep(200);
		system("cls");
		cout << "\n  GooD";
		Sleep(200);
		system("cls");
		cout << "\n  GooD B";
		Sleep(200);
		system("cls");
		cout << "\n  GooD By";
		Sleep(200);
		system("cls");
		cout << "\n  GooD ByE";
		Sleep(1000);
	}
	return num == 1 ? 1 : 0;
}
void ShowStudentMenu(int number){
	int key;
	do{
		system("cls");
		cout << "Hello Dear " << student.name << " " << student.family << " Welcome :)\n";
		cout << "Please Select On Of The Following Items ?\n";
		cout << "1.Show Class List\n";
		cout << "2.Show Lessons\n";
		cout << "3.Change Password\n";
		cout << "4.Show Foods\n";
		cout << "5.Reserve Food\n";
		cout << "6.Sign Out\n";
		cout << "7.Exit\n";
		cout << "Reply : ";
		cin >> key;
		switch (key){
		case 1:
			ClassList();
			break;
		case 2:
			Lessons();
			break;
		case 3:
			ChangePass(student.password, number);
			break;
		case 4:
			system("cls");
			ShowFoods();
			break;
		case 5:
			Reserve(number);
			break;
		case 6:
			if (SignOut() == 1){
				import();
				key = 7;
				break;
			}
			else
				break;
		case 7:
			if (Exit() == 1)
				break;
			else{
				key = 1;
				break;
			}
		default:
			system("cls");
			cout << "Error!\a\n";
			system("pause");
		}
	} while (key != 7);
}
void ShowAdminMenu(int number){
	int key;
	do{
		system("cls");
		cout << "Hi Dear " << student.name << " " << student.family << " (Admin)\n";
		cout << "Please Select On Of The Following Items ?\n";
		cout << "1.Show Class List\n";
		cout << "2.Show Lessons\n";
		cout << "3.Change Password\n";
		cout << "4.Change Class Information\n";
		cout << "5.Show Number Of Reserved Foods\n";
		cout << "6.Show Foods\n";
		cout << "7.Change Foods\n";
		cout << "8.Sign Out\n";
		cout << "9.Exit\n";
		cout << "Reply : ";
		cin >> key;
		switch (key){
		case 1:
			ClassList();
			break;
		case 2:
			Lessons();
			break;
		case 3:
			ChangePass(student.password, number);
			break;
		case 4:
			ChangeInfo();
			break;
		case 5:
			ShowNumberOfReserved();
			break;
		case 6: 
			system("cls");
			ShowFoods();
			break;
		case 7:
			ChangeFoods();
			break;
		case 8:
			if (SignOut() == 1){
				import();
				key = 9;
				break;
			}
			else
				break;
		case 9: 
			if (Exit() == 1)
				break;
			else{
				key = 1;
				break;
			}
		default:
			system("cls");
			cout << "Error!\a\n";
			system("pause");
		}
	} while (key != 9);
}
void RecieveFood(){
	int num, n,num1,i;
	string pass;
	long long int username;
	system("cls");
	ShowFoods();
	OpenUsers();
	OpenReserved();
	do{
		do{
			system("cls");
			cout << "Select The Day :\n";
			cout << "1.Saturday\t2.Sunday\t3.Monday\n4.Tuesday\t5.Wednesday\t6.Thursday\n\t\t7.Friday\n\t\t8.Exit\n\nReply : ";
			cin >> num;
			if (num > 8){
				system("cls");
				cout << "Error!\a\n";
				system("pause");
			}
		} while (num > 8);
		if (num == 8)
			break;
		num--;
		system("cls");
		cout << food[num].day << "==> Brf : " << food[num].breakfast << "  Lch : " << food[num].lunch << "  Dnr : " << food[num].dinner << endl;
		cout << "Select The Food You Want to Recieve :\n";
		cout << "1.Breakfast\n2.Lunch\n3.Dinner\nReply : ";
		cin >> n;
		do{
			bool isFound = false;
			num1 = 0;
			system("cls");
			cout << "(Enter Your Information...)\n";
			cout << "Please Enter Your Username : ";
			cin >> username;
			cout << "please Enter Your Password : ";
			cin >> pass;
			if (username<941402100 || username>941402135){
				system("cls");
				cout << "The Username Is Out Of Renge!\nDo You Want To Exit Program :( ?\n1.Yes\t2.No\nReply : ";
				cin >> num1;
			}
			for (i = 0; i < 35 && !isFound; i++){
				if (username == people[i].StNumber && pass == people[i].password){
					isFound = true;
				}
			}
			i--;
			if (!isFound && username>941402100 && username < 941402136){
				system("cls");
				cout << "The Password Is Incorrect!\nDo You Want To Exit Program :( ?\n1.Yes\t2.No\nReply : ";
				cin >> num1;
			}
		} while (num1 == 2);
		bool isFound;
		switch (n){
		case 1:
			isFound = false;
			for (int j = 0; j < 21 && !isFound; j++){
				if (reserve[i].codes[j] == food[num].BreakfastCode){
					system("cls");
					cout << "The Food Is Reserved :)\a";
					reserve[i].codes[j] = (-1)*food[num].BreakfastCode;
					SaveReserved();
					isFound = true;
					_getch();
				}
				else if (reserve[i].codes[j] == 0){
					system("cls");
					cout << "You Didn't Reserve This Food !\n";
					system("pause");
					isFound = true;
				}
				else if (reserve[i].codes[j] == (-1)*food[num].BreakfastCode){
					system("cls");
					cout << "This Food Was Taked !\n";
					system("pause");
					isFound = true;
				}
			}
			if (!isFound){
				system("cls");
				cout << "You Didn't Reserve This Food !\n";
				system("pause");
			}
			break;
		case 2:
			isFound = false;
			for (int j = 0; j < 21 && !isFound; j++){
				if (reserve[i].codes[j] == food[num].LunchCode){
					system("cls");
					cout << "The Food Is Reserved :)\a";
					_getch();
					reserve[i].codes[j] = (-1)*food[num].LunchCode;
					SaveReserved();
					isFound = true;
				}
				else if (reserve[i].codes[j] == 0){
					system("cls");
					cout << "You Didn't Reserve This Food !\n";
					system("pause");
					isFound = true;
				}
				else if (reserve[i].codes[j] == (-1)*food[num].LunchCode){
					system("cls");
					cout << "This Food Was Taked !\n";
					system("pause");
					isFound = true;
				}
			}
			if (!isFound){
				system("cls");
				cout << "You Didn't Reserve This Food !\n";
				system("pause");
			}
			break;
		case 3:
			isFound = false;
			for (int j = 0; j < 21 && !isFound; j++){
				if (reserve[i].codes[j] == food[num].DinnerCode){
					system("cls");
					cout << "The Food Is Reserved :)\a";
					_getch();
					reserve[i].codes[j] = (-1)*food[num].DinnerCode;
					SaveReserved();
					isFound = true;
				}
				else if (reserve[i].codes[j] == 0){
					system("cls");
					cout << "You Didn't Reserve This Food !\n";
					system("pause");
					isFound = true;
				}
				else if (reserve[i].codes[j] == (-1)*food[num].DinnerCode){
					system("cls");
					cout << "This Food Was Taked !\n";
					system("pause");
					isFound = true;
				}
			}
			if (!isFound){
				system("cls");
				cout << "You Didn't Reserve This Food !\n";
				system("pause");
			}
			break;
		default:
			system("cls");
			cout << "Error!\a\n";
			system("pause");
		}
	}while (num != 7);
}
void import(){
	string pass;
	long long int username;
	OpenUsers();
	int num;
	do{
		bool isFound = false;
		num = 0;
		system("cls");
		cout << "(Enter Your Information...)\n";
		cout << "Please Enter Your Username : ";
		cin >> username;
		cout << "please Enter Your Password : ";
		cin >> pass;
		if (username<941402100 || username>941402135){
			system("cls");
			cout << "The Username Is Out Of Renge!\nDo You Want To Exit Program :( ?\n1.Yes\t2.No\nReply : ";
			cin >> num;
		}
		for (int i = 0; i < 35 && !isFound; i++){
			if (username == people[i].StNumber && pass == people[i].password && people[i].role == "Student"){
				student = people[i];
				ShowStudentMenu(i);
				isFound = true;
			}
			else if (username == people[i].StNumber && pass == people[i].password && people[i].role == "Admin"){
				student = people[i];
				ShowAdminMenu(i);
				isFound = true;
			}
		}
		if (!isFound && username>941402100 && username<941402136){
			system("cls");
			cout << "The Password Is Incorrect!\nDo You Want To Exit Program :( ?\n1.Yes\t2.No\nReply : ";
			cin >> num;
		}
	} while (num==2);
}
void main(){
	int num;
	//welcome();
	system("cls");
	system("color 07");
		cout << "1.Sign In\t2.Recieve\nReply : ";
		cin >> num;
		switch (num){
		case 1:
			import();
			break;
		case 2:
			RecieveFood();
			break;
		default:
			cout << "Error!\a\n";
			system("pause");
		}
}