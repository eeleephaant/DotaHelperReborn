#pragma once

struct TextPlaceholder
{
    public:
    int x, y;
    const char* text;

    TextPlaceholder(int x, int y, const char* text) {
        this->x = x;
        this->y = y;
        this->text = text;
    }
};
