#pragma once
#pragma once

#include <string>
#include <iostream>
#include <vector>
#include <list>
#include <fstream>
#include <sstream>
#include<algorithm>

using namespace std;

//Annual number of deaths by cause file 
struct Annual_file
{
	string Country;
	int Year;
	int Death_by_cancer;
	int Death_by_diseases;
	bool operator < ( const Annual_file& x )const
	{
		return Death_by_cancer > x.Death_by_cancer;
	}
};

//Total cancer deaths by type file
struct Total_cancer_file
{
	//Variables with the number of deaths

	string Country;
	int Year;
	vector <int> Number_of_deaths;
};


//Share of population with cancer file 
struct Population_share_file
{
	//Variables 

	string Country;
	int Year;

	double All_ages;
	vector<double> Deaths;
	/*
	bool operator < ( const Population_share_file& x )const
	{
		return Deaths > x.Deaths;
	}
	*/
};

struct Type_year
{
	int Year;
	vector<int> Deaths;
};

struct all
{
	string Country;
	int Year;
	double Most_deaths_num_age;
	string Most_deaths_range;
	double Least_deaths_num_age;
	string Least_deaths_range;

	int Most_deaths_num;
	string Most_deaths_name;
	int Least_deaths_num;
	string Least_deaths_name;

	int Total_num_population;
};

class File
{
private:

	//Method declarations
	bool annual_file_read( string file_name );
	bool total_file_read( string file_name );
	bool share_file_read( string file_name );


public:

	bool population( );								// count number of death overall in each country and year
	bool static_cancer( );							//method with checking which type of cancer caused the most and least death in each country and year
	bool static_ages( );							// find max and min number of deaths by age range in each country and year
	void annual_sort( );							//sorting from the largest number of deaths performed due to the uprisin
	bool death_count_by_year( );					// count hhoww many deaths were in each of year in each type of cancer
													// find max and min number of deaths by type overall
	bool per( );
	bool save_to_file( );

	vector<all>Summary;
	//Vector with column headers
	vector <string> Head_annual;

	//Vector with type of cancer - Annual file
	vector <string> Type_of_cancer;

	//Vector with age range - Share file
	vector <string> Age_range;

	//List with all countries
	list <string> Country;

	//List with all years 
	list <int> Years;

	//List with all number of population
	//vector <int> Total_num_population;

	//Struct vector
	vector <Annual_file> Data_annual;
	vector <Total_cancer_file> Data_total;
	vector <Population_share_file> Data_population;

	vector <Annual_file> Country_by_cancer;

	//funckja liczaca ile bylo zgonow dla kazdego typu w kazdym roku
	vector<Type_year> Death_num_by_type;

	vector<int> Min_in_type;
	vector<int> Max_in_type;
	vector<double> Percent;

	File( string file1, string file2, string file3 );
};