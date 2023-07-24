#include<iostream>
#include<random>

#include<list>
#include<vector>

#include<algorithm>
#include<functional>

bool IsMort(int a, int b) {
	return a > b;
}

int main() {
	setlocale(LC_ALL, "Russian");

	std::list<int>cill1;
	std::vector<int>cill2;

	std::random_device rd;    // генератор энтропии
	std::mt19937 generator(rd());   // генератор псевдослучайных чисел
	std::uniform_int_distribution<int>provider(10, 99);

	for (size_t i = 0; i < 10; ++i) {
		cill1.push_back(provider(generator));
		cill2.push_back(provider(generator));
	}
	int count = 0;
	/*for (const auto& node : cill1) {
		for (const auto& it : cill2) {
			if (it == node) {
				count++; break;
			}
		}
	}*/
	for (const auto& node : cill1) {
		count += std::count(cill2.begin(), cill2.end(), node);
	}
	std::cout << count << " дублированные элементы\n";
	for (const auto& node : cill1) {
		std::cout << node << ' ';
	}
	std::cout << '\n';
	for (const auto& it : cill2) {
		std::cout << it << ' ';
	}

	std::cout << '\n';

	if (count > 0) {
		for (const auto& node : cill1) {
			auto it = std::find(cill2.begin(), cill2.end(), node);
			if (it != cill2.end()) {
				cill2.erase(it);
			}
		}
		for (const auto& node : cill1) {
			std::cout << node << ' ';
		}
		std::cout << '\n';
		for (const auto& it : cill2) {
			std::cout << it << ' ';
		}

		std::cout << '\n';
	}

	// min, max, min_max, contain, sort, shuffle, split

	auto lamb = [](int x, int y)->bool {
		return x > y;
	};

	std::sort(cill2.begin(), cill2.end(), [](int x, int y)->bool {return x > y; });   // или функция IsMort()   (она там вверху)) , или lamd
	std::cout << '\n';
	for (const auto& it : cill2) {
		std::cout << it << ' ';
	}
	std::cout << "\n\n";

	auto search = std::find_if(cill2.begin(), cill2.end(), [](int x)->bool {return x > 30; });
	std::cout << *search<<"\n\n";

	// Задачка.
	std::random_device ran;   
	std::mt19937 gen(ran());   
	std::uniform_int_distribution<int>prov(0, 25);
	std::vector<int>vec1;
	std::vector<int>vec2 ;
	std::vector<int>vec3 = vec1;
	for (size_t i = 0; i < 30; ++i) {
		vec1.push_back(prov(gen));
	}
	for (const auto& it : vec1) {
		std::cout << it << ' ';
	}
	std::cout << "\n\n";
	for (auto& it1 : vec1) {
		int cou = std::count(vec1.begin(), vec1.end(), it1);
		if (cou > 1) {
			vec2.push_back(it1);
			vec1.erase(std::find(vec1.begin(), vec1.end(), it1));
			cou = std::count(vec1.begin(), vec1.end(), it1);
		}
	}
	for (auto& it : vec1) {
		std::cout << it << ' ';
	}
	std::cout << '\n';
	for (auto& it : vec2) {
		std::cout << it << ' ';
	}


	return 0;
}