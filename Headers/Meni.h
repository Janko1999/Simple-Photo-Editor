#pragma once
#include<iostream>
#include "sloj.h"
class Meni :
	public sloj
{
	bool sthdone = false;
public:
	void startMeni() {
		int p = 1;
		while (p != 0)
		{
			cout << "Meni" << endl
				<< "1.Dodati sloj" << endl
				<<"2.Ukloniti sloj"<<endl
				<< "3.Postaviti sekciju" << endl
				<<"4. Izbrisati sekciju"<<endl
				<< "5. Ispuniti sekciju" << endl
				<< "6. Aritmeticka operacija" << endl
				<< "7.Funkcije" << endl
				<< "8. Preklopi slojeve" << endl
				<< "9. Ucitaj Kompozitnu funkciju" << endl
				<< "10. Ucitaj Postojeci Projekat" << endl
				<< "11. Ispis slike u nekom formatu" << endl
				<< "12. Ispis u sopstvenom formatu" << endl
				<< "13. Izlaz" << endl;

			int x;
			cin >> x;
			switch (x) {
			case 1: {
				cout << "1. Ucitati sliku u sloj" << endl;
				cout << "2. Bez slike" << endl;
				int y;
				cin >> y;
				switch (y) {
				case 1: {
					cout << "Unesite putanju do slike" << endl;
					std::string z;
					cin >> z;
					cout << "Unesite transparentnost" << endl;
					int q;
					cin >> q;
					slika_u_bmp* slika1 = new slika_u_bmp(z, q);
					dodaj_sloj(slika1);
					
					break;
				}
				case 2: {
					cout << "Unesite visinu" << endl;
					int height;
					cin >> height;
					cout << "Unesite sirinu" << endl;
					int width;
					cin >> width;
					cout << "Unesite providnost" << endl;
					int transp;
					cin >> transp;
					slika_u_bmp* sl = new slika_u_bmp(height, width, transp);
					dodaj_sloj(sl);
					break;
				}
				}
				sthdone = true;
				break;
			}
			case 2: {cout << "Unesite indeks sloja koji zelite da izbrisete" << endl;
				int r;
				cin >> r;
				slojevi.erase(slojevi.begin() + r - 1);
				sthdone = true;
				break; }
			case 3: {
				cout << "Unesite ime sekcije" << endl;
				std::string ime;
				cin >> ime;
				sekcija* s1 = new sekcija(ime);

				while (true) {
					cout << "Unesite visinu vaseg kvadrata" << endl;
					int height;
					cin >> height;
					cout << "Unesite sirinu vaseg kvadrata" << endl;
					int width;
					cin >> width;
					cout << "Unesite poziciju kvadrata" << endl;
					int x;
					int y;
					cin >> x;
					cin >> y;
					Kvadrat k(height, width, x, y);
					s1->dodajKvadrat(k);
					cout << "Da li zelite jos kvadrata?" << endl;
					std::string answer;
					cin >> answer;
					if (answer == "No") break;
				}
				postavi_sekciju(s1);
				sthdone = true;
				break;
			}
			case 4: {this->set_s(nullptr); break; sthdone = true; }
			case 5: {
				cout << "Unesite boju" << endl;
				int R;
				int G;
				int B;
				float A;
				cin >> R;
				cin >> G;
				cin >> B;
				cin >> A;
				for (slika_u_bmp* sl : slojevi)
					sl->fill_section(*get_s(), R, G, B, A);
				sthdone = true;
				break;
			}
			case 6: {
				cout << "1.Sabiranje" << endl;
				cout << "2. Oduzimanje" << endl;
				cout << "3.Mnozenje" << endl;
				cout << "4. Deljenje" << endl;
				cout << "5. Stepen" << endl;
				cout << "6. Apsolutna vrednost" << endl;
				cout << "7. Logaritam" << endl;
				cout << "8. Min" << endl;
				cout << "9. Max" << endl;
				int r;
				cin >> r;
				switch (r) {
				case 1: {cout << "Unesite konstantu" << endl; int con; cin >> con; plus(con); break; }
				case 2: {cout << "Unesite konstantu" << endl; int con; cin >> con; minus(con); break; }
				case 3: {cout << "Unesite konstantu" << endl; int con; cin >> con; mnozenjee(con); break; }
				case 4: {cout << "Unesite konstantu" << endl; int con; cin >> con; deljenjee(con); break; }
				case 5: {cout << "Unesite konstantu" << endl; int con; cin >> con; powers(con); break; }
				case 6: { abs(); break; }
				case 7: {log(); break; }
				case 8: {cout << "Unesite konstantu" << endl; int con; cin >> con; Minimum(con); break; }
				case 9: {cout << "Unesite konstantu" << endl; int con; cin >> con; Maximum(con); break; }
				}
				repaint();
				sthdone = true;
				break;
			}
			case 7: {
				cout << "1.Inverzija" << endl;
				cout << "2. Crno bela slika" << endl;
				cout << "3. Siva slika" << endl;
				cout << "4. Medijana" << endl;
				int d;
				cin >> d;
				switch (d) {
				case 1: {invertion(); break; }
				case 2: {crnobelaa(); break; }
				case 3: {sivaa(); break; }
				case 4: {medijana(); break; }
				}
				repaint();
				sthdone = true;
				break;
			}
			case 8: {repaint(); break; }
			case 9: {cout << "Unesite putanju do funksije" << endl;
				std::string fname;
				cin >> fname;
				citajFunkciju(fname); sthdone = true; break; }
			case 10: {cout << "Unesite putanju do projekta" << endl;
				std::string file;
				cin >> file;
				ucitaj_program(file);
				sthdone = true;
				break;
			}
			case 11: {cout << "Napisite lokaciju eksporta" << endl;
				std::string x;
				cin >> x;
				eksport(x);
				sthdone = true;
				break; }
			case 12: {
				cout << "Unesite lokacije eksporta" << endl;
				std::string location;
				cin >> location; 
				ispisi_program(location);
				break;
			}
			case 13: {p = 0; if (sthdone) {
				cout << "Da li zelite da sacuvate vas projekat" << endl;
				std::string f;
				cin >> f;
				if (f == "da") {
					cout << "Unesite lokacije eksporta" << endl;
					std::string location;
					cin >> location;
					ispisi_program(location);
				}
			}
				break; }
			}
		}
	}
};

