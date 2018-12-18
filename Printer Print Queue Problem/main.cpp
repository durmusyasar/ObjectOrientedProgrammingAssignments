#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
#include <time.h>
#include <unistd.h>
#define CAPACITY 10
int ekli = 0;
unsigned int k_b_gonderme_hizi, y_s_yazma_hizi;
int k_ekleme_zamani =0, ko_yy_zamani=0, k_ekleme_sayaci=0, ko_sayaci=0, pc_zamani=0, sayfa_zamani=0;
// k_ekleme_zamani : Kuyruga ekleme zamani
// pc_zamani : Sistem zamani
// ko_yy_zamani :Kuyruktan okuma ve yazicinin yazma zamani
// k_ekleme_sayaci : Kuyruða ekleme kontrolünü saðlayan sayac
// ko_sayaci : kuyruktan ne zaman veri çekileceðini hesaplayan sayac
// sayfa_zamani : Dosyanin ne kadar sürede yazdirildigi
using namespace std;
struct Person
{
    string name;
    string surname;
    string u_name;
    string email;
    int d_of_birth;
};
struct History
{
    int year;
    int day;
    int moon;
    int hour;
    int minute;
    int second;
};
struct Document
{
    string path;
    int size;
    int n_of_pages;
    Person p;
    History c_date;
};
void file_add(Document *q, Document *d)
{
  
  q[ekli].path = d->path;
  q[ekli].size = d->size;
  q[ekli].n_of_pages = d->n_of_pages;
  q[ekli].p.name = d->p.name;
  q[ekli].p.surname = d->p.surname;
  q[ekli].p.u_name = d->p.u_name;
  q[ekli].p.email = d->p.email;
  q[ekli].p.d_of_birth = d->p.d_of_birth;
  q[ekli].c_date.year = d->c_date.year;
  q[ekli].c_date.moon = d->c_date.moon;
  q[ekli].c_date.day = d->c_date.day;
  q[ekli].c_date.hour = d->c_date.hour;
  q[ekli].c_date.minute = d->c_date.minute;
  q[ekli].c_date.second = d->c_date.second;
  ekli++;
}
Document file_remove(Document *f1)
{
  
  int i;
  Document temp0;
  temp0.path = f1[0].path;
  temp0.size = f1[0].size;
  temp0.n_of_pages = f1[0].n_of_pages;
  temp0.p.name = f1[0].p.name;
  temp0.p.surname = f1[0].p.surname;
  temp0.p.u_name = f1[0].p.u_name;
  temp0.p.email = f1[0].p.email;
  temp0.p.d_of_birth = f1[0].p.d_of_birth;
  temp0.c_date.year = f1[0].c_date.year;
  temp0.c_date.moon = f1[0].c_date.moon;
  temp0.c_date.day = f1[0].c_date.day;
  temp0.c_date.hour = f1[0].c_date.hour;
  temp0.c_date.minute = f1[0].c_date.minute;
  temp0.c_date.second = f1[0].c_date.second;
  for(i=0;i<ekli-1;i++)
  {
    f1[i].path = f1[i+1].path;
    f1[i].size = f1[i+1].size;
    f1[i].n_of_pages = f1[i+1].n_of_pages;
    f1[i].p.name = f1[i+1].p.name;
    f1[i].p.surname = f1[i+1].p.surname;
    f1[i].p.u_name = f1[i+1].p.u_name;
    f1[i].p.email = f1[i+1].p.email;
    f1[i].p.d_of_birth = f1[i+1].p.d_of_birth;
    f1[i].c_date.year = f1[i+1].c_date.year;
    f1[i].c_date.moon = f1[i+1].c_date.moon;
    f1[i].c_date.day = f1[i+1].c_date.day;
    f1[i].c_date.hour = f1[i+1].c_date.hour;
    f1[i].c_date.minute = f1[i+1].c_date.minute;
    f1[i].c_date.second = f1[i+1].c_date.second;
  }
  ekli--;
  return temp0;
}
int main()
{
	cout<<"PC kac saniyede kuyrupa belge gondersin (sn): ";
	cin>>k_b_gonderme_hizi;
	cout<<"Yazicinin bir sayfayi yazma hizi nedir? (cn): ";
	cin>>y_s_yazma_hizi;
	Document queue[CAPACITY];
	string filein = "belge.txt";
	std::ifstream file;
	file.open(filein.c_str());
	int end = 0, file_end = 0;
	string path; //Kuyruktan okunan dosyanin path'i
	int page; //Kuyruktan okunan dosyanin page'i
	while(end!=-1)// Dosyanin sonuna gelindiginde ve kuyrukta dosya  kalmadiginda dongu biter.
	{
		Document temp;
		if(pc_zamani == k_ekleme_zamani)// kuyruga dosya eklenecek zamani kontrol eder.
		{
			if(!file.eof()) // eklenecek dosya olup olmadigini kontrol eder.
		    {  
		    	if(ekli < CAPACITY) // kuyrugun dolulugunu kontrol eder.
				{
			      file>>temp.path;
			      file>>temp.size;
			      file>>temp.n_of_pages;
			      file>>temp.p.name;
			      file>>temp.p.surname;
			      file>>temp.p.u_name;
			      file>>temp.p.email;
			      file>>temp.p.d_of_birth;
			      file>>temp.c_date.year;
			      file>>temp.c_date.moon;
			      file>>temp.c_date.day;
			      file>>temp.c_date.hour;
			      file>>temp.c_date.minute;
			      file>>temp.c_date.second; 
				  
				 	//Sleep(pc*1000);
				  file_add(queue, &temp);
				  cout<< pc_zamani << "sn - Pc kuyruga yazdi - " << temp.path <<endl;
				  if(pc_zamani == 0){
				  	cout<< pc_zamani <<"sn - Yazici kuyruktan okudu -" <<queue[0].path <<endl;
				  	path = queue[0].path; // Dosya kuyruktan okunduktan sonra kuyruktan cikacagi icin cikan dosyanin path'i tutulur.
				  	page = queue[0].n_of_pages; // Dosya kuyruktan okunduktan sonra kuyruktan cikacagi icin cikan dosyanin page'i tutulur.
				  	file_remove(queue);
				  }	
				}
				else{
					cout<<pc_zamani<<".sn Pc Kuyruga yazamadi...\n";
				}
				k_ekleme_zamani += k_b_gonderme_hizi; //Bir sonraki dosyanin ne zaman kuyruga eklenecegi hesaplanir.
			}
		}
		sayfa_zamani = page*y_s_yazma_hizi;
		ko_yy_zamani = sayfa_zamani + ko_sayaci;
		if(pc_zamani == ko_yy_zamani)
		{
			cout<< pc_zamani <<"sn - Yazici belgeyi yazdi - " << path << endl;
			path = queue[0].path;
			page = queue[0].n_of_pages;
			file_remove(queue);
			if(ekli != -1){
				cout << pc_zamani <<"sn - Yazici kuyruktan okudu -" <<path <<endl; 
				ko_sayaci = ko_yy_zamani;
			}
		}	
		if(file.eof() && ekli==-1){// Dosyanin sonuna gelinip gelinmedigini ve kuyrukta dosya kalip kalmadigini kontrol eder.
			end = -1;
		}
		pc_zamani += 1;
	}
	cout<<"-------------------"<<endl;
	file.close();
	cout<<"Tüm Belgeler Yazdýrýldý....."<<endl;
}
