#include <fstream>
#include <iostream>
class Adress
{
private:
	std::string C, H;
	int nh, nr;
public:
	std::string output_adress() {
		char nhh, nrh;
		nhh = nh;
		nrh = nr;
		std::string ou = this->C + ", " + this->H + ", " + nhh;
		return ou;
	}
	Adress()
	{
		C = "Неизвесный";
		H = "Неизвестный";
		nh = 1;
		nr = 1;
	}
	Adress(std::string C, std::string H, int nh, int nr)
	{
		this->C = C;this->H = H; this->nh = nh; this->nr = nr;
	}
};
int main()
{
	setlocale(LC_ALL, "Russian");
	std::ifstream fin("in.txt");
	int q;
	if (!(fin.is_open()))
	{
		std::cout << "Файл не найден";
	}
	else {
		fin >> q;
		Adress* arr = new Adress[q];
		for (int i = 0; i < q; i++) {
			std::string C, H;
			int nh, nr;
			fin >> C;
			fin >> H;
			fin >> nh;
			fin >> nr;
			Adress r(C, H, nh, nr);
			arr[i] = r;
		}
		std::ofstream fout("out.txt");
		fout << q << std::endl;
		for (int i = q - 1; i >= 0; i--) {
			Adress r;
			r = arr[i];
			fout << r.output_adress() << std::endl;
		}
		delete[] arr;
		fout.close();
		fin.close();
	}

}
