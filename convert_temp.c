#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>


double f_to_c(double f_temp)
{
	double c_temp = 5.0/9.0 * (f_temp - 32);
	return c_temp;
}

double c_to_f(double c_temp)
{
	double f_temp = (1.8 * c_temp) + 32;
	return f_temp;
}

int is_num(char *number)
{
	int length  = strlen(number);
        int j;
        int is_number = 1;
	int dots = 0;
        for (j = 0; j < length; j++)
        {
		if (number[j] == '.')
		{
			dots += 1;
			if (dots > 1)
			{
				printf("%s is not a valid temperature.\n", number);
                        	return is_number = 0;
                        	break;
			}
		}
		if (number[j] == '-')
		{
			if (j != 0)
			{
				printf("%s is not a valid temperature.\n", number);
                        	return is_number = 0;
                        	break;
			}
		}
                if ((!isdigit(number[j])) && (number[j] != '.') && (number[j] != '-'))
                {
			printf("%s is not a valid temperature.\n", number);
                        return is_number = 0;
                        break;
                }
        }
	return is_number = 1;
}

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		printf("usage: convert_temp F|C temp (temp ...)\n");
		return 0;
	}
	if ((strcmp(argv[1], "F") == 0) && (argc > 2))
	{
		for (int i = 2; i < argc; i++)
		{
			double arg = atof(argv[i]);
			double c_temp = f_to_c(arg);
			int is_number = is_num(argv[i]);
			if (is_number == 1)
			{
				printf("%gF = %gC\n", arg, c_temp);
			}
		}
	}
	else if ((strcmp(argv[1], "C") == 0) && (argc > 2))
	{
                for (int i = 2; i < argc; i++)
                {
                        double arg = atof(argv[i]);
			double f_temp = c_to_f(arg);
			int is_number = is_num(argv[i]);
                        if (is_number == 1)
                        {
                        	printf("%gC = %gF\n", arg, f_temp);
			}
                }
	}
	else
	{
		printf("usage: convert_temp F|C temp (temp ...)\n");
	}
	return 0;
}	
