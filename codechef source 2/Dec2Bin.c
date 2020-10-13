#include<stdio.h>
#include<stdlib.h>
#define MAX_LENGTH 64
#define PRECISION 16

char bit[2] = {'0','1'};

char* dec2bin(double dec, int precision)
{
	int integral_part = (int) dec;
	dec -= integral_part;
	
	char* ans;
	ans = malloc(MAX_LENGTH);
	
	int i;
	for(i=0;i<MAX_LENGTH;i++) ans[i]=' ';
	
	int pos = MAX_LENGTH-precision-2; 
	ans[pos] = '.';
	pos--;
	
	int current_bit=0;
	
	while(integral_part>0)
	{
		current_bit = integral_part % 2;
		ans[pos] = bit[current_bit];
		pos--;
		integral_part = (integral_part-current_bit)/2;
	} 
	
	int firstpos = pos;
	
	pos = MAX_LENGTH - precision-1;
	while(pos<MAX_LENGTH-1)
	{
		dec *= 2;
		current_bit = (dec>=1) ? 1 : 0;
		dec -= current_bit;
		ans[pos] = bit[current_bit];
		pos++;
	}
	
	return ans+firstpos+1;
}

int main()
{
	double dec;

	scanf("%lf", &dec);
	
	printf("%s",dec2bin(dec, PRECISION));
	
	return 0;
}
