#include <utility>
#include <iostream>

/*
*  Здесь мы имеем функцию foo() со спецификацией noexcept,
*  проверяющей, не будут ли бросать исключение сложение двух объектов типа Т,
*  копирование объектов типа Т и присваивание объектов типа Т
*
*/

template <class T>
void do_math() noexcept(noexcept (std::declval<T>() + std::declval<T>()) && std::is_nothrow_copy_constructible<T>::value && std::is_nothrow_assignable<T&, T>::value)
{
	//что-то делаем
}


int main() {
	bool a = noexcept(do_math<int>());  //true
	bool b = noexcept(do_math<std::string>());  //false
	return 0;
}