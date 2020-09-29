#pragma once
#include "my_override_functions_and_operators.h"
#include <ctime>
using namespace ofo;

namespace bi//book information
{
	enum class Participation
	{ 
		TheMainCharacter,
		MinorCharacter,
		EpisodicCharacter
	};
	struct Date
	{
		int year;
		int month;
		int day;
		Date();
		Date(int year, int month, int day);
	};
	struct Book
	{	
		std::string name;
		std::vector<std::string> authorsNames;
		Date releaseDate;
		std::size_t size;
		std::string shortAbstract;
		Book();
		Book(const std::string& name, const std::vector<std::string>& authorsNames, Date releaseDate, std::size_t size, const std::string& shortAbstract);
		~Book();
	};
	struct Character
	{
		std::vector<std::string> namesList;
		std::vector<Book*> books;		
		std::vector<Participation> participations;
		Character();
		Character(const std::vector<std::string>& namesList, const std::vector<Book*>& books, const std::vector<Participation>& participations);
		~Character();
	};
	struct Information
	{
		std::vector<Book> books;
		std::vector<Character> characters;
		std::vector<Book*> series;
		Information();
		Information(const std::vector<Book>& books, const std::vector<Character>& characters, const std::vector<Book*>& series);
		~Information();
	};
}

namespace bi
{
	//Date
	Date::Date() : year(0), month(0), day(0) {}
	Date::Date(int year, int month, int day) : year(year), month(month), day(day) {}
	//Book
	Book::Book(): name(""), authorsNames({}), releaseDate(Date()), size(0), shortAbstract("") {}
	Book::Book(const std::string& name, const std::vector<std::string>& authorsNames, Date releaseDate, std::size_t size, const std::string& shortAbstract)
		: name(name), authorsNames(authorsNames), releaseDate(releaseDate), size(size), shortAbstract(shortAbstract) {}
	Book::~Book()
	{
		name = "";
		authorsNames.clear();
		releaseDate = Date();
		size = 0;
		shortAbstract = "";
	}
	//Character
	Character::Character() : namesList({}), books({}), participations({}) {}
	Character::Character(const std::vector<std::string>& namesList, const std::vector<Book*>& books, const std::vector<Participation>& participations)
		: namesList(namesList), books(books), participations(participations) {}
	Character::~Character()
	{
		namesList.clear();
		books.clear();
		participations.clear();
	}
	//Information
	Information::Information() : books({}), characters({}), series({}) {}
	Information::Information(const std::vector<Book>& books, const std::vector<Character>& characters, const std::vector<Book*>& series)
		: books(books), characters(characters), series(series) {}
	Information::~Information()
	{
		books.clear();
		characters.clear();
		series.clear();
	}
}
