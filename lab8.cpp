// lab8.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
template <typename T>
struct LDS
{
	struct element
	{
		T* next = nullptr;
	    T*prev = nullptr;
		T value;
	};
	element* head; 
};

// Конструктор
template <typename T>
void constructor_DLC( LDS<T>& lds) {
	lds.head->next = nullptr;
	lds.head->prev = nullptr;
	lds.head = nullptr;
}

// Деструктор.
template <typename T>
void deconstructor_DLS(LDS<T>& lds) {
	while (lds.head != nullptr)
	{
		LDS::element* q = new LDS::element;
		q = lds.head->next;
		delete lds.head;
		lds.head = q;
		delete q;
	}
}

// Добавление элемента в начало.
template <typename T>
void push_LDS(LDS<T>& lds, T c){
	LDS::element* new_el = new LDS::element;
	if (lds.head == nullptr) {
		lds.head = new_el;
		lds.head->next = new_el;
		lds.head->prev = new_el;
		new_el->value = c;
	 }
	else {
		LDS::element* z = new LDS::element;
		z = lds.head->prev;
		new_el->next = lds.head;
		new_el->prev = lds.head->prev; 
		lds.head->prev = new_el;
		new_el->value = c;
		lds.head = new_el;
		z->next = new_el;
		delete z;
	}
}

// Добавление элемента в конец.
template <typename T>
void push_2_LDS(LDS<T>& lds, T c) {
	LDS::element* new_el = new LDS::element;
	if (lds.head == nullptr) {
		lds.head = new_el;
		new_el->value = c;
	}
	else {
		LDS::element* z = new LDS::element;
		z = lds.head->prev;
		z->next = new_el;
		new_el->prev = z;
		new_el->next = lds.head;
		lds.head->prev = new_el;
		delete z;
	}
}
//Удаление элемента из начала.
template <typename T>
void delete_pop(LDS<T>& lds) {
	LDS::element* z = new LDS::element;
	z = lds.head->next;
	LDS::element* v = new LDS::element;
	v = lds.head->prev;
	z->prev = lds.head->prev;
	v->next = z;
	delete lds.head;
	lds.head = z;
	delete z, v;
}
//Удаление элемента из конца.
template <typename T>
void delete_2_pop(LDS<T>& lds) {
	LDS::element* v = new LDS::element;
	v = lds.head->prev;
	delete lds.head->prev;
	lds.head = v->prev;
	v->next = lds.head;
	delete v;

}

// Подсчет коль-ва элементов.
template <typename T>
void podschet(LDS<T>& lds) {
	LDS::element* v = new LDS::element;
	v = lds.head->next;
	int k = 0;
	while (v!=lds.head)
	{
		k++;
		v = v->next;
	}
	delete v;
	std::cout <<"Количество элементов:"<< k << std::endl;
}
//Добавление по индексу.
template <typename T>
void push_index(LDS<T>& lds, int c, T value) {
	LDS::element* new_el= new LDS::element;
	new_el->value = value;
	LDS::element* v = new LDS::element;
	v = lds.head->next;
	LDS::element* z = new LDS::element;
	int k = 0;
	while (k!=c)
	{
		k++;
		v = v->next;
	}
	z = v->next;
	v->next = new_el;
	new_el->prev = v;
	new_el->next = z;
	z->prev = new_el;
	delete z, v;
}
//Добавление по указателю.
template <typename T>
void push_iterator(LDS<T>& lds, T* t,T value) {
	T* prev2 = nullptr;
	T* next2 = nullptr;
	LDS::element* v = new LDS::element;
	v = lds.head->next;
	LDS::element* y = new LDS::element;
	while (v != t )
	{
		v = v->next;
	}
	prev2 = v;
	next2 = v->next;
	v->next=y;
	y->next =next2;
	y->prev = prev2;
	v->next->prev = y;
	y.value = value;
	delete  v;
}
//Извлечение по индексу.
template <typename T>
void pop_index(LDS<T>& lds, int c) {
	LDS::element* v = new LDS::element;
	v = lds.head->next;
	LDS::element* y = new LDS::element;
	int k = 0;
	while (k !=c)
	{
		k++;
		v = v->next;
	}
	y = v->next;
	delete v->next;
	v->next = y->next;
	y->next->prev = v;
	delete  v, y;
}
//Извлечение по итератору.
template <typename T>
void pop_iterator(LDS<T>& lds) {
	LDS::element* v = new LDS::element;
	v = lds.head->next;
	LDS::element* y = new LDS::element;
	while (v != y)
	{
		v = v->next;
	}
	y = v->next;
	delete v->next;
	v->next = y->next;
	y->next->next = y->prev;
	delete y, v;
}

// Получение значения по индексу.
template <typename T>
void poisk_po_indeksy(LDS<T>& lds,int z) {
	LDS::element* v = new LDS::element;
	v = lds.head;
	int k = 0;
	int a;
	while (k < 1) {
		if (a == z) {
			std::cout << v->value;
			k++;
		}
		a++;
		v = v->next;
	}
}
// Поиск позиции первого элемента, равного по значению искоиоиу.
template <typename T>
void poisk_po_znacheniy(LDS<T>& lds,int c) {
	LDS::element* v = new LDS::element;
	v = lds.head;
	int y = 0;
	int k = 0;
	while (k < 1) {
		if (v->value == c) {
			std::cout << y;
			k++;
		}
		v = v->next;
		y++;
	}
}
// Печать на экран.
template <typename T>
void print_LDS(LDS<T>& lds) {
	LDS::element* v = new LDS::element;
	v = lds.head;
	while (v->next != lds.head) {
		std::cout << v << std::endl;
		v = v->next;
	}
	std::cout << lds.head->prev << std::endl;
}



//Линейный список.
template <typename T, int size>
struct LS
{	
	T value[size];
	int size;
};
template <typename T, int size>
void constructor_l(LS<T, size>& ls)
{
	ls.size= 0;
	for (int i = 0; i < size; ++i)
	{
		ls.value[i] = 0;
	}
}
template <typename T,int size>
size_t size_of_ls(LS<T, size>& ls)
{
	return LS.size();
}
template <typename T, int size>
void push_back(LS<T, size>& ls,T value) {
	if (size > ls.size) {
		std::cout << "Error" << std::endl;
	}
	else {
		ls.value[size] = value;
	}
	size++;
}
template <typename T, int size>
void push_index(LS<T, size>& ls, T value, int k) {
	if (k < size + 1  ) {
		ls.value[k] = value;
	}
	size++;
}
template <typename T, int size>
T izvlechenie_iz_n(LS<T, size>& ls) {
	T otv = ls.value[0];
	ls.size--;
	for (size_t i = 0; i < ls.size; i++) {
		ls.value[i] = ls.value[i + 1];
	}
	ls.value[ls.size + 1] = 0;
	return otv;
}
template <typename T, int size>
T izvlechenie_iz_k(LS<T, size>& ls) {
	T otv = ls.value[ls.size];
	ls.size--;
	ls.value[ls.size + 1] = 0;
	return otv;
}
template <typename T, int size>
T izvlechenie_po_i(LS<T, size>& ls,int k) {
	T otv = ls.value[k];
	for (size_t i = k; i < ls.size; i++) {
		ls.value[i] = ls.value[i + 1];
	}
	ls.size--;
	ls.value[ls.size + 1] = 0;
	return otv;
}
template <typename T, int size>
T polychenie_po_i(LS<T, size>& ls, int k) {
	T otv = ls.value[k];
	return otv;
}
template <typename T, int size>
T poisk(LS<T, size>& ls, T z) {
	int k = 0;
	int i = 0;
	while (k < 1) {
		if (z == ls.value[i]) {
			k++;
			return i;
		}
		else {
			i++;
		}
	}
}
template <typename T, int size>
void print_ls(LS<T, size>& ls) {
	for (size_t i = 0; i < ls.size; i++) {
		std::cout << ls.value[i] << ' ';
	}
}


int main()
{
	setlocale(LC_ALL, "Russian");
    std::cout << "Hello World!\n";
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку".

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
