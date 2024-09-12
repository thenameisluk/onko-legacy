#pragma once
#include <functional>
#include "ctx.hpp"

void drawText(dsl::ctx8888& ctx);
void triggerText(std::string text,std::function<void()> callback);