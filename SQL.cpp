#include <iostream>
using namespace std;
#include "sqlite/sqlite3.h"
#include <string>


void help()
{
	cout << "Where would you like help?\n";

	cout << "\n1 for INSERT"
		<< "\n2 for UPDATE (update a single or selected values)"
		<< "\n3 for SELECT (returns data where you select)"
		<< "\n4 for WHERE"
		<< "\n5 for CREATE (create a table)"
		<< "\n6 for DROP (delete a table)"
		<< "\n\n0 for SQL Injection (illegal if you don't own the database or network, even if your attempts dont work)";
	cout << "\n\nInput: ";
	int input;
	cin >> input;

	
	switch (input)
	{
	case 1: // INSERT
		cout << "\nExample:\n\tINSERT INTO 'name of table' ( 'column1', 'column2', so on..) \n\t\tVALUES('value1' 'value2' so on.) *they must be in order*"
			<< "\nAnd that will work. or you can\n\n\tINSERT INTO 'name of your table' VALUES('value1, 'value2', so on..)";
		break;
	case 2: // UPDATE
		cout << "\n Example:\n\tUPDATE 'name of table' SET 'column1' = 'new value'\n\t\tWHERE 'column2' = 'existing value'";
		cout << "\nIf you dont add the WHERE statement, the update will update every column in that table.\n";
		break;
	case 3:	// SELECT
		cout << "\nExample 1:\n\tSELECT * FROM 'name of table'\nThis will return everything inside that table\n";
		cout << "\nExample 2:\n\tSELECT 'name of column' FROM 'name of table'\nThis will return every value under that column in that table\n";
		cout << "\nExample 3:\n\tSELECT 'name of column', 'other column name' FROM 'name of table'\nThis will return every value of those columns in that table\n";
		break;
	case 4: // WHERE
		cout << "\nExample:\n\tWHERE";
		break;
	case 5: // CREATE
		cout << "\nExample:\n\tCREATE TABLE 'name you want for table'( example_column varchar(100), 'name your column' 'data type', 'rinse' 'and repeat until done')";
		cout << "\nCongrats! you've just made a new table! you can use an int, long int, varchar(256), flaot, bool.. so on";
		break;
	case 6: // DROP
		cout << "\nExample:\n\tDROP TABLE 'name of table'";
		cout << "\nWarning, there is no going back from this.";
		break;
	case 0: // SQL Injection
		system("cls");
		cout << "This is my favorite part\n\n";
		cout << "SQL Injection can take many forms. A few easy ones to tickle your imagination are\n"
			  << "\tComments, Additional Statements and Tautology (modifiying a bool statement to always equate to true)";
		cout << "\n\nThis is primarily done by pre-exiting a statement. Half of these primarily apply to html and javascript\n"
			  << "\tBut can also apply to a program like this one, depending on how its written.";

		cout << "\n\nA website with a login or any form of field input where the website uses the input to execute a code,"
			  << "\n\tIs vulnerable to an attack. The input is used to make a SQL or javascript command to be executed.";

		cout << "\n\nExample: A website that uses 1 input field to form a SQL statement would look like this in code"
			  << "\n\n\tstring sql_statement = (\"SELECT * FROM Users WHERE username = '\" + inputfield + \"';);\n"
			  << "\n\tcreating a string to be used as a SQL Statement of \"SELECT * FROM User WHERE username = '______';\""
	  		  << "\n\nIf I input (username'; DROP Users; -- )\n\tSELECT * FROM  Users WHERE username = 'username';\n\t\tDROP Users;"
			  << "\n\nThe user was able to modify the intended SQL statement to ALSO delete the table"
			  << "\nthe user added a single quotation mark which exited the expected input, but because I was modifying everything,"
			  << "\n\nI needed to add semi-colons so it complies to the coding language and the -- would comment out the\nlast ' added from the formed query";
		break;
	default:
		cout << "type help again";
		break;
	}

	cout << "\n\n\n";

	return;
}

/*
 * Arguments:
 *
 *   unused - Ignored in this case, see the documentation for sqlite3_exec
 *    count - The number of columns in the result set
 *     data - The row's data
 *  columns - The column names
 */
int my_special_callback(void* unused, int count, char** data, char** columns)
{
	int idx;

	printf("There are %d column(s)\n", count);

	for (idx = 0; idx < count; idx++) {
		printf("The data in column \"%s\" is: %s\n", columns[idx], data[idx]);
	}

	printf("\n");

	return 0;
}



string execute()
{
	string returnSQL;
	string input;
	system("cls");
	cout << "Select what you want to add\n\n1 SELECT\n2 CREATE\n3 INSERT\n4 UPDATE\n5 DROP";
	cout << "\n\tExec Ready: ";
	cin >> input;

	if (input == "1") // SELECT
	{
		returnSQL += "SELECT";
			
	}
	else if (input == "2") // CREATE
	{
		returnSQL += "CREATE TABLE ";
		cout << "\nWhat is the name of your new table? : ";
		cin >> input;
		returnSQL += input;
		returnSQL += "(";
		cout << "Entering into a loop of creating columns for your table\n\tType \"done\" when your done\n";
		int i = 1;
		bool done = false;
		while (!done)
		{

			cout << "\nWhat is the name of column " << i << "? : ";
			cin >> input;
			if (input == "done")
				break;
			if (i > 1)
				returnSQL += ",";
			returnSQL += (input + " ");  // adding name and space
			cout << "What is the data type? : ";
			cin >> input;
			returnSQL += input;

			i++;

		}
		returnSQL += ")";
	}
	else if (input == "3") // INSERT
	{
		returnSQL += "INSERT ";
	}
	else if (input == "4") // UPDATE
	{
		returnSQL += "UPDATE ";
	}
	else if (input == "5") // DROP
	{
		returnSQL += "DROP TABLE ";
		cout << "\nDROP what table? : ";
		cin >> input;
		returnSQL += input;
	}
	cout << "\n\n\t" << returnSQL << "\n\n";
	return returnSQL;
}

int main()
{
	char* error;
	const char* dir = "C:\\Users\\brand\\OneDrive\\School CS\\A++\\CSE310\\Sprint04\\my_Database.db";
	system("cls");
	//cout << "\nhello world " << dir << endl << endl;
	sqlite3 *db;
	sqlite3_stmt* p_Statement;
	string allQuery;
	sqlite3_open(dir, &db);
	int response;
	while (true)
	{
		//cin.ignore(0);
		cout << "\n\nType help for assistance \nOr exec for premade SQL statements\nOr type now to execute code directly\n\n";
		cout << "\tReady: "; 
		getline(cin, allQuery);
		if (allQuery == "")
			continue;
		if (allQuery == "quit")
			break;
		else if (allQuery == "help")
		{
			help();
			continue;
		}
		else if (allQuery == "exec")
		{
			allQuery = execute();
		}
		allQuery += ";";
		response = sqlite3_exec(db, allQuery.c_str(), my_special_callback, NULL, &error);
		if (response != SQLITE_OK)
			cout << error << endl << endl;
		allQuery = "";
		//cout << p_Statement;
		
	}

	sqlite3_close(db);

	return 0;
}