#pragma once

#include <string>
#include <iostream>
#include <vector>
#include <list>
#include <fstream>
#include <sstream>

using namespace std;

//Annual number of deaths by cause file 
struct Annual_file
{
	string Country;
	int Year;
	int Death_by_cancer;
	int Death_by_diseases;
};

//Total cancer deaths by type file
struct Total_cancer_file
{
	//Variables with the number of deaths

	string Country;
	int Year;
	vector <int> Number_of_deaths;

	/*
	int Liver_cancer;
	int Kidney_cancer;
	int Lip_and_oral_cavity_cancer;
	int Tracheal_bronchus_and_lung_cancer;
	int Larynx_cancer;
	int Gallbladder_and_biliary_tract_cancer;
	int Malignant_skin_melanoma;
	int Leukemia;
	int Hodgkin_lymphoma;
	int Multiple_myeloma;
	int Other_neoplasms;
	int Breast_cancer;
	int Prostate_cancer;
	int Thyroid_cancer;
	int Stomach_cancer;
	int Bladder_cancer;
	int Uterine_cancer;
	int Ovarian_cancer;
	int Cervical_cancer;
	int Brain_and_central_nervous_system_cancer;
	int Non_Hodgkin_lymphoma;
	int Pancreatic_cancer;
	int Esophageal_cancer;
	int Testicular_cancer;
	int Nasopharynx_cancer;
	int Other_pharynx_cancer;
	int Colon_and_rectum_cancer;
	int Non_melanoma_skin_cancer;
	int Mesothelioma;
	*/
};


//Share of population with cancer file 
struct Population_share_file
{
	//Variables 

	string Country;
	int Year;

	double First_range;		//under five
	double Second_range;	//5-14
	double Third_range;		//15-49
	double Fourth_range;	//50-69
	double Fifth_range;		//70+
	double All_ages;
};

class File
{
public:
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
	
	//Struct vector
	vector <Annual_file> Data_annual;
	vector <Total_cancer_file> Data_total;
	vector <Population_share_file> Data_population;

	//Method declarations
	bool annual_file_read( string file_name );
};