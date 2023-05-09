#include "Paddle.h"

Paddle::Paddle(int i) {
	id = i;
	speed = 20.f;

	if (id == 0) {
		pos.x = 0;
	}
	else if (id == 1) {
		pos.x = SCREEN_WIDTH - width;
	}

	pos.y = SCREEN_HEIGHT / 2 - height / 2;

	rect.x = (int)pos.x;
	rect.y = (int)pos.y;
	rect.w = width;
	rect.h = height;
}

void Paddle::Update() {
	// Set initial y
	pos.y = pos.y + speed * dir;

	// Keey y inbounds
	if (pos.y < 0) {
		pos.y = 0;
	}
	else if (pos.y + height > SCREEN_HEIGHT) {
		pos.y = SCREEN_HEIGHT - height;
	}

	rect.y = pos.y;
}

void Paddle::SetDir(int d) {
	dir = d;
}

int Paddle::GetId() {
	return id;
}

Vec2 Paddle::GetPos() {
	return pos;
}

SDL_Rect* Paddle::GetRect() {
	return &rect;
}
