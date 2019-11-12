// Exercise 5

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string find_field(string, string);



int main() {
	string page, line, location, temperature;
	ifstream inputFile("weather.xml");
	
	while (getline (inputFile, line)) {
 	    page.append(line);
 	    line.erase();
	}
	
	location = find_field(page, "location");
	temperature = find_field(page, "temp_c");
	
	cout << "Location: " << location << endl;
	cout << "Temperature: " << temperature << endl; 
	system("pause");
}

string find_field(string str, string tag)
{
	string err = "Error: Tag not found";
	string startTag = "<" + tag + ">";
	string endTag = "</" + tag + ">";

	size_t startPos = str.find(startTag);
	size_t endPos = str.find(endTag);
	if (startPos == string::npos || endPos == string::npos)  
		return err;

	startPos += startTag.length(); //we need the text past the tag

	string content = str.substr(startPos, (endPos - startPos));
#if 0
	cout << tag << endl;
	cout << startPos << endl;
	cout << endPos << endl;
	cout << content << endl;
#endif
	return content;
}
