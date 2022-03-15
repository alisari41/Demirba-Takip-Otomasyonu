#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include <iomanip>//duzenleme komut sinifi
#include <stdlib.h>//char degiskenini int' e donusturmek icin bu kutuphaneyi caagirdim
#include <cmath>
using namespace std;
static int sayac,sayac2,sayac3;
//static int idbulma;
class demirbas   //demirbasin temel bilgilerini saklar
{
	protected:
		int urun_kodu;
	private :
		string urunadi;		
		string saticifirma;
		string alimyapan;
		string alimyaptiran;
		string alimyaptirandepartman;
		string durum;
		int alimtarihigun;
		int alimtarihiay;
		int alimtarihiyil;
		int garantigun;
		int garantiay;
		int garantiyil;
		int garantisuresi;
		int adet;
		int birimfiyati;
	public:
	
		demirbas()//kurucu yapici fonksiyon
		{
			cout.setf(ios::right);
			cout<<setw(75)<<"Demirbas Takip Programi....:"<<endl;
		//	cout<<"Ali SARI Demirbas ";
// normalde burda dosya actim fakat dosya surekli acik kaldigi icin yapici fonksiyondan cikardin
// sil ve guncelleme icin
		}
		
		~demirbas()
		{
         	 cout<<"....Dilerim ";
	 	}	
		void demirbasekle();
		void demirbaslistele();
		void urun_arama();
		void seturun(string urun)
		{
			urunadi=urun;
		}
		string geturun()
		{
			return urunadi;
		}
		virtual void seturun_kodu(int urunkod)
		{
			urun_kodu=urunkod;
		}
		virtual	int geturun_kodu()
		{
			return urun_kodu;
		}
		void setfirma(string firma)
		{
			saticifirma=firma;
		}
		string getfirma()
		{
			return saticifirma;
		}
		
		void setalimyapan(string alimyapankisi)
		{
			alimyapan=alimyapankisi;
		}
		string getalimyapan()
		{
			return alimyapan;
		}
		
		void setalimyaptiran(string alimyaptirankisi)
		{
			alimyaptiran=alimyaptirankisi;
		}
		string getalimyaptiran()
		{
			return alimyaptiran;
		}
		
		
		void setalimyaptirandep(string alimyaptirandep)
		{
			alimyaptirandepartman=alimyaptirandep;
		}
		string getalimyaptirandep()
		{
			return alimyaptirandepartman;
		}
       
	   void setdurum(string durumyaz)
	   {
	   	durum=durumyaz;
	   }
	   string getdurumyaz()
	   {
	   	return durum;
	   }
	   
	   void setalimtarihigunu(int alimgunu)
	   {
	   	alimtarihigun=alimgunu;
	   }
	   int getalimtarihigunu()
	   {
	   	return alimtarihigun;
	   }
	   void setalimtarihiay(int alimayi)
	   {
	   	alimtarihiay=alimayi;
	   }
	   int getalimtarihiay()//private degiskenlere disardan eristim
	   {
	   	return alimtarihiay;
	   }
	   void setalimtarihiyil(int alimyili)
	   {
	   	alimtarihiyil=alimyili;
	   }
	   int getalimtarihiyil()
	   {
	   	return alimtarihiyil;
	   }
		void setgarantigun(int g_gun)
		{
			garantigun=g_gun;
		}
		int getgarantigun()
		{
			return garantigun;
		}
		void setgarantiay(int g_ay)
		{
			garantiay=g_ay;
		}
		int getgarantiay()
		{
			return garantiay;
		}
		void setgarantiyil(int g_yil)
		{
			garantiyil=g_yil;
		}
		int getgarantiyil()
		{
			return garantiyil;
		}
		void setgarantisuresi(int g_sure)
		{
			garantisuresi=g_sure;
		}
		int getgarantisuresi()
		{
			return garantisuresi;
		}
		void setadet(int adeti)
		{
			adet=adeti;
		}
		int getadet()
		{
			return adet;
		}
		void setbirimfiyati(int fiyat)
		{
			birimfiyati=fiyat;
		}
		int getbirimfiyati()
		{
			return birimfiyati;
		}
		
};

//void demirbas::demirbaslarigir() bu foksiyonu cikardim get set kullandim 
//void demirbas::demirbaslariyaz() fonksiyonunu cikardim asiri yukleme yaptim
void demirbas::demirbasekle()
{
								
		fstream dosya;
		dosya.open("proje.txt",ios::out|ios::in|ios::app);
		//ios::app    Dosya varsa içindeki deðerler korunur ve yazýlanlar dosyanýn sonuna eklenir. Eðer dosya yoksa açýlýr.
		//ios::in     Giriþ modudur. Bilgiler dosyadan okunur. Eðer dosya yoksa oluþturulamaz ve hata verir.
		//ios::out    Çýkýþ modudur. Bilgiler dosyaya yazýlýr. Eðer dosya yoksa oluþturulur, varsa içindekiler silinir ve yeniden açýlýr.Soldan eklme yapar uzerine yani
		dosya.setf(ios::left);
		dosya<<setw(15)<<sayac		
		<<setw(15)<<geturun()//urunler kucuk yaziliyor aramalari kucuk yaz
		<<setw(15)<<geturun_kodu()
		<<setw(15)<<getfirma()
		<<setw(15)<<getalimyapan()
		<<setw(15)<<getalimyaptiran()
		<<setw(20)<<getalimyaptirandep()
		<<setw(15)<<getdurumyaz()//set ile private degeri aldik get ile dosyaya yazdirdim
		<<setw(2)<<this->alimtarihigun<<"."//int deger oldugu ýcýn get ile cagýrmada hata veriyor
		<<setw(2)<<this->alimtarihiay<<"."  											 // 1=nokta
		<<setw(9)<<this->alimtarihiyil//9 yazmamim sebebi toplam karakter 15 olsun diye 2+1+2+1+9  5 tanede bosluk ekler ay gun tek haneli ise 7 bosluk ekler
		<<setw(2)<<this->garantigun<<"."//int deger oldugu ýcýn get ile cagýrmada hata veriyor
		<<setw(2)<<this->garantiay<<"."                                             // 1=nokta
		<<setw(9)<<this->garantiyil//9 yazmamim sebebi toplam karakter 15 olsun diye 2+1+2+1+9  5 tanede bosluk ekler ay gun tek haneli ise 7 bosluk ekler
		<<setw(12)<<this->garantisuresi//this bu siniftaki degisen g.suresini getir
		<<setw(7)<<this->adet
		<<setw(8)<<this->birimfiyati<<"TL"
		<<endl;
		dosya.close();
		
}

void demirbas::demirbaslistele()
{
			fstream dosya2;
			dosya2.open("proje.txt",ios::out|ios::in|ios::app);
		//ios::app    Dosya varsa içindeki deðerler korunur ve yazýlanlar dosyanýn sonuna eklenir. Eðer dosya yoksa açýlýr.
		//ios::in     Giriþ modudur. Bilgiler dosyadan okunur. Eðer dosya yoksa oluþturulamaz ve hata verir.
		//ios::out    Çýkýþ modudur. Bilgiler dosyaya yazýlýr. Eðer dosya yoksa oluþturulur, varsa içindekiler silinir ve yeniden açýlýr.Soldan eklme yapar uzerine yani
		string oku;
			while(!dosya2.eof())
			{
				getline(dosya2,oku);
				cout<<oku<<endl;
			}
			dosya2.close();
}

void demirbas::urun_arama()
{
	cout<<"1-ID numarasi ile arama "<<endl;
	cout<<"2-Urun adi ile arama "<<endl;
	int secim;
	cout<<endl<<endl<<"Arama yapmak icin seciminizi yaziniz... :";
	cin>>secim;
	cin.ignore();
	system("cls");
	fstream dosya3;
			dosya3.open("proje.txt",ios::out|ios::in|ios::app);
		//ios::app    Dosya varsa içindeki deðerler korunur ve yazýlanlar dosyanýn sonuna eklenir. Eðer dosya yoksa açýlýr.
		//ios::in     Giriþ modudur. Bilgiler dosyadan okunur. Eðer dosya yoksa oluþturulamaz ve hata verir.
		//ios::out    Çýkýþ modudur. Bilgiler dosyaya yazýlýr. Eðer dosya yoksa oluþturulur, varsa içindekiler silinir ve yeniden açýlýr.Soldan eklme yapar uzerine yani
	switch(secim)
	{
		case 1:
			{
				int sayac=0;
				char kelime[15];
				cout<<"Aramak istediginiz urunun seri numarasini giriniz    : ";
				gets(kelime);
				string oku;
				int uzunluk=strlen(kelime);//kelimenin uzunlugunu aldim
			//	strupr(kelime);//kelimeyi buyulttum
				string kelime2;
				kelime2=kelime;//campare icin string'e atadim
				for(int i=0;i<15-uzunluk;i++)//uzunlugu karakter girilmediyse cikardim bosluk eklemek icin dosyanin icinde 15 karakatere kadar urun var cunku
				{
					kelime2=kelime2+" ";
				}
						
				while(!dosya3.eof())
				{
					int a;
					getline(dosya3,oku);//dosyadaki bilgileri oku ya at satir satir bitene kadar kontrol eder while ici
					a=oku.compare(0,15,kelime2);//girilen kelime dasyadaki 0,15 index arasina esitse 0 degeri verir
					if(a==0)//girilen kelime esitse yazdirmak icin 
					{
						cout<<oku<<endl;//girilen urun varsa yazdir
						sayac++;//eslesme yoksa ekrana  yazdirmak icin kullandim
					}
				}
				if(sayac==0)
				{
					cout.setf(ios::right);
					cout<<endl<<setw(25)<<"Urun Bulunamadi...";
				}
					
				dosya3.close();	
				break;
			}
			case 2:
			{
				int sayac=0;
				char kelime[15];
				cout<<"Aramak istediginiz urunun adini giriniz    : ";
				gets(kelime);
				string oku;
				int uzunluk=strlen(kelime);//kelimenin uzunlugunu aldim
				string kelime2;
				kelime2=kelime;//campare icin string'e atadim
				for(int i=0;i<15-uzunluk;i++)//uzunlugu karakter girilmediyse cikardim bosluk eklemek icin dosyanin icinde 15 karakatere kadar urun var cunku
				{
					kelime2=kelime2+" ";//asagi unutma
				}
					
							
				while(!dosya3.eof())
				{
					int a;
					getline(dosya3,oku);//dosyadaki bilgileri oku ya at satir satir bitene kadar kontrol eder while ici
					char arama[15];
					int s=0;//urun aramaya gecmek icin
					for(int i=0;i<30;i++)
					{
						if(i>14)
						{
							arama[s]=oku[i];//string ifadeyi chara atadim sifirdan baslatip compare da kontrol etmek icin
							s++;
						}
									
					}
					string arama2;
					arama2=arama;//char ifadeyi string yaptim
					a=arama2.compare(0,15,kelime2);//girilen kelime dasyadaki 0,15 index arasina esitse 0 degeri verir
					if(a==0)//girilen kelime esitse yazdirmak icin 
					{
					cout<<oku<<endl;//girilen urun varsa yazdir
					sayac++;//eslesme yoksa ekrana  yazdirmak icin kullandim
					}
				}
				if(sayac==0)
				{
					cout.setf(ios::right);
					cout<<endl<<setw(25)<<"Urun Bulunamadi...";
				}
								
				dosya3.close();
				break;
			}
				default : cout<<"Yanlis secim yaptiniz!!!"<<"\a";
				dosya3.close();
				break;	
		}
}


class Kurum//butun demirbaslari icinde bulunduracak gerektigi zaman kayit yapacak gerektigi zaman kayitlardan demirbas bulabilecek
{//gerektigi zaman demirbas silecek , guncelleyecek ve listeleyecek
	public:
		demirbas d;//demirbasda d degiskeni tanimladim
		Kurum()
		{
			cout.setf(ios::right);
			cout<<setw(75)<<"****************************"<<endl;
			// normalde burda dosya actim fakat dosya surekli acik kaldigi icin yapici fonksiyondan cikardin
			// sil ve guncelleme icin
		}	   
		~Kurum()
		{
			//yikici fonksiyon
			cout<<"....Iyi gunler ";
		}
		void demirbas_silme()
		{
				cout<<"Silmek istediginiz urunun ID Numarasini giriniz    : ";			
					    int sayac7=0;		
						char kelime[15];
						gets(kelime);
						string oku;
						int uzunluk=strlen(kelime);//kelimenin uzunlugunu aldim
					//	strupr(kelime);//kelimeyi buyulttum
						string kelime2;
						kelime2=kelime;//campare icin char'i string'e atadim
						for(int i=0;i<15-uzunluk;i++)//uzunlugu karakter girilmediyse cikardim bosluk eklemek icin dosyanin icinde 15 karakatere kadar urun var cunku
						{
							kelime2=kelime2+" ";
						}
						fstream dosya4;
						dosya4.open("proje.txt",ios::out|ios::in|ios::app);
			//ios::app    Dosya varsa içindeki deðerler korunur ve yazýlanlar dosyanýn sonuna eklenir. Eðer dosya yoksa açýlýr.
		//ios::in     Giriþ modudur. Bilgiler dosyadan okunur. Eðer dosya yoksa oluþturulamaz ve hata verir.
		//ios::out    Çýkýþ modudur. Bilgiler dosyaya yazýlýr. Eðer dosya yoksa oluþturulur, varsa içindekiler silinir ve yeniden açýlýr.Soldan eklme yapar uzerine yani
						while(!dosya4.eof())
						{
							int a;
							getline(dosya4,oku);//dosyadaki bilgileri oku ya at satir satir bitene kadar kontrol eder while ici
							a=oku.compare(0,15,kelime2);//girilen kelime dasyadaki 0,15 index arasina esitse 0 degeri verir
							if(a==0)sayac7++;//girilen kelime esitse islem yapma
							else
							{
								fstream dosya5("proje2.txt",ios::out|ios::in|ios::app);//yeni proje olusturdum fakat silemedim dosyayi
//ios::app    Dosya varsa içindeki deðerler korunur ve yazýlanlar dosyanýn sonuna eklenir. Eðer dosya yoksa açýlýr.
//ios::in     Giriþ modudur. Bilgiler dosyadan okunur. Eðer dosya yoksa oluþturulamaz ve hata verir.
//ios::out    Çýkýþ modudur. Bilgiler dosyaya yazýlýr. Eðer dosya yoksa oluþturulur, varsa içindekiler silinir ve yeniden açýlýr.Soldan eklme yapar uzerine yani
								dosya5<<oku<<endl;
								dosya5.close();
							}
						}
						
						if(sayac7==0)
						{
							cout.setf(ios::right);
							cout<<endl<<setw(45)<<".....Urun Bulunamadi....."<<endl;
						}
						else
						{
							cout.setf(ios::right);
							cout<<setw(45)<<".....Silme islemi gerceklestirildi....."<<endl;
						}
						dosya4.close();
		
						remove("proje.txt");
						rename("proje2.txt","proje.txt");
						
		}
		void guncelleme()
		{
			cout<<"Guncellemek istediginiz urunun seri numarasini adini giriniz    : ";
			
			
			fstream dosya6;
			dosya6.open("proje.txt",ios::out|ios::in|ios::app);
		//ios::app    Dosya varsa içindeki deðerler korunur ve yazýlanlar dosyanýn sonuna eklenir. Eðer dosya yoksa açýlýr.
		//ios::in     Giriþ modudur. Bilgiler dosyadan okunur. Eðer dosya yoksa oluþturulamaz ve hata verir.
		//ios::out    Çýkýþ modudur. Bilgiler dosyaya yazýlýr. Eðer dosya yoksa oluþturulur, varsa içindekiler silinir ve yeniden açýlýr.Soldan eklme yapar uzerine yani
				int sayac2=0;		
				char kelime[15];
				gets(kelime);
				int sayi;
				sayi=atoi(kelime);//chari int e donusturur
				string oku;
				int uzunluk=strlen(kelime);//kelimenin uzunlugunu aldim
				string kelime2;
				kelime2=kelime;//campare icin char'i string'e atadim
				for(int i=0;i<15-uzunluk;i++)//uzunlugu karakter girilmediyse cikardim bosluk eklemek icin dosyanin icinde 15 karakatere kadar urun var cunku
				{
					kelime2=kelime2+" ";
				}
						
				while(!dosya6.eof())
				{
				int a;
			 	getline(dosya6,oku);//dosyadaki bilgileri oku ya at satir satir bitene kadar kontrol eder while ici
				a=oku.compare(0,15,kelime2);//girilen kelime dasyadaki 0,15 index arasina esitse 0 degeri verir
				if(a==0)//girilen kelime esitse yazdirmak icin 
				{	sayac2++;				
				fstream dosya7("proje2.txt",ios::out|ios::in|ios::app);

				   				
					string urun;
					cout.setf(ios::right);//consolda saga dayali yaz
					cout<<setw(75)<<"Lutfen Urun Adini giriniz :";//75 karakterli olsun
					cin>>urun;
					
												d.seturun(urun);
					
					
					int urunkod;
					cout.setf(ios::right);
					cout<<setw(75)<<"Urun kodunu giriniz :";
					cin>>urunkod;
												d.seturun_kodu(urunkod);
					
					
					string firma;
					cout.setf(ios::right);//consolda saga dayali yaz
					cout<<setw(75)<<"Lutfen Satici Firmanin Adini giriniz :";//50 karakterli olsun
					cin>>firma;
												d.setfirma(firma);
						
					string alimyapankisi;							
					cout.setf(ios::right);
					cout<<setw(75)<<"Luften alim yapan kisinin Adini yaziniz :";
					cin>>alimyapankisi;			
												d.setalimyapan(alimyapankisi);				
							
							
					string alimyaptirankisi;							
					cout.setf(ios::right);
					cout<<setw(75)<<"Lutfen alim yaptiran kisinin Adini giriniz :";
					cin>>alimyaptirankisi;						
												d.setalimyaptiran(alimyaptirankisi);
												
					string alimyaptirandep;							
					cout.setf(ios::right);
					cout<<setw(75)<<"Lutfen alim yaptiran Departmanin Adini yaziniz :";
					cin>>alimyaptirandep;							
												
												d.setalimyaptirandep(alimyaptirandep);
					
					string durumyaz;							
					cout.setf(ios::right);
					cout<<setw(75)<<"Alinan Demirbas Durumu Yeni mi Eksi mi ? :";
					cin>>durumyaz;							
												
												d.setdurum(durumyaz);
					
					
						//alim tarihi 
				    int alimgunu;    
					cout.setf(ios::right);
					cout<<setw(75)<<"Lutfen Alinan Demirbasin Gununu Giriniz :";
					do
					{
						cin>>alimgunu;
						if(alimgunu>31)
						{
							cout.setf(ios::right);
							cout<<setw(75)<<"Lutfen gecerli gun giriniz :"<<"\a";
						}
					}while(alimgunu>31);//gun 31 den cok ise bir daha ister gunu	
											
											    d.setalimtarihigunu(alimgunu);
					int alimayi;
					cout.setf(ios::right);
					cout<<setw(75)<<"Luften Alinan Demirbasin Ayi Giriniz :";
					do
					{
						cin>>alimayi;
						if(alimayi>12)
						{
							cout.setf(ios::right);
							cout<<setw(75)<<"Lutfen gecerli ay giriniz :"<<"\a";
						}
					}while(alimayi>12);//ay 12 den cok ise bir daha ister ayi						    
										
												d.setalimtarihiay(alimayi);
					int alimyili;
					cout.setf(ios::right);
					cout<<setw(75)<<"Luften Alinan Demirbasin Yilini Giriniz :";
					do
					{
						cin>>alimyili;
						if(alimyili/1000<1||alimyili/1000>10)
						{
							cout.setf(ios::right);
							cout<<setw(75)<<"Lutfen gecerli yil giriniz :"<<"\a";
						}
						
					}while(alimyili/1000<1||alimyili/1000>10);// yil 4 rakam olsun 
								
												d.setalimtarihiyil(alimyili);
					
					//garanti baslangic tarihi 
					int g_gun;
					cout.setf(ios::right);
					cout<<setw(75)<<"Luften Alinan Demirbasin Garanti Baslangic Gununu Giriniz :";
					do
					{
						cin>>g_gun;
						if(g_gun>31)
						{
							cout.setf(ios::right);
							cout<<setw(75)<<"Lutfen gecerli gun giriniz :"<<"\a";
						}
					}while(g_gun>31);//gun 31 den cok ise bir daha ister gunu		
					
												d.setgarantigun(g_gun);
					int g_ay;							
					cout.setf(ios::right);
					cout<<setw(75)<<"Luften Alinan Demirbasin Garanti Baslangic Ayini Giriniz :";
					do
					{
					    cin>>g_ay;
						if(g_ay>12)
						{
							cout<<setw(75)<<"Lutfen gecerli ay giriniz :"<<"\a";
						}
					}while(g_ay>12);//ay 12 den cok ise bir daha ister ayi		
					
												d.setgarantiay(g_ay);
					int g_yil;							
					cout<<setw(75)<<"Luften Alinan Demirbasin Garanti Baslangic Yilini Giriniz :";
					do
					{
						cin>>g_yil;
						if(g_yil/1000<1||g_yil/1000>10)
						{
							cout.setf(ios::right);
							cout<<setw(75)<<"Lutfen gecerli  yil giriniz :"<<"\a";
						}
					}while(g_yil/1000<1||g_yil/1000>10);															
												d.setgarantiyil(g_yil);
												
												
					//garanti suresi 
					int g_sure;
					cout.setf(ios::right);
					cout<<setw(75)<<"Aldiginiz Demirbasin Garanti Suresi giriniz :";
					cin>>g_sure;
												d.setgarantisuresi(g_sure);
					
					// demirbas adeti
					int adeti;
					cout.setf(ios::right);
					cout<<setw(75)<<"Aldiginiz Demirbasin Adetini giriniz :";
					cin>>adeti;
												
												d.setadet(adeti);
					
					//birim fiyatini girirdim
					int fiyat;
					cout.setf(ios::right);
					cout<<setw(75)<<"Alinan Demirbasin Birim Fiyatini Giriniz :";
					cin>>fiyat;
								
								d.setbirimfiyati(fiyat);//fiyati birimfiyatina ata
				
		
			
				dosya7.setf(ios::left);
				dosya7<<setw(15)<<sayi				
				<<setw(15)<<d.geturun()//urunler kucuk yaziliyor aramalari kucuk yaz
				<<setw(15)<<d.geturun_kodu()
				<<setw(15)<<d.getfirma()
				<<setw(15)<<d.getalimyapan()
				<<setw(15)<<d.getalimyaptiran()
				<<setw(20)<<d.getalimyaptirandep()
				<<setw(15)<<d.getdurumyaz()//set ile private degeri aldik get ile dosyaya yazdirdim
				<<setw(2)<<d.getalimtarihigunu()<<"."//int deger oldugu ýcýn get ile cagýrmada hata veriyor
				<<setw(2)<<d.getalimtarihiay()<<"."  											 // 1=nokta
				<<setw(9)<<d.getalimtarihiyil()//9 yazmamim sebebi toplam karakter 15 olsun diye 2+1+2+1+9  5 tanede bosluk ekler ay gun tek haneli ise 7 bosluk ekler
				<<setw(2)<<d.getgarantigun()<<"."//int deger oldugu ýcýn get ile cagýrmada hata veriyor
				<<setw(2)<<d.getgarantiay()<<"."                                             // 1=nokta
				<<setw(9)<<d.getgarantiyil()//9 yazmamim sebebi toplam karakter 15 olsun diye 2+1+2+1+9  5 tanede bosluk ekler ay gun tek haneli ise 7 bosluk ekler
				<<setw(12)<<d.getgarantisuresi()//this bu siniftaki degisen g.suresini getir
				<<setw(7)<<d.getadet()
				<<setw(8)<<d.getbirimfiyati()<<"TL"
				<<endl;
				}
				else
				{
					fstream dosya7("proje2.txt",ios::out|ios::in|ios::app);
					dosya7<<oku<<endl;
					dosya7.close();
				}
			}
			dosya6.close();	
			remove("proje.txt");
			rename("proje2.txt","proje.txt");
			
		}
				
};

class yaz:public demirbas,public Kurum//demirbas ve kurum publicde bulunan verileri yaz içinde geçerli olsun yani miras alýnýyor
{
	public :
		yaz()
		{
			cout.setf(ios::right);
			cout<<setw(75)<<"....Ali SARI...."<<endl;
		}
		~yaz()
		{
			cout<<"....Gule ....Gule  ";
		}
		void demirbaslariyaz(int urun_kodu);//kalitým urun_kodu protected tanimlandi demirbas sinifinda
		void demirbaslariyaz(string urun);
		void demirbaslariyaz(string firma,string alimyapankisi);
		void demirbaslariyaz(string alimyaptirankisi,string alimyaptirandep,string durumyaz);
		void demirbaslariyaz(int alimgunu,int alimayi,int alimyili);
		void demirbaslariyaz(int g_gun,int g_ay,int g_yil,int g_sure);
		void demirbaslariyaz(int adeti,int fiyat);
};
void yaz::demirbaslariyaz(int urun_kodu)
{
	cout.setf(ios::right);
	cout<<setw(75)<<"Urun Kodu :"<<urun_kodu<<endl;//kalitim yaptim urun_kodu protected tanimli
}
void yaz::demirbaslariyaz(string urun)
{
	cout<<endl<<endl;
	cout.setf(ios::right);
	cout<<setw(75)<<"....Eklenen demirbas...."<<endl<<endl;
	cout<<setw(75)<<"Urun Adi :"<<urun<<endl;
}
void yaz::demirbaslariyaz(string firma,string alimyapankisi)
{
	cout.setf(ios::right);
	
	cout<<setw(75)<<"Satici Firmanin Adi :"<<firma<<endl;
	cout<<setw(75)<<"Alim yapan kisinin Adi :"<<alimyapankisi<<endl;
}
void yaz::demirbaslariyaz(string alimyaptirankisi,string alimyaptirandep,string durumyaz)
{
		cout.setf(ios::right);
	
	cout<<setw(75)<<"Alim yaptiran kisinin Adi :"<<alimyaptirankisi<<endl;
	cout<<setw(75)<<"Alim yaptiran Departmanin Adi :"<<alimyaptirandep<<endl;
	cout<<setw(75)<<"Alinan Demirbas Durumu Yeni mi Eksi mi ? :"<<durumyaz<<endl;
}
void yaz::demirbaslariyaz(int alimgunu,int alimayi,int alimyili)
{
		cout.setf(ios::right);
	
	cout<<setw(75)<<"Alinan Demirbasin Tarihi :";
	cout.setf(ios::left);
	cout<<alimgunu<<"."<<alimayi<<"."<<alimyili<<endl;
}
void yaz::demirbaslariyaz(int g_gun,int g_ay,int g_yil,int g_sure)
{
	cout.setf(ios::right);
	
	cout<<setw(75)<<"Alinan Demirbasin Garanti Baslangic Tarihi :";
	cout.setf(ios::left);
	cout<<g_gun<<"."<<g_ay<<"."<<g_yil<<endl;
    cout<<setw(75)<<"Aldiginiz Demirbasin Garanti Suresi :"<<g_sure<<endl;
}
void yaz::demirbaslariyaz(int adeti,int fiyat)
{
	cout.setf(ios::right);
	
	cout<<setw(75)<<"Aldiginiz Demirbasin Adeti :"<<adeti<<endl;
    cout<<setw(75)<<"Alinan Demirbasin Birim Fiyati :"<<fiyat<<" TL"<<endl;
}
int main()
{  

        fstream dosya9;
		dosya9.open("proje.txt",ios::out|ios::in|ios::app);
		//ios::app    Dosya varsa içindeki deðerler korunur ve yazýlanlar dosyanýn sonuna eklenir. Eðer dosya yoksa açýlýr.
		//ios::in     Giriþ modudur. Bilgiler dosyadan okunur. Eðer dosya yoksa oluþturulamaz ve hata verir.
		//ios::out    Çýkýþ modudur. Bilgiler dosyaya yazýlýr. Eðer dosya yoksa oluþturulur, varsa içindekiler silinir ve yeniden açýlýr.Soldan eklme yapar uzerine yani
		string oku;
		string devam_etmek;
			int a;
				getline(dosya9,oku);
				a=oku[0];
			if(a>=65 && a<=122)//ilk index in asci kodu bu arada degilse  else komudunda baslik ekle(buyuk kucuk butun harfler)
			{
			//	demirbas d;//class sinifinida k degiskeni cagirdim
			//	Kurum k;	
			//	yaz y;//turetilmis sinif yaptigim icin sadece bunu kullandim
			//	do
			//	{
					system("cls");
					int secim;
					cout.setf(ios::left);
					cout<<endl<<setw(75)<<"1-Demirbas Ekleme :(demirbaslari yaz)"<<endl;
					cout<<setw(75)<<"2-Demirbas Listeleme :"<<endl;
					cout<<setw(75)<<"3-Demirbas Sorgulama :"<<endl;
					cout<<setw(75)<<"4-Demirbas Silme :"<<endl;
					cout<<setw(75)<<"5-Demirbas Guncelleme :"<<endl<<endl;
					cout<<"Yapmak Istediginiz Secimin Numarasini giriniz :";
					cin>>secim;
					cin.ignore();
					system("cls");//bu satirdan onceki yazilari ekrandan siler
					
					switch (secim)
					{
						case 1:
							{   yaz y;//yapici fonksiyonlari ekrana gostermek icin kullandim
								char idnumarasi[6];
								cout.setf(ios::right);
								cout<<endl<<endl<<setw(75)<<"Lutfen giris yapilan kelimelerde Turkce karakter kullanmayiniz  !!!"<<endl<<endl;                                                                                                                            
								int a; 	
							    string oku;
								int idbulma;
								sayac=10000;
								while(!dosya9.eof())
								{
									
									getline(dosya9,oku);
									a=oku[0];
									if(a>=48 && a<=122)
									{
										sayac++;
										idnumarasi[0]=oku[0];
										idnumarasi[1]=oku[1];
										idnumarasi[2]=oku[2];
										idnumarasi[3]=oku[3];
										idnumarasi[4]=oku[4];
										idnumarasi[5]=oku[5];
									 	
										idbulma=atoi(idnumarasi);
										idbulma++;
										sayac=idbulma;
									}
									//	cout<<idbulma<<endl<<idnumarasi<<endl<<sayac<<endl;							
								}
								string urun;
								cout.setf(ios::right);//consolda saga dayali yaz
								cout<<setw(75)<<"Lutfen Urun Adini giriniz :";//75 karakterli olsun
								cin>>urun;
								
															y.seturun(urun);
								
								
								int urunkod;
								cout.setf(ios::right);
								cout<<setw(75)<<"Urun kodunu giriniz :";
								cin>>urunkod;
															y.seturun_kodu(urunkod);
															
																						
								string firma;
								cout.setf(ios::right);//consolda saga dayali yaz
								cout<<setw(75)<<"Lutfen Satici Firmanin Adini giriniz :";//50 karakterli olsun
								cin>>firma;
															y.setfirma(firma);
									
								string alimyapankisi;							
								cout.setf(ios::right);
								cout<<setw(75)<<"Luften alim yapan kisinin Adini yaziniz :";
								cin>>alimyapankisi;			
															y.setalimyapan(alimyapankisi);				
										
										
								string alimyaptirankisi;							
								cout.setf(ios::right);
								cout<<setw(75)<<"Lutfen alim yaptiran kisinin Adini giriniz :";
								cin>>alimyaptirankisi;						
															y.setalimyaptiran(alimyaptirankisi);
															
								string alimyaptirandep;							
								cout.setf(ios::right);
								cout<<setw(75)<<"Lutfen alim yaptiran Departmanin Adini yaziniz :";
								cin>>alimyaptirandep;							
															
															y.setalimyaptirandep(alimyaptirandep);
								
								string durumyaz;							
								cout.setf(ios::right);
								cout<<setw(75)<<"Alinan Demirbas Durumu Yeni mi Eksi mi ? :";
								cin>>durumyaz;							
															
															y.setdurum(durumyaz);
								
								
									//alim tarihi 
							    int alimgunu;    
								cout.setf(ios::right);
								cout<<setw(75)<<"Lutfen Alinan Demirbasin Gununu Giriniz :";
								do
								{
									cin>>alimgunu;
									if(alimgunu>31)
									{
										cout.setf(ios::right);
										cout<<setw(75)<<"Lutfen gecerli gun giriniz :"<<"\a";
									}
								}while(alimgunu>31);//gun 31 den cok ise bir daha ister gunu	
														
														    y.setalimtarihigunu(alimgunu);
								int alimayi;
								cout.setf(ios::right);
								cout<<setw(75)<<"Luften Alinan Demirbasin Ayi Giriniz :";
								do
								{
									cin>>alimayi;
									if(alimayi>12)
									{
										cout.setf(ios::right);
										cout<<setw(75)<<"Lutfen gecerli ay giriniz :"<<"\a";
									}
								}while(alimayi>12);//ay 12 den cok ise bir daha ister ayi						    
													
															y.setalimtarihiay(alimayi);
								int alimyili;
								cout.setf(ios::right);
								cout<<setw(75)<<"Luften Alinan Demirbasin Yilini Giriniz :";
								do
								{
									cin>>alimyili;
									if(alimyili/1000<1||alimyili/1000>10)
									{
										cout.setf(ios::right);
										cout<<setw(75)<<"Lutfen gecerli yil giriniz :"<<"\a";
									}
									
								}while(alimyili/1000<1||alimyili/1000>10);// yil 4 rakam olsun 
											
															y.setalimtarihiyil(alimyili);
								
								//garanti baslangic tarihi 
								int g_gun;
								cout.setf(ios::right);
								cout<<setw(75)<<"Luften Alinan Demirbasin Garanti Baslangic Gununu Giriniz :";
								do
								{
									cin>>g_gun;
									if(g_gun>31)
									{
										cout.setf(ios::right);
										cout<<setw(75)<<"Lutfen gecerli gun giriniz :"<<"\a";
									}
								}while(g_gun>31);//gun 31 den cok ise bir daha ister gunu		
								
															y.setgarantigun(g_gun);
								int g_ay;							
								cout.setf(ios::right);
								cout<<setw(75)<<"Luften Alinan Demirbasin Garanti Baslangic Ayini Giriniz :";
								do
								{
								    cin>>g_ay;
									if(g_ay>12)
									{
										cout<<setw(75)<<"Lutfen gecerli ay giriniz :"<<"\a";
									}
								}while(g_ay>12);//ay 12 den cok ise bir daha ister ayi		
								
															y.setgarantiay(g_ay);
								int g_yil;							
								cout<<setw(75)<<"Luften Alinan Demirbasin Garanti Baslangic Yilini Giriniz :";
								do
								{
									cin>>g_yil;
									if(g_yil/1000<1||g_yil/1000>10)
									{
										cout.setf(ios::right);
										cout<<setw(75)<<"Lutfen gecerli  yil giriniz :"<<"\a";
									}
								}while(g_yil/1000<1||g_yil/1000>10);															
															y.setgarantiyil(g_yil);
															
															
								//garanti suresi 
								int g_sure;
								cout.setf(ios::right);
								cout<<setw(75)<<"Aldiginiz Demirbasin Garanti Suresi giriniz :";
								cin>>g_sure;
															y.setgarantisuresi(g_sure);
								
								// demirbas adeti
								int adeti;
								cout.setf(ios::right);
								cout<<setw(75)<<"Aldiginiz Demirbasin Adetini giriniz :";
								cin>>adeti;
															
															y.setadet(adeti);
								
								//birim fiyatini girirdim
								int fiyat;
								cout.setf(ios::right);
								cout<<setw(75)<<"Alinan Demirbasin Birim Fiyatini Giriniz :";
								cin>>fiyat;
								
								y.setbirimfiyati(fiyat);//fiyati birimfiyatina ata
								
								
								y.demirbasekle();
								system("cls");
				                y.demirbaslariyaz(urun);
				                y.demirbaslariyaz(urunkod);
				                y.demirbaslariyaz(firma,alimyaptirandep);
				                y.demirbaslariyaz(alimyaptirankisi,alimyaptirandep,durumyaz);
				                y.demirbaslariyaz(alimgunu,alimayi,alimyili);
				                y.demirbaslariyaz(g_gun,g_ay,g_yil,g_sure);
				                y.demirbaslariyaz(adeti,fiyat);
								break ;
							}
						case 2:
							{
								yaz y;//yapici fonksiyonlari ekrana gostermek icin kullandim
								cout<<endl <<endl;
								dosya9.close();
								y.demirbaslistele();
								
								break;
							}	
						case 3:
							{
								yaz y;//yapici fonksiyonlari ekrana gostermek icin kullandim
								cout<<endl <<endl;
								dosya9.close();
								y.urun_arama();
							
								break;
							}
							
						case 4:
							{
								yaz y;//yapici fonksiyonlari ekrana gostermek icin kullandim
								cout<<endl<<endl;
								dosya9.close();
								y.demirbas_silme();
								
								break;
							}
						case 5:
							{
								yaz y;//yapici fonksiyonlari ekrana gostermek icin kullandim
								cout<<endl<<endl;
								dosya9.close();
								y.guncelleme();
								
								break;
							}
						
						default :
							cout<<"Yanlis secim yaptiniz " <<"\a";
							
							
							break;
					}
			
			
			   
			   //cout<<"Devam etmek istiyorsaniz e'ye basiniz...";
			  // cin>>devam_etmek;
		       //dosya9.close(); 
			//}while(devam_etmek=="e"||devam_etmek=="E");
					
					
		}	

		
				
			else              //baslik eklemek icin yaptim 
			{
				fstream dosya;
				dosya.open("proje.txt",ios::out|ios::in|ios::app);	
							dosya.setf(ios::left);
				    		dosya<<setw(15)<<"ID Numarasi"
							<<setw(15)<<"Urun adi "
							<<setw(15)<<"Urun Kodu "
							<<setw(15)<<"Satici Firma"
							<<setw(15)<<"Alim Yapan"
							<<setw(15)<<"Alim Yaptiran"
							<<setw(20)<<"Alim Yaptiran Dep."
							<<setw(15)<<"Durum"
							<<setw(15)<<"Alim Tarihi"
							<<setw(15)<<"Garanti T."
							<<setw(12)<<"Garanti S."
							<<setw(7)<<"Adet"
							<<"Fiyat"
							<<endl;
			dosya.close();
			cout.setf(ios::right);
			cout<<endl<<setw(75)<<".....Dosyaya Kategoriler Eklendi....."<<endl<<endl;
			}
	return 0;
}

