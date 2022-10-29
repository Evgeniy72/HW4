#include <fstream>
#include <iostream>
#include <string>
class Adress
{
private:
	std::string C, H;
	int nh, nr;
public:
		std::string output_adress() {
		std::string ou = this->C + ", " + this->H + ", " + std::to_string(nh) + ", " + std::to_string(nr);
		return ou;
	}
		std::string get_city() { return C;}
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
void sort(Adress* adresses, int size) {
		bool ch;
	do
	{
		ch = false;
		for (int i = 0; i < size-1; i++)
		{
			Adress ch1, ch2;
			 ch1 = adresses[i];
			 ch2 = adresses[i+1];
			if (ch1.get_city() > ch1.get_city())
			{
				Adress temp = adresses[i + 1];
				adresses[i + 1] = adresses[i];
				adresses[i] = temp;
				ch = true;
			}
		}
	} while (ch);
	}
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
		sort(arr, q);
		std::ofstream fout("out.txt");
		fout << q << std::endl;
		for (int i = 0; i < q; i++) {
			Adress r;
			r = arr[i];
			fout << r.output_adress() << std::endl;
		}
		delete[] arr;
		fout.close();
		fin.close();
	}

}
