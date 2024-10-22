#include<iostream>
#include<string>
using namespace std;

//Maximum number of people stored in the address book
#define Max 1000 //maximum number of people


//Define a contact structure
struct Contacts
{
	string cName;		//Name 
	int cGender = 1;	//Gender
	int cAge = 0;		//Age
	string cPhone;		//telephone number
	string cAdd;		//Address
};

//Define an address book structure
struct AddressBooks
{
	Contacts contactsArry[Max];	//ͨAddress book contact information array
	int aCount = 0;					//The number of people in the address book
};

//Main Menu
void showMenu()
{
	cout << "********************************" << endl;
	cout << "***** Correspondence record management system  *****" << endl;
	cout << "****************************************************" << endl;
	cout << "*****    1. Add contacts      **********************" << endl;
	cout << "*****    2. Display contacts  **********************" << endl;
	cout << "*****    3. Delete contacts    *********************" << endl;
	cout << "*****    4. Find contacts      *********************" << endl;
	cout << "*****    5. Modify contact person     **************" << endl;
	cout << "*****    6. Clear contacts    **********************" << endl;
	cout << "*****    0. Exit the address book     **************" << endl;
	cout << "****************************************************" << endl;
	cout << "*********** Version 1.0.13 *************************" << endl;
	cout << "****************************************************" << endl;
}

//Add contacts
void AddContacts(AddressBooks* abs)
{
	//Determine whether it is full
	if (abs->aCount == Max)
	{
		cout << "The address book is full and cannot be added!" << endl;
		return;
	}
	else
	{
		//Name
		string name;
		cout << "Please type in your name:" << endl;
		cin >> name;
		abs->contactsArry[abs->aCount].cName = name;

		//gender
		int gender;
		cout << " Please enter gender: " << endl;
		cout << "1----Male " << endl;
		cout << "2----Female " << endl;

		while (true)
		{
			cin >> gender;
			if (gender == 1 || gender == 2)
			{
				abs->contactsArry[abs->aCount].cGender = gender;
				break;
			}
			cout << "If there is an error in your entry, please re-enter it!" << endl;
		}

		//Age
		int age;
		cout << "Please enter your age:" << endl;
		cin >> age;
		abs->contactsArry[abs->aCount].cAge = age;

		//Phone
		string phone;
		cout << "Please enter phone number: " << endl;
		cin >> phone;
		abs->contactsArry[abs->aCount].cPhone = phone;

		//Telephone
		string add;
		cout << "Please enter address: " << endl;
		cin >> add;
		abs->contactsArry[abs->aCount].cAdd = add;

		//Added successfully!
		abs->aCount += 1;
		cout << "Added successfully!" << endl;
		system("pause");
		//clear screen
		system("cls");
	}

}

//Show contacts
void ShowContacts(AddressBooks* abs)
{
	if (abs->aCount == 0)
	{
		cout << "There is no contact person, please add it first!" << endl;
	}
	else
	{
		//Show all contacts
		for (int i = 0; i < abs->aCount; i++)
		{
			cout << " Name:" << abs->contactsArry[i].cName << endl << " gender:" << (abs->contactsArry[i].cGender != 2 ? "male" : "female") <<endl<< " age: " << abs->contactsArry[i].cAge <<endl<< " phone: " << abs->contactsArry[i].cPhone<<endl << " Address:" << abs->contactsArry[i].cAdd <<endl<< endl;
		}
	}
	system("pause");
	system("cls");
}

//Check if someone exists
int IsExit(AddressBooks* abs, string name)
{
	for (int i = 0; i < abs->aCount; i++)
	{
		if (abs->contactsArry[i].cName == name)
		{
			return i;
		}
	}
	return -1;
}

//Delete
void DeleteContacts(AddressBooks* abs)
{
	//Record the name entered by the user
	string name;
	cout << "Please enter the name of the user you want to delete:" << endl;
	cin >> name;
	//Determine whether the contact exists
	int index = IsExit(abs, name);
	//forward shift operation
	if (index > -1)
	{
		for (int i = index; i < abs->aCount - 1; i++)
		{
			//Reduce one record
			Contacts temp = abs->contactsArry[i];
			abs->contactsArry[i] = abs->contactsArry[i + 1];
			abs->contactsArry[i + 1] = temp;
		}
		//Reduce one record
		abs->aCount--;
		cout << "successfully deleted!" << endl;
	}
	else//does not exist
	{
		cout << "No such person found" << endl;
	}
	system("pause");
	system("cls");
}

//Find a contact
void GetContacts(AddressBooks* abs)
{
	//Record the name entered by the user
	string name;
	cout << "Please enter the name of the user you are looking for " << endl;
	cin >> name;
	//Determine whether the contact exists
	int index = IsExit(abs, name);
	if (index > -1)
	{
		//exist
		cout << "Name:" << abs->contactsArry[index].cName << endl;
		cout << "gender:" << abs->contactsArry[index].cGender << endl;
		cout << "age:" << abs->contactsArry[index].cAge << endl;
		cout << "TelePhone:" << abs->contactsArry[index].cPhone << endl;
		cout << "address:" << abs->contactsArry[index].cAdd << endl;
	}
	else
	{
		//does not exist
		cout << "No such person found" << endl;
	}
	system("pause");
	system("cls");

}

//Modify contact
void ModefyContacts(AddressBooks* abs)
{
	//Record the name entered by the user
	string name;
	cout << "Please enter the user name you want to modify" << endl;
	cin >> name;
	//Determine whether the contact exists
	int index = IsExit(abs, name);
	if (index > -1)
	{
		//exist
		//Name
		string name;
		cout << "Please enter your modified name: " << endl;
		cin >> name;
		abs->contactsArry[index].cName = name;

		//gender
		int gender;
		cout << "Please enter your modified gender: " << endl;
		cout << "1----Male " << endl;
		cout << "2----Female" << endl;

		while (true)
		{
			cin >> gender;
			if (gender == 1 || gender == 2)
			{
				abs->contactsArry[index].cGender = gender;
				break;
			}
			cout << "If there is an error in your entry, please re-enter it!" << endl;
		}

		//age
		int age;
		cout << "Please enter your revised age: " << endl;
		cin >> age;
		abs->contactsArry[index].cAge = age;

		//Telephone
		string phone;
		cout << "Please enter the modified phone number: " << endl;
		cin >> phone;
		abs->contactsArry[index].cPhone = phone;

		//address
		string add;
		cout << "Please enter the modified address: " << endl;
		cin >> add;
		abs->contactsArry[index].cAdd = add;
		cout << "Successfully modified!" << endl;
	}
	else
	{
		//does not exist
		cout << "No such person found" << endl;
	}
	system("pause");
	system("cls");
}

//Clear contacts
void ClearContacts(AddressBooks* abs)
{
	string choose = "N";
	cout << "Are you sure you want to clear your address book? (Y confirm/N cancel)" << endl;

	while (true)
	{
		cin >> choose;
		if (choose == "Y" || choose == "N")
		{
			break;
		}
		else
		{
			cout << "If there is an error in the input, please re-enter!!" << endl;
		}
	}

	if (choose == "Y")
	{
		abs->aCount = 0;
		cout << "Cleared successfully!!" << endl;
	}
	else
	{
		cout << "Operation canceled!!" << endl;
	}
	system("pause");
	system("cls");
}


int main()
{
	//Record the information entered by the user
	int select = 0;
	//Define an address book structure
	AddressBooks abs;
	//Set the current number of people to zero
	abs.aCount = 0;

	while (true)
	{
		//Show main menu
		showMenu();

		cin >> select;
		switch (select)
		{
		case 1://1. Add contacts
			AddContacts(&abs);	//address delivery
			break;
		case 2://2. Display contacts
			ShowContacts(&abs); //address delivery
			break;
		case 3://3. Delete contacts
			DeleteContacts(&abs);
			break;
		case 4://4. Find contacts
			GetContacts(&abs);
			break;
		case 5://5. Modify contact person
			ModefyContacts(&abs);
			break;
		case 6://6. Clear contacts
			ClearContacts(&abs);
			break;
		case 0://0. Exit the address book
			cout << "Welcome next time, bye" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
		}
	}


	system("pause");//Press any key to continue
	return 0;
}