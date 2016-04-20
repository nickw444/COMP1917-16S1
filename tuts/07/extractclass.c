#include "string.h"
#include "stdio.h"
#include "stdlib.h"
#include "assert.h"

typedef struct _triordinate
{
	double x;
	double y;
	double z;
} triordinate;

triordinate extractString(char * string);


int main(int argc, char const *argv[])
{
	/* code */
	char * myString = "x33.333_y-43.222_z10";
	triordinate myCoords = extractString(myString);
	printf("The Coordinates were: X:%lf  Y:%lf Z:%lf\n", myCoords.x, myCoords.y, myCoords.z);
}

triordinate extractString(char * string) {
	printf("We need to extract the values from:%s\n", string);
	int i = 0;
	char current_char = string[i];

	int is_x_current = 0;
	int is_y_current = 0;
	int is_z_current = 0;

	char x_string[10];
	char y_string[10];
	char z_string[10];
	int current_pos = 0;

	while(current_char != 0) {
		printf("%c\n", current_char);

		if (is_x_current) {
			x_string[current_pos] = current_char;
			current_pos++;
		}
		else if (is_y_current) {
			y_string[current_pos] = current_char;
			current_pos++;
		}
		else if (is_z_current) {
			z_string[current_pos] = current_char;
			current_pos++;
		}

		if (current_char == 'x') {
			is_x_current = 1;
		}
		else if (current_char == 'y') {
			is_y_current = 1;
		}
		else if (current_char == 'z') {
			is_z_current = 1;
		}
		else if (current_char == '_') {
			if (is_x_current) {
				x_string[current_pos] = 0;
			}
			else if (is_z_current) {
				z_string[current_pos] = 0;
			}
			else if (is_y_current) {
				y_string[current_pos] = 0;
			}

			is_x_current = is_y_current = is_z_current = 0;
			current_pos = 0;
		}


		i++;
		current_char = string[i];
	}
	printf("X Part :%s\n", x_string);
	printf("Y Part :%s\n", y_string);
	printf("Z Part :%s\n", z_string);

	triordinate extractedTri;
	extractedTri.x = 44.4;
	extractedTri.y = 44.5;
	extractedTri.z = 45.5;

	return extractedTri;
}