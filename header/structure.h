/*!
 *	\file structure.h  
 *
 *  \brief  It contain declarations for structure to be defined
 *
 *      
 *	Compiler g++
 *
 *  \author amarjeet singh kapoor
 *      
 */

#ifndef _STRUCTURE_H
#define _STRUCTURE_H

#include"header.h"
#include"job.h"

//add an attribute to the joints struct:
struct Joint{

    int id;
    double x, y, z;
    //default value is free, and those 
    //who are fixed will be modified in the function.
    string support="FREE";
};

struct Member{
    vector<int> joint_id;
    int id;
    string material;
    string beta="0";
};

struct Material{
    string name, type, strength;
    double E,poisson, alpha, density, damp , G=9.8;
};

struct MemPro{
	vector<int> member_id;
	string type;
	string country;
	double YD;
	double ZD;
	double ZB;
};


struct CodeType{
	string code;
	string section;
	vector<int> member_id;
};

struct ConcreteDesign{
	string code;
	vector<CodeType> cty;
};

struct Load{
	int id;
	string type,title;
	bool reduce;
};	

class Structure{

	Job job;
	sql::Driver *driver;
	sql::Statement *stmt;
	sql::Connection *con;
	sql::PreparedStatement  *prep_stmt;
	string width, unit, group;
    vector<Joint> job_joints;
    vector<Member> job_members;
    vector<Material> job_material;
	string units;
	string widht;
	Joint jo;
	string x;
	vector<int> beam;
	vector<int> column;
	vector<MemPro> member_pr;
	ConcreteDesign con_des;
	string message;
	vector <Load> load;
	void getSupportsTypes(string temp1,string type);
	public:
		
		/*!
			\brief This is constructor that is used initialize all member
			variables.
    	*/
    	
    	
		Structure(fstream &);
		
		/*!
			\brief This member function is used to get units nad input widht
			 and is called in structure()
			\param temp string to be parsed
    	*/
		void getUnits(string);
		/*!
			\brief This member function is used to print all properties 
			of job and calls job::print() 
    	*/
		void print();	
		
		/*!
			\brief This member function is used to initialize material 
			property and is called in structure()
			\param temp string to be parsed
    	*/
		void getMaterial(string);
		
		/*!
			\brief This member function is used to initialize member property 
			and is called in structure() 
			\param temp string to be parsed
    	*/
		void getMemberPro(string);
		
		/*!
			\brief This member function is used to initialize design property 
			and is called in structure() 
			\param temp string to be parsed
    	*/
		void getDesign(string);
		
		/*!
			\brief This member function is used to initialize design column 
			and is called in structure() 
			\param temp string to be parsed
    	*/
		void getDesignColumn(string);
		
		/*!
			\brief This member function is used to initialize design beam 
			and is called in structure() 
			\param temp string to be parsed
    	*/
		void getDesignBeam(string);

		/*!
			\brief This member function is used to initialize joints 
			and is called in structure()
			\param temp string to be parsed
    	*/
		void getJoint(string str);
		
		/*!
			\brief This member function is used to initialize members 
			and is called in structure()
			\param temp string to be parsed
    	*/
		void getMember(string);
		
		
		void getSupports(string);
		void getBeta(string);
		void getLoad(string);
		
		/*!
			\brief This member function is used to insert data into DB.
    	*/
		void insert();
		
		/*!
			\brief This member function is used to insert members 
			\param z unique id of job generated by job::insert() 
			
    	*/
		void insertMember(int );
		
		/*!
			\brief This member function is used to insert material 
			property into Database.
      		\param z unique id of job generated by job::insert()
      		
    	*/
		void insertMaterial(int);
		
		/*!
			\brief This function is used to insert member property
				into Database.
      \param z unique id of job generated by job::insert()
      
     
    	*/
		void insertMemberPro(int);
		
		/*!
			\brief This destructure for structure that frees pointers.
    */
		~Structure();
		
};

#endif


