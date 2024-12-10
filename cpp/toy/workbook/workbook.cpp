#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <rapidjson/document.h>
#include <rapidjson/writer.h>
#include <rapidjson/stringbuffer.h>

class WorkBook
{
public:
	std::string Question;
};

/*
"question":"sample question. 1 + 2",
"choices":["2",	"3", "4", "5"],		
"answer": 2,						
"grade":"basic",					
"code":"testc0de"					
*/

int	main()
{
	std::ifstream file("data.json");
	if (!file)
	{
		std::cerr<<	"Failed	to open	file" << std::endl;
		return 1;
	}
	
	std::stringstream buffer;
	buffer << file.rdbuf();
	std::string	jsonStr	= buffer.str();
	
	rapidjson::Document	doc;
	doc.Parse(jsonStr.c_str());
	
	if (doc.HasParseError())
	{
		std::cerr << "Error	parsing	JSON." << std::endl;
		return 1;
	}
	
	if (!doc.IsArray())
	{
		
	}
	
	for	(const auto& item :	doc.GetArray())	{
		if (item.IsObject()) {
			// "question" 출력
			if (item.HasMember("question") && item["question"].IsString()) {
				std::cout << "Question:	" << item["question"].GetString() << std::endl;
			}

			// "choices" 출력
			if (item.HasMember("choices") && item["choices"].IsArray())	{
				std::cout << "Choices: ";
				for	(const auto& choice	: item["choices"].GetArray()) {
					if (choice.IsString()) {
						std::cout << choice.GetString()	<< " ";
					}
				}
				std::cout << std::endl;
			}

			// "answer"	출력
			if (item.HasMember("answer") &&	item["answer"].IsInt())	{
				std::cout << "Answer: "	<< item["answer"].GetInt() << std::endl;
			}

			// "grade" 출력
			if (item.HasMember("grade")	&& item["grade"].IsString()) {
				std::cout << "Grade: " << item["grade"].GetString()	<< std::endl;
			}

			// "code" 출력
			if (item.HasMember("code") && item["code"].IsString()) {
				std::cout << "Code:	" << item["code"].GetString() << std::endl;
			}

			std::cout << "------------------------"	<< std::endl;
		}
	}
	
	return 0;
}