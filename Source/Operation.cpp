#include "Operation.h"

sloj sabiranje::operacija(sloj s)
{
	for (slika_u_bmp* sl : s.slojevi) {
		if (sl->get_active() == true) {
			if (s.get_s() != nullptr) {
				for (Kvadrat k : s.get_s()->kvadrati)
					for (int y = k.poz.second; y <  k.poz.second + k.height; y++)
						for (int x = k.poz.first; x < k.poz.first + k.width; x++)
							*(sl->pikseli[y * sl->get_width() + x]) = *(sl->pikseli[y * sl->get_width() + x]) + z;

			}
			else
				for (int x = 0; x < sl->get_height()*sl->get_width(); x++)
					*(sl->pikseli[x] = sl->pikseli[x]) + z;

		}
		sl->update();
	}
	return s;
}

sloj oduzimanje::operacija(sloj s)
{
	for (slika_u_bmp* sl : s.slojevi) {
		if (sl->get_active() == true) {
			if (s.get_s() != nullptr) {
				for (Kvadrat k : s.get_s()->kvadrati)
					for (int y = k.poz.second; y < k.poz.second + k.height; y++)
						for (int x = k.poz.first; x < k.poz.first + k.width; x++)
							*(sl->pikseli[y * sl->get_width() + x]) =*( sl->pikseli[y* sl->get_width() + x]) - z;

			}
			else
				for (int x = 0; x < sl->get_height() * sl->get_width(); x++)
					*(sl->pikseli[x]) = *(sl->pikseli[x]) - z;

		}
		sl->update();
	}
	return s;
}

sloj mnozenje::operacija(sloj s)
{
	for (slika_u_bmp* sl : s.slojevi) {
		if (sl->get_active() == true) {
			if (s.get_s() != nullptr) {
				for (Kvadrat k : s.get_s()->kvadrati)
					for (int y = k.poz.second; y < k.poz.second + k.height; y++)
						for (int x = k.poz.first; x < k.poz.first + k.width; x++)
							*(sl->pikseli[y * sl->get_width() + x]) = *(sl->pikseli[y * sl->get_width() + x] )* z;

			}
			else
				for (int x = 0; x < sl->get_height() * sl->get_width(); x++)
					*(sl->pikseli[x]) = *(sl->pikseli[x]) * z;

		}
		sl->update();
	}
	return s;
}

sloj deljenje::operacija(sloj s)
{
	for (slika_u_bmp* sl : s.slojevi) {
		if (sl->get_active() == true) {
			if (s.get_s() != nullptr) {
				for (Kvadrat k : s.get_s()->kvadrati)
					for (int y = k.poz.second; y < k.poz.second + k.height; y++)
						for (int x = k.poz.first; x < k.poz.first + k.width; x++)
							*(sl->pikseli[y * sl->get_width() + x]) = *(sl->pikseli[y * sl->get_width() + x]) / z;

			}
			else
				for (int x = 0; x < sl->get_height() * sl->get_width(); x++)
					*(sl->pikseli[x]) = *(sl->pikseli[x]) / z;

		}
		sl->update();
	}
	return s;
}

sloj logaritam::operacija(sloj s)
{
	for (slika_u_bmp* sl : s.slojevi) {
		if (sl->get_active() == true) {
			if (s.get_s() != nullptr) {
				for (Kvadrat k : s.get_s()->kvadrati)
					for (int y = k.poz.second; y < k.poz.second + k.height; y++)
						for (int x = k.poz.first; x < k.poz.first + k.width; x++)
							*(sl->pikseli[y * sl->get_width() + x]) = sl->pikseli[y * sl->get_width() + x]->logarithm();

			}
			else
				for (int x = 0; x < sl->get_height() * sl->get_width(); x++)
					*(sl->pikseli[x]) = sl->pikseli[x]->logarithm();

		}
		sl->update();
	}
	return s;
}

sloj Max::operacija(sloj s)
{
	for (slika_u_bmp* sl : s.slojevi) {
		if (sl->get_active() == true) {
			if (s.get_s() != nullptr) {
				for (Kvadrat k : s.get_s()->kvadrati)
					for (int y = k.poz.second; y < k.poz.second + k.height; y++)
						for (int x = k.poz.first; x < k.poz.first + k.width; x++)
							*(sl->pikseli[y * sl->get_width() + x]) = sl->pikseli[y * sl->get_width() + x]->max(z);

			}
			else
				for (int x = 0; x < sl->get_height() * sl->get_width(); x++)
					*(sl->pikseli[x]) = sl->pikseli[x]->max(z);

		}
		sl->update();
	}
	return s;
}

sloj Min::operacija(sloj s)
{
	for (slika_u_bmp* sl : s.slojevi) {
		if (sl->get_active() == true) {
			if (s.get_s() != nullptr) {
				for (Kvadrat k : s.get_s()->kvadrati)
					for (int y = k.poz.second; y < k.poz.second + k.height; y++)
						for (int x = k.poz.first; x < k.poz.first + k.width; x++)
							*(sl->pikseli[y * sl->get_width() + x]) = sl->pikseli[y * sl->get_width() + x]->min(z);

			}
			else
				for (int x = 0; x < sl->get_height() * sl->get_width(); x++)
					*(sl->pikseli[x]) = sl->pikseli[x]->min(z);

		}
		sl->update();
	}
	return s;
}

sloj power::operacija(sloj s)
{
	for (slika_u_bmp* sl : s.slojevi) {
		if (sl->get_active() == true) {
			if (s.get_s() != nullptr) {
				for (Kvadrat k : s.get_s()->kvadrati)
					for (int y = k.poz.second; y < k.poz.second + k.height; y++)
						for (int x = k.poz.first; x < k.poz.first + k.width; x++)
							*(sl->pikseli[y * sl->get_width()+ x]) = sl->pikseli[y * sl->get_width() + x]->power(z);

			}
			else
				for (int x = 0; x < sl->get_height() * sl->get_width(); x++)
					*(sl->pikseli[x]) = sl->pikseli[x]->power(z);

		}
		sl->update();
	}
	return s;
}

sloj absolute::operacija(sloj s)
{
	for (slika_u_bmp* sl : s.slojevi) {
		if (sl->get_active() == true) {
			if (s.get_s() != nullptr) {
				for (Kvadrat k : s.get_s()->kvadrati)
					for (int y = k.poz.second; y < k.poz.second + k.height; y++)
						for (int x = k.poz.first; x < k.poz.first + k.width; x++)
							*(sl->pikseli[y * sl->get_width() + x]) = sl->pikseli[y * sl->get_width() + x]->absolute();

			}
			else
				for (int x = 0; x < sl->get_height() * sl->get_width(); x++)
					*(sl->pikseli[x]) = sl->pikseli[x]->absolute();

		}
		sl->update();
	}
	return s;
}

sloj crnobela::operacija(sloj s)
{
	for (slika_u_bmp* sl : s.slojevi) {
		if (sl->get_active() == true) {
			if (s.get_s() != nullptr) {
				for (Kvadrat k : s.get_s()->kvadrati)
					for (int y = k.poz.second; y < k.poz.second + k.height; y++)
						for (int x = k.poz.first; x < k.poz.first + k.width; x++)
							*(sl->pikseli[y * sl->get_width() + x]) = sl->pikseli[y * sl->get_width() + x]->crnobela();

			}
			else
				for (int x = 0; x < sl->get_height() * sl->get_width(); x++)
					*(sl->pikseli[x]) = sl->pikseli[x]->crnobela();

		}
		sl->update();
	}
	return s;
}

sloj siva::operacija(sloj s)
{
	for (slika_u_bmp* sl : s.slojevi) {
		if (sl->get_active() == true) {
			if (s.get_s() != nullptr) {
				for (Kvadrat k : s.get_s()->kvadrati)
					for (int y = k.poz.second; y < k.poz.second + k.height; y++)
						for (int x = k.poz.first; x < k.poz.first + k.width; x++)
							*(sl->pikseli[y * sl->get_width() + x]) = sl->pikseli[y * sl->get_width() + x]->siva();

			}
			else
				for (int x = 0; x < sl->get_height() * sl->get_width(); x++)
					*(sl->pikseli[x]) = sl->pikseli[x]->siva();

		}
		sl->update();
	}
	return s;
}

sloj invert::operacija(sloj s)
{
		for (slika_u_bmp* sl : s.slojevi) {
			if (sl->get_active() == true) {
				if (s.get_s() != nullptr) {
					for (Kvadrat k : s.get_s()->kvadrati)
						for (int y = k.poz.second; y < k.poz.second + k.height; y++)
							for (int x = k.poz.first; x < k.poz.first + k.width; x++)
								*(sl->pikseli[y * sl->get_width() + x]) = sl->pikseli[y * sl->get_width() + x]->invert();

				}
				else
					for (int x = 0; x < sl->get_height() * sl->get_width(); x++)
						*(sl->pikseli[x]) = sl->pikseli[x]->invert();

			}
			sl->update();
		}
		return s;
	
}

sloj Medijana::operacija(sloj s)
{
	int r[5];
	int g[5];
	int b[5];
	float a[5];
	int i = 0;
	int p, key, t;
	for (slika_u_bmp* sl : s.slojevi) {
		if (sl->get_active() == true) {
			if (s.get_s() != nullptr) {
				for (Kvadrat k : s.get_s()->kvadrati)
					for (int x = k.poz.second; x < k.poz.second + k.height; x++)
						for (int y = k.poz.first; y < k.poz.first + k.width; y++) {
							i = 0;
							 a[i]=sl->pikseli[x * sl->get_width() + y]->get_A() ;
							 r[i] = sl->pikseli[x * sl->get_width() + y]->get_R();
							 g[i] = sl->pikseli[x * sl->get_width() + y]->get_G();
							 b[i++] = sl->pikseli[x * sl->get_width() + y]->get_B();
							if (x + 1 < sl->get_height()) {
								a[i] = sl->pikseli[(x + 1) * sl->get_width() + y]->get_A ();
								r[i] = sl->pikseli[(x + 1) * sl->get_width() + y]->get_R();
								g[i] = sl->pikseli[(x + 1) * sl->get_width() + y]->get_G();
								b[i++] = sl->pikseli[(x + 1) * sl->get_width() + y]->get_B();
							}if (x - 1 > 0) {
								a[i] = sl->pikseli[(x - 1) * sl->get_width() + y]->get_A ();
								r[i] = sl->pikseli[(x - 1) * sl->get_width() + y]->get_R();
								g[i] = sl->pikseli[(x - 1) * sl->get_width() + y]->get_G();
								b[i++] = sl->pikseli[(x - 1) * sl->get_width() + y]->get_B() ;
							}if (y + 1 < sl->get_width()) {
								a[i] = sl->pikseli[x * sl->get_width() + y + 1]->get_A();
								r[i] = sl->pikseli[x * sl->get_width() + y + 1]->get_R ();
								g[i] = sl->pikseli[x * sl->get_width() + y + 1]->get_G ();
								b[i++] = sl->pikseli[x * sl->get_width() + y + 1]->get_B();
							}if (y - 1 > 0) {
								a[i] = sl->pikseli[x * sl->get_width() + y - 1]->get_A();
								r[i] = sl->pikseli[x * sl->get_width() + y - 1]->get_R();
								g[i] = sl->pikseli[x * sl->get_width() + y - 1]->get_G ();
								b[i++] = sl->pikseli[x * sl->get_width() + y - 1]->get_B();
							}

							for (p = 1; p < i; p++) {
								float key1 = a[p];
								t = p - 1;
								while (t >= 0 && a[t] > key1)
								{
									a[t + 1] = a[t];
									t = t - 1;
								}
								a[t + 1] = key1;
							}

							for (p = 1; p < i; p++) {
								key = b[p];
								t = p - 1;
								while (t >= 0 && b[t] > key)
								{
									b[t + 1] = b[t];
									t = t - 1;
								}
								b[t + 1] = key;
							}

							for (p = 1; p < i; p++) {
								key = r[p];
								t = p - 1;
								while (t >= 0 && r[t] > key)
								{
									r[t + 1] = r[t];
									t = t - 1;
								}
								r[t + 1] = key;
							}

							for (p = 1; p < i; p++) {
								key = g[p];
								t = p - 1;
								while (t >= 0 && g[t] > key)
								{
									g[t + 1] = g[t];
									t = t - 1;
								}
								g[t + 1] = key;
							}
							sl->pikseli[x * sl->get_width() + y]->set_A(a[i / 2]);
							sl->pikseli[x * sl->get_width() + y]->set_R(r[i / 2]);
							sl->pikseli[x * sl->get_width() + y]->set_G(g[i / 2]);
							sl->pikseli[x * sl->get_width() + y]->set_B(b[i / 2]);
						}
			}


			else
				for (int x = 0; x < sl->get_height(); x++)
					for (int y = 0; y < sl->get_width(); y++) {
						i = 0;
						a[i] = sl->pikseli[x * sl->get_width() + y]->get_A();
						r[i] = sl->pikseli[x * sl->get_width() + y]->get_R();
						g[i] = sl->pikseli[x * sl->get_width() + y]->get_G();
						b[i++] = sl->pikseli[x * sl->get_width() + y]->get_B();
						if (x + 1 < sl->get_height()) {
							a[i] = sl->pikseli[(x + 1) * sl->get_width() + y]->get_A();
							r[i] = sl->pikseli[(x + 1) * sl->get_width() + y]->get_R();
							g[i] = sl->pikseli[(x + 1) * sl->get_width() + y]->get_G();
							b[i++] = sl->pikseli[(x + 1) * sl->get_width() + y]->get_B();
						}if (x - 1 > 0) {
							a[i] = sl->pikseli[(x - 1) * sl->get_width() + y]->get_A();
							r[i] = sl->pikseli[(x - 1) * sl->get_width() + y]->get_R();
							g[i] = sl->pikseli[(x - 1) * sl->get_width() + y]->get_G();
							b[i++] = sl->pikseli[(x - 1) * sl->get_width() + y]->get_B();
						}if (y + 1 < sl->get_width()) {
							a[i] = sl->pikseli[x * sl->get_width() + y + 1]->get_A();
							r[i] = sl->pikseli[x * sl->get_width() + y + 1]->get_R();
							g[i] = sl->pikseli[x * sl->get_width() + y + 1]->get_G();
							b[i++] = sl->pikseli[x * sl->get_width() + y + 1]->get_B();
						}if (y - 1 > 0) {
							a[i] = sl->pikseli[x * sl->get_width() + y - 1]->get_A();
							r[i] = sl->pikseli[x * sl->get_width() + y - 1]->get_R();
							g[i] = sl->pikseli[x * sl->get_width() + y - 1]->get_G();
							b[i++] = sl->pikseli[x * sl->get_width() + y - 1]->get_B();
						}

						for (p = 1; p < i; p++) {
							float key2 = a[p];
							t = p - 1;
							while (t >= 0 && a[t] > key2)
							{
								a[t + 1] = a[t];
								t = t - 1;
							}
							a[t + 1] = key2;
						}

						for (p = 1; p < i; p++) {
							key = b[p];
							t = p - 1;
							while (t >= 0 && b[t] > key)
							{
								b[t + 1] = b[t];
								t = t - 1;
							}
							b[t + 1] = key;
						}

						for (p = 1; p < i; p++) {
							key = r[p];
							t = p - 1;
							while (t >= 0 && r[t] > key)
							{
								r[t + 1] = r[t];
								t = t - 1;
							}
							r[t + 1] = key;
						}

						for (p = 1; p < i; p++) {
							key = g[p];
							t = p - 1;
							while (t >= 0 && g[t] > key)
							{
								g[t + 1] = g[t];
								t = t - 1;
							}
							g[t + 1] = key;
						}
						sl->pikseli[x * sl->get_width() + y]->set_A(a[i / 2]);
						sl->pikseli[x * sl->get_width() + y]->set_R(r[i / 2]);
						sl->pikseli[x * sl->get_width() + y]->set_G(g[i / 2]);
						sl->pikseli[x * sl->get_width() + y]->set_B( b[i / 2]);
					}
		


			sl->update();
		}
	}
	



	return s;
}
