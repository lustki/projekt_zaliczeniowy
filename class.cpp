#include "class.h"

bool File::annual_file_read( string file_name )
{
	fstream file{ file_name, ios::in };

	if(file.good( ) == false)
	{
		cerr << "Error: File can not be open." << file_name;
		return false;
	}

	string line;
	string head_temp;
	getline( file, line );
	stringstream stemp( line );
	int i = 0;
	Annual_file annual_temp;

	while (getline( stemp, head_temp, ',' ))
	{
		Head_annual.push_back( head_temp );
	} 

	while(EOF)
	{
		getline( file, line );
		stringstream stemp( line );

		while(getline( stemp, head_temp, ',' ))
		{
			if(i == 0)
			{
				annual_temp.Country = head_temp;
				Country.push_back( head_temp );
			}
			else if(i == 1)
			{
				annual_temp.Year = stoi( head_temp );		//convert string to int

			}



		}

	}
	//sortowanie i uniq listy counrty
	return true;
}