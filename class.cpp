#include "class.h"

//konstruktor
File::File( string file1, string file2, string file3 )
{

	annual_file_read( file1 );
	total_file_read( file2 );
	share_file_read( file3 );
}

bool File::annual_file_read( string file_name )
{
	//Open the file
	fstream file{ file_name, ios::in };

	//Check if the file opens correctly
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
	int index = 0;			//Variable to save the index of neoplasms
	int j = 0;
	Annual_file annual_temp = { "",0,0,0 };		//Struct variabole to save : country, year, number of deaths cause by cancer, overall number of deaths 

	//Reading the headlines and find the index od neoplasm
	while(getline( stemp, head_temp, ',' ))
	{
		Head_annual.push_back( head_temp );
		if(head_temp == "Neoplasms")
		{
			index = i;
		}
		i++;
	}

	//Reading all lines of a file and writing them to variables
	while(!file.eof( ))
	{
		getline( file, line );
		stringstream stemp( line );

		while(getline( stemp, head_temp, ',' ))
		{
			if(j == 0)
			{
				if(head_temp == "")
					break;
				annual_temp.Country = head_temp;
				Country.push_back( head_temp );
			}
			else if(j == 2)
			{
				try
				{
					annual_temp.Year = stoi( head_temp );		//convert string to int
					Years.push_back( stoi( head_temp ) );
				}
				catch(const invalid_argument& ia)
				{
					Country.pop_back( );
					break;
				}
			}
			else if(j == index)
			{
				try
				{
					annual_temp.Death_by_cancer = stoi( head_temp );
				}
				catch(const invalid_argument& ia)
				{
					annual_temp.Death_by_cancer = -1;
				}
			}
			else if(j > 2)
			{
				try
				{
					annual_temp.Death_by_diseases += stoi( head_temp );
				}
				catch(const invalid_argument& ia) { }
			}
			j++;

		}
		Data_annual.push_back( annual_temp );
		j = 0;
		annual_temp.Death_by_diseases = 0;
	}

	// sort and delete repeated variables (Country, Years)

	Country.sort( );
	Country.unique( );

	Years.sort( );
	Years.unique( );

	return true;
}

bool File::total_file_read( string file_name )
{
	//Open the file
	fstream file{ file_name, ios::in };

	//Check if the file opens correctly
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
	int j = 0;

	Total_cancer_file annual_temp;

	while(getline( stemp, head_temp, ',' ))
	{
		if(i >= 0 && i <= 2)
			i++;
		else
			Type_of_cancer.push_back( head_temp );

	}


	//Reading all lines of a file and writing them to variables
	while(!file.eof( ))
	{
		getline( file, line );
		stringstream stemp( line );

		while(getline( stemp, head_temp, ',' ))
		{
			if(j == 0)
			{
				if(head_temp == "")
					break;
				annual_temp.Country = head_temp;
				Country.push_back( head_temp );
			}
			else if(j == 2)
			{
				try
				{
					annual_temp.Year = stoi( head_temp );		//convert string to int
					Years.push_back( stoi( head_temp ) );
				}
				catch(const invalid_argument& ia)
				{
					Country.pop_back( );
					break;
				}
			}
			else if(j > 2)
			{
				try
				{
					annual_temp.Number_of_deaths.push_back( stoi( head_temp ) );
				}
				catch(const invalid_argument& ia) {
					annual_temp.Number_of_deaths.push_back( -1 );
				}
			}
			j++;

		}
		Data_total.push_back( annual_temp );
		annual_temp.Number_of_deaths = { };
		j = 0;
	}

	// sort and delete repeated variables (Country, Years)
	Country.sort( );
	Country.unique( );

	Years.sort( );
	Years.unique( );

	return true;
}

bool File::share_file_read( string file_name )
{
	//Open the file
	fstream file{ file_name, ios::in };

	//Check if the file opens correctly
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
	int j = 0;

	Population_share_file annual_temp;

	while(getline( stemp, head_temp, ',' ))
	{
		if(i >= 0 && i <= 2)
			i++;
		else
			Age_range.push_back( head_temp );

	}

	//Reading all lines of a file and writing them to variables
	while(!file.eof( ))
	{
		getline( file, line );
		stringstream stemp( line );

		while(getline( stemp, head_temp, ',' ))
		{
			if(j == 0)
			{
				if(head_temp == "")
					break;
				annual_temp.Country = head_temp;
				Country.push_back( head_temp );
			}
			else if(j == 2)
			{
				try
				{
					annual_temp.Year = stoi( head_temp );		//convert string to double
					Years.push_back( stoi( head_temp ) );
				}
				catch(const invalid_argument& ia)
				{
					Country.pop_back( );
					break;
				}
			}
			if(j == 8)
			{
				try
				{
					annual_temp.All_ages = stod( head_temp );
					annual_temp.Deaths.push_back( stod( head_temp ) );
				}
				catch(const invalid_argument& ia) {
					annual_temp.All_ages = -1;
					annual_temp.Deaths.push_back( -1 );
				}
			}
			else if(j > 2)
			{
				try
				{
					annual_temp.Deaths.push_back( stod( head_temp ) );
				}
				catch(const invalid_argument& ia) {
					annual_temp.Deaths.push_back( -1 );
				}
			}
			j++;
		}
		Data_population.push_back( annual_temp );
		annual_temp.Deaths = { };
		j = 0;
	}

	// sort and delete repeated variables (Country, Years)
	Country.sort( );
	Country.unique( );

	Years.sort( );
	Years.unique( );

	return true;
}

bool File::population( )
{
	vector <Annual_file> annual_temp = Data_annual;
	vector<Population_share_file> population_temp = Data_population;

	all temp = { "",0,0,"",0,"",0,"",0,"",0 };

	for(auto country : Country)
	{
		int i = 0;
		int j = 0;
		int k = 0;
		int l = 0;
		for(auto years : Years)
		{
			k = 0;
			temp.Country = country;
			temp.Year = years;
			for(i = 0; i < annual_temp.size( ); i++)
			{
				l = 0;
				if(annual_temp[i].Country == country && annual_temp[i].Year == years)
				{
					for(j = 0; j < population_temp.size( ); j++)
					{
						if(population_temp[j].Country == country && population_temp[j].Year == years)
						{
							if(annual_temp[i].Death_by_cancer == -1 || population_temp[j].All_ages == -1)
							{
								annual_temp.erase( annual_temp.begin( ) + i );
								population_temp.erase( population_temp.begin( ) + j );
								temp.Total_num_population = -1;
								break;
							}
							temp.Total_num_population = annual_temp[i].Death_by_cancer * 100 / population_temp[j].All_ages ;
							annual_temp.erase( annual_temp.begin( ) + i );
							population_temp.erase( population_temp.begin( ) + j );
							break;
						}
						else
							l++;
					}
					if(l == population_temp.size( ) && population_temp.size( ) > 2)
					{
						temp.Total_num_population = -1;
						annual_temp.erase( annual_temp.begin( ) + i );
					}
				}
				else
					k++;
			}
			if(k == annual_temp.size( ) && annual_temp.size( ) > 2)
				temp.Total_num_population = -1;
			Summary.push_back( temp );
		}
	}
	return true;
}

bool File::static_cancer( )
{
	int k;
	int l;
	int n = 0;
	all summary_temp = { "",0,0,"",0,"",0,"",0,"",0 };
	for(auto country : Country)
	{
		for(auto year : Years)
		{
			summary_temp.Country = country;
			summary_temp.Year = year;
			int m = 0;
			for(int i = 0; i < Data_total.size( ); i++)
			{
				if(Data_total[i].Country == country || Data_total[i].Year == year)
				{
					int min = Data_total[i].Number_of_deaths[0];
					k = 0;
					l = 0;
					int max = Data_total[i].Number_of_deaths[0];
					for(int j = 1; j < Data_total[i].Number_of_deaths.size( ); j++)
					{
						if(Data_total[i].Number_of_deaths[j] != -1)
						{
							if(Data_total[i].Number_of_deaths[j] < min)
							{
								min = Data_total[i].Number_of_deaths[j];
								k = j;
							}
							if(Data_total[i].Number_of_deaths[j] > max)
							{
								max = Data_total[i].Number_of_deaths[j];
								l = j;
							}
						}
					}
					summary_temp.Least_deaths_num = min;
					summary_temp.Least_deaths_name = Type_of_cancer[k];
					summary_temp.Most_deaths_num = max;
					summary_temp.Most_deaths_name = Type_of_cancer[l];
				}
				else
					m++;

				if(m == Data_total.size( ))
				{
					summary_temp.Least_deaths_num = -1;
					summary_temp.Least_deaths_name = "";
					summary_temp.Most_deaths_num = -1;
					summary_temp.Most_deaths_name = "";
				}
			}
			Summary.push_back( summary_temp );
			n++;
		}
	}

	return true;
}

bool File::static_ages( )
{
	int k, l;
	int n = 0;
	for(auto country : Country)
	{
		for(auto year : Years)
		{
			int m = 0;
			for(int i = 0; i < Data_population.size( ); i++)
			{
				if(Data_population[i].Country == country || Data_population[i].Year == year)
				{
					double min = Data_population[i].Deaths[0];
					double max = Data_population[i].Deaths[0];
					for(int j = 1; j < Data_population[i].Deaths.size( ); j++)
					{
						if(Data_population[i].Deaths[j] == Data_population[i].All_ages);
						else
						{
							if(Data_population[i].Deaths[j] < min)
							{
								min = Data_population[i].Deaths[j];
								k = j;
							}
							if(Data_population[i].Deaths[j] > max)
							{
								max = Data_population[i].Deaths[j];
								l = j;
							}
						}
					}
					Summary[n].Least_deaths_num_age = min;
					Summary[n].Least_deaths_range = Age_range[k];
					Summary[n].Most_deaths_num_age = max;
					Summary[n].Most_deaths_range = Age_range[l];
				}
				else
					m++;
				if(m == Data_population.size( ))
				{
					Summary[n].Least_deaths_num_age = -1;
					Summary[n].Least_deaths_range = "";
					Summary[n].Most_deaths_num_age = -1;
					Summary[n].Most_deaths_range = "";
				}
			}
			n++;
		}
	}

	return true;
}

void File::annual_sort( )
{
	Country_by_cancer = Data_annual;
	sort( Country_by_cancer.begin( ), Country_by_cancer.end( ) );
}

bool File::death_count_by_year( )
{
	Type_year temp;

	int* sum = new int[Years.size( )];
	for(auto years : Years)
	{
		temp.Year = years;

		for(int k = 0; k < Years.size( ); k++)
			sum[k] = 0;

		for(int j = 0; j < Data_total.size( ); j++)
		{
			if(Data_total[j].Year == years)
			{
				for(int k = 0; k < Data_total[j].Number_of_deaths.size( ); k++)
					sum[k] += Data_total[j].Number_of_deaths[k];
			}
		}

		for(int k = 0; k < Years.size( ); k++)
		{
			temp.Deaths.push_back( sum[k] );
		}

		Death_num_by_type.push_back( temp );
		temp.Deaths = { };
	}
	delete(sum);

	//searches max and min number of deaths for each type of cancer
	for(int i = 0; i < Death_num_by_type.size( ); i++)
	{
		int min = Death_num_by_type[0].Deaths[i];
		int max = Death_num_by_type[0].Deaths[i];
		int year_min = Death_num_by_type[0].Year;
		int year_max = Death_num_by_type[0].Year;
		for(int j = 1; j < Type_of_cancer.size( ); j++)
		{
			if(Death_num_by_type[j].Deaths[i] < min)
			{
				year_min = Death_num_by_type[j].Year;
				min = Death_num_by_type[j].Deaths[i];
			}

			if(Death_num_by_type[j].Deaths[i] > max)
			{
				year_max = Death_num_by_type[j].Year;
				max = Death_num_by_type[j].Deaths[i];
			}
		}
		Max_in_type.push_back( max );		//index Type_of_cancer == index Max/Min_in_type 
		Min_in_type.push_back( min );
	}
	return true;
}

bool File::per( )
{
	int k, l;
	int n = 0;
	double x;
	for(auto country : Country)
	{
		for(auto year : Years)
		{
			int m = 0;
			for(int i = 0; i < Data_annual.size( ); i++)
			{
				if(Data_annual[i].Country == country || Data_annual[i].Year == year)
				{
					x = (double( Data_annual[i].Death_by_cancer ) / double( Data_annual[i].Death_by_diseases )) * 100;
					Percent.push_back( x );
				}
				else
					m++;
				if(m == Data_annual.size( ))
				{
					Percent.push_back( -1 );
				}
			}
		}
	}
	return true;
}

bool File::save_to_file( )
{
	ofstream outfile1( "statistic_cancer.csv" );
	outfile1 << "Country,Year,Type of cancer with the most deaths,Deaths,Type of cancer with the least deaths,Deaths,Age range with the most deaths,Deaths,Age range with the least deaths,Deaths" << endl;
	for(int i = 0; i < Summary.size( ); i++)
	{
		outfile1 << Summary[i].Country << "," << Summary[i].Year << "," << Summary[i].Most_deaths_name << "," << Summary[i].Most_deaths_num << "," << Summary[i].Least_deaths_name << "," << Summary[i].Least_deaths_num << "," << Summary[i].Most_deaths_range << "," << Summary[i].Most_deaths_num_age << "," << Summary[i].Least_deaths_range << "," << Summary[i].Least_deaths_num_age << endl;
	}
	outfile1.close( );

	ofstream outfile2( "statistic_year.csv" );
	outfile2 << "Year";			// rok, typy nowotworow ilosc zgonow ponizej 
	for(int i = 0; i < Type_of_cancer.size( ); i++)
	{
		outfile2 << "," << Type_of_cancer[i];
	}
	outfile2 << endl;


	for(int i = 0; i < Death_num_by_type.size( ); i++)
	{
		outfile2 << Death_num_by_type[i].Year;
		for(int j = 0; j < Years.size( ); j++)
		{
			outfile2 << "," << Death_num_by_type[i].Deaths[j];
		}
		outfile2 << endl;
	}
	outfile2.close( );


	ofstream outfile3( "statistic_year_type.csv" );
	outfile3 << "Type of cancer,Min,Max" << endl;
	for(int i = 0; i < Type_of_cancer.size( ); i++)
	{
		outfile3 << Type_of_cancer[i] << "," << Min_in_type[i] << "," << Max_in_type[i] << endl;
	}
	outfile3.close( );

	ofstream outfile4( "percent.death.csv" );
	outfile4 << "Country,Year,Percentage" << endl;
	for(int i = 0; i < Summary.size( ); i++)
	{
		outfile4 << Summary[i].Country << "," << Summary[i].Year << "," << Percent[i] << endl;
	}
	outfile4.close( );

	return true;
}
