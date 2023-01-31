#include "class.h"

using namespace std;

int main()
{
	//wczytanie danych do wektora dla kazdego kraju z kazdego roku
 
	cout << "Data for each country and each year are saved in files. The 'statistic_cancer.csv' file contains data for each country in each year. \nThe file 'country_by_num_of_deaths.csv' contains data for each country and year, sorted from lowest to highest number of deaths. \nStatistical data for each year up to 'statistic_year.csv' for each type of cancer are stored in the file 'statistic_year_type.csv'. ";

	File temp = File("annual-number-of-deaths-by-cause.csv", "total-cancer-deaths-by-type.csv", "share-of-population-with-cancer-by-age.csv");

	temp.static_cancer( );
	temp.static_ages( );
	temp.annual_sort( );
	temp.death_count_by_year( );
	temp.per( );
	temp.save_to_file( );

	return 0;
}