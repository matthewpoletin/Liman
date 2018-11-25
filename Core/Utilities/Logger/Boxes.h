/**
 * @file Boxes.h
 * @author matthewpoletin
 */

#pragma once

#include <string>

#ifdef WINDOWS
#include <Windows.h>
#endif

void CreateBox(std::string header, std::string text) {
#ifdef WINDOWS
	LPCTSTR s = L"char";

	MessageBox(
		NULL,
		L"Привет!",
		L"Дай пять",
		MB_YESNO | //Да нет (кнопки)
		MB_DEFBUTTON1 | //Выделеная кнопка
		MB_ICONEXCLAMATION | //Тип иконки
		MB_DEFAULT_DESKTOP_ONLY
		);
#endif

}
