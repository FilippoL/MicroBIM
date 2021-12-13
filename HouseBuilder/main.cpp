#include <stdio.h>
#include <iostream>
#include "Builder.h"

int main() {
	Builder builder;

	builder.initialise_canvas_dimension();
	builder.run();

	return 0;
}