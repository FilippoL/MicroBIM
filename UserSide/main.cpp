#include <stdio.h>
#include <iostream>
#include "Builder.h"

int main() {
	Builder builder;

	builder.initialise_canvas_dimension();
	builder.run();

	//builder.make_default_prefab();

	std::cin.ignore();

	return 0;
}