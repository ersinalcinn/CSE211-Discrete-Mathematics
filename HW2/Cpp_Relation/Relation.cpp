#include <iostream>
#include <fstream>
using namespace std;
ofstream saveFile("output.txt");
ifstream input("input.txt");
void Reflexive(int rSize, char relationElements[][2], int element,char elements[20]) {
	cout << "n" << endl;
	saveFile << "n" << endl;
	char temp[element];
	int reflex = 0,countt = 0;
	for (int i = 0; i < rSize; i++)
	{
		cout << "(" << relationElements[i][0] << "," << relationElements[i][1]<< ")";
		saveFile << "(" << relationElements[i][0] << "," << relationElements[i][1]<< ")";
	}
	cout << endl;
	saveFile << endl;
	for (int i = 0; i < element; i++) {
		temp[i] = 0;
	}
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < rSize; j++) {
			if (elements[i] == relationElements[j][0]&& elements[i] == relationElements[j][1])
			{
				reflex++;
				temp[countt] = elements[i];
				countt++;
			}
		}
	}
	if (reflex == element) {
		cout << "Reflexive: Yes, all elements are present.\n";
		saveFile << "Reflexive: Yes, all elements are present.\n";
	} else {
		cout << "Reflexive: No, all elements are  not present.";
		saveFile << "Reflexive: No, all elements are  not present.";

		for (int i = 0; i < element; i++) {
			if (temp[i] != elements[i]) {
				cout << "(" << elements[i] << "," << elements[i] << ")";
				saveFile << "(" << elements[i] << "," << elements[i] << ")";
				break;
			}

		}

		cout << "  not found\n";
		saveFile << "  not found\n";
	}
	reflex = 0;

}
void Symmetric(int rSize, char relationElements[][2], int element) {
	int symmetric = 0;
	for (int i = 0; i < rSize; i++) {
		for (int j = 0; j < rSize; j++) {
			if (relationElements[i][0] == relationElements[j][1]&& relationElements[i][1] == relationElements[j][0])
			{
				symmetric++;
			}
		}
	}
	if (symmetric == rSize) {
		cout << "Symmetric: Yes, all elements are present.\n";
		saveFile << "Symmetric: Yes, all elements are present.\n";
	} else {
		symmetric = 0;
		cout << "Symmetric: No,";
		saveFile << "Symmetric: No,";
		for (int i = 0; i < rSize; i++) {
			for (int j = 0; j < rSize; j++) {
				if (relationElements[i][0] == relationElements[j][1]&& relationElements[i][1] == relationElements[j][0])
				{
					symmetric++;
				}
			}
			if (symmetric == 0) {
				cout << "(" << relationElements[i][1] << ","<< relationElements[i][0] << ")" << " ";
				saveFile << "(" << relationElements[i][1] << ","<< relationElements[i][0] << ")" << " ";
				i = rSize;
			}
			symmetric = 0;
		}
		cout << "is not found whereas ";
		saveFile << "is not found whereas ";
		symmetric = 0;
		for (int i = 0; i < rSize; i++) {
			for (int j = 0; j < rSize; j++) {
				if (relationElements[i][0] == relationElements[j][1]&& relationElements[i][1] == relationElements[j][0])
				{
					symmetric++;
				}
			}
			if (symmetric == 0) {
				cout << "(" << relationElements[i][0] << ","
						<< relationElements[i][1] << ")" << " ";
				saveFile << "(" << relationElements[i][0] << ","
										<< relationElements[i][1] << ")" << " ";
				i = rSize;
			}
			symmetric = 0;
		}
		cout << "is found" << endl;
		saveFile << "is found" << endl;
	}
}
void antiSymmetric(int rSize, char relationElements[][2], int element) {
	int antisymmetric = 0;
	for (int i = 0; i < rSize; i++) {
		for (int j = 0; j < rSize; j++) {
			if (relationElements[i][0] == relationElements[j][1] && relationElements[i][1] == relationElements[j][0])
			{
				antisymmetric++;
			}
		}
	}
	if (antisymmetric == rSize) {
		cout << "Antisymmetric: No,";
		saveFile << "Antisymmetric: No,";
		for (int i = 0; i < rSize; i++) {
			for (int j = 0; j < rSize; j++) {
				if (relationElements[i][0] == relationElements[j][1]&& relationElements[i][1] == relationElements[j][0]) {
					antisymmetric++;
				}
			}
			if (antisymmetric != 0) {
				cout << "(" << relationElements[i][1] << ","<< relationElements[i][0] << ")" << " ";
				saveFile << "(" << relationElements[i][1] << ","<< relationElements[i][0] << ")" << " ";
				i = rSize;
			}
			antisymmetric = 0;
		}
		cout << " are found " << endl;
		saveFile << " are found " << endl;
	} else {
		antisymmetric = 0;
		cout << "Antisymmetric: Yes,";
		saveFile << "Antisymmetric: Yes,";
		for (int i = 0; i < rSize; i++) {
			for (int j = 0; j < rSize; j++) {
				if (relationElements[i][0] == relationElements[j][1]&& relationElements[i][1] == relationElements[j][0]) {
					antisymmetric++;
				}
			}
			if (antisymmetric == 0) {
				cout << "(" << relationElements[i][1] << ","<< relationElements[i][0] << ")" << " ";
				saveFile << "(" << relationElements[i][1] << ","<< relationElements[i][0] << ")" << " ";
				i = rSize;
			}
			antisymmetric = 0;
		}
		cout << "is not found whereas";
		saveFile << "is not found whereas";
		antisymmetric = 0;
		for (int i = 0; i < rSize; i++) {
			for (int j = 0; j < rSize; j++) {
				if (relationElements[i][0] == relationElements[j][1]&& relationElements[i][1] == relationElements[j][0]) {
					antisymmetric++;
				}
			}
			if (antisymmetric == 0) {
				cout << "(" << relationElements[i][0] << ","<< relationElements[i][1] << ")" << " ";
				saveFile << "(" << relationElements[i][0] << ","<< relationElements[i][1] << ")" << " ";
				i = rSize;
			}
			antisymmetric = 0;
		}
		cout << "is found" << endl;
		saveFile << "is found" << endl;
	}
}
void Transitive(int rSize, char relationElements[][2], int element) {
	cout << "Transitive:";
	saveFile << "Transitive:";
	char checTransitive[rSize * 3][2];
	int x = 0;
	int a, b;
	for (int i = 0; i < rSize; i++) {
		for (int j = 0; j < rSize; j++) {
			if (relationElements[i][1] == relationElements[j][0]) {
				checTransitive[x][0] = relationElements[i][0];
				checTransitive[x][1] = relationElements[j][1];
				x++;
			}
		}
	}
	int count = 0;
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < rSize; j++) {
			if (checTransitive[i][0] == relationElements[j][0]&& checTransitive[i][1] == relationElements[j][1]) {
				count++;
				a = i;
				b = j;
				break;
			}
		}
	}
	if (count == x) {
		x = 0;
		cout << "Yes\n";
		saveFile << "Yes\n";
	} else {
		cout << "No\n";
		saveFile << "No\n";
		count = 0;
	}
}
void inputFile() {

	int element = 0, a = 0, rSize,newElements=0,size=20;
	char elements[20],c;
	//First of all, I can check the file, then I use the while loop to read to the end of the line.
	if (input.is_open()) {
		while (!input.eof()) {
			for (int i = 0; i < size; i++)
			{
				elements[i] = 0;
			}
			element = 0;
			input.get(c);
			//I keep reading for the \ n at the end of the line. I used my reading as char. (getc)
			if (c == '\n')
			{
				input.get(c);
			} else
			{
				//I am reading relation size and if there is no value after you, I applied the if condition because it will be \ n.
				rSize = (int) c - 48;
				input.get(c);
				if (c != '\n') {
					rSize = (rSize * 10) + ((int) c - 48);//The coefficient was determined for the possibility of having a relation greater than 10.
					input.get(c);
				}
				input.get(c);
				char relationElements[rSize][2];//then define the char array to keep the elements according to the relation size.
				while (c != '\n')
				{
					if (c != ',')
					{
						elements[element - (element / 2)] = c;
					}
					input.get(c);
					//the number of elements increases with every char data it reads here
					element++;
				}
				//Thus, I filled the relation elements array separately for each relation using a loop and sent it to functions.
				for (int k = 0; k < rSize; k++)
				{
					input.get(c);
					relationElements[k][0] = c;
					input.get(c);
					input.get(c);
					relationElements[k][1] = c;
					input.get(c);

				}
				newElements=element-(element / 2);//I subtract the number of commas read from each number of characters counted.
				Reflexive(rSize, relationElements, newElements,elements);//reflexive
				Symmetric(rSize, relationElements, newElements);//symmetric
				antiSymmetric(rSize, relationElements, newElements);//antisymmetric
				Transitive(rSize, relationElements, newElements);//transitive
			}
		}
	}
}

int main() {
	//I call the input File function, where we will read the relations on main.
		inputFile();
}
