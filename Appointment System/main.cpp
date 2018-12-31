// 314040 Durmus YASAR

# include <iostream>
# include <string>
# include <fstream>
# include <sstream>

# define MAKSIMUM 100

using namespace std;

// Classes tanımlamaları ve Fonksiyon prototipleri

// PersonalInformation.h
class PersonalInformation {
	
	private:

		string	name         	;
		string  surname      	;		
		string  mail         	;
		string 	phone_number 	;

	public:

		PersonalInformation 	()									;
		PersonalInformation 	(string, string, string, string)	;
		~PersonalInformation	()									;

		void 	setName        	(string name)						;
		void    setSurname     	(string surname)					;
		void    setMail        	(string mail)						;
		void    setPhoneNumber 	(string p_number)					;

		string  getName        	()									;
		string  getSurname     	()									;
		string  getMail        	()									;
		string 	getPhoneNumber 	()									;		

};

// Student.h
class Student : public PersonalInformation {
	
	private:

		fstream 	studentDocument			;

		int    		year_of_registration 	;
		int    		student_number       	;	
		int 		student_idtodelete 		;

		string		data 					;
		string 		department 	 			;

	public:

				Student 				()													;
		       	Student 				(string, string, string, string, int, string, int)	;
			   	~Student 				()													;

		void   	setStudentNumber 		(int s_number)										;
		void   	setDepartment 			(string department)									;
		void   	setYearOfRegistration 	(int y_registration)								;
		void 	showStudentInfo	 		()													;
		void   	writeStudentFile		()													;
		void	deleteStudent			()													;

		int    	getYearOfRegistration 	()													;
		int    	getStudentNumber 		()													;

		string 	getDepartment 			()													;

};

// Academician.h
class Academician : public PersonalInformation {

	private:

		fstream 	academicianDocument		;

		int    		registration_number	 	;
		int 		academ_idtodelete 		;

		string 		master_science_branch	;
		string 		title 				 	;
		string 		data 					;

	public:

				Academician 			()														;
			   	Academician 			(string, string, string, string, int, string, string) 	;
			   	~Academician 		  	()														;

		void   	setMasterScienceBranch 	(string m_branch)										;
		void   	setRegistrationNumber  	(int r_number)											;
		void   	setTitle 			  	(string title)											;
		void   	showAcademicianInfo		()														;
		void	writeAcademicianFile	()														;
		void	deleteAcademician		()														;

		int    	getRegistrationNumber  	()														;

		string 	getMasterScienceBranch 	()														;
		string 	getTitle 			  	()														;

};

// Appointment.h
class Appointment{
	
	private:

		Student     student 							;
		Academician academician 						;

		fstream 	appointmentDocument					;

		int 		hour 								;
		int 		minute 								;
		int 		day 								;
		int 		month								;
		int 		year 								;
		int 		appoint_idtodelete 					;

		string data 									;

	public:

		Appointment 		  		()						;
		~Appointment 		  		()						;

		void setDate 		  		(int , int , int )		;
		void getDate 		  		(int&, int&, int&)		;
		void setTime 		  		(int , int )			;
		void getTime          		(int&, int&)			;
		void incrementHours   		()						;
		void incrementMinutes 		()						;
		void incrementDay 	  		()						;
		void incrementMonth   		()						;
		void incrementYear    		()						;
		void makeAppointment  		()						;
		void showAppointmentInfo  	()						;
		void deleteAppointment		()						;
		void menu					()						;

};

// Menu.h
class Menu {

	private:

		PersonalInformation person 		;
		Student 			student 	;
		Academician 		academician ;
		Appointment 		appointment ;

	public:

		Menu()							;
		void appointmentSystemMenu	()	;
		~Menu()							;

};

// ------------------------------------------------------

// ********** PersonalInformation Function *********** //

// PersonalInformation.cpp

PersonalInformation::PersonalInformation() { }

PersonalInformation::PersonalInformation (
	string name 	,
	string surname 	,
	string mail 	,
	string p_number )
{ }

void PersonalInformation::setName (string name) {

	this -> name = name ;
}

string PersonalInformation::getName () {

	return name ;
}

void PersonalInformation::setSurname (string surname) {

	this -> surname = surname ;
}

string PersonalInformation::getSurname () {

	return surname ;
}

void PersonalInformation::setMail (string mail) {

	this -> mail = mail ;
}

string PersonalInformation::getMail () {

	return mail ;
}

void PersonalInformation::setPhoneNumber (string p_number) {

	this -> phone_number = p_number ;
}

string PersonalInformation::getPhoneNumber () {

	return phone_number ;
}

PersonalInformation::~PersonalInformation () { }

// ------------------------------------------------------

// **************** Student Function ***************** //

// Student.cpp

Student::Student() { }

Student::Student (

	string   	 name 			,
	string   	 surname 		,
	string  	 mail 			,
	string 		 p_number 		,
	int      	 s_number 		,
	string   	 department 	,
	int      	 y_registration
	):PersonalInformation(name, surname, mail, p_number) {

}

void Student::setStudentNumber (int s_number) {

	this -> student_number = s_number ;
}

int Student::getStudentNumber () {

	return student_number ;
}

void Student::setDepartment (string department) {

	this -> department = department ;
}

string Student::getDepartment () {

	return department ;
}

void Student::setYearOfRegistration (int y_registration) {

	this -> year_of_registration = y_registration ;
}

int Student::getYearOfRegistration () {

	return year_of_registration ;
}

void Student::showStudentInfo () {

	string studentData 									;
	
	fstream file 										;
	file.open("ogrenci.txt") 							;

	while(!file.eof()) {

		getline(file,studentData)						;
		cout << studentData << endl						;

	}
	
	file.close() 										;
}

void Student::writeStudentFile() {	

	int 	student_number 				,
			student_yearOfRegistration 	;

	string 	student_name 				,
			student_surname 			,
			student_department 			,
			student_mail 				,
			student_phoneNumber 		;

	ofstream file("ogrenci.txt", ios::app) 						;

	cout 	<< "Ogrenci Numarasi : " 			<<	endl		;
	cin 	>> student_number 									;
	
	cout 	<< "Ogrenci Adi : " 				<<	endl		;
	cin 	>> student_name 									;
	
	cout 	<< "Ogrenci Soyadi : " 				<<	endl		;
	cin 	>> student_surname									;

	cout 	<< "Ogrenci Bolumu : "  			<<	endl		;
	cin 	>> student_department								;

	cout 	<< "Ogrenci Kayit Yili : " 			<<	endl		;
	cin 	>> student_yearOfRegistration						;

	cout 	<< "Ogrenci Mail : " 				<<	endl		;
	cin 	>> student_mail										;

	cout 	<< "Ogrenci Telefon No : "  		<<	endl		;
	cin 	>> student_phoneNumber								;

	if(0 < student_number && 1955 <= student_yearOfRegistration) {

		file 	<< "\n" <<	student_number 				<< " "	;
		file 	<< 			student_name 				<< " "	;
		file 	<< 			student_surname				<< " "	;
		file 	<< 			student_department			<< " "	;
		file 	<< 			student_yearOfRegistration	<< " "	;
		file 	<< 			student_mail				<< " "	;
		file 	<< 			student_phoneNumber			<< " "	;

		file.close()											;
	}

	else {

		cout << "Yanlis Bilgi Girdiniz...."						;
		exit(1)													;

	}
	file.close() 										;

}

void Student::deleteStudent() {
	
    Student student_file															;
    showStudentInfo()																;
    int num_student 																;
    
    studentDocument.open("ogrenci.txt")												;
    studentDocument.clear()															;
    student_file.studentDocument.open("newogrenci.txt", ios::out | ios::trunc)		;
    cout << "Enter the Student Number to delete \n"									;
    cin >> student_idtodelete														;

    while (studentDocument.good()) {

        getline(studentDocument, data)												;

        if (studentDocument) {

            istringstream(data) >> num_student 										;

            if (num_student != student_idtodelete) {

                student_file.studentDocument << data << endl						;

            }

        }

    }

    studentDocument.close()															;
    student_file.studentDocument.close()											;

    remove("ogrenci.txt")															;
    rename("newogrenci.txt", "ogrenci.txt")											;

}

Student::~Student () { }

// ------------------------------------------------------

// ************** Academician Function *************** //

// Academician.cpp

Academician::Academician() { }

Academician::Academician (

	string 	 	name 			,
	string 	 	surname 		,
	string 	 	mail 			,
	string 		p_number 		,
	int  	 	r_number 		,
	string 	 	m_branch 		,
	string 		title
	):PersonalInformation(name, surname, mail, p_number) {

}

void Academician::setRegistrationNumber (int r_number) {

	this -> registration_number = r_number ;
}

int Academician::getRegistrationNumber () {

	return registration_number ;
}

void Academician::setMasterScienceBranch (string m_branch) {

	this -> master_science_branch = m_branch ;
}

string Academician::getMasterScienceBranch () {

	return master_science_branch ;
}

void Academician::setTitle (string title) {

	this -> title = title ;
}

string Academician::getTitle () {

	return title ;
}	

void Academician::showAcademicianInfo() {

	string 	academicianData 							;
	
	fstream file 										;
	file.open("akademisyen.txt") 						;

	while(!file.eof()) {

		getline(file,academicianData)					;
		cout << academicianData << endl					;

	}
	
	file.close() 										;
	
}

void Academician::writeAcademicianFile() {

	int 	academician_registrationNumber				;			

	string 	academician_name 							,
			academician_surname 						,
			academician_department 						,
			academician_mail 							,
			academician_masterScienceBranch 			,
			academician_title 							,
			academician_phoneNumber 					;

	string 		fileout = "akademisyen.txt" 			;

	ofstream 	file 									;
	file.open(fileout.c_str()) 							;

	cout 	<< "Akademisyen Sicil Numarasi : " 		<<	endl 	;
	cin 	>> academician_registrationNumber					;
	
	cout 	<< "Akademisyen Adi : " 				<<	endl	;
	cin 	>> academician_name 								;
	
	cout 	<< "Akademisyen Soyadi : " 				<<	endl	;
	cin 	>> academician_surname								;

	cout 	<< "Akademisyen Ana Bilim Dali : "  	<<	endl	;
	cin 	>> academician_masterScienceBranch					;

	cout 	<< "Akademisyen Mail : " 				<<	endl	;
	cin 	>> academician_mail									;

	cout 	<< "Akademisyen Telefon No : " 			<<	endl	;
	cin 	>> academician_phoneNumber							;

	cout 	<< "Akademisyen Unvan : "  				<<	endl	;
	cin 	>> academician_title								;

	if (0 < academician_registrationNumber) {
		
		file 	<< "\n" <<  academician_registrationNumber	<< " "	;
		file 	<< 			academician_name 				<< " "	;
		file 	<< 			academician_surname				<< " "	;
		file 	<< 			academician_masterScienceBranch	<< " "	;
		file 	<< 			academician_mail				<< " "	;
		file 	<< 			academician_phoneNumber			<< " "	;
		file 	<< 			academician_title				<< " "	;

		file.close()												;

	}

	else {

		cout << "Yanlis Bilgi Girdiniz...."							;
		exit(1)														;
		
	}

}

void Academician::deleteAcademician() {
	
    Academician academ_file																;
    showAcademicianInfo()																;
    int num_academ 																		;
    
    academicianDocument.open("akademisyen.txt");
    academicianDocument.clear();
    academ_file.academicianDocument.open("newakademisyen.txt", ios::out | ios::trunc)	;

    cout << "Enter the Academician Number to delete \n"									;
    cin >> academ_idtodelete															;

    while (academicianDocument.good()) {

        getline(academicianDocument, data)												;

        if (academicianDocument) {

            istringstream(data) >> num_academ 											;

            if (num_academ != academ_idtodelete) {

                academ_file.academicianDocument << data << endl							;
            }

        }

    }

    academicianDocument.close()															;
    academ_file.academicianDocument.close()												;

    remove("akademisyen.txt")															;
    rename("newakademisyen.txt", "akademisyen.txt")										;
}

Academician::~Academician () { }

// ------------------------------------------------------

// ************** Appointment Function ************** //

// Appointment.cpp

Appointment::Appointment () { }

void Appointment::setDate (int month, int day, int year) {

	if (month >= 1 && month <= 12)
        this -> month = month 	;

    else
        month = 1 				;
    
    if (day <= 1 && day >= 31)
        day = day 				;
    
    else
        day = 1 				;
    
    if (year >= 1900 && year <= 2030)
        year = year 			;
   
    else
        year = 1900 			;

}

void Appointment::getDate (int& month, int& day, int& year) {

	this -> month = month 		;
	this -> day = day 			;
	this -> year = year 		; 

}

void Appointment::setTime (int hour, int minute) {

	if(0 <= hour && hour < 24)
        this -> hour = hour 	;
   
    else
        hour = 0 				;
   
    if(0 <= minute && minute < 60)
        this -> minute = minute ;
    
    else
         minute = 0 			;

}

void Appointment::getTime (int& hour, int& minute) {

	hour = hour 				;
    minute = minute 			;

}

void Appointment::incrementHours () {

      hour++ 					;

      if(hour > 23)
        hour = 0 				;

}

void Appointment::incrementMinutes () {

      minute++ 					;

      if(minute > 59) {
        minute = 0;
        incrementHours()		;

      }

}

void Appointment::incrementDay () {

      day++						;

      if(day > 31)
        day = 1 				;

}

void Appointment::incrementMonth () {

      month++ 					;

      if(month > 12) {
        month = 1 				;
        incrementYear() 		;

      }

}

void Appointment::incrementYear () {

    year++ 						;

}

void Appointment::makeAppointment() {

	int appointmentStudentNumber 		,
		appointmentAcademicianNumber 	,
		sTimeHour, sTimeMinute			,
		fTimeHour, fTimeMinute			,
		appointmentDay					,
		appointmentMonth				,
		appointmentYear					;

	string 		fileout = "randevu.txt"	;

	ofstream 	file 					;
	file.open(fileout.c_str()) 			;

	cout 	<< "Ogrenci Okul Numarasi :"				<< endl	;
	cin 	>> appointmentStudentNumber							;
	
	cout 	<< "Akademisyen Sicil Numarasi : " 			<< endl ;
	cin 	>> appointmentAcademicianNumber						;
	
	cout 	<< "Randevu Gunu (Format : Gun Ay Yil) : "	<< endl	;
	cin 	>> appointmentDay									;
	cin 	>> appointmentMonth									;
	cin 	>> appointmentYear									;

	cout 	<< "Baslangic Saati(Format: Saat Dakika) :"	<< endl	;
	cin 	>> sTimeHour										;
	cin 	>> sTimeMinute										;

	cout 	<< "Bitis Saati(Format: Saat Dakika) :"		<< endl	;
	cin 	>> fTimeHour										;
	cin 	>> fTimeMinute										;
	
	if (0 < appointmentStudentNumber, appointmentAcademicianNumber &&
		2018 <= appointmentYear) {

		if(appointmentMonth==1 || appointmentMonth==3 || appointmentMonth==5 ||
		   appointmentMonth==7 || appointmentMonth==8 || appointmentMonth==10 ||
		   appointmentMonth==12) {

			if((0< appointmentDay  && appointmentDay < 32) && 
				(0 <= sTimeHour, fTimeHour < 24 &&
				 0 <= sTimeMinute,fTimeMinute <= 59)) {

				file 	<< "\n" <<  appointmentStudentNumber	<< " "		;
				file 	<< 			appointmentAcademicianNumber<< " "		;
				file 	<< 			appointmentDay				<< "/"		;
				file 	<< 			appointmentMonth			<< "/"		;
				file 	<< 			appointmentYear				<< " "		;
				file 	<< 			sTimeHour					<< ":"		;
				file 	<< 			sTimeMinute					<< " "		;
				file 	<< 			fTimeHour					<< ":"		;
				file 	<< 			fTimeMinute					<< " "		;
		
				file.close()												;

			}

			else {

				cout << "Yanlis Bilgi Girdiniz...."							;
				exit(1)														;

			}

		}

		else if(appointmentMonth==4 || appointmentMonth==6 ||
			appointmentMonth==9 || appointmentMonth==11) {

			if((0< appointmentDay  && appointmentDay < 31) &&
				(0 <=sTimeHour, fTimeHour < 24 &&
				 0 <= sTimeMinute,fTimeMinute <= 59)) {

				file 	<< "\n" <<  appointmentStudentNumber	<< " "		;
				file 	<< 			appointmentAcademicianNumber<< " "		;
				file 	<< 			appointmentDay				<< "/"		;
				file 	<< 			appointmentMonth			<< "/"		;
				file 	<< 			appointmentYear				<< " "		;
				file 	<< 			sTimeHour					<< ":"		;
				file 	<< 			sTimeMinute					<< " "		;
				file 	<< 			fTimeHour					<< ":"		;
				file 	<< 			fTimeMinute					<< " "		;
		
				file.close()												;

			}

			else {

				cout << "Yanlis Bilgi Girdiniz...."							;
				exit(1)														;

			}

		}

		else if(appointmentMonth==2) {

			if(appointmentYear%4 != 0) {

				if((0< appointmentDay  && appointmentDay < 29) &&
					(0 <=sTimeHour, fTimeHour < 24 &&
					 0 <= sTimeMinute,fTimeMinute <= 59)) {

					file 	<< "\n" <<  appointmentStudentNumber	<< " "		;
					file 	<< 			appointmentAcademicianNumber<< " "		;
					file 	<< 			appointmentDay				<< "/"		;
					file 	<< 			appointmentMonth			<< "/"		;
					file 	<< 			appointmentYear				<< " "		;
					file 	<< 			sTimeHour					<< ":"		;
					file 	<< 			sTimeMinute					<< " "		;
					file 	<< 			fTimeHour					<< ":"		;
					file 	<< 			fTimeMinute					<< " "		;
			
					file.close()												;

				}

				else {

					cout << "Yanlis Bilgi Girdiniz...."							;
					exit(1)														;

				}

			}

			else {

				if((0< appointmentDay  && appointmentDay < 30) &&
					(0 <=sTimeHour, fTimeHour < 24 &&
					 0 <= sTimeMinute,fTimeMinute <= 59)) {

					file 	<< "\n" <<  appointmentStudentNumber	<< " "		;
					file 	<< 			appointmentAcademicianNumber<< " "		;
					file 	<< 			appointmentDay				<< "/"		;
					file 	<< 			appointmentMonth			<< "/"		;
					file 	<< 			appointmentYear				<< " "		;
					file 	<< 			sTimeHour					<< ":"		;
					file 	<< 			sTimeMinute					<< " "		;
					file 	<< 			fTimeHour					<< ":"		;
					file 	<< 			fTimeMinute					<< " "		;
			
					file.close()												;

				}

				else {

				cout << "Yanlis Bilgi Girdiniz...."								;
				exit(1)															;

				}

			}

		}

		else {

			cout << "Yanlis Bilgi Girdiniz...."									;
			exit(1)																;

		}	

	} 

	else {

		cout << "Yanlis Bilgi Girdiniz...."										;
		exit(1)																	;
		
	}
}

void Appointment::showAppointmentInfo() {

	string appointmentData 								;
	
	fstream file 										;
	file.open("randevu.txt") 							;

	while(!file.eof()) {

		getline(file, appointmentData)					;
		cout << appointmentData << endl					;

	}

	file.close() 										;

}

void Appointment::deleteAppointment() {
	
    Appointment appoint_file														;
    showAppointmentInfo()															;
    int num_appoint 																;
    
    appointmentDocument.open("randevu.txt");
    appointmentDocument.clear();
    appoint_file.appointmentDocument.open("newrandevu.txt", ios::out | ios::trunc)	;

    cout << "Enter the Student Number to delete \n"									;
    cin >> appoint_idtodelete														;

    while (appointmentDocument.good()) {

        getline(appointmentDocument, data)											;
        if (appointmentDocument) {

            istringstream(data) >> num_appoint 										;

            if (num_appoint != appoint_idtodelete) {

                appoint_file.appointmentDocument << data << endl					;

            }

        }

    }

    appointmentDocument.close()														;
    appoint_file.appointmentDocument.close()										;

    remove("randevu.txt")															;
    rename("newrandevu.txt", "randevu.txt")											;

}

Appointment::~Appointment () { }

// ------------------------------------------------------

// ****************** Menu Function ****************** //

// Menu.cpp

Menu::Menu() { }

void Menu::appointmentSystemMenu() {

	int 	choice 												;
	bool 	loop = true 										;

	while (loop) {

		cout << "-------------------------------------------\n" ;
		cout << "Lutfen yapmak istediginiz islemi seciniz...\n"	;
		cout << "-------------------------------------------\n" ;
		
		cout << "Cikis yapmak icin :________________________0\n";
		
		cout << "-------------------------------------------\n" ;
		
		cout <<	"Ogrenci eklemek icin :_____________________1\n";
		cout <<	"Ogrencileri gostermek icin :_______________2\n";
		cout <<	"Ogrenci silmek icin :______________________3\n";
		
		cout << "-------------------------------------------\n" ;
				
		cout << "Akademisyen eklemek icin :_________________4\n";
		cout << "Akademisyenleri gostermek icin :___________5\n";
		cout << "Akademisyen silmek icin :__________________6\n";
		
		cout << "-------------------------------------------\n" ;
		
		cout << "Randevu almak icin :_______________________7\n";
		cout << "Randevulari gostermek icin :_______________8\n";
		cout << "Randevu silmek icin :______________________9\n";
		
		cout << "-------------------------------------------\n" ;

		cout << "Secenek : "									;
		cin >> choice 											;

		cout << "-------------------------------------------\n" ;

		switch(choice) {

			case 0:
				cout << "Cikis Yapiliyor.......................";
				loop = false									;
				break											;
			
			case 1:
				student.writeStudentFile()						;
				break											;
			
			case 2:
				student.showStudentInfo()						;
				break											;
			
			case 3:
				student.deleteStudent()							;
				break											;

			case 4:
				academician.writeAcademicianFile()				;
				break											;
			
			case 5:
				academician.showAcademicianInfo()				;
				break											;

			case 6:
				academician.deleteAcademician()					;
				break											;
			
			case 7:
				appointment.makeAppointment()					;
				break											;
			
			case 8:
				appointment.showAppointmentInfo()				;
				break											;

			case 9:
				appointment.deleteAppointment()					;
				break											;

			default:
				cout << "Yanlis secim yaptiniz...\n"			;
		}

	}

}

Menu::~Menu() { }

// ------------------------------------------------------

// ****************** Main Function ****************** //

// main.cpp

int main() {

	Menu menu 						;
	menu.appointmentSystemMenu()	;
	
	return 0						;

}
