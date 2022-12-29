#include "class.h"

using namespace std;

int main()
{
	
	//wczytanie danych do wektora dla kazdego kraju z kazdego roku
	
	/*
	fstream File_annual{ "annual-number-of-deaths-by-cause.csv" };
	fstream File_share{ "share-of-population-with-cancer-by-age.csv" };
	fstream File_total{ "total-cancer-deaths-by-type.csv" };
	*/

	File temp;
	temp.annual_file_read( "annual-number-of-deaths-by-cause.csv" );

}