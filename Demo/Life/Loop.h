#pragma once
// Loop.h - MainLoop functions.
#include <iostream>


void Iteration(void);
void HandleKeyboard(void);
void CheckCollisions(void);
void UpdateMovables(float deltaTime);
void Draw(void);

void OnUpPress();
void OnDownPress();
void OnRightPress();
void OnLeftPress();

void OnSpacePress();