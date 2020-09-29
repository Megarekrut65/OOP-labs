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
	class Book
	{	
	private:
		std::string name;
		std::vector<std::string> authorsNames;
		Date releaseDate;
		std::size_t size;
		std::string shortAbstract;
	public:
		Book();
		Book(const std::string& name, const std::vector<std::string>& authorsNames, Date releaseDate, std::size_t size, const std::string& shortAbstract);
		~Book();
		void addAuthor(const std::string& author);
	};
	class Character
	{
	private:
		std::vector<std::string> namesList;
		std::vector<Book*> books;		
		std::vector<Participation> participations;
	public:
		Character();
		Character(const std::vector<std::string>& namesList, const std::vector<Book*>& books, const std::vector<Participation>& participations);
		~Character();
		void addBook(const std::string& characterName, Book* bookAddress, Participation participation);
	};
	class Information
	{
	private:
		std::vector<Book> library;
		std::vector<Character> characters;
		std::vector<std::vector<Book*>> series;
		void addToSerie(std::size_t bookIndex);
	public:
		Information();
		Information(const std::vector<Book>& books, const std::vector<Character>& characters, const std::vector<std::vector<Book*>>& series);
		~Information();
		void addBook(const Book& book);
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
	void Book::addAuthor(const std::string& author)
	{
		authorsNames.push_back(author);
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
	void Character::addBook(const std::string& characterName, Book* bookAddress, Participation participation)
	{
		namesList.push_back(characterName);
		books.push_back(bookAddress);
		participations.push_back(participation);
	}
	//Information
	Information::Information() : library({}), characters({}), series({}) {}
	Information::Information(const std::vector<Book>& books, const std::vector<Character>& characters, const std::vector<std::vector<Book*>>& series)
		: library(books), characters(characters), series(series) {}
	Information::~Information()
	{
		library.clear();
		characters.clear();
		series.clear();
	}
	void Information::addBook(const Book& book)
	{
		library.push_back(book);
	}
	void Information::addToSerie(std::size_t bookIndex)
	{

	}
}
