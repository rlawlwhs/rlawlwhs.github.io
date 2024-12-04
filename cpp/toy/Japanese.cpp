#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <rapidjson/document.h>
#include <rapidjson/writer.h>
#include <rapidjson/stringbuffer.h>

int printtest(void);

int printtest(void)
{
	std::string str = "ありがとうございました";
	std::cout << str << std::endl;
	return 0;
}

int main()
{
	std::ifstream file("data.json");
	std::stringstream buffer;
	buffer << file.rdbuf();
	std::string jsonStr = buffer.str();
	
	rapidjson::Document doc;
	doc.Parse(jsonStr.c_str());
	
	if (doc.HasParseError())
	{
		std::cerr << "Error parsing JSON." << std::endl;
		return 1;
	}
	
	std::cout << "Name: " << doc["name"].GetString() << std::endl;
	std::cout << "Age: " << doc["age"].GetInt() << std::endl;
	
	rapidjson::Document newDoc;
	newDoc.SetObject();
	rapidjson::Document::AllocatorType& allocator = newDoc.GetAllocator();
	newDoc.AddMember("name", "John", allocator);
	newDoc.AddMember("age", 30, allocator);
		
	rapidjson::StringBuffer bufferOut;
	rapidjson::Writer<rapidjson::StringBuffer> writer(bufferOut);
	newDoc.Accept(writer);
	
	std::cout << "New JSON: " << bufferOut.GetString() << std::endl;
	
	return 0;
}