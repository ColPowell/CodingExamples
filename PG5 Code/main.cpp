#include <iostream>
#include <string>
#include "main.h"
#include "Database.h"
#include "DB.h"
#include "CmpString.h"
#include "DRT.h"
#include "Comparable.h"
#include <sstream>
using namespace std;

//pretty sure first() is crashing.


int main () {

	string input = "";
	string command = "d";
	string filename = "";
	int count = 0;
	Database *D = new DB ();
	while(command != ""){
		cin >> command;
		if(command == "ADD"){
			getline(cin, filename);
			if(filename != ""){
				filename = filename.substr(1, filename.length());
				count++;
				D->modify(new CmpString(filename, 1), new CmpString("", 1));
				cout << "One copy of " << filename << " has been added to the library." << endl;
				filename = "";
			}
			else cout << "There was no filename." << endl;
		}

		else if(command == "PRINT"){
			int temp = count;
			if(count > 0){
				DRT *info = D->search(NULL);
				Comparable *k = info->getprev();
				info = D->search(k);
				Item *d = info->getdata();
				CmpString *dd = (CmpString *)d;
				cout << "The following books in the library are:" << endl;
				while(temp > 0){
					CmpString *kk = (CmpString*)k;
					temp -= kk->getc();
					cout << kk->gets() << ": " << kk->getc() <<  endl;
					k = (CmpString *) info->getnext();
					info = D->search(k);
				}
			}
			else{
				cout << "There is nothing in the library." << endl;
			}
			
		}
		else if(command == "DELETE"){
			//do remove stuff
			//should just search for filename, then do remove. remove will handle the rest.
			//should only remove one copy.
			//isn't working right. deleting node, but not rotating maybe

			bool fileb = true;
			getline(cin, filename);
			if(filename != ""){
				filename = filename.substr(1, filename.length());}
			else{ cout << "There was no filename." << endl; fileb = false;}
			if(count > 0 && fileb){
				DRT *info = D->search (NULL);
				Comparable *k = info->getprev();
				CmpString *kk;
				CmpString *dd;
				Item* d;
				int loopcount = count;
				int temp = count;
				while (loopcount > 0) {
					loopcount--;
					cout << loopcount << endl;
					kk = (CmpString *)k;
					info = D->search (k);
					if(kk->gets() == filename){
						D->modify(k, NULL);
						count--;
						cout << "One copy of " << filename << " has been removed from the library." << endl;
						break;
					}
					if(count == 0) break;
					cout << "getnext" << endl;
					k = info->getnext();
				}
				if(temp == count){ cout << filename << " was not found in the library." << endl;}
			}
			else{
				if (fileb == true)
					cout << "The library is empty." << endl;
			}
		}
		else if(command == "COUNT"){
			//return how many books there are
			int temp2 = 0;
			int temp = count;
			if(count > 0){
				DRT *info = D->search(NULL);
				Comparable *k = info->getprev();
				info = D->search(k);
				Item *d = info->getdata();
				CmpString *dd = (CmpString *)d;
				while(temp > 0){
					CmpString *kk = (CmpString*)k;
					temp -= kk->getc();
					temp2 += kk->getc();
					k = (CmpString *) info->getnext();
				}
			}
			cout << "There are " << temp2 << " books in the library." << endl;
		}
		//how to end?
	}
	system("pause");
	return 0;
}


void SplitInput(string input, string &command, string &filename, string &priority){

	command = "";
	filename = "";
	priority = "";
	int count = 0;
	int start = 0;
	for(int com = 0; com < (int)input.length(); com++){
		if(input[com] == ' ' && count == 0){
			command = input.substr(0,com);
			start = com;
			count++;
			com++;
		}
		if(input[com] == ' ' && count == 1){
			filename = input.substr(start+1, com-start-1);
			if((command.length() + filename.length() + 1) == input.length()){
				command = "";
			}
			priority = input.substr(com+1, input.length());
			count++;
		}
	}
}